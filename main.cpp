/*
main.cpp - internship application tracker
this program demonstrates using a doubly linked list to track internship applications
we'll add, remove, search, and update applications to show how the data structure works
*/

#include <iostream>
#include <cstdlib>
#include "application.h"
#include "doublyLinkedList.h"

int main() {
    std::cout << "======================================" << std::endl;
    std::cout << "  INTERNSHIP APPLICATION TRACKER" << std::endl;
    std::cout << "======================================" << std::endl << std::endl;

    // create our doubly linked list to store all applications
    DoublyLinkedList<Application> myApplications;

    std::cout << "Starting with an empty list..." << std::endl;
    std::cout << "Current size: " << myApplications.size() << std::endl << std::endl;

    // ========== INSERTING APPLICATIONS ==========
    std::cout << "--- ADDING APPLICATIONS ---" << std::endl << std::endl;

    // let's create some sample applications for different companies
    std::cout << "1. Adding Google application at the HEAD" << std::endl;
    Application google("Google", "Software Engineering Intern", "Mountain View, CA", 
                      "Applied", "2026-01-15", "Referred by a friend");
    myApplications.insertAtHead(google);
    std::cout << "   Size now: " << myApplications.size() << std::endl << std::endl;

    // add another one at the tail
    std::cout << "2. Adding Amazon application at the TAIL" << std::endl;
    Application amazon("Amazon", "SDE Intern", "Seattle, WA", 
                      "Applied", "2026-01-20", "Applied through career portal");
    myApplications.insertAtTail(amazon);
    std::cout << "   Size now: " << myApplications.size() << std::endl << std::endl;

    // add one more at the tail
    std::cout << "3. Adding Microsoft application at the TAIL" << std::endl;
    Application microsoft("Microsoft", "Software Engineer Intern", "Redmond, WA", 
                         "Interview Scheduled", "2026-01-18", "First round on Feb 1");
    myApplications.insertAtTail(microsoft);
    std::cout << "   Size now: " << myApplications.size() << std::endl << std::endl;

    // insert one at a specific position
    std::cout << "4. Adding Meta application at POSITION 2" << std::endl;
    Application meta("Meta", "Software Engineering Intern", "Menlo Park, CA", 
                    "Applied", "2026-01-22", "Interested in React team");
    myApplications.insertAtPos(meta, 2);
    std::cout << "   Size now: " << myApplications.size() << std::endl << std::endl;

    // add a couple more
    std::cout << "5. Adding Apple application at the HEAD" << std::endl;
    Application apple("Apple", "Software Engineering Intern", "Cupertino, CA", 
                     "Applied", "2026-01-25", "Dream company!");
    myApplications.insertAtHead(apple);
    std::cout << "   Size now: " << myApplications.size() << std::endl << std::endl;

    std::cout << "6. Adding Netflix application at the TAIL" << std::endl;
    Application netflix("Netflix", "Backend Engineering Intern", "Los Gatos, CA", 
                       "Not Applied", "TBD", "Need to update resume first");
    myApplications.insertAtTail(netflix);
    std::cout << "   Size now: " << myApplications.size() << std::endl << std::endl;

    // ========== PRINTING THE LIST ==========
    std::cout << "--- CURRENT LIST (forward) ---" << std::endl;
    std::cout << "Total applications: " << myApplications.size() << std::endl << std::endl;
    myApplications.printList();
    std::cout << std::endl;

    std::cout << "--- CURRENT LIST (reverse) ---" << std::endl;
    myApplications.printReverse();
    std::cout << std::endl;

    // ========== SEARCHING ==========
    std::cout << "--- SEARCHING FOR APPLICATIONS ---" << std::endl << std::endl;

    std::cout << "Looking for Microsoft application..." << std::endl;
    if (myApplications.search(microsoft) != nullptr) {
        std::cout << "Found it! Here are the details:" << std::endl;
        microsoft.display();
    } else {
        std::cout << "Not found!" << std::endl;
    }
    std::cout << std::endl;

    // try searching for something that doesn't exist
    Application fake("SpaceX", "Rocket Intern", "Mars", "Applied", "2025-12-01", "Out of this world!");
    std::cout << "Looking for SpaceX application..." << std::endl;
    if (myApplications.search(fake) != nullptr) {
        std::cout << "Found it!" << std::endl;
    } else {
        std::cout << "Not found! (We haven't applied there yet)" << std::endl;
    }
    std::cout << std::endl;

    // ========== UPDATING AN APPLICATION ==========
    std::cout << "--- UPDATING APPLICATION STATUS ---" << std::endl << std::endl;

    std::cout << "Great news! Google moved us to the interview stage!" << std::endl;
    google.updateStatus("Interview Scheduled");
    google.updateNotes("Phone screen scheduled for Feb 10");
    std::cout << "Updated Google application:" << std::endl;
    google.display();
    std::cout << std::endl;

    std::cout << "Unfortunately, Amazon rejected us..." << std::endl;
    amazon.updateStatus("Rejected");
    amazon.updateNotes("Didn't make it past resume screen");
    std::cout << "Updated Amazon application:" << std::endl;
    amazon.display();
    std::cout << std::endl;

    // ========== DELETING APPLICATIONS ==========
    std::cout << "--- REMOVING APPLICATIONS ---" << std::endl << std::endl;

    std::cout << "Removing the application at the HEAD" << std::endl;
    myApplications.deleteAtHead();
    std::cout << "Size after deleting head: " << myApplications.size() << std::endl << std::endl;

    std::cout << "Removing the application at the END" << std::endl;
    myApplications.deleteAtEnd();
    std::cout << "Size after deleting tail: " << myApplications.size() << std::endl << std::endl;

    std::cout << "Removing the application at POSITION 2" << std::endl;
    myApplications.deleteAtPos(2);
    std::cout << "Size after deleting position 2: " << myApplications.size() << std::endl << std::endl;

    std::cout << "Let's see what's left..." << std::endl;
    myApplications.printList();
    std::cout << std::endl;

    // delete by value
    std::cout << "Removing Amazon application by value (since we got rejected)" << std::endl;
    if (myApplications.deleteByValue(amazon)) {
        std::cout << "Successfully removed Amazon!" << std::endl;
    } else {
        std::cout << "Couldn't find Amazon to remove" << std::endl;
    }
    std::cout << "Size after deleting Amazon: " << myApplications.size() << std::endl << std::endl;

    // ========== FINAL STATE ==========
    std::cout << "--- FINAL LIST ---" << std::endl;
    std::cout << "Applications remaining: " << myApplications.size() << std::endl << std::endl;
    myApplications.printList();
    std::cout << std::endl;

    // check if list is empty
    if (myApplications.isEmpty()) {
        std::cout << "The list is empty! Time to apply to more companies!" << std::endl;
    } else {
        std::cout << "Still tracking " << myApplications.size() << " application(s)!" << std::endl;
    }

    std::cout << std::endl << "======================================" << std::endl;
    std::cout << "  THANKS FOR USING THE TRACKER!" << std::endl;
    std::cout << "======================================" << std::endl;

    return EXIT_SUCCESS;
}