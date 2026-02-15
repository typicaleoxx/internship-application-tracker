#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
using namespace std;

class Application{
    public:
        Application();
        void display() const;

        void updateCompany(const string& newCompany);
        void updateRole(const string& newRole);
        void updateLocation(const string& newLocation);
        void updateStatus(const string& newStatus);
        void updateDate(const string& newDate);
        void updateNotes(const string& newNotes);

        string getCompany() const{return company;}
        string getRole() const{return role;}
        string getLocation() const{return location;}
        string getStatus() const{return status;}
        string getDate() const{return date_applied;}
        string getNotes() const{return notes;}

    private:
        string company;
        string role;
        string location;
        string status;
        string date_applied;
        string notes;
};

#endif