#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*=========================================================
 SMART TRAFFIC LIGHT CONTROL SYSTEM

 DATA STRUCTURES USED:
 1. Queue          -> Represents vehicles waiting in lanes
 2. Max Heap       -> Selects lane with highest traffic
 3. Stack          -> Stores signal history
 4. Linked List    -> Manages emergency vehicles
 5. BST            -> Stores vehicle records
 6. Graph          -> Represents road network

=========================================================*/

#define INTERSECTIONS 4
#define LANES 4
#define MAX_VEHICLES 100
#define MAX_HISTORY 100
#define MAX_HEAP_SIZE 100

/*==================================================
 QUEUE IMPLEMENTATION

 Purpose:
 - Each lane at an intersection is represented
   using a Queue.
 - Vehicles follow FIFO
   (First In First Out) principle.
 - Vehicle enters from rear (enqueue)
 - Vehicle exits from front (dequeue)

 Real World Mapping:
 Lane -> Queue
 Vehicles -> Queue Elements

 Time Complexity:
 Enqueue : O(1)
 Dequeue : O(1)

==================================================*/

typedef struct
{
    int vehicles[MAX_VEHICLES];
    int front;
    int rear;
    int count;

} Queue;

/* Initializes an empty lane queue */
void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

/* Checks whether lane is empty */
int isQueueEmpty(Queue *q)
{
    return q->count == 0;
}

/* Checks whether lane has reached maximum capacity */
int isQueueFull(Queue *q)
{
    return q->count == MAX_VEHICLES;
}

/* Adds a new vehicle to the lane queue */
void enqueue(Queue *q, int vehicleID)
{
    if(isQueueFull(q))
        return;

    q->rear =
        (q->rear + 1) % MAX_VEHICLES;

    q->vehicles[q->rear] =
        vehicleID;

    q->count++;
}

/* Removes the vehicle that crosses the signal */
int dequeueVehicle(Queue *q)
{
    if(isQueueEmpty(q))
        return -1;

    int vehicle =
        q->vehicles[q->front];

    q->front =
        (q->front + 1) % MAX_VEHICLES;

    q->count--;

    return vehicle;
}

/* Returns the current number of vehicles in lane */
int getVehicleCount(Queue *q)
{
    return q->count;
}

/*==================================================
 PRIORITY QUEUE USING MAX HEAP

 Purpose:
 - Determines which lane should get
   the green signal.
 - Lane with maximum vehicles gets
   highest priority.

 Real World Mapping:
 Lane Traffic Density -> Heap Priority

 Example:
 Lane 1 = 20 vehicles
 Lane 2 = 50 vehicles
 Lane 3 = 15 vehicles

 Selected Lane:
 Lane 2 (Highest Traffic)

 Time Complexity:
 Insert : O(log n)
 Extract Max : O(log n)

==================================================*/

typedef struct
{
    int laneID;
    int vehicleCount;

} HeapNode;

typedef struct
{
    HeapNode nodes[MAX_HEAP_SIZE];
    int size;

} MaxHeap;

