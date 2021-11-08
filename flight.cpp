#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;
// This is the main menu for the program
int user_decision, FlightPrice, TicketCount, FlightAmount,ColumnId;
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
	cout << setw(70) << "|       [1] Search Flight Record      |" << endl;
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
	cout << setw(70) << "|       [1] Add Flight				   |" << endl;
	cout << setw(70) << "|       [2] Display Flight            |" << endl;
	cout << setw(70) << "|       [3] Delete Flight             |" << endl;
	cout << setw(70) << "|       [4] Edit Flight               |" << endl;
	cout << setw(70) << "|       [5] Back To Main Menu         |" << endl;
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
void ShowAddNewFlight() {
	Flight ff;

	cout << "\n\tEnter Flight No.: ";
	cin.get();
	getline(cin, ff.FlightNum);
	cout << "\n\tEnter Flight Name: ";
	cin.get();
	getline(cin, ff.FlightName);
	cout << "\n\tEnter Flight From: ";
	cin.get();
	getline(cin, ff.FlightFrom);
	cout << "\n\tEnter Flight Destination: ";
	cin.get();
	getline(cin, ff.Destination);
	cout << "\n\tEnter Class: ";
	cin.get();
	getline(cin, ff.FlightClass);
	cout << "\n\tEnter Flight Time: ";
	cin >> ff.FlightTime;
	cout << "\n\tEnter Amount: ";
	cin >> ff.FlightAmount;
	ColumnId++;

	ofstream write;
	write.open("record.txt", ios::app);
	write << "\n" << ColumnId;
	write << "\n" << ff.FlightNum;
	write << "\n" << ff.FlightName;
	write << "\n" << ff.FlightFrom;
	write << "\n" << ff.Destination;
	write << "\n" << ff.FlightClass;
	write << "\n" << ff.FlightTime;
	write << "\n" << ff.FlightAmount;
	write.close();
	write.open("columnid.txt");
	write << ColumnId;
	write.close();
	cout << "\n\tData saved to file...";
}

void DisplayFlightRecord(Flight f) {

	cout << "\n\tColumn ID: " << f.ColumnId;
	cout << "\n\tFlight No.: " << f.FlightNum;
	cout << "\n\tFlight Name: " << f.FlightName;
	cout << "\n\tFrom: " << f.FlightFrom;
	cout << "\n\tDestination: " << f.Destination;
	cout << "\n\tClass: " << f.FlightClass;
	cout << "\n\tTime: " << f.FlightTime;
	cout << "\n\tPrice: " << f.FlightAmount << " Php";

}

void ReadFLightRecord() {
	Flight ff;
	ifstream read;
	read.open("record.txt");
	while (!read.eof()) {
		read >> ff.ColumnId;
		read >> ff.FlightNum;
		read.ignore();
		getline(read, ff.FlightName);
		read.ignore();
		getline(read, ff.FlightFrom);
		read.ignore();
		getline(read, ff.Destination);
		read.ignore();
		getline(read, ff.FlightClass);
		read >> ff.FlightTime;
		read >> ff.FlightAmount;
		DisplayFlightRecord(ff);
	}
	read.close();
}

int SearchFlightRecord() {
	int ColumnId;
	cout << "\n\tEnter Column ID you want to search: ";
	cin >> ColumnId;
	Flight ff;
	ifstream read;
	read.open("record.txt");
	while (!read.eof()) {
		read >> ff.ColumnId;
		read >> ff.FlightNum;
		read.ignore();
		getline(read, ff.FlightFrom);
		read >> ff.FlightAmount;
		read.ignore();
		getline(read, ff.Destination);
		read >> ff.FlightTime;
		read.ignore();
		getline(read, ff.FlightClass);

		if (ff.ColumnId == ColumnId) {
			DisplayFlightRecord(ff);
			return ColumnId;
		}
	}
}

