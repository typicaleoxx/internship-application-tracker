#include "application.h"
#include <iostream>

// default constructor initializes all fields with default placeholder values
Application::Application() {
    company = "Unknown Company";
    role = "Unknown Role";
    location = "TBD";
    status = "Not Applied";
    date_applied = "N/A";
    notes = "No notes";
}

// parameterized constructor initializes all fields with the provided values
Application::Application(const std::string& company, const std::string& role,
                         const std::string& location, const std::string& status,
                         const std::string& date_applied, const std::string& notes) {
    this->company = company;
    this->role = role;
    this->location = location;
    this->status = status;
    this->date_applied = date_applied;
    this->notes = notes;
}

// display all application information in a formatted way
void Application::display() const {
    std::cout << "Company: " << company << std::endl;
    std::cout << "Role: " << role << std::endl;
    std::cout << "Location: " << location << std::endl;
    std::cout << "Status: " << status << std::endl;
    std::cout << "Date Applied: " << date_applied << std::endl;
    std::cout << "Notes: " << notes << std::endl;
}

// update the company name
void Application::updateCompany(const std::string& newCompany) {
    company = newCompany;
}

// update the job role
void Application::updateRole(const std::string& newRole) {
    role = newRole;
}

// update the location
void Application::updateLocation(const std::string& newLocation) {
    location = newLocation;
}

// update the application status
void Application::updateStatus(const std::string& newStatus) {
    status = newStatus;
}

// update the date applied
void Application::updateDate(const std::string& newDate) {
    date_applied = newDate;
}

// update the notes
void Application::updateNotes(const std::string& newNotes) {
    notes = newNotes;
}

// getter for company name
std::string Application::getCompany() const {
    return company;
}

// getter for job role
std::string Application::getRole() const {
    return role;
}

// getter for location
std::string Application::getLocation() const {
    return location;
}

// getter for status
std::string Application::getStatus() const {
    return status;
}

// getter for date applied
std::string Application::getDate() const {
    return date_applied;
}

// getter for notes
std::string Application::getNotes() const {
    return notes;
}

// compare two applications for equality by checking all fields
bool Application::operator==(const Application& other) const {
    return company == other.company &&
           role == other.role &&
           location == other.location &&
           status == other.status &&
           date_applied == other.date_applied &&
           notes == other.notes;
}

// compare two applications for inequality
bool Application::operator!=(const Application& other) const {
    return !(*this == other);
}

// output stream operator for easy printing of application objects
std::ostream& operator<<(std::ostream& os, const Application& app) {
    os << "Company: " << app.company << "\n"
       << "Role: " << app.role << "\n"
       << "Location: " << app.location << "\n"
       << "Status: " << app.status << "\n"
       << "Date Applied: " << app.date_applied << "\n"
       << "Notes: " << app.notes;
    return os;
}