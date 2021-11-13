#include <iostream>
#include <fstream>
#include<string>
using namespace std;
int ColumnId;
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
	Flight f1;
	ifstream read;
	read.open("record.txt");
	while (!read.eof()) {
		read >> f1.ColumnId;
		read >> f1.FlightNum;
		read.ignore();
		getline(read, f1.FlightName);
		read.ignore();
		getline(read, f1.FlightFrom);
		read.ignore();
		getline(read, f1.Destination);
		read.ignore();
		getline(read, f1.FlightClass);
		read >> f1.FlightTime;
		read >> f1.FlightAmount;
		DisplayFlightRecord(f1);
	}
	read.close();
}

int SearchFlightRecord() {
	int ColumnId;
	cout << "\n\tEnter Column ID you want to search: ";
	cin >> ColumnId;
	Flight f1;
	ifstream read;
	read.open("record.txt");
	while (!read.eof()) {
		read >> f1.ColumnId;
		read >> f1.FlightNum;
		read.ignore();
		getline(read, f1.FlightFrom);
		read >> f1.FlightAmount;
		read.ignore();
		getline(read, f1.Destination);
		read >> f1.FlightTime;
		read.ignore();
		getline(read, f1.FlightClass);

		if (f1.ColumnId == ColumnId) {
			DisplayFlightRecord(f1);
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
		Flight f1;
		ofstream tempFile;
		tempFile.open("temp.txt");
		ifstream read;
		read.open("record.txt");
		while (!read.eof()) {
			read >> f1.ColumnId;
			read >> f1.FlightNum;
			read.ignore();
			getline(read, f1.FlightName);
			read.ignore();
			getline(read, f1.FlightFrom);
			read.ignore();
			getline(read, f1.Destination);
			read.ignore();
			getline(read, f1.FlightClass);
			read >> f1.FlightTime;
			read >> f1.FlightAmount;

			if (f1.ColumnId != ColumnId) {
				tempFile << "\n" << f1.ColumnId;
				tempFile << "\n" << f1.FlightNum;
				tempFile << "\n" << f1.FlightName;
				tempFile << "\n" << f1.FlightFrom;
				tempFile << "\n" << f1.Destination;
				tempFile << "\n" << f1.FlightClass;
				tempFile << "\n" << f1.FlightTime;
				tempFile << "\n" << f1.FlightAmount;
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
		Flight f1;
		ofstream tempFile;
		tempFile.open("temp.txt");
		ifstream read;
		read.open("record.txt");
		while (!read.eof()) {
			read >> f1.ColumnId;
			read >> f1.FlightNum;
			read.ignore();
			getline(read, f1.FlightName);
			read.ignore();
			getline(read, f1.FlightFrom);
			read.ignore();
			getline(read, f1.Destination);
			read.ignore();
			getline(read, f1.FlightClass);
			read >> f1.FlightTime;
			read >> f1.FlightAmount;
			if (f1.ColumnId != ColumnId) {
				tempFile << "\n" << f1.ColumnId;
				tempFile << "\n" << f1.FlightNum;
				tempFile << "\n" << f1.FlightName;
				tempFile << "\n" << f1.FlightFrom;
				tempFile << "\n" << f1.Destination;
				tempFile << "\n" << f1.FlightClass;
				tempFile << "\n" << f1.FlightTime;
				tempFile << "\n" << f1.FlightAmount;
			}
			else {
				tempFile << "\n" << f1.ColumnId;
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

int main()
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
		cout << "\n\t1.Add student data";
		cout << "\n\t2.See student data";
		cout << "\n\t3.Search student data";
		cout << "\n\t4.Delete student data";
		cout << "\n\t5.Update student data";
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
			SearchFlightRecord();
			break;
		case 4:
			ShowDeleteFlight();
			break;
		case 5:
			ShowEditFlight();
			break;
		}
	}

}