/* Swaps two heap nodes */
void swapHeap(
        HeapNode *a,
        HeapNode *b)
{
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

/* Initializes an empty max heap */
void initHeap(MaxHeap *heap)
{
    heap->size = 0;
}

/* Restores heap property after insertion */
void heapifyUp(
        MaxHeap *heap,
        int index)
{
    while(index > 0)
    {
        int parent =
            (index - 1) / 2;

        if(heap->nodes[parent].
           vehicleCount <
           heap->nodes[index].
           vehicleCount)
        {
            swapHeap(
                &heap->nodes[parent],
                &heap->nodes[index]);

            index = parent;
        }
        else
        {
            break;
        }
    }
}

/* Restores heap property after deletion */
void heapifyDown(
        MaxHeap *heap,
        int index)
{
    while(1)
    {
        int largest = index;

        int left =
            2 * index + 1;

        int right =
            2 * index + 2;

        if(left < heap->size &&
           heap->nodes[left].
           vehicleCount >
           heap->nodes[largest].
           vehicleCount)
        {
            largest = left;
        }

        if(right < heap->size &&
           heap->nodes[right].
           vehicleCount >
           heap->nodes[largest].
           vehicleCount)
        {
            largest = right;
        }

        if(largest == index)
            break;

        swapHeap(
            &heap->nodes[index],
            &heap->nodes[largest]);

        index = largest;
    }
}

/* Inserts lane information into priority queue */
void insertHeap(
        MaxHeap *heap,
        int laneID,
        int vehicleCount)
{
    heap->nodes[heap->size].
        laneID = laneID;

    heap->nodes[heap->size].
        vehicleCount =
        vehicleCount;

    heapifyUp(
        heap,
        heap->size);

    heap->size++;
}

/* Selects lane with highest traffic density */
HeapNode extractMax(
        MaxHeap *heap)
{
    HeapNode empty =
    {
        -1,
        -1
    };

    if(heap->size == 0)
        return empty;

    HeapNode maxNode =
        heap->nodes[0];

    heap->nodes[0] =
        heap->nodes[
            heap->size - 1];

    heap->size--;

    heapifyDown(heap,0);

    return maxNode;
}

/* Builds priority queue based on vehicle count */
void buildHeap(
        MaxHeap *heap,
        int laneCounts[],
        int totalLanes)
{
    initHeap(heap);

    for(int i=0;
        i<totalLanes;
        i++)
    {
        insertHeap(
            heap,
            i,
            laneCounts[i]);
    }
}

/*==================================================
 STACK IMPLEMENTATION

 Purpose:
 - Stores history of signal decisions.
 - Keeps track of previously
   activated green signals.

 Real World Mapping:
 Traffic Control Log

 Example:
 Lane 2 -> Green
 Lane 1 -> Green
 Lane 4 -> Green

 Latest signal remains at top.

 Time Complexity:
 Push : O(1)
 Pop  : O(1)

==================================================*/

typedef struct
{
    int intersectionID;
    int laneID;
    int vehicles;

} SignalRecord;

typedef struct
{
    SignalRecord records[
        MAX_HISTORY];

    int top;

} SignalStack;

/* Initializes empty stack */
void initStack(
        SignalStack *s)
{
    s->top = -1;
}

/* Checks whether stack is empty */
int isStackEmpty(
        SignalStack *s)
{
    return s->top == -1;
}

/* Stores signal activity for future analysis */
void pushSignal(
        SignalStack *s,
        int intersectionID,
        int laneID,
        int vehicles)
{
    if(s->top ==
       MAX_HISTORY - 1)
    {
        return;
    }

    s->top++;

    s->records[s->top].
        intersectionID =
        intersectionID;

    s->records[s->top].
        laneID =
        laneID;

    s->records[s->top].
        vehicles =
        vehicles;
}

/* Displays previous signal history */
void displayHistory(
        SignalStack *s)
{
    printf(
    "\n========== SIGNAL HISTORY ==========\n");

    if(isStackEmpty(s))
    {
        printf(
        "No signal history available.\n");

        return;
    }

    for(int i=s->top;
        i>=0;
        i--)
    {
        printf(
        "Intersection %d | Lane %d | Vehicles %d\n",
        s->records[i].
        intersectionID,

        s->records[i].
        laneID,

        s->records[i].
        vehicles);
    }
}



/*==================================================
 LINKED LIST IMPLEMENTATION

 Purpose:
 - Stores emergency vehicles dynamically.
 - Gives priority to Ambulance, Fire Truck,
   and Police vehicles.

 Real World Mapping:
 Emergency Vehicle Queue

 Example:
 Ambulance
    ↓
 Fire Truck
    ↓
 Police Vehicle

 Time Complexity:
 Insertion : O(n)
 Deletion  : O(1)

==================================================*/

typedef struct EmergencyNode
{
    int vehicleID;
    int intersectionID;
    int laneID;
    char type[20];

    struct EmergencyNode *next;

} EmergencyNode;

typedef struct
{
    EmergencyNode *head;

} EmergencyList;

/* Initializes emergency vehicle list */
void initEmergencyList(
        EmergencyList *list)
{
    list->head = NULL;
}

/* Adds emergency vehicle to linked list */
void addEmergencyVehicle(
        EmergencyList *list,
        int vehicleID,
        int intersectionID,
        int laneID,
        char type[])
{
    EmergencyNode *newNode =
        (EmergencyNode*)
        malloc(sizeof(EmergencyNode));

    newNode->vehicleID =
        vehicleID;

    newNode->intersectionID =
        intersectionID;

    newNode->laneID =
        laneID;

    strcpy(
        newNode->type,
        type);

    newNode->next = NULL;

    if(list->head == NULL)
    {
        list->head = newNode;
        return;
    }

    EmergencyNode *temp =
        list->head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

/* Checks if emergency vehicle exists */
int hasEmergencyVehicle(
        EmergencyList *list)
{
    return list->head != NULL;
}

/* Returns highest priority emergency vehicle */
EmergencyNode*
getNextEmergency(
        EmergencyList *list)
{
    return list->head;
}

/* Removes serviced emergency vehicle */
void removeEmergencyVehicle(
        EmergencyList *list)
{
    if(list->head == NULL)
        return;

    EmergencyNode *temp =
        list->head;

    list->head =
        list->head->next;

    free(temp);
}

/* Displays all emergency vehicles */
void displayEmergencyVehicles(
        EmergencyList *list)
{
    printf(
    "\n======= EMERGENCY VEHICLES =======\n");

    if(list->head == NULL)
    {
        printf(
        "No Emergency Vehicles\n");

        return;
    }

    EmergencyNode *temp =
        list->head;

    while(temp != NULL)
    {
        printf(
        "ID:%d | %s | Intersection:%d | Lane:%d\n",

        temp->vehicleID,
        temp->type,
        temp->intersectionID,
        temp->laneID);

        temp = temp->next;
    }
}

/*==================================================
 BINARY SEARCH TREE (BST)

 Purpose:
 - Stores all vehicle records.
 - Allows fast searching of vehicles.

 Real World Mapping:
 Vehicle Database

 Example:
 Vehicle ID
 Intersection
 Lane
 Arrival Cycle

 Time Complexity:
 Insert : O(log n)
 Search : O(log n)

 Worst Case:
 O(n)

==================================================*/

typedef struct VehicleNode
{
    int vehicleID;
    int intersectionID;
    int laneID;
    int arrivalCycle;

    struct VehicleNode *left;
    struct VehicleNode *right;

} VehicleNode;

/* Creates new BST node */
VehicleNode*
createVehicleNode(
        int vehicleID,
        int intersectionID,
        int laneID,
        int arrivalCycle)
{
    VehicleNode *newNode =
        (VehicleNode*)
        malloc(sizeof(VehicleNode));

    newNode->vehicleID =
        vehicleID;

    newNode->intersectionID =
        intersectionID;

    newNode->laneID =
        laneID;

    newNode->arrivalCycle =
        arrivalCycle;

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/* Inserts vehicle into BST */
VehicleNode*
insertVehicle(
        VehicleNode *root,
        int vehicleID,
        int intersectionID,
        int laneID,
        int arrivalCycle)
{
    if(root == NULL)
    {
        return createVehicleNode(
            vehicleID,
            intersectionID,
            laneID,
            arrivalCycle);
    }

    if(vehicleID <
       root->vehicleID)
    {
        root->left =
            insertVehicle(
                root->left,
                vehicleID,
                intersectionID,
                laneID,
                arrivalCycle);
    }
    else if(vehicleID >
            root->vehicleID)
    {
        root->right =
            insertVehicle(
                root->right,
                vehicleID,
                intersectionID,
                laneID,
                arrivalCycle);
    }

    return root;
}

/* Searches vehicle using vehicle ID */
VehicleNode*
searchVehicle(
        VehicleNode *root,
        int vehicleID)
{
    if(root == NULL)
        return NULL;

    if(root->vehicleID ==
       vehicleID)
    {
        return root;
    }

    if(vehicleID <
       root->vehicleID)
    {
        return searchVehicle(
            root->left,
            vehicleID);
    }

    return searchVehicle(
        root->right,
        vehicleID);
}

/* Displays vehicle database in sorted order */
void inorderVehicles(
        VehicleNode *root)
{
    if(root == NULL)
        return;

    inorderVehicles(
        root->left);

    printf(
    "ID:%d | Intersection:%d | Lane:%d | Cycle:%d\n",

    root->vehicleID,
    root->intersectionID,
    root->laneID,
    root->arrivalCycle);

    inorderVehicles(
        root->right);
}

/*==================================================
 GRAPH IMPLEMENTATION

 Purpose:
 - Represents road network.
 - Nodes represent intersections.
 - Edges represent roads.

 Real World Mapping:

 A ----- B
 |       |
 |       |
 C ----- D

 Used for:
 - Smart city traffic network
 - Route planning
 - Future shortest path algorithms

 Time Complexity:
 Edge Check : O(1)

==================================================*/

typedef struct
{
    int adjacency
    [INTERSECTIONS]
    [INTERSECTIONS];

} Graph;

/* Initializes road network graph */
void initGraph(Graph *g)
{
    int temp[4][4] =
    {
        {0,1,1,0},
        {1,0,0,1},
        {1,0,0,1},
        {0,1,1,0}
    };

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            g->adjacency[i][j] =
                temp[i][j];
        }
    }
}

/* Displays adjacency matrix */
void displayGraph(Graph *g)
{
    printf(
    "\n====== ROAD NETWORK ======\n");

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf(
            "%d ",
            g->adjacency[i][j]);
        }

        printf("\n");
    }
}

