# Smart-Traffic-Control-System

A console-based Smart Traffic Light Control System developed in **C** to simulate intelligent traffic management using multiple Data Structures. The system dynamically manages traffic at multiple intersections, prioritizes congested lanes, handles emergency vehicles, maintains vehicle records, and stores signal history.

---

## 📌 Features

- Simulates real-time traffic generation using virtual sensors.
- Dynamically allocates green signals based on traffic density.
- Calculates adaptive signal timing.
- Manages vehicles using Queue (FIFO).
- Prioritizes busiest lanes using a Max Heap.
- Maintains signal history using a Stack.
- Stores and searches vehicle records using a Binary Search Tree (BST).
- Handles emergency vehicles using a Linked List.
- Represents the road network using a Graph.
- Supports vehicle search by Vehicle ID.
- Displays traffic status and signal history.

---

## 🛠️ Data Structures Used

| Data Structure | Purpose |
|----------------|---------|
| Queue | Vehicle management in each lane |
| Max Heap | Select lane with highest traffic density |
| Stack | Store signal history |
| Linked List | Manage emergency vehicles |
| Binary Search Tree | Store and search vehicle records |
| Graph | Represent the road network |

---

## 💻 Technologies

- C Programming
- Data Structures & Algorithms
- Console Application

---

## 📋 Menu

```
1. Run Traffic Cycle
2. View Traffic Status
3. View Signal History
4. View Vehicle Database
5. Search Vehicle
6. Add Emergency Vehicle
7. View Emergency Vehicles
0. Exit
```

---

## 📷 Sample Output

=================================
TRAFFIC CYCLE 2
1. Run Traffic Cycle
2. View Traffic Status
3. View Signal History
4. View Vehicle Database
5. Search Vehicle
6. Add Emergency Vehicle
7. View Emergency Vehicles
0. Exit
Enter Choice : 1

Generating Traffic Using Sensors...

Intersection 1
Green Signal -> Lane 2
Vehicles Waiting : 13
Signal Timer : 6 sec
5 vehicles passed.

Intersection 2
Green Signal -> Lane 4
Vehicles Waiting : 13
Signal Timer : 6 sec
5 vehicles passed.

Intersection 3
Green Signal -> Lane 4
Vehicles Waiting : 14
Signal Timer : 7 sec
5 vehicles passed.

Intersection 4
Green Signal -> Lane 3
Vehicles Waiting : 11
Signal Timer : 5 sec
5 vehicles passed.

=================================
TRAFFIC CYCLE 2
1. Run Traffic Cycle
2. View Traffic Status
3. View Signal History
4. View Vehicle Database
5. Search Vehicle
6. Add Emergency Vehicle
7. View Emergency Vehicles
0. Exit
Enter Choice : 2

========== TRAFFIC STATUS ==========

Intersection 1
Lane 1 : 4 vehicles
Lane 2 : 8 vehicles
Lane 3 : 1 vehicles
Lane 4 : 0 vehicles

Intersection 2
Lane 1 : 0 vehicles
Lane 2 : 10 vehicles
Lane 3 : 5 vehicles
Lane 4 : 8 vehicles

Intersection 3
Lane 1 : 6 vehicles
Lane 2 : 5 vehicles
Lane 3 : 12 vehicles
Lane 4 : 9 vehicles

Intersection 4
Lane 1 : 0 vehicles
Lane 2 : 7 vehicles
Lane 3 : 6 vehicles
Lane 4 : 5 vehicles

=================================
TRAFFIC CYCLE 2
1. Run Traffic Cycle
2. View Traffic Status
3. View Signal History
4. View Vehicle Database
5. Search Vehicle
6. Add Emergency Vehicle
7. View Emergency Vehicles
0. Exit
Enter Choice : 3

========== SIGNAL HISTORY ==========
Intersection 4 | Lane 3 | Vehicles 11
Intersection 3 | Lane 4 | Vehicles 14
Intersection 2 | Lane 4 | Vehicles 13
Intersection 1 | Lane 2 | Vehicles 13

=================================
TRAFFIC CYCLE 2
1. Run Traffic Cycle
2. View Traffic Status
3. View Signal History
4. View Vehicle Database
5. Search Vehicle
6. Add Emergency Vehicle
7. View Emergency Vehicles
0. Exit
Enter Choice : 4

