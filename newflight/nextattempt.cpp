#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int ID, choice, choiceadmin, choicecustomer, seatAvailable1 = 1, seatAvailable2 = 15, seatAvailable3 = 8, seatAvailable4 = 24, seatAvailable5 = 7, seatAvailable6 = 13;
struct Customer
{
    int id;
    string name;
    int age;
    string nationality;
    int passportid;
    int choiceflight;
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
    cout << "=========================================" << endl
         << endl;
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
    cout << "=========================================" << endl
         << endl;
}
void showAvailableFlights()
{
    //0 15 8 24 7 13
    cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "| Flight Destination | Flight No.  | Flight Name  | Time of Departure | Class        |Price           |Seat Available  |" << endl;
    cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "|  South Korea    [1]|   001       |  SK001       | 0700h             | Economy      |  7,000 Php     |       " << seatAvailable1 << "        |" << endl;
    cout << "|                 [2]|   002       |  SK002       | 1300h             | Premium Eco. |  10,000 Php    |       " << seatAvailable2 << "       |" << endl;
    cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "|  Hongkong       [3]|   003       |  HK003       | 0900h             | Economy      |  10,000 Php    |       " << seatAvailable3 << "        |" << endl;
    cout << "|                 [4]|   004       |  HK004       | 1500h             | Premium Eco. |  14,000 Php    |       " << seatAvailable4 << "       |" << endl;
    cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "|  Japan          [5]|   005       |  JPN005       | 1000h            | Economy      |  20,000 Php    |       " << seatAvailable5 << "        |" << endl;
    cout << "|                 [6]|   006       |  JPN006       | 1800h            | Premium Eco. |  30,000 Php    |       " << seatAvailable6 << "       |" << endl;
    cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
}
void bookflight()
{
    Customer customer;
    cout << "\n\tEnter your choice: ";
    cin >> customer.choiceflight;
    if (customer.choiceflight == 1)
    {
        cout << "\n\tFlight Name: SK001 ";
        cout << "\n\tFlight Number: 001 ";
        cout << "\n\tFlight Destination: South Korea ";
        cout << "\n\tFlight Time Departure: 7:00AM ";
        cout << "\n\tClass: Economy ";
        cout << "\n\tFlight Price: 7,000 Php ";
        cout << "\n\tSeat Available: " << seatAvailable1;
    }
    else if (customer.choiceflight == 2)
    {
        cout << "\n\tFlight Name: SK002 ";
        cout << "\n\tFlight Number: 002 ";
        cout << "\n\tFlight Destination: South Korea ";
        cout << "\n\tFlight Time Departure: 1:00PM ";
        cout << "\n\tClass: Premium Eco. ";
        cout << "\n\tFlight Price: 10,000 Php ";
        cout << "\n\tSeat Available: " << seatAvailable2;
    }
    else if (customer.choiceflight == 3)
    {
        cout << "\n\tFlight Name: HK003 ";
        cout << "\n\tFlight Number: 003 ";
        cout << "\n\tFlight Destination: Hongkong ";
        cout << "\n\tFlight Time Departure: 9:00AM ";
        cout << "\n\tClass: Economy ";
        cout << "\n\tFlight Price: 10,000 Php ";
        cout << "\n\tSeat Available: " << seatAvailable3;
    }
    else if (customer.choiceflight == 4)
    {
        cout << "\n\tFlight Name: HK004 ";
        cout << "\n\tFlight Number: 004 ";
        cout << "\n\tFlight Destination: Hongkong ";
        cout << "\n\tFlight Time Departure: 3:00PM ";
        cout << "\n\tClass: Premium Eco. ";
        cout << "\n\tFlight Price: 14,000 Php ";
        cout << "\n\tSeat Available: " << seatAvailable4;
    }
    else if (customer.choiceflight == 5)
    {
        cout << "\n\tFlight Name: JPN005 ";
        cout << "\n\tFlight Number: 005 ";
        cout << "\n\tFlight Destination: Japan ";
        cout << "\n\tFlight Time Departure: 10:00AM ";
        cout << "\n\tClass: Economy ";
        cout << "\n\tFlight Price: 20,000 Php ";
        cout << "\n\tSeat Available: " << seatAvailable5;
    }
    else if (customer.choiceflight == 6)
    {
        cout << "\n\tFlight Name: JPN006 ";
        cout << "\n\tFlight Number: 006 ";
        cout << "\n\tFlight Destination: Japan ";
        cout << "\n\tFlight Time Departure: 7:00AM ";
        cout << "\n\tClass: Premium Eco.";
        cout << "\n\tFlight Price: 30,000 Php ";
        cout << "\n\tSeat Available: " << seatAvailable6;
    }
    cout << "\n\tEnter your name: ";
    cin.get();
    getline(cin, customer.name);
    cout << "\n\tEnter your age: ";
    cin >> customer.age;
    cout << "\n\tEnter your nationality: ";
    cin >> customer.nationality;
    cout << "\n\tEnter your passport ID: ";
    cin >> customer.passportid;
    ID++;

    ofstream write;
    write.open("customerrecord.txt", ios::app);
    write << "\n"
          << ID;
    write << "\n"
          << customer.choiceflight;
    write << "\n"
          << customer.name;
    write << "\n"
          << customer.age;
    write << "\n"
          << customer.nationality;
    write << "\n"
          << customer.passportid;
    write << "\n"
          << customer.choiceflight;
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
    cout << "\n\n " << c.choiceflight;
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
        read >> customer.choiceflight;
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
        read >> customer.choiceflight;
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
        cout << "\n\tEnter your name; ";
        cin.get();
        getline(cin, newdata.name);
        cout << "\n\tEnter your age; ";
        cin >> newdata.age;
        cout << "\n\tEnter your nationality; ";
        cin >> newdata.nationality;
        cout << "\n\tEnter your passportid; ";
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
                         << customer.choiceflight;
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
                         << customer.choiceflight;
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
                showAvailableFlights();
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
    else if (choice == 2)
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

