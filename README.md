# Internship Application Tracker

## About This Project

This is a C++ console program that helps students track their internship applications.

We built this project using a templated doubly linked list. The program stores applications dynamically in memory and allows the user to manage them using a simple menu system.

This project focuses on data structures, memory management, and clean code organization.

---

## Why We Built This

Students apply to many internships. It becomes difficult to track:

- Where we applied  
- Which role we applied for  
- The application status  
- Notes or updates  

This program solves that problem by keeping everything in one place.

At the same time, it demonstrates:

- Doubly linked list implementation  
- Templates in C++  
- Dynamic memory management  
- Object-oriented design  

---

## Features

The program allows the user to:

1. Add a new internship application  
2. Remove an application  
3. Search for an application by company name  
4. Update the application status  
5. Display all applications  
6. Display the total number of applications  

---

## Data Stored (Application Class)

Each internship application stores:

- Company Name  
- Role  
- Location  
- Status (Applied, Interview, Rejected, Offer)  
- Date Applied  
- Notes  

This data is stored inside the `Application` class.

---

## How the Program Works

The program uses a templated doubly linked list.

Each application becomes a node in the list.

Each node contains:
- The application data  
- A pointer to the next node  
- A pointer to the previous node  

When the user adds an application, the program creates a new node using dynamic memory (`new`).

When the user removes an application, the program deletes the node using `delete`.

The list grows and shrinks dynamically during runtime.

---

## Project Structure

### main.cpp

- Contains the `main()` function  
- Displays the menu  
- Takes user input  
- Calls functions from the linked list  

This file controls the overall program flow.

---

### Application.h

- Defines the `Application` class  
- Stores internship data  
- Contains constructors  
- Contains getter functions  
- Contains a display function  

This file represents the data model.

---

### DoublyLinkedList.h

- Implements a templated doubly linked list  
- Defines the internal Node structure  
- Handles insertion and deletion  
- Handles search and traversal  
- Manages memory in the destructor  

This file handles all linked list logic.

---

## Example Scenario

Day 1:  
I apply to Google for a Software Engineering internship.  
I add it to the tracker.

Day 3:  
I apply to Amazon.  
I add it to the tracker.

Day 10:  
Amazon invites me for an interview.  
I update the status to "Interview".

Day 20:  
Google rejects me.  
I remove Google from the list.

The tracker keeps everything organized and updated.

---

## How to Compile (Linux / Mac)

Make sure all files are in the same folder.

Compile using:

g++ main.cpp -o tracker

Run using:

./tracker

---

## What We Learned

- How to implement a doubly linked list from scratch  
- How templates make a data structure reusable  
- How to manage memory safely using pointers  
- How to organize a C++ project into multiple files  
- How to design a small but complete system  

---

## Future Improvements

- Add file storage (save data to a file)  
- Add sorting by company or status  
- Add filtering by status  
- Add a simple graphical interface  

---

This project demonstrates practical understanding of data structures and clean system design in C++.
