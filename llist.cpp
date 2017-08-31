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
// FILE: llist.cpp
//
// Description: The function definition of the llist class.
//
//****************************************************************/
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
#include"record2.h"
#include"llist.h"
/*****************************************************************
//
// Function name: llist()
//
// DESCRIPTION: llist constructor that intializes class variables and
// calls readfile()
//
// Parameters: None
//
// Return values: None
//
//****************************************************************/
llist::llist()
{
    start = NULL;
    filename = "output.txt";
    readfile();
    #ifdef DEBUGMODE
    {
        cout << "llist Constructor called.\n";
    }
    #endif
}
/*****************************************************************
//
// Function name: llist
//
// DESCRIPTION: llist constructor that intializes class variables and
// calls readfile()
//
// Parameters: string a: the name of the text file that is being read by
// readfile()
//
// Return values: None
//
//****************************************************************/
llist::llist(string a)
{
    start = NULL;
    filename = a;
    readfile();
    #ifdef DEBUGMODE
        cout << "llist Constructor called.\n";
        cout << "Parameters passed: string " << a << "\n";
    #endif
}
/*****************************************************************
//
// Function name: readfile
//
// DESCRIPTION: Reads the text file and calls addRecord to add the data
// in the text file.
//
// Parameters: None
//
// Return values: int: 0 successfully called
//
//****************************************************************/
int llist::readfile()
{
    ifstream fs(filename.c_str());
    int tempaccno;
    string tempname;
    string tempadd;
    string str;
    int tempyob;
    int test;
    int boolean = 0;
    int boolean2 = 0;
    std::size_t found;
    if(fs.is_open())
    {
        while(boolean == 0)
        {
            fs >> tempaccno;
            if(fs.eof())
            {
                boolean = -1;
            }
            else
            {
                getline(fs >> ws, tempname);
                while(boolean2 == 0)
                {
                    getline(fs,str);
                    tempadd.append(str);
                    found = tempadd.find_first_of(".");
                    if(found != std::string::npos)
                    {
                        boolean2 = -1;
                         tempadd[found] = '\n';
                    }
                    else
                    {
                        tempadd += '\n';
                    }
                }
                boolean2 = 0;
                fs >> tempyob;
                addRecord(tempaccno,tempname,tempadd,tempyob);
                tempadd.clear();
                tempname.clear();
            }
        }
        #ifdef DEBUGMODE
        {
            cout << "llist function readfile called.\n";
        }
        #endif
    }
    else
    {
        cout << "Could not read file\n";
        #ifdef DEBUGMODE
        {
            cout << "llist function readfile called.\n";
        }
        #endif
    }
    fs.close();
    return(0);
}
/*****************************************************************
//
// Function name: addRecord
//
// DESCRIPTION: Creates a record on the heap
//
// Parameters: int:     a: The account number
//                      d: The year of birth
//             string:  b: The name
//                      c: The address
//
// Return values: int: 0 successfully added record
//
//****************************************************************/
int llist::addRecord(int a,string b, string c, int d)
{
    struct record *temp;
    struct record *temp2;
    struct record *temp3;
    temp = new record();
    (*temp).accountno = a;
    (*temp).name = b;
    (*temp).address = c;
    (*temp).yearofbirth = d;
    if(start != NULL)
    {
        temp2 = start;
        while(temp2 != NULL && (*temp).yearofbirth < (*temp2).yearofbirth)
        {
            temp3 = temp2;
            temp2 = (*temp2).next;
        }
        if(start == temp2 && temp2 != NULL)
        {
            (*temp).next = start;
            start = temp;
        }
        else if(temp2 != NULL && (*temp2).yearofbirth == (*temp).yearofbirth)
        {
             (*temp).next = temp2;
             (*temp3).next = temp;   
        }
        else
        {
            (*temp).next = (*temp3).next;
            (*temp3).next = temp;
        }
        #ifdef DEBUGMODE
        {
            cout << "llist add function called.\n";
            cout << "Parameters passed: accountnumber: " << a << " name: " << b << " address: " << c << "year: " << d << "\n";
        }
        #endif
        return(0);
    }
    else
    {
        (*temp).next = start;
        start = temp;
        #ifdef DEBUGMODE
        {
            cout << "llist add function called.\n";
            cout << "Parameters passed: accountnumber: " << a << " name: " << b << " address: " << c << "year: " << d << "\n";
        }
        #endif
        return(0);
    }
}
/*****************************************************************
//
// Function name: printRecord
//
// DESCRIPTION: Prints the record with the account number given
//
// Parameters: int: a: the account number
//
// Return values: int: 0 successfully prints
//                     1 the list is empty
//                    -1 could not find the record
//
//****************************************************************/
int llist::printRecord(int a)
{
    struct record *temp;
    int boolean;
    boolean = 1;
    temp = start;
    while(temp != NULL)
    {
        if((*temp).accountno == a)
        {
            cout << (*temp).accountno << "\n";
            cout << (*temp).name << "\n";
            cout << (*temp).address;
            cout << (*temp).yearofbirth << "\n";
            boolean = 0;
        }
        temp = (*temp).next;
    }
    #ifdef DEBUGMODE
    {
        cout << "llist function printRecord called.\n";
        cout << "Parameters passed: accountnumber: " << a << "\n";
    }
    #endif
    if(start == NULL)
    {
        return(1);
    }
    else if(boolean == 1)
    {
        return(-1);
    }
    else
    {
        return(0);
    }
}
/*****************************************************************
//
// Function name: modifyRecord
//
// DESCRIPTION: modifies the records address with the account number given
//
// Parameters: int:    a: the account number
//             string: b: the address in which it is changing to
//
// Return values: int: 0 successfully modified address
//                     1 the list is empty
//                    -1 could not find the record
//
//****************************************************************/
int llist::modifyRecord(int a, string b)
{
    struct record *temp;
    temp = start;
    int boolean;
    boolean = 1; 
    while(temp != NULL)
    {
        if((*temp).accountno == a)
        {
            (*temp).address = b;
            boolean = 0;
        }
        temp = (*temp).next;
    }
    #ifdef DEBUGMODE
    {
        cout << "llist modifyRecord called.\n";
        cout << "Parameters passed: account: " << a << " address: " << b << "\n";
    }
    #endif
    if(start == NULL)
    {
        return(1);
    }
    else if(boolean == 1)
    {
        return(-1);
    }
    else
    {
        return(0);
    }
}
/*****************************************************************
//
// Function name: printAll
//
// DESCRIPTION: Prints all records in the list
//
// Parameters: None
//
// Return values: None
//
//****************************************************************/
void llist::printAll()
{
    struct record *temp;
    temp = start;
    if(temp != NULL)
    {
        while(temp != NULL)
        {
            cout << (*temp).accountno << "\n";
            cout << (*temp).name << "\n";
            cout << (*temp).address;
            cout << (*temp).yearofbirth << "\n";
            temp = (*temp).next;
        }
    }
    #ifdef DEBUGMODE
    {
        cout << "llist printAll called.\n";
    }
    #endif
}
/*****************************************************************
//
// Function name: deleteRecord
//
// DESCRIPTION: Deletes the record with the account number given
//
// Parameters: int: a: the account number
//
// Return values: int: 0 successfully prints
//                     1 the list is empty
//                    -1 could not find the record
//
//****************************************************************/
int llist::deleteRecord(int a)
{
    struct record *temp;
    struct record *temp2;
    int boolean;
    boolean = 1;
    temp = start;
    while(temp != NULL)
    {
        temp2 = temp;
        temp = (*temp).next;
        if(temp2 == start &&(*temp2).accountno == a)
        {
            start = (*temp2).next;
            delete temp2;
            boolean = 0;   
        }
        else if(temp != NULL && (*temp).accountno == a)
        {
            (*temp2).next = (*temp).next;
            delete temp;
            temp = temp2;
            boolean = 0;
        }
    }
    #ifdef DEBUGMODE
    {
        cout << "llist deleteRecord called.\n";
        cout << "Parameters passed: " << a << "\n";
    }
    #endif
    if(start == NULL)
    {
        return(1);
    }
    else if(boolean == 1)
    {
        return(-1);
    }
    else
    {
        return(0);
    }
}
/*****************************************************************
//
// Function name: reverse
//
// DESCRIPTION: Calls the reverse method to reverse the list
//
// Parameters: None
//
// Return values: None
//
//****************************************************************/
void llist::reverse()
{
    if(start != NULL)
    {
        reverse(start);
    }
    else
    {
        cout << "The list is empty.\n";
    }
    #ifdef DEBUGMODE
    {
        cout << "llist reverse called.\n";
        cout << "Parameters passed: start\n";
    }
    #endif
}
/*****************************************************************
//
// Function name: ~llist
//
// DESCRIPTION: Destructor of the llist class, calls writefile and
// cleanup to write and clear the list respectively
//
// Parameters: None
//
// Return values: None
//
//****************************************************************/
llist::~llist()
{
    writefile();
    cleanup();
}
/*****************************************************************
//
// Function name: cleanup
//
// DESCRIPTION: Goes through the list and deletes each record
//
// Parameters: None
//
// Return values: None
//
//****************************************************************/
void llist::cleanup()
{
    struct record *temp;
    struct record *temp2;
    temp = start;
    while(temp != NULL)
    {
        temp2 = temp;
        temp = (*temp).next;
        delete temp2;    
    }
    #ifdef DEBUGMODE
    {
        cout << "llist cleanup called.\n";
    }
    #endif
}
/*****************************************************************
//
// Function name: writefile
//
// DESCRIPTION: Writes the list into a textfile
//
// Parameters: None
//
// Return values: 0 succesfully written
//
//****************************************************************/
int llist::writefile()
{
    ofstream fs(filename.c_str());
    struct record *temp;
    temp = start;
    string tempadd;
    std::size_t found; 
    while(temp != NULL)
    {
        tempadd = (*temp).address;
        found = tempadd.find_last_of('\n');
        tempadd[found] = '.';
        fs << (*temp).accountno << "\n";
        fs << (*temp).name << "\n";
        fs << tempadd << "\n";
        fs << (*temp).yearofbirth << "\n";
        temp = (*temp).next;
    }
    #ifdef DEBUGMODE
    {
        cout << "llist writefile called.\n";
    }
    #endif
    fs.close();
    return(0);
}
/*****************************************************************
//
// Function name: reverse
//
// DESCRIPTION: Recursive function that reverses the list
//
// Parameters: record *: a: an address of a record
//
// Return values: record *: an address of a record
//
//****************************************************************/
record * llist::reverse(record * a)
{
    record *temp;
    if((*a).next == NULL)
    {
        start = a;
    }
    else
    {
        temp = reverse((*a).next);
        (*a).next = (*temp).next;
        (*temp).next = a;
    }
    return a;
}
/*****************************************************************
//
// Function name: operator <<
//
// DESCRIPTION: Overload the operator << to printout the list
//
// Parameters: ostream &: a: the reference to a stream
//               llist &: b: the reference to the list
//
// Return values: ostream&: the reference to a stream
//
//****************************************************************/
ostream& operator<<(ostream &a,llist &b)
{
    struct record *temp;
    temp = b.start;
    if(temp != NULL)
    {
        while(temp != NULL)
        {
            a << (*temp).accountno << "\n";
            a << (*temp).name << "\n";
            a << (*temp).address;
            a << (*temp).yearofbirth << "\n";
            temp = (*temp).next;
        }
    }
    #ifdef DEBUGMODE
    {
        cout << "printAll used << operator called.\n";
    }
    #endif
    return a;
}
