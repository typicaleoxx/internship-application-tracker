/*
main.cpp - internship application tracker
interactive menu-driven CLI program for tracking internship applications
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "application.h"
#include "doublyLinkedList.h"

void displayMenu() {
    std::cout << "\nInternship Application Tracker\n" << std::endl;
    std::cout << "1. Add application" << std::endl;
    std::cout << "2. View all applications" << std::endl;
    std::cout << "3. Search by company name" << std::endl;
    std::cout << "4. Update application status" << std::endl;
    std::cout << "5. Delete an application" << std::endl;
    std::cout << "6. Print in reverse order" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "\nEnter your choice: ";
}

void addApplication(DoublyLinkedList<Application>& apps) {
    std::string company, role, location, status, date, notes;
    
    std::cout << "\n--- Add Application ---" << std::endl;
    std::cout << "Company name: ";
    std::getline(std::cin, company);
    
    std::cout << "Job role: ";
    std::getline(std::cin, role);
    
    std::cout << "Location: ";
    std::getline(std::cin, location);
    
    std::cout << "Status (Applied/Interview Scheduled/Offer/Rejected): ";
    std::getline(std::cin, status);
    
    std::cout << "Date applied (YYYY-MM-DD): ";
    std::getline(std::cin, date);
    
    std::cout << "Notes: ";
    std::getline(std::cin, notes);
    
    Application newApp(company, role, location, status, date, notes);
    apps.insertAtTail(newApp);
    std::cout << "\nApplication added successfully." << std::endl;
}

void viewAllApplications(DoublyLinkedList<Application>& apps) {
    std::cout << "\n--- All Applications ---" << std::endl;
    if (apps.size() == 0) {
        std::cout << "No applications found." << std::endl;
        return;
    }
    std::cout << "Total: " << apps.size() << std::endl << std::endl;
    apps.printList();
}

void searchByCompany(DoublyLinkedList<Application>& apps) {
    std::string companyName;
    
    std::cout << "\n--- Search Application ---" << std::endl;
    std::cout << "Enter company name: ";
    std::getline(std::cin, companyName);
    
    bool found = false;
    
    // traverse the list manually and search by company name
    for (int i = 0; i < apps.size(); i++) {
        Application* app = apps.getAt(i);
        if (app != nullptr && app->getCompany() == companyName) {
            std::cout << "\nFound application:" << std::endl;
            app->display();
            found = true;
            break;
        }
    }
    
    if (!found) {
        std::cout << "Application not found." << std::endl;
    }
}

void updateApplicationStatus(DoublyLinkedList<Application>& apps) {
    std::string companyName, newStatus, newNotes;
    
    std::cout << "\n--- Update Application ---" << std::endl;
    std::cout << "Enter company name to update: ";
    std::getline(std::cin, companyName);
    
    bool found = false;
    
    // traverse the list and find the application by company name
    for (int i = 0; i < apps.size(); i++) {
        Application* app = apps.getAt(i);
        if (app != nullptr && app->getCompany() == companyName) {
            std::cout << "New status: ";
            std::getline(std::cin, newStatus);
            
            std::cout << "New notes: ";
            std::getline(std::cin, newNotes);
            
            app->updateStatus(newStatus);
            app->updateNotes(newNotes);
            
            std::cout << "\nApplication updated successfully." << std::endl;
            found = true;
            break;
        }
    }
    
    if (!found) {
        std::cout << "Application not found." << std::endl;
    }
}

void deleteApplication(DoublyLinkedList<Application>& apps) {
    std::string companyName;
    
    std::cout << "\n--- Delete Application ---" << std::endl;
    std::cout << "Enter company name to delete: ";
    std::getline(std::cin, companyName);
    
    bool found = false;
    
    // traverse the list and find the application by company name
    for (int i = 0; i < apps.size(); i++) {
        Application* app = apps.getAt(i);
        if (app != nullptr && app->getCompany() == companyName) {
            // delete by creating a temporary with the same data and using deleteByValue
            Application toDelete = *app;
            if (apps.deleteByValue(toDelete)) {
                std::cout << "\nApplication deleted successfully." << std::endl;
                found = true;
            }
            break;
        }
    }
    
    if (!found) {
        std::cout << "Application not found." << std::endl;
    }
}

void printReverse(DoublyLinkedList<Application>& apps) {
    std::cout << "\n--- Applications (Reverse Order) ---" << std::endl;
    if (apps.size() == 0) {
        std::cout << "No applications found." << std::endl;
        return;
    }
    apps.printReverse();
}

int main() {
    DoublyLinkedList<Application> myApplications;
    int choice;
    std::string input;
    
    while (true) {
        displayMenu();
        std::getline(std::cin, input);
        choice = atoi(input.c_str());
        
        switch (choice) {
            case 1:
                addApplication(myApplications);
                break;
            case 2:
                viewAllApplications(myApplications);
                break;
            case 3:
                searchByCompany(myApplications);
                break;
            case 4:
                updateApplicationStatus(myApplications);
                break;
            case 5:
                deleteApplication(myApplications);
                break;
            case 6:
                printReverse(myApplications);
                break;
            case 7:
                std::cout << "\nGoodbye." << std::endl;
                return 0;
            default:
                std::cout << "\nInvalid choice. Try again." << std::endl;
        }
    }

    return 0;
}