====== VEHICLE DATABASE ======
ID:1000 | Intersection:1 | Lane:1 | Cycle:1
ID:1001 | Intersection:1 | Lane:1 | Cycle:1
ID:1002 | Intersection:1 | Lane:1 | Cycle:1
ID:1003 | Intersection:1 | Lane:1 | Cycle:1
ID:1004 | Intersection:1 | Lane:2 | Cycle:1
ID:1005 | Intersection:1 | Lane:2 | Cycle:1
ID:1006 | Intersection:1 | Lane:2 | Cycle:1
ID:1007 | Intersection:1 | Lane:2 | Cycle:1
ID:1008 | Intersection:1 | Lane:2 | Cycle:1
ID:1009 | Intersection:1 | Lane:2 | Cycle:1
ID:1010 | Intersection:1 | Lane:2 | Cycle:1
ID:1011 | Intersection:1 | Lane:2 | Cycle:1
ID:1012 | Intersection:1 | Lane:2 | Cycle:1
ID:1013 | Intersection:1 | Lane:2 | Cycle:1
ID:1014 | Intersection:1 | Lane:2 | Cycle:1
ID:1015 | Intersection:1 | Lane:2 | Cycle:1
ID:1016 | Intersection:1 | Lane:2 | Cycle:1
ID:1017 | Intersection:1 | Lane:3 | Cycle:1
ID:1018 | Intersection:2 | Lane:2 | Cycle:1
ID:1019 | Intersection:2 | Lane:2 | Cycle:1
ID:1020 | Intersection:2 | Lane:2 | Cycle:1
ID:1021 | Intersection:2 | Lane:2 | Cycle:1
ID:1022 | Intersection:2 | Lane:2 | Cycle:1
ID:1023 | Intersection:2 | Lane:2 | Cycle:1
ID:1024 | Intersection:2 | Lane:2 | Cycle:1
ID:1025 | Intersection:2 | Lane:2 | Cycle:1
ID:1026 | Intersection:2 | Lane:2 | Cycle:1
ID:1027 | Intersection:2 | Lane:2 | Cycle:1
ID:1028 | Intersection:2 | Lane:3 | Cycle:1
ID:1029 | Intersection:2 | Lane:3 | Cycle:1
ID:1030 | Intersection:2 | Lane:3 | Cycle:1
ID:1031 | Intersection:2 | Lane:3 | Cycle:1
ID:1032 | Intersection:2 | Lane:3 | Cycle:1
ID:1033 | Intersection:2 | Lane:4 | Cycle:1
ID:1034 | Intersection:2 | Lane:4 | Cycle:1
ID:1035 | Intersection:2 | Lane:4 | Cycle:1
ID:1036 | Intersection:2 | Lane:4 | Cycle:1
ID:1037 | Intersection:2 | Lane:4 | Cycle:1
ID:1038 | Intersection:2 | Lane:4 | Cycle:1
ID:1039 | Intersection:2 | Lane:4 | Cycle:1
ID:1040 | Intersection:2 | Lane:4 | Cycle:1
ID:1041 | Intersection:2 | Lane:4 | Cycle:1
ID:1042 | Intersection:2 | Lane:4 | Cycle:1
ID:1043 | Intersection:2 | Lane:4 | Cycle:1
ID:1044 | Intersection:2 | Lane:4 | Cycle:1
ID:1045 | Intersection:2 | Lane:4 | Cycle:1
ID:1046 | Intersection:3 | Lane:1 | Cycle:1
ID:1047 | Intersection:3 | Lane:1 | Cycle:1
ID:1048 | Intersection:3 | Lane:1 | Cycle:1
ID:1049 | Intersection:3 | Lane:1 | Cycle:1
ID:1050 | Intersection:3 | Lane:1 | Cycle:1
ID:1051 | Intersection:3 | Lane:1 | Cycle:1
ID:1052 | Intersection:3 | Lane:2 | Cycle:1
ID:1053 | Intersection:3 | Lane:2 | Cycle:1
ID:1054 | Intersection:3 | Lane:2 | Cycle:1
ID:1055 | Intersection:3 | Lane:2 | Cycle:1
ID:1056 | Intersection:3 | Lane:2 | Cycle:1
ID:1057 | Intersection:3 | Lane:3 | Cycle:1
ID:1058 | Intersection:3 | Lane:3 | Cycle:1
ID:1059 | Intersection:3 | Lane:3 | Cycle:1
ID:1060 | Intersection:3 | Lane:3 | Cycle:1
ID:1061 | Intersection:3 | Lane:3 | Cycle:1
ID:1062 | Intersection:3 | Lane:3 | Cycle:1
ID:1063 | Intersection:3 | Lane:3 | Cycle:1
ID:1064 | Intersection:3 | Lane:3 | Cycle:1
ID:1065 | Intersection:3 | Lane:3 | Cycle:1
ID:1066 | Intersection:3 | Lane:3 | Cycle:1
ID:1067 | Intersection:3 | Lane:3 | Cycle:1
ID:1068 | Intersection:3 | Lane:3 | Cycle:1
ID:1069 | Intersection:3 | Lane:4 | Cycle:1
ID:1070 | Intersection:3 | Lane:4 | Cycle:1
ID:1071 | Intersection:3 | Lane:4 | Cycle:1
ID:1072 | Intersection:3 | Lane:4 | Cycle:1
ID:1073 | Intersection:3 | Lane:4 | Cycle:1
ID:1074 | Intersection:3 | Lane:4 | Cycle:1
ID:1075 | Intersection:3 | Lane:4 | Cycle:1
ID:1076 | Intersection:3 | Lane:4 | Cycle:1
ID:1077 | Intersection:3 | Lane:4 | Cycle:1
ID:1078 | Intersection:3 | Lane:4 | Cycle:1
ID:1079 | Intersection:3 | Lane:4 | Cycle:1
ID:1080 | Intersection:3 | Lane:4 | Cycle:1
ID:1081 | Intersection:3 | Lane:4 | Cycle:1
ID:1082 | Intersection:3 | Lane:4 | Cycle:1
ID:1083 | Intersection:4 | Lane:2 | Cycle:1
ID:1084 | Intersection:4 | Lane:2 | Cycle:1
ID:1085 | Intersection:4 | Lane:2 | Cycle:1
ID:1086 | Intersection:4 | Lane:2 | Cycle:1
ID:1087 | Intersection:4 | Lane:2 | Cycle:1
ID:1088 | Intersection:4 | Lane:2 | Cycle:1
ID:1089 | Intersection:4 | Lane:2 | Cycle:1
ID:1090 | Intersection:4 | Lane:3 | Cycle:1
ID:1091 | Intersection:4 | Lane:3 | Cycle:1
ID:1092 | Intersection:4 | Lane:3 | Cycle:1
ID:1093 | Intersection:4 | Lane:3 | Cycle:1
ID:1094 | Intersection:4 | Lane:3 | Cycle:1
ID:1095 | Intersection:4 | Lane:3 | Cycle:1
ID:1096 | Intersection:4 | Lane:3 | Cycle:1
ID:1097 | Intersection:4 | Lane:3 | Cycle:1
ID:1098 | Intersection:4 | Lane:3 | Cycle:1
ID:1099 | Intersection:4 | Lane:3 | Cycle:1
ID:1100 | Intersection:4 | Lane:3 | Cycle:1
ID:1101 | Intersection:4 | Lane:4 | Cycle:1
ID:1102 | Intersection:4 | Lane:4 | Cycle:1
ID:1103 | Intersection:4 | Lane:4 | Cycle:1
ID:1104 | Intersection:4 | Lane:4 | Cycle:1
ID:1105 | Intersection:4 | Lane:4 | Cycle:1

