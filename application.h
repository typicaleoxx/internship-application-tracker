#include <iostream>
#include <string>
using namespace std;

class Application{
    public:
        Application();
        
    private:
        string company;
        string role;
        string location;
        string status;
        string date_applied;
        string notes;
};

Application::Application(){
    company = "Unkown Company";
    role = "Unkown Role";
    location = "TBD";
    status = "Not Applied";
    date_applied = "N/A";
    notes = "No notes";
};