/* Checks connectivity between intersections */
int areConnected(
        Graph *g,
        int source,
        int destination)
{
    return
    g->adjacency
    [source]
    [destination];
}


/*==================================================
 SMART TRAFFIC CONTROLLER

 Purpose:
 - Each intersection contains 4 lanes.
 - Sensors generate vehicles automatically.
 - Heap selects busiest lane.
 - Dynamic timer adjusts signal duration.
 - Partial lane clearance simulates real traffic.
 - Stack stores signal history.
 - BST stores vehicle records.
 - Linked List manages emergency vehicles.
==================================================*/

typedef struct
{
    Queue lanes[LANES];

} Intersection;

static int vehicleIDCounter = 1000;

/* Initializes all intersections and lanes */
void initializeIntersections(
        Intersection intersections[])
{
    for(int i=0;
        i<INTERSECTIONS;
        i++)
    {
        for(int j=0;
            j<LANES;
            j++)
        {
            initQueue(
                &intersections[i].
                lanes[j]);
        }
    }
}

/*==================================================
 DYNAMIC SIGNAL TIMER

 More traffic -> More green signal time

 Minimum : 5 seconds
 Maximum : 30 seconds
==================================================*/

int calculateTimer(
        int vehicles)
{
    int timer =
        vehicles / 2;

    if(timer < 5)
        timer = 5;

    if(timer > 30)
        timer = 30;

    return timer;
}