=================================
TRAFFIC CYCLE 2
1. Run Traffic Cycle
2. View Traffic Status
3. View Signal History
4. View Vehicle Database
5. Search Vehicle
6. Add Emergency Vehicle
7. View Emergency Vehicles
0. Exit
Enter Choice : 5
Enter Vehicle ID : 1086

Vehicle Found
Intersection : 4
Lane : 2
Arrival Cycle : 1

=================================
TRAFFIC CYCLE 2
1. Run Traffic Cycle
2. View Traffic Status
3. View Signal History
4. View Vehicle Database
5. Search Vehicle
6. Add Emergency Vehicle
7. View Emergency Vehicles
0. Exit
Enter Choice : 6
Vehicle ID : 9878
Intersection : 4
Lane : 2
Type (Ambulance/Fire/Police): 0
Emergency Vehicle Added.

=================================
TRAFFIC CYCLE 2
1. Run Traffic Cycle
2. View Traffic Status
3. View Signal History
4. View Vehicle Database
5. Search Vehicle
6. Add Emergency Vehicle
7. View Emergency Vehicles
0. Exit
Enter Choice : 7

======= EMERGENCY VEHICLES =======
ID:9878 | 0 | Intersection:4 | Lane:2

=================================
TRAFFIC CYCLE 2
1. Run Traffic Cycle
2. View Traffic Status
3. View Signal History
4. View Vehicle Database
5. Search Vehicle
6. Add Emergency Vehicle
7. View Emergency Vehicles
0. Exit
Enter Choice : 1

Generating Traffic Using Sensors...

Intersection 1
Green Signal -> Lane 2
Vehicles Waiting : 22
Signal Timer : 11 sec
10 vehicles passed.

Intersection 2
Green Signal -> Lane 4
Vehicles Waiting : 19
Signal Timer : 9 sec
10 vehicles passed.

Intersection 3
Green Signal -> Lane 3
Vehicles Waiting : 25
Signal Timer : 12 sec
10 vehicles passed.

*** EMERGENCY VEHICLE DETECTED ***
Type : 0
Intersection : 4
Green Signal -> Lane 2
5 vehicles passed.

=================================
TRAFFIC CYCLE 3
1. Run Traffic Cycle
2. View Traffic Status
3. View Signal History
4. View Vehicle Database
5. Search Vehicle
6. Add Emergency Vehicle
7. View Emergency Vehicles
0. Exit
Enter Choice : 0

System Shutdown



## 🎯 Learning Outcomes

- Implemented six fundamental Data Structures in a single real-world application.
- Applied priority-based scheduling for intelligent traffic control.
- Simulated emergency vehicle prioritization.
- Improved understanding of modular programming and algorithm design.

---

## 🔮 Future Enhancements

- Graphical User Interface (GUI)
- Real-time IoT sensor integration
- Traffic prediction using Machine Learning
- Shortest path routing using Dijkstra's Algorithm
- Database integration

---

## 👥 Team

Developed as a four-member academic project for the Data Structures course.

---
