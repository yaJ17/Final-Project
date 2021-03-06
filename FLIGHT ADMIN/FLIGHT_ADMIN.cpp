#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int ID, choice, choiceadmin, choicecustomer;
struct Customer
{
    int id;
    string name;
    int age;
    string nationality;
    int passportid;
};

void Menu()
{
    cout << "======WELCOME TO T.I.P. QC AIRLINE======" << endl;
    cout << "|                                       |" << endl;
    cout << "|                                       |" << endl;
    cout << "|            [1] CUSTOMER               |" << endl;
    cout << "|            [2] ADMIN                  |" << endl;
    cout << "|                                       |" << endl;
    cout << "|                                       |" << endl;
    cout << "=========================================" << endl
         << endl;
    cout << "ENTER YOUR CHOICE: ";
    cin >> choice;
}
void CustomerMenu()
{
    cout << "======WELCOME TO T.I.P. QC AIRLINE======" << endl;
    cout << "|                                       |" << endl;
    cout << "|                                       |" << endl;
    cout << "|            [1] BOOK A FLIGHT          |" << endl;
    cout << "|            [2] SEARCH YOUR TICKET     |" << endl;
    cout << "|            [3] EXIT                   |" << endl;
    cout << "|                                       |" << endl;
    cout << "|                                       |" << endl;
    cout << "=========================================" << endl << endl;

}
void AdminMenu()
{
    cout << "======WELCOME TO T.I.P. QC AIRLINE======" << endl;
    cout << "|                                       |" << endl;
    cout << "|                                       |" << endl;
    cout << "|        [1] BOOK FLIGHT HISTORY        |" << endl;
    cout << "|        [2] SEARCH TICKET HISTORY      |" << endl;
    cout << "|        [3] EXIT                       |" << endl;
    cout << "|                                       |" << endl;
    cout << "|                                       |" << endl;
    cout << "=========================================" << endl << endl;
}
void bookflight()
{
    Customer customer;

    cout << "\n\tEnter your name: " ;
	cin.get();
    getline(cin, customer.name);
    cout << "\n\tEnter your age; " ;
	 cin >> customer.age;
    cout << "\n\tEnter your nationality; " ; 
	cin >> customer.nationality;
    cout << "\n\tEnter your passportid; " ;
	 cin >> customer.passportid;
    ID++;

    ofstream write;
    write.open("customerrecord.txt", ios::app);
    write << "\n"
          << ID;
    write << "\n"
          << customer.name;
    write << "\n"
          << customer.age;
    write << "\n"
          << customer.nationality;
    write << "\n"
          << customer.passportid;
    write.close();
    write.open("id.txt");
    write << ID;
    write.close();
    cout << "\n\tSuccessfully book a flight...." << endl;
    cout << "\n\tThank you and have a nice day...." << endl;
}

void printticket(Customer c)
{
    cout << "\n\n\tYour ticket flight";
    cout << "\n\tID: " << c.id;
    cout << "\n\tNAME: " << c.name;
    cout << "\n\tAGE: " << c.age;
    cout << "\n\tNATIONALITY: " << c.nationality;
    cout << "\n\tPASSPORT ID: " << c.passportid;
}

void readcustomer()
{
    Customer customer;
    ifstream read;
    read.open("customerrecord.txt");
    while (!read.eof())
    {
        read >> customer.id;
        read.ignore();
        getline(read, customer.name);
        read >> customer.age;
        read >> customer.nationality;
        read >> customer.passportid;
        printticket(customer);
    }
    read.close();
}

int searchticket()
{
    int passportid;
    cout << "\n\tEnter Your Passport ID: ";
    cin >> passportid;
    Customer customer;
    ifstream read;
    read.open("customerrecord.txt");
    while (!read.eof())
    {
        read >> customer.id;
        read.ignore();
        getline(read, customer.name);
        read >> customer.age;
        read >> customer.nationality;
        read >> customer.passportid;
        if (customer.passportid == passportid)
        {
            printticket(customer);
            return passportid;
        }
    }
}
void updatecustomer()
{
    int passportid = searchticket();
    cout << "\n\tYou want to update your information? (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        Customer newdata;
        cout << "\n\tEnter your name; " ; 
		cin.get();
        getline(cin, newdata.name);
        cout << "\n\tEnter your age; " ; 
		cin >> newdata.age;
        cout << "\n\tEnter your nationality; " ; 
		cin >> newdata.nationality;
        cout << "\n\tEnter your passportid; " ; 
		cin >> newdata.passportid;

        Customer customer;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("customerrecord.txt");
        while (!read.eof())
        {
            read >> customer.id;
            read.ignore();
            getline(read, customer.name);
            read >> customer.age;
            read >> customer.nationality;
            read >> customer.passportid;
            if (customer.passportid != passportid)
            {
                tempFile << "\n"
                         << customer.id;
                tempFile << "\n"
                         << customer.name;
                tempFile << "\n"
                         << customer.age;
                tempFile << "\n"
                         << customer.nationality;
                tempFile << "\n"
                         << customer.passportid;
            }
            else
            {
                tempFile << "\n"
                         << customer.id;
                tempFile << "\n"
                         << newdata.name;
                tempFile << "\n"
                         << newdata.age;
                tempFile << "\n"
                         << newdata.nationality;
                tempFile << "\n"
                         << newdata.passportid;
            }
        }
        read.close();
        tempFile.close();
        remove("customerrecord.txt");
        rename("temp.txt", "customerrecord.txt");
        cout << "\n\tYour information updated successfully";
    }
    else
    {
        cout << "\n\tInvalid Passport ID...";
    }
}

int main()
{
	Customer c;
    Menu();
    if (choice == 1)
    {
        CustomerMenu();
        ifstream read;
        read.open("id.txt");
        if (!read.fail())
        {
            read >> ID;
        }
        else
        {
            ID = 0;
        }
        read.close();

        while (true)
        {
            int choice;
            cout << "\n\n\tEnter choice : ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                bookflight();
                break;
            case 2:
                searchticket();
                break;
            case 3:
                //exit
                break;
            }
        }
    }
    else if (choice==2)
    {
        AdminMenu();
         ifstream read;
        read.open("id.txt");
        if (!read.fail())
        {
            read >> ID;
        }
        else
        {
            ID = 0;
        }
        read.close();

        while (true)
        {
            int choice;
            cout << "\n\n\tEnter choice : ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                readcustomer();
                break;
            case 2:
                searchticket();
                break;
            case 3:
                //exit
                break;
            }
        }
    }
}