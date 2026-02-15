#include "application.h"
#include <iostream>
using namespace std;

//Constructor
Application::Application(){
    company = "Unkown Company";
    role = "Unkown Role";
    location = "TBD";
    status = "Not Applied";
    date_applied = "N/A";
    notes = "No notes";
};

//Display Function
void Application::display() const{
    cout << company;
    cout << role;
    cout << location;
    cout << status;
    cout << date_applied;
    cout << notes;
};

//Update Functions
void Application::updateCompany(const string& newCompany){
    company = newCompany;
};

void Application::updateRole(const string& newRole){
    role = newRole;
};

void Application::updateLocation(const string& newLocation){
    location = newLocation;
};

void Application::updateStatus(const string& newStatus){
    status = newStatus;
};

void Application::updateDate(const string& newDate){
    date_applied = newDate;
};

void Application::updateNotes(const string& newNotes){
    notes = newNotes;
};