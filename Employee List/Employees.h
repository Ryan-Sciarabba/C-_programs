#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include <string>
#include <fstream>

using namespace std;

class Employee{

    public:

        char fName[100],
             lName[100],
             sAddress[100],
             position[100];

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

        int lastID,
            i;

        char cLastID;

        bool found,
             done;

        ofstream eDatIn;
        ifstream eDatOut;
};

#endif // EMPOLYEE_H
