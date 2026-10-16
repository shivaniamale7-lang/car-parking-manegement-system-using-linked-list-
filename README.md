Car Parking Management System Using Linked List
1. Introduction
This project is a console-based Car Parking Management System implemented in C++. It utilizes the concepts of the Linked List data structure to manage vehicle records dynamically, allowing efficient allocation and tracking of parking spaces.
2. Problem Statement
Traditional manual parking record management is unorganized, prone to data entry errors, and time-consuming. Sequential storage methods like standard arrays have fixed sizes, which can lead to memory wastage or limits on capacity. This system solves these issues by handling vehicle data dynamically based on real-time requirements.
3. Objectives
To manage car parking allocations and records effectively.
To apply dynamic memory allocation techniques using Linked Lists.
To perform seamless insertion, searching, and deletion of vehicle data.
To check the real-time availability of spaces inside the system.
4. Data Structure Used
Singly Linked List: Every vehicle's record acts as a 'Node' containing data variables (Vehicle Number, Owner Name) and a pointer (next) that links to the subsequent vehicle record.
5. Technologies Used
Language: C++
Concept: Non-contiguous memory structures (Linked List), Pointers
IDE/Compiler: Any standard C++ Compiler (GCC, VS Code)
6. Key Operations Implemented
Add Vehicle: Creates a new node for the arriving vehicle, prompts for details, and appends it to the end of the list.
Display Vehicles: Traverses the entire linked list from the head node to show a list of all currently parked cars.
Search Vehicle: Looks up a specific vehicle using its unique registration number by traversing the active nodes.
Remove Vehicle: Deletes the specific vehicle's node from the memory once it leaves the parking lot, adjusting the links accordingly.
