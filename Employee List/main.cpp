#include <iostream>
#include <string>
#include <Employees.h>

using namespace std;

int main()
{
    int nEmp,
        option = 0;

    string idNum,
           name;

    Employees ContraCorp;

    while(option != 7){

        cout<<">Press number associated with desired option<"<<endl;
        cout<<"[1] New Employee"<<endl;
        cout<<"[2] Employee ID Search"<<endl;
        cout<<"[3] Employee First Name Search"<<endl;
        cout<<"[4] Employee Last Name Search"<<endl;
        cout<<"[5] Display all Employees with ID Number"<<endl;
        cout<<"[6] Display all Employees and All Employee Data"<<endl;
        cout<<"[7] Close Database"<<endl;
        cin>>option;

        if(option == 1){
            ContraCorp.newEmployee();
            nEmp--;
        }

        if(option == 2){
                cout<<"Search for employee using ID number or enter '@@' to quit: ";
                cin>>idNum;
                cout<<endl;
            while(idNum != "@@"){
                ContraCorp.idSearch(idNum);
                cout<<"Search for employee using ID number or enter '@@' to quit: ";
                cin>>idNum;
                cout<<endl;
            }
        }

        if(option == 3){
                cout<<"Search for employee using first name or enter '@@' to quit: ";
                cin>>name;
                cout<<endl;
            while(name != "@@"){
                ContraCorp.fNameSearch(name);
                cout<<"Search for employee using first name or enter '@@' to quit:";
                cin>>name;
                cout<<endl;
            }
        }

        if(option == 4){
                cout<<"Search for employee using last name or enter '@@' to quit: ";
                cin>>name;
                cout<<endl;
            while(name != "@@"){
                ContraCorp.lNameSearch(name);
                cout<<"Search for employee using last name or enter '@@' to quit:";
                cin>>name;
                cout<<endl;
            }
        }

        if(option == 5){
                ContraCorp.display();
        }

        if(option == 6){
                ContraCorp.dDisplay();
        }
    }

    return 0;
}
