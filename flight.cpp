#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;
// This is the main menu for the program
int user_decision, FlightPrice, TicketCount, FlightAmount;
char Choice, FlightTime;
string FlightNum, FlightName, Destination, FlightFrom, FlightClass;

struct Flight
{
	int ColumnId;
	int FlightAmount;
	string FlightNum;
	string FlightName;
	string Destination;
	string FlightFrom;
	string FlightTime;
	string FlightClass;
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
	cout << setw(70) << "|       [1] Display Flight Record     |" << endl;
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
//ADMIN VOID - FLIGHT DETAILS
void ShowAddNewFlight(ofstream& write)
{
	Flight f1;
	cout << "Welcome To T.I.P. Airlines" << endl;
	cout << "Add Flight Record" << endl;

	cout << "\n\tEnter Column ID: ";
	cin >> f1.ColumnId;

	cout << "Enter Flight No.: ";
	cin.get();
	getline(cin, f1.FlightNum);

	cout << "Enter Flight Name: ";
	cin.get();
	getline(cin, f1.FlightName);

	cout << "Enter Flight From: ";
	cin.get();
	getline(cin, f1.FlightFrom);

	cout << "Enter Flight Destination: ";
	cin.get();
	getline(cin, f1.Destination);

	cout << "Enter Class: ";
	cin.get();
	getline(cin, f1.FlightClass);

	cout << "Enter Flight Time: ";
	cin >> f1.FlightTime;

	cout << "Enter Amount: ";
	cin >> f1.FlightAmount;

	cout << "Successfully added in database." << endl;
	write << f1.ColumnId << endl;
	write<< f1.FlightNum << endl<< f1.FlightName << endl<< f1.FlightFrom << endl<< f1.Destination << endl<< f1.FlightClass << endl;
	write << f1.FlightTime << endl << f1.FlightAmount << endl<< endl;

	cout << "Add another Flight? Y if yes / N if no: ";
	cin >> Choice;
	if (Choice == 'Y' || Choice == 'y') {
		ShowAddNewFlight(write);
		}
	else if (Choice == 'N' || Choice == 'n') {
		showAdminMenu();
	}
	else {
		cout << "Invalid Choice";
	}
}
Flight flightgetdata(ifstream &read)
{
	Flight obj;
	read >> obj.ColumnId;

	read.get();
	getline(read, obj.FlightNum);

	read.get();
	getline(read, obj.FlightName);

	read.get();
	getline(read, obj.FlightFrom);

	read.get();
	getline(read, obj.Destination);

	read.get();
	getline(read, obj.FlightClass);
	read >> obj.FlightTime;
	read >> obj.FlightAmount;

	return obj;
}
void DisplayCustomerChoice(Flight f) {
	cout << "\n\tDestination: " << f.Destination;
	cout << "\n\tFlight Number: " << f.FlightNum;
	cout << "\n\tFlight Name: " << f.FlightName;
	cout << "\n\tFlight Time: " << f.FlightTime;
	cout << "\n\tFlight Class: " << f.FlightClass;
	cout << "\n\tFlight Price:" << f.FlightAmount <<endl;
}
void DisplayFlightRecord(Flight f)
{
	cout << "\n\tColumn ID: " << f.ColumnId;
	cout << "\n\tFlight No.: " << f.FlightNum;
	cout << "\n\tFlight Name: " << f.FlightName;
	cout << "\n\tFrom: " << f.FlightFrom;
	cout << "\n\tDestination: " << f.Destination;
	cout << "\n\tClass: " << f.FlightClass;
	cout << "\n\tTime: " << f.FlightTime;
	cout << "\n\tPrice: " << f.FlightAmount << " Php" << endl;
}
void showDeleteFlight(int ColumnId, ifstream& read)
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
				<< f1.FlightClass << endl
				<< f1.FlightTime << endl
				<< f1.FlightAmount << endl
				<< f1.FlightFrom;
		}
		f1 = flightgetdata(read);
	}
	nf.close();
	read.close();

	remove("record.txt");
	rename("temp.txt", "record.txt");
}
void showEditFlight(int ColumnId, ifstream& read)
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
//ADMIN VOID - FLIGHT DETAILS
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
	Flight f;
	int ColumnId =0;
	ifstream read;
	read.open("record.txt", ios::in);
	ofstream write("record.txt", ios::app);
	string password = "";
	string username = "";
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
				DisplayCustomerChoice(f);
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
			cout << setw(55) << "Log in sucessful" << endl << endl<< endl;
		showAdminMenu();
		cout << setw(65) << "Enter your choice here: ";
		cin >> user_decision;
            if (user_decision == 1)
            {
                ifstream read;
                read.open("record.txt", ios::in);
                Flight f1;
                f1 = flightgetdata(read);
                while (!read.eof()) {
                    DisplayFlightRecord(f1);
                    f1 = flightgetdata(read);
                }
            }
            else if (user_decision == 2)
            {
                system("cls");
                showFlightDetailsMenu();
                cout << setw(65) << "Enter your choice here: ";
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
                else if (user_decision == 4)
                {
                    showAdminMenu();
                }
                else
                {
                    cout << "Invalid Choice...";
                }
            }
        else
        {
            cout << "Invalid Username and Password" << endl;
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
		return 0;
	}
}
