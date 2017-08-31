/*****************************************************************
//
// NAME: Cristian Aspacio
//
// HOMEWORK: Project 2 
//
// CLASS: ICS 212
//
// INSTRUCTOR: Ravi Narayan
//
// DATE: November 24, 2016
//
// FILE: userinterface.cpp
//
// DESCRIPTION: This file contains the main functions and user interface functions for Project2
//
//****************************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include <cstddef>
using namespace std;
#include "record2.h"
#include "llist.h"
void getaddress(string &a);
/*****************************************************************
//
// Function name: main 
//
// DESCRIPTION: User interface functions and menu choice for users and calls Read and write file at the beginning and end of program.
// 
//
// Parameters: int argc , char *argv[]
// 
// Return values: 0 : Successful execution
//
//****************************************************************/
int main(int argc, char *argv[])
{
    llist list;
    char check[100]; 
    int choice = 0;
    int tempacc;
    string tempname;
    string tempadd;
    int tempbirth;
    int tempcheck = 1;
    int checkfunction;
    while(choice != 6)
    {
        cout << "Enter 1 to add a record.\n"; 
        cout << "Enter 2 to print a record.\n";
        cout << "Enter 3 to modify and existing record.\n";
        cout << "Enter 4 to print ALL records.\n";
        cout << "Enter 5 to delete a record.\n";
        cout << "Enter 6 to reverse the list.\n";
        cout << "Enter 7 to exit.\n";
        cout << "Type choice here:";
        if(!(cin >> choice))
        {
             cout << "Please enter a valid choice.\n";
             cin.clear();
             cin.ignore(1000,'\n');
        }
        else if(choice == 1)
        {
            cout << "Please enter an account number:";
            while(tempcheck != 0)
            {
                if(!(cin >> tempacc))
                {
                    cout << "Please enter a valid account number:";
                    cin.clear();
                    cin.ignore(1000,'\n');
                }
                else
                {
                    tempcheck = 0;
                    cin.clear();
                    cin.ignore(1000,'\n');
                }
            }
            tempcheck = 1;
            cout << "Please enter a name:";
            getline(cin,tempname);
            cout << "Please enter an address and end it with a .";
            getaddress(tempadd);
            cout << "Please enter the year of your birth:";
            while(tempcheck != 0)
            {
                if(!(cin >> tempbirth))
                {
                    cout << "Please enter a valid year:";
                    cin.clear();
                    cin.ignore(1000,'\n');
                }
                else
                {
                    tempcheck = 0;
                    cin.clear();
                    cin.ignore(1000,'\n');
                }
            }
            tempcheck = 1;
            checkfunction = list.addRecord(tempacc,tempname,tempadd,tempbirth);
            if(checkfunction == 0)
            {
                cout << "Record added.\n";
            }
            tempadd.clear();
            tempname.clear();
            choice = 0;
        }
        else if(choice == 2)
        {
            cout << "Please enter an account number:";
            while(tempcheck != 0)
            {
                if(!(cin >> tempacc))
                {
                    cout << "Please enter a valid account number:";
                    cin.clear();
                    cin.ignore(1000,'\n');
                }
                else
                {
                    tempcheck = 0;
                    cin.clear();
                    cin.ignore(1000,'\n');
                }
            }
            tempcheck = 1;
            checkfunction = list.printRecord(tempacc);
            if(checkfunction == 1)
            {
                cout << "List is empty.\n";
            }
            else if(checkfunction == -1)
            {
                cout << "Could not find account number.\n";
            }
            choice = 0;
        }
        else if(choice == 3)
        {
            cout << "Please enter an account number:";
            while(tempcheck != 0)
            {
                if(!(cin >> tempacc))
                {
                    cout << "Please enter a valid account number:";
                    cin.clear();
                    cin.ignore(1000,'\n');
                }
                else
                {
                    tempcheck = 0;
                    cin.clear();
                    cin.ignore(1000,'\n');
                }
            }
            tempcheck = 1;
            cout << "Please enter an address and end it with a .";
            getaddress(tempadd);
            checkfunction = list.modifyRecord(tempacc,tempadd);
            if(checkfunction == 1)
            {
                cout << "The list is empty.\n";
            }
            else if(checkfunction == -1)
            {
                cout << "Could not find account number.\n";
            }
            tempadd.clear();
            tempname.clear();
            choice = 0;
        }
        else if(choice == 4)
        {
            cout << list;
            choice = 0;
        }
        else if(choice == 5)
        {
            cout << "Please enter an account number:";
            while(tempcheck != 0)
            {
                if(!(cin >> tempacc))
                {
                    cout << "Please enter a valid account number:";
                    cin.clear();
                    cin.ignore(1000,'\n');
                }
                else
                {
                    tempcheck = 0;
                    cin.clear();
                    cin.ignore(1000,'\n');
                }
            }
            checkfunction = list.deleteRecord(tempacc);
            if(checkfunction == 1)
            {
                cout << "The List is empty.\n";
            }
            else if(checkfunction == -1)
            {
                cout << "Could not find account number.\n";
            }
            else
            {
                cout << "Record deleted.\n";
            }
            tempcheck = 1;
            choice = 0;
        }
        else if(choice == 6)
        {
            list.reverse();
            choice = 0;
        }
        else if(choice == 7)
        {
            return(0);
        }
        else
        {
            cout << "Please enter a valid choice.\n";
            cin.clear();
            cin.ignore(1000,'\n');
        }
    }
}
/*****************************************************************
//
// Function name: getaddress
//
// DESCRIPTION: gets the address input from the user.
// 
//
// Parameters: string add : the string variable that stores the address
//
// Return values: None
//
//****************************************************************/
void getaddress(string &add)
{
    std::size_t found;
    string temp;
    int boolean = 0;
    found = add.find_first_of(".");
    while(boolean == 0)
    { 
       if(add.empty())
       {
           getline(cin,add);
           found = add.find_first_of(".");
           if(found != std::string::npos)
           {
               boolean = -1;
               add[found] = '\n';
           }
           else
           {
               add += '\n';
           }
       }
       else
       {
           getline(cin,temp);
           add.append(temp);
           found = add.find_first_of(".");
           if(found != std::string::npos)
           {
               boolean = -1;
               add[found] = '\n';
           }
           else
           {
               add += '\n';
           }
       }
   }
   #ifdef DEBUGMODE
    {
        cout << "Function getaddress called\n";
        cout << "Parameters passed: string &add\n";
    }
    #endif
}  
