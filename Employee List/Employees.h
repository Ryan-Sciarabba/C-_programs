#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include <string>

using namespace std;

class Employee{

    public:

        string fName,
               lName,
               position;

        char sAddress[100];

        int id,
            age;

        Employee *next;

};

class Employees{

    public:
        Employees();

        void newEmployee();
        void idSearch(string empID);
        void fNameSearch(string empFName);
        void lNameSearch(string empLName);
        void display();
        void dDisplay();

    private:

        Employee *head, *it;
        int lastID;

        bool found;
};

#endif // EMPOLYEE_H