void ShowDeleteFlight() {
	int ColumnId = SearchFlightRecord();
	cout << "\n\tYou want to delete record (y/n) : ";
	char choice;
	cin >> choice;
	if (choice == 'y') {
		Flight ff;
		ofstream tempFile;
		tempFile.open("temp.txt");
		ifstream read;
		read.open("record.txt");
		while (!read.eof()) {
			read >> ff.ColumnId;
			read >> ff.FlightNum;
			read.ignore();
			getline(read, ff.FlightName);
			read.ignore();
			getline(read, ff.FlightFrom);
			read.ignore();
			getline(read, ff.Destination);
			read.ignore();
			getline(read, ff.FlightClass);
			read >> ff.FlightTime;
			read >> ff.FlightAmount;

			if (ff.ColumnId != ColumnId) {
				tempFile << "\n" << ff.ColumnId;
				tempFile << "\n" << ff.FlightNum;
				tempFile << "\n" << ff.FlightName;
				tempFile << "\n" << ff.FlightFrom;
				tempFile << "\n" << ff.Destination;
				tempFile << "\n" << ff.FlightClass;
				tempFile << "\n" << ff.FlightTime;
				tempFile << "\n" << ff.FlightAmount;
			}
		}
		read.close();
		tempFile.close();
		remove("record.txt");
		rename("temp.txt", "record.txt");
		cout << "\n\tData deleted successfully";
	}
	else {
		cout << "\n\tRecord not deleted";
	}
}

void ShowEditFlight() {
	int ColumnId = SearchFlightRecord();
	cout << "\n\tYou want to update record (y/n) : ";
	char choice;
	cin >> choice;
	if (choice == 'y') {
		Flight newData;
		cout << "\n\tEnter Flight No.: ";
		cin.get();
		getline(cin, newData.FlightNum);
		cout << "\n\tEnter Flight Name: ";
		cin.get();
		getline(cin, newData.FlightName);
		cout << "\n\tEnter Flight From: ";
		cin.get();
		getline(cin, newData.FlightFrom);
		cout << "\n\tEnter Flight Destination: ";
		cin.get();
		getline(cin, newData.Destination);
		cout << "\n\tEnter Class: ";
		cin.get();
		getline(cin, newData.FlightClass);
		cout << "\n\tEnter Flight Time: ";
		cin >> newData.FlightTime;
		cout << "\n\tEnter Amount: ";
		cin >> newData.FlightAmount;
		Flight ff;
		ofstream tempFile;
		tempFile.open("temp.txt");
		ifstream read;
		read.open("record.txt");
		while (!read.eof()) {
			read >> ff.ColumnId;
			read >> ff.FlightNum;
			read.ignore();
			getline(read, ff.FlightName);
			read.ignore();
			getline(read, ff.FlightFrom);
			read.ignore();
			getline(read, ff.Destination);
			read.ignore();
			getline(read, ff.FlightClass);
			read >> ff.FlightTime;
			read >> ff.FlightAmount;
			if (ff.ColumnId != ColumnId) {
				tempFile << "\n" << ff.ColumnId;
				tempFile << "\n" << ff.FlightNum;
				tempFile << "\n" << ff.FlightName;
				tempFile << "\n" << ff.FlightFrom;
				tempFile << "\n" << ff.Destination;
				tempFile << "\n" << ff.FlightClass;
				tempFile << "\n" << ff.FlightTime;
				tempFile << "\n" << ff.FlightAmount;
			}
			else {
				tempFile << "\n" << ff.ColumnId;
				tempFile << "\n" << newData.FlightNum;
				tempFile << "\n" << newData.FlightName;
				tempFile << "\n" << newData.FlightFrom;
				tempFile << "\n" << newData.Destination;
				tempFile << "\n" << newData.FlightClass;
				tempFile << "\n" << newData.FlightTime;
				tempFile << "\n" << newData.FlightAmount;
			}
		}
		read.close();
		tempFile.close();
		remove("record.txt");
		rename("temp.txt", "record.txt");
		cout << "\n\tData updated successfuly";
	}
	else {
		cout << "\n\tRecord not deleted";
	}
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
	int ColumnId = 0;
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
				//DIsplayCustomerChoice
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
			cout << setw(55) << "Log in sucessful" << endl<< endl << endl;
		system("cls");
			if (user_decision == 2)
			{
				ifstream read;
				read.open("columnid.txt");
				if (!read.fail()) {
					read >> ColumnId;
				}
				else {
					ColumnId = 0;
				}
				read.close();

				while (true) {
					showFlightDetailsMenu();
					int choice;
					cout << "\n\tEnter choice : ";
					cin >> choice;
					switch (choice) {
					case 1:
						ShowAddNewFlight();
						break;
					case 2:
						ReadFLightRecord();
						break;
					case 3:
						ShowDeleteFlight();
						break;
					case 4:
						ShowEditFlight();
						break;
					case 5:
						showAdminMenu();
						break;
					}
				}
			}
		}
		else
        {
            cout << "Invalid Input . . ." << endl;
            system("pause");
            system("cls");
            main();
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


