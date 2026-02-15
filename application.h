#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <iostream>

// application class represents a single internship application with all its details
// stores company info, role, location, status, date applied, and additional notes
class Application {
public:
    // default constructor initializes all fields to empty strings
    Application();

    // parameterized constructor initializes all fields with provided values
    Application(const std::string& company, const std::string& role, 
                const std::string& location, const std::string& status,
                const std::string& date_applied, const std::string& notes);

    // displays all application information to the console
    void display() const;

    // updates the company name for this application
    void updateCompany(const std::string& newCompany);

    // updates the job role/position for this application
    void updateRole(const std::string& newRole);

    // updates the location where the job is based
    void updateLocation(const std::string& newLocation);

    // updates the current status of the application (applied, interview, offer, rejected)
    void updateStatus(const std::string& newStatus);

    // updates the date when the application was submitted
    void updateDate(const std::string& newDate);

    // updates any additional notes or comments about this application
    void updateNotes(const std::string& newNotes);

    // returns the company name
    std::string getCompany() const;

    // returns the job role/position
    std::string getRole() const;

    // returns the job location
    std::string getLocation() const;

    // returns the application status
    std::string getStatus() const;

    // returns the date the application was submitted
    std::string getDate() const;

    // returns any additional notes
    std::string getNotes() const;

    // compares two applications for equality based on all fields
    bool operator==(const Application& other) const;

    // compares two applications for inequality
    bool operator!=(const Application& other) const;

    // allows printing an application object directly to an output stream
    friend std::ostream& operator<<(std::ostream& os, const Application& app);

private:
    std::string company;  // name of the company where applying
    std::string role;  // job title or position being applied for
    std::string location;  // city or region where the job is located
    std::string status;  // current state of application (applied, interview, offer, rejected)
    std::string date_applied;  // date when the application was submitted
    std::string notes;  // additional comments or information about the application
};

#endif