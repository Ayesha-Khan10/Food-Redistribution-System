# Food Redistribution System

A C++ console-based application designed to bridge the gap between food surplus and food insecurity by connecting donors directly with recipients such as NGOs, hospitals, and welfare trusts. The system uses advanced Data Structures and algorithms to ensure fair, efficient, and timely distribution of surplus food.

---

## Project Overview

In Pakistan, while food surplus exists in many sectors, a significant portion of the population faces food insecurity. The **Food Redistribution System** addresses this problem by:

- Managing donors, donations, and recipient requests
- Prioritizing urgent needs (e.g., hospitals) using **Priority Queues**
- Calculating shortest delivery paths using **Dijkstra's Algorithm**
- Persistently storing all data in **CSV files** to prevent data loss

The system simulates a realistic delivery network across Karachi, including 15 locations, ensuring optimized routing and fair allocation of resources.

---

## Features

### Donor Management
- Add, remove, and search donors
- Record food donations with expiry dates
- Automatic removal of expired donations

### Request Management
- Submit and edit requests
- Priority-based allocation:
  - Level 1: Hospitals (highest priority)
  - Level 2: Old Age Homes
  - Level 3: Charities
- Rebooking for pending requests

### Routing & Reporting
- Graph-based map of Karachi locations
- Shortest path calculation between donor and recipient using **Dijkstra's Algorithm**
- Statistics module: Tracks delivered food and donor contributions

### Data Management
- Persistent storage with **CSV/Excel-compatible files**
- Linked Lists for dynamic donor and donation storage
- Priority Queues (Heap) for urgent requests
- FIFO Queues for normal requests
- Stacks for request history

---

## Technologies Used
- **C++**: Core programming language
- **Data Structures & Algorithms**:
  - Linked Lists, Stacks, Queues, Priority Queues (Heap), Graphs
  - Dijkstra’s Algorithm for route optimization
- **File Handling**: CSV-based data persistence
- **Development Environment**: Visual Studio 2022
- **Libraries Used**: `<iostream>`, `<vector>`, `<fstream>`, `<string>`, `<unordered_map>`

---

## Limitations
- Console-based (no GUI)
- Manual data entry
- Single-user system
- No real-time GPS integration
- No online payment or web interface

---

## Future Enhancements
- GUI or web-based version
- Multi-user access with login system
- Real-time GPS integration (Google Maps API)
- Mobile app version
- Cloud-based database support
- Automated notifications for donors and recipients

---

## How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/Food-Redistribution-System.git
2. Open the project in Visual Studio 2022
3. Compile and run the project
4. Use the menu-driven interface to:
5. Add donors
6. Record donations
7. Submit requests
8. Track deliveries and statistics
