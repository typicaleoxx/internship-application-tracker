# Internship Application Tracker

## About This Project

This is a C++ console program that helps students track their internship applications.

The program is built using a **templated doubly linked list**. Applications are stored dynamically in memory and managed through a simple menu-driven interface.

This project demonstrates:

- Implementation of a templated data structure
- Dynamic memory management using `new` and `delete`
- Object oriented programming
- Operator overloading
- Clean and modular code organization

---

## Why We Built This

Students apply to many internships, and it becomes difficult to track:

- Where we applied  
- Which role we applied for  
- The application status  
- Notes or updates  

This program solves that problem by keeping everything organized in one place while demonstrating core data structure concepts.

---

## Features

The program allows the user to:

1. Add a new internship application  
2. View all applications  
3. Search for an application by company name  
4. Update an application's status and notes  
5. Delete an application by company name  
6. Print all applications in reverse order  
7. Exit the program  

When viewing applications, the program also displays the total number of applications stored.

---

## Data Stored (Application Class)

Each internship application stores:

- Company Name  
- Role  
- Location  
- Status  
- Date Applied  
- Notes  

This data is stored inside the `Application` class.

The class includes:

- Default constructor  
- Parameterized constructor  
- Getter functions  
- Update functions  
- `display()` function  
- Overloaded `==` and `!=` operators  
- Overloaded `<<` operator for formatted printing  

---

## How the Program Works

The program uses a **templated DoublyLinkedList** class.

Each application becomes a node in the list.

Each node contains:

- The application data  
- A pointer to the next node  
- A pointer to the previous node  

When the user adds an application, the program inserts a new node at the tail of the list.

When the user deletes an application, the program removes the corresponding node and frees the memory.

The list grows and shrinks dynamically during runtime.

The list maintains:

- `head` pointer  
- `tail` pointer  
- A `count` variable to track the number of elements  

---

## Project Structure

### main.cpp

- Contains the `main()` function  
- Displays the interactive menu  
- Handles user input  
- Calls linked list operations  

This file controls the overall program flow.

---

### application.h / application.cpp

- Defines and implements the `Application` class  
- Stores internship data  
- Contains constructors, getters, and update functions  
- Implements operator overloading  
- Provides a display function  

This class represents the data model.

---

### doublyLinkedList.h

- Implements a templated doubly linked list  
- Defines an internal `Node` class  
- Handles insertion (head, tail, position)  
- Handles deletion (head, tail, position, by value)  
- Supports forward and reverse traversal  
- Supports search  
- Tracks size  
- Manages memory in the destructor  

This file handles all linked list logic.

---

## Example Scenario

Day 1:  
I apply to a Software Engineering internship at a company.  
I add it to the tracker.

Day 3:  
I apply to another internship.  
I add it to the tracker.

Day 10:  
One company schedules an interview.  
I update the status and add notes.

Day 20:  
I decide to remove an old application.  
I delete it from the tracker.

The tracker keeps everything organized and updated.

---

## How to Compile (Linux / Mac / Student Cluster)

Make sure all files are in the same folder:

- main.cpp  
- application.cpp  
- application.h  
- doublyLinkedList.h  

Compile using:

g++ -std=c++11 -o tracker main.cpp application.cpp

Run using:

./tracker


---

## What We Learned

- How to implement a doubly linked list from scratch  
- How templates make a data structure reusable  
- How to manage dynamic memory safely  
- How to use operator overloading  
- How to organize a multi file C++ project  

---

## Future Improvements

- Add file storage to save applications between runs  
- Add sorting functionality  
- Add filtering by status  
- Improve search functionality  
- Add a graphical user interface  

---

This project demonstrates practical understanding of data structures, templates, memory management, and object oriented programming in C++.
