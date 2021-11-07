#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;
// This is the main menu for the program
int user_decision, FlightPrice, TicketCount, ColumnId;
char Choice;
string FlightNum, FlightName, Destination, FlightTime, FlightAmount, FlightAvail, FlightFrom, FlightClass;
struct Flight
{
    int ColumnId;
    string FlightNum, FlightName, Destination, FlightTime,
        FlightAmount, FlightAvail, FlightFrom, FlightClass;
    char Choice;
};
void showMenu()
{
    cout << setw(70) << "*******************************" << endl;
    cout << setw(70) << "*           WELCOME           *" << endl;
    cout << setw(70) << "*             TO              *" << endl;
    cout << setw(70) << "*       T.I.P. AIRLINES       *" << endl;
    cout << setw(70) << "===============================" << endl;
    cout << setw(70) << "*                             *" << endl;
    cout << setw(70) << "*                             *" << endl;
    cout << setw(70) << "*                             *" << endl;
    cout << setw(70) << "*                             *" << endl;
    cout << setw(70) << "*          [1] Customer       *" << endl;
    cout << setw(70) << "*          [2] Admin          *" << endl;
    cout << setw(70) << "*                             *" << endl;
    cout << setw(70) << "*                             *" << endl;
    cout << setw(70) << "*******************************" << endl;
}
// to show the customer menu
void showCustomerMenu()
{
    cout << setw(70) << "|-------------------------------------|" << endl;
    cout << setw(70) << "|                                     |" << endl;
    cout << setw(70) << "|                                     |" << endl;
    cout << setw(70) << "|                                     |" << endl;
    cout << setw(70) << "|       [1] Book Flight               |" << endl;
    cout << setw(70) << "|       [2] Check Flight Details      |" << endl;
    cout << setw(70) << "|       [3] Cancel Flight             |" << endl;
    cout << setw(70) << "|       [4] Exit                      |" << endl;
    cout << setw(70) << "|                                     |" << endl;
    cout << setw(70) << "|                                     |" << endl;
    cout << setw(70) << "|-------------------------------------|" << endl;
}
//Book flights menu
void showAdminMenu()
{
    cout << setw(70) << "|-------------------------------------|" << endl;
    cout << setw(70) << "|                                     |" << endl;
    cout << setw(70) << "|                                     |" << endl;
    cout << setw(70) << "|                                     |" << endl;
    cout << setw(70) << "|       [1] Display Passenger         |" << endl;
    cout << setw(70) << "|       [2] Flight Details            |" << endl;
    cout << setw(70) << "|       [3] Exit                      |" << endl;
    cout << setw(70) << "|                                     |" << endl;
    cout << setw(70) << "|                                     |" << endl;
    cout << setw(70) << "|-------------------------------------|" << endl;
}
//To Show Admin menu
void showFlightDetailsMenu()
{
    cout << setw(70) << "|-------------------------------------|" << endl;
    cout << setw(70) << "|                                     |" << endl;
    cout << setw(70) << "|                                     |" << endl;
    cout << setw(70) << "|                                     |" << endl;
    cout << setw(70) << "|       [1] Add Flight                |" << endl;
    cout << setw(70) << "|       [2] Delete Flight             |" << endl;
    cout << setw(70) << "|       [3] Edit Flight               |" << endl;
    cout << setw(70) << "|       [4] Back To Main Menu         |" << endl;
    cout << setw(70) << "|                                     |" << endl;
    cout << setw(70) << "|                                     |" << endl;
    cout << setw(70) << "|-------------------------------------|" << endl;
}
void showBookFlights()
{
    cout << setw(105) << "|----------------------------------------------------------------------------------------------|" << endl;
    cout << setw(105) << "| Flight Destination | Flight No.  | Flight Name  | Time   | Class        |Price               |" << endl;
    cout << setw(105) << "|--------------------------------------------------------------------------------------------- |" << endl;
    cout << setw(105) << "|  South Korea    [1]|   001       |  SK001       | 0700h   | Economy      |  31,000 Php       |" << endl;
    cout << setw(105) << "|                 [2]|   002       |  SK002       | 1300h   | Premium Eco. |  39,000 Php       |" << endl;
    cout << setw(105) << "|--------------------------------------------------------------------------------------------- |" << endl;
    cout << setw(105) << "|  Hongkong       [3]|   003       |  HK003       | 0900h   | Economy      |  23,000 Php       |" << endl;
    cout << setw(105) << "|                 [4]|   004       |  HK004       | 1500h   | Premium Eco. |  31,000 Php       |" << endl;
    cout << setw(105) << "|--------------------------------------------------------------------------------------------- |" << endl;
    cout << setw(105) << "|  Japan          [5]|   005       |  JP005       | 1000h   | Economy      |  32,000 Php       |" << endl;
    cout << setw(105) << "|                 [6]|   006       |  JP006       | 1800h   | Premium Eco. |  40,000 Php       |" << endl;
    cout << setw(105) << "|--------------------------------------------------------------------------------------------- |" << endl;
}
void ShowAddNewFlight(ofstream &write)
{
    Flight f1;
    cout << "\n\tEnter Column ID: ";
    cin >> f1.ColumnId;
    cout << "Welcome To T.I.P. Airlines" << endl;
    cout << "Add Flight Record" << endl;
    cout << "Enter Flight No.: ";
    cin.get();
    getline(cin, f1.FlightNum);
    cout << "Enter Flight Name: ";
    cin.get();
    getline(cin, f1.FlightName);
    cout << "Enter Flight From: ";
    cin.get();
    getline(cin, f1.FlightFrom);
    cout << "Enter Flight DEstination: ";
    cin.get();
    getline(cin, f1.Destination);
    cout << "Enter Flight Time: ";
    cin.get();
    getline(cin, f1.FlightTime);
    cout << "Enter Amount: ";
    cin.get();
    getline(cin, f1.FlightAmount);
    cout << "Enter Flight Availability (A (Available)/ N (Not Available)): ";
    cin.get();
    getline(cin, f1.FlightAvail);
    cout << "Successfully added in database." << endl;
    write << f1.ColumnId << endl
          << f1.FlightNum << endl
          << f1.FlightName << endl
          << f1.Destination << endl
          << f1.FlightTime << endl
          << f1.FlightAmount << endl
          << f1.FlightAvail << endl
          << f1.FlightFrom << endl
          << f1.FlightClass << endl;
}
Flight flightgetdata(ifstream &read)
{
    Flight obj;
    read >> obj.ColumnId;
    read.get();
    getline(read, obj.FlightName);
    cin.get();
    getline(cin, obj.FlightName);
    cin.get();
    getline(cin, obj.FlightFrom);
    cin.get();
    getline(cin, obj.Destination);
    cin.get();
    getline(cin, obj.FlightTime);
    cin.get();
    getline(cin, obj.FlightAmount);
    cin.get();
    getline(cin, obj.FlightAvail);
    cin.get();
    getline(cin, obj.FlightClass);
    return obj;
}
void DisplayFlightRecord(Flight f)
{
    cout << "|----------------------------------------------------------------------------|" << endl;
    cout << "| Column ID | Flight No. | Flight Name | From | Destination |  Class  | Time |" << endl;
    cout << "|----------------------------------------------------------------------------|" << endl;
    cout << f.ColumnId << f.FlightNum << f.FlightName << f.FlightFrom << f.Destination << f.FlightClass << f.FlightTime << endl;
    cout << "|----------------------------------------------------------------------------|" << endl;
}
void showDeleteFlight(int ColumnId, ifstream &read)
{
    //We get all data from our file i.e record.txt
    //We have to write data into temp file
    //We have to use rename and remove
    ofstream nf;
    nf.open("temp.txt");
    Flight f1;
    f1 = flightgetdata(read);
    while (!read.eof())
    {
        //There we delete record
        if (f1.ColumnId != ColumnId)
        {
            nf << f1.ColumnId << endl
               << f1.FlightNum << endl
               << f1.FlightName << endl
               << f1.Destination << endl
               << f1.FlightTime << endl
               << f1.FlightAmount << endl
               << f1.FlightAvail << endl
               << f1.FlightFrom << endl
               << f1.FlightClass;
        }
        f1 = flightgetdata(read);
    }
    nf.close();
    read.close();

    remove("record.txt");
    rename("temp.txt", "record.txt");
}
void showEditFlight(int ColumnId, ifstream &read)
{
    ofstream write("temp1.txt");
    Flight f;
    f = flightgetdata(read);
    while (!read.eof())
    {
        //Update data
        if (f.ColumnId == ColumnId)
        {
            cout << "\n\tEnter a Column Id: " << ColumnId;
            ShowAddNewFlight(write);
        }
        else
        {
            write << f.ColumnId << endl
                  << f.FlightNum << endl
                  << f.FlightName << endl
                  << f.Destination << endl
                  << f.FlightTime << endl
                  << f.FlightAmount << endl
                  << f.FlightAvail << endl
                  << f.FlightFrom << endl
                  << f.FlightClass;
        }
        f = flightgetdata(read);
    }

    write.close();
    read.close();
    remove("record.txt");
    rename("temp1.txt", "record.txt");
}
void printFlightDetails()
{
    cout << "Destination: " << Destination << endl;
    cout << "Flight Number: " << FlightNum << endl;
    cout << "Flight Name: " << FlightName << endl;
    cout << "Flight Time: " << FlightTime << endl;
    cout << "Flight Class: " << FlightClass << endl;
    cout << "Flight Price: " << FlightPrice << endl;
    cout << "how many tickets you would like to buy? ";
    cin >> TicketCount;
    cout << "That would be " << TicketCount * FlightPrice << " total" << endl;
}
void printCheckFlightDetails()
{
    cout << "Destination: " << Destination << endl;
    cout << "Flight Number: " << FlightNum << endl;
    cout << "Flight Name: " << FlightName << endl;
    cout << "Flight Time: " << FlightTime << endl;
    cout << "Flight Class: " << FlightClass << endl;
    cout << "Total Ticket Price: " << FlightPrice * TicketCount << endl;
}
int main()
{
    int ColumnId = 0;
    ifstream read;
    ofstream write;
    string password = "";
    string username = "";
    //admin log in system-------------------------------
    cout << setw(60) << "Login Admin Account" << endl;
    cout << setw(55) << "Username: ";
    cin >> username;
    cout << endl;
    cout << setw(55) << "Password: ";
    cin >> password;
   
    if (username == "admin" && password == "admin")
    {
        system("cls");
        cout << setw(55) << "Log in sucessful" << endl
             << endl
             << endl;
    }
    else {
        cout<< "Invalid Username and Password"<<endl<<endl<<endl;
    }
     //--------------------------------------------------p
        showMenu();
        cout << setw(65) << "Enter your choice here: ";
        cin >> user_decision;
        // CUSTOMER SIDE
        if (user_decision == 1)
        {
            system("cls");
            showCustomerMenu();
            cout << setw(65) << "Enter your choice here: ";
            cin >> user_decision;
            //Book Flight
            if (user_decision == 1)
            {
                system("cls");
                showBookFlights();
                cout << setw(65) << "Enter your choice here: (Example Input '1')";
                cin >> user_decision;
                if (user_decision == 1)
                {
                    Destination = "South Korea";
                    FlightNum = "001";
                    FlightName = "SK001";
                    FlightTime = "0700h";
                    FlightClass = "Economy";
                    FlightPrice = 31000;
                    printFlightDetails();
                }
                else if (user_decision == 2)
                {
                    Destination = "South Korea";
                    FlightNum = "002";
                    FlightName = "SK02";
                    FlightTime = "1300h";
                    FlightClass = "Premium Economy";
                    FlightPrice = 39000;
                    printFlightDetails();
                }
                else if (user_decision == 3)
                {
                    Destination = "Hongkong";
                    FlightNum = "003";
                    FlightName = "HK003";
                    FlightTime = "0900h";
                    FlightClass = "Economy";
                    FlightPrice = 23000;
                    printFlightDetails();
                }
                else if (user_decision == 4)
                {
                    Destination = "Hongkong";
                    FlightNum = "004";
                    FlightName = "HK004";
                    FlightTime = "1500h";
                    FlightClass = "Premium Economy";
                    FlightPrice = 31000;
                    printFlightDetails();
                }
                else if (user_decision == 5)
                {
                    Destination = "Japan";
                    FlightNum = "005";
                    FlightName = "JP005";
                    FlightTime = "1000h";
                    FlightClass = "Economy";
                    FlightPrice = 32000;
                    printFlightDetails;
                }
                else if (user_decision == 6)
                {
                    Destination = "Japan";
                    FlightNum = "006";
                    FlightName = "JP006";
                    FlightTime = "1800h";
                    FlightClass = "Premium Economy";
                    FlightPrice = 40000;
                    printFlightDetails();
                }
            }
            // Check Flight Details
            else if (user_decision == 2)
            {
                system("cls");
                printCheckFlightDetails();
            }
            //Cancel Flight
            else if (user_decision == 3)
            {
                cout << "3";
            }
            // Exit
            else if (user_decision == 4)
            {
                cout << "Thank you for using our service!" << endl;
                cout << "Have a nice day!" << endl;
                exit(0);
            }
            else
            {
                system("cls");
                cout << setw(60) << "Invalid Input" << endl;
                main();
            }
        }
        // ADMIN SIDE
        else if (user_decision == 2)
        {

            system("cls");
            showAdminMenu();
            cout << setw(65) << "Enter your choice here: ";
            cin >> user_decision;
            if (user_decision == 1)
            {

                //DisplayFlight();
                //notyetdone
            }
            else if (user_decision == 2)
            {
                system("cls");
                showFlightDetailsMenu();
                cout << setw(65) << "Enter your choice here: (Example Input '1')";
                cin >> user_decision;
                if (user_decision == 1)
                {
                    ShowAddNewFlight(write);
                }
                else if (user_decision == 2)
                {
                    showDeleteFlight(ColumnId, read);
                }
                else if (user_decision == 3)
                {
                    showEditFlight(ColumnId, read);
                }
                else
                {
                    cout << "Invalid choice.";
                }
            }

            else
            {
                cout << "Invalid Input" << endl;
                cout << "Try again . . ." << endl;
                exit(0);
            }
            system("pause");
            system("cls");
            main();
        }
    }