/*==================================================
 PARTIAL LANE CLEARANCE

 Instead of clearing whole lane,
 only a realistic number of vehicles pass.

 Example:
 58 vehicles -> 25 pass
==================================================*/

void partialClear(
        Queue *lane)
{
    int pass;

    if(lane->count >= 50)
        pass = 25;

    else if(lane->count >= 30)
        pass = 20;

    else if(lane->count >= 15)
        pass = 10;

    else
        pass = 5;

    if(pass > lane->count)
        pass = lane->count;

    for(int i=0;
        i<pass;
        i++)
    {
        dequeueVehicle(lane);
    }

    printf(
    "%d vehicles passed.\n",
    pass);
}

/*==================================================
 SENSOR SIMULATION

 Simulates vehicle detection sensors.

 Randomly generates incoming vehicles
 for every lane.
==================================================*/

void simulateTraffic(
        Intersection intersections[],
        VehicleNode **database,
        int cycle)
{
    for(int i=0;
        i<INTERSECTIONS;
        i++)
    {
        for(int j=0;
            j<LANES;
            j++)
        {
            int arrivals =
                rand() % 15;

            for(int k=0;
                k<arrivals;
                k++)
            {
                int id =
                    vehicleIDCounter++;

                enqueue(
                    &intersections[i].
                    lanes[j],
                    id);

                *database =
                    insertVehicle(
                    *database,
                    id,
                    i+1,
                    j+1,
                    cycle);
            }
        }
    }
}

/*==================================================
 DISPLAY CURRENT TRAFFIC STATUS
==================================================*/

void displayTrafficStatus(
        Intersection intersections[])
{
    printf(
    "\n========== TRAFFIC STATUS ==========\n");

    for(int i=0;
        i<INTERSECTIONS;
        i++)
    {
        printf(
        "\nIntersection %d\n",
        i+1);

        for(int j=0;
            j<LANES;
            j++)
        {
            printf(
            "Lane %d : %d vehicles\n",
            j+1,
            intersections[i].
            lanes[j].count);
        }
    }
}

/*==================================================
 PROCESS SINGLE INTERSECTION

 Heap selects busiest lane.
 Dynamic timer calculated.
 Lane partially cleared.
 Signal stored in history.
==================================================*/

void processIntersection(
        Intersection *intersection,
        int intersectionID,
        SignalStack *history,
        EmergencyList *emergencies)
{
    /* FIRST PRIORITY -> Emergency Vehicle */
    if(hasEmergencyVehicle(emergencies))
    {
        EmergencyNode *emergency =
            getNextEmergency(emergencies);

        if(emergency->intersectionID ==
           intersectionID)
        {
            printf(
            "\n*** EMERGENCY VEHICLE DETECTED ***\n");

            printf(
            "Type : %s\n",
            emergency->type);

            printf(
            "Intersection : %d\n",
            emergency->intersectionID);

            printf(
            "Green Signal -> Lane %d\n",
            emergency->laneID);

            /* Allow emergency lane to pass */
            partialClear(
                &intersection->lanes[
                emergency->laneID - 1]);

            pushSignal(
                history,
                intersectionID,
                emergency->laneID,
                getVehicleCount(
                &intersection->lanes[
                emergency->laneID - 1]));

            removeEmergencyVehicle(
                emergencies);

            return;
        }
    }

    /* NORMAL HEAP-BASED LOGIC */
    int laneCounts[LANES];

    for(int i=0;i<LANES;i++)
    {
        laneCounts[i] =
            getVehicleCount(
            &intersection->lanes[i]);
    }

    MaxHeap heap;

    buildHeap(
        &heap,
        laneCounts,
        LANES);

    HeapNode greenLane =
        extractMax(&heap);

    if(greenLane.laneID == -1)
        return;

    int timer =
        calculateTimer(
        greenLane.vehicleCount);

    printf(
    "\nIntersection %d\n",
    intersectionID);

    printf(
    "Green Signal -> Lane %d\n",
    greenLane.laneID + 1);

    printf(
    "Vehicles Waiting : %d\n",
    greenLane.vehicleCount);

    printf(
    "Signal Timer : %d sec\n",
    timer);

    partialClear(
        &intersection->lanes[
        greenLane.laneID]);

    pushSignal(
        history,
        intersectionID,
        greenLane.laneID + 1,
        greenLane.vehicleCount);
}

/*==================================================
 MAIN FUNCTION
==================================================*/

int main()
{
    srand(time(NULL));

    Graph cityGraph;

    initGraph(
        &cityGraph);

    printf(
    "\nSMART TRAFFIC LIGHT CONTROL SYSTEM\n");

    printf(
    "\nRoad Network:\n");

    displayGraph(
        &cityGraph);

    Intersection intersections[
        INTERSECTIONS];

    initializeIntersections(
        intersections);

    VehicleNode *database =
        NULL;

    SignalStack history;

    initStack(
        &history);

    EmergencyList emergencies;

    initEmergencyList(
        &emergencies);

    int cycle = 1;
    int choice;

    while(1)
    {
        printf(
        "\n=================================\n");

        printf(
        "TRAFFIC CYCLE %d\n",
        cycle);

        printf(
        "1. Run Traffic Cycle\n");

        printf(
        "2. View Traffic Status\n");

        printf(
        "3. View Signal History\n");

        printf(
        "4. View Vehicle Database\n");

        printf(
        "5. Search Vehicle\n");

        printf(
        "6. Add Emergency Vehicle\n");

        printf(
        "7. View Emergency Vehicles\n");

        printf(
        "0. Exit\n");

        printf(
        "Enter Choice : ");

        scanf(
        "%d",
        &choice);

        switch(choice)
        {
            case 1:
            {
                printf(
                "\nGenerating Traffic Using Sensors...\n");

                simulateTraffic(
                    intersections,
                    &database,
                    cycle);

                for(int i=0;
                    i<INTERSECTIONS;
                    i++)
                {
                  processIntersection(
    &intersections[i],
    i+1,
    &history,
    &emergencies);
                }

                cycle++;

                break;
            }

            case 2:
            {
                displayTrafficStatus(
                    intersections);

                break;
            }

            case 3:
            {
                displayHistory(
                    &history);

                break;
            }

            case 4:
            {
                printf(
                "\n====== VEHICLE DATABASE ======\n");

                inorderVehicles(
                    database);

                break;
            }

            case 5:
            {
                int id;

                printf(
                "Enter Vehicle ID : ");

                scanf(
                "%d",
                &id);

                VehicleNode *found =
                    searchVehicle(
                    database,
                    id);

                if(found)
                {
                    printf(
                    "\nVehicle Found\n");

                    printf(
                    "Intersection : %d\n",
                    found->intersectionID);

                    printf(
                    "Lane : %d\n",
                    found->laneID);

                    printf(
                    "Arrival Cycle : %d\n",
                    found->arrivalCycle);
                }
                else
                {
                    printf(
                    "Vehicle Not Found\n");
                }

                break;
            }

            case 6:
            {
                int id;
                int intersection;
                int lane;
                char type[20];

                printf(
                "Vehicle ID : ");
                scanf(
                "%d",
                &id);

                printf(
                "Intersection : ");
                scanf(
                "%d",
                &intersection);

                printf(
                "Lane : ");
                scanf(
                "%d",
                &lane);

                printf(
                "Type (Ambulance/Fire/Police): ");
                scanf(
                "%s",
                type);

                addEmergencyVehicle(
                    &emergencies,
                    id,
                    intersection,
                    lane,
                    type);

                printf(
                "Emergency Vehicle Added.\n");

                break;
            }

            case 7:
            {
                displayEmergencyVehicles(
                    &emergencies);

                break;
            }

            case 0:
            {
                printf(
                "\nSystem Shutdown\n");

                return 0;
            }

            default:
            {
                printf(
                "Invalid Choice\n");
            }
        }
    }

    return 0;
}
