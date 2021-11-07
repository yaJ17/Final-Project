#include <iostream>
#include<string>
#include<fstream>
using namespace std;
struct Flight{
     int ColumnId;
	 string FlightNum,FlightName,Destination,FlightTime,
     FlightAmount,FlightAvail,FlightFrom, FlightClass;
     char Choice;
};
void ShowAddNewFlight(ofstream &write) {
	Flight f1;
	cout << "\n\tEnter Column ID: ";
	cin >> f1.ColumnId;
	cout<<"Welcome To T.I.P. Airlines"<< endl;
            cout<<"Add Flight Record"<<endl;
            cout<<"Enter Flight No.: ";
            cin.get();
            getline(cin,f1.FlightNum);
            cout<<"Enter Flight Name: ";
            cin.get();
            getline(cin,f1.FlightName);
            cout<<"Enter Flight From: ";
            cin.get();
            getline(cin, f1.FlightFrom);
            cout<<"Enter Flight DEstination: ";
            cin.get();
            getline(cin,f1.Destination);
            cout<<"Enter Flight Time: ";
            cin.get();
            getline(cin, f1.FlightTime);
            cout<<"Enter Amount: ";
            cin.get();
            getline(cin,f1.FlightAmount);
            cout<<"Enter Flight Availability (A (Available)/ N (Not Available)): ";
            cin.get();
            getline(cin,f1.FlightAvail);
            cout<<"Successfully added in database."<<endl;

            write << f1.ColumnId<< endl <<f1.FlightNum<< endl <<f1.FlightName<< endl <<f1.Destination<< endl <<f1.FlightTime<< endl <<
          f1.FlightAmount<< endl <<f1.FlightAvail<< endl <<f1.FlightFrom<< endl <<f1.FlightClass;

	
}
Flight flightgetdata(ifstream &read) {
	Flight obj;
	        read >> obj.ColumnId;
	        read.get();
	        getline(read, obj.FlightName);
            cin.get();
            getline(cin,obj.FlightName);
            cin.get();
            getline(cin, obj.FlightFrom);
            cin.get();
            getline(cin,obj.Destination);
            cin.get();
            getline(cin, obj.FlightTime);
            cin.get();
            getline(cin,obj.FlightAmount);
            cin.get();
            getline(cin,obj.FlightAvail);
            cin.get();
            getline(cin,obj.FlightClass);
	        return obj;
}
void print_data(Flight f) {
    cout<<"|----------------------------------------------------------------------------|"<<endl;
    cout<<"| Column ID | Flight No. | Flight Name | From | Destination |  Class  | Time |"<<endl;
    cout<<"|----------------------------------------------------------------------------|"<<endl;
    cout<<f.ColumnId<<f.FlightNum<<f.FlightName<<f.FlightFrom<<f.Destination<<f.FlightClass<<f.FlightTime<<endl;
    cout<<"|----------------------------------------------------------------------------|"<<endl;
}
void showDeleteFlight(int ColumnId, ifstream &read) {
	//We get all data from our file i.e record.txt
	//We have to write data into temp file
	//We have to use rename and remove
	ofstream nf;
	nf.open("temp.txt");
	Flight f1;
	f1 = flightgetdata(read);
	while (!read.eof()) {
		//There we delete record
		if (f1.ColumnId != ColumnId) {
			nf << f1.ColumnId<< endl <<f1.FlightNum<< endl <<f1.FlightName<< endl <<f1.Destination<< endl <<f1.FlightTime<< endl <<
          f1.FlightAmount<< endl <<f1.FlightAvail<< endl <<f1.FlightFrom<< endl <<f1.FlightClass;
		}
		f1 = flightgetdata(read);
	}

	nf.close();
	read.close();

	remove("record.txt");
	rename("temp.txt", "record.txt");
}

void showEditFlight(int ColumnId, ifstream &read) {
	ofstream write("temp1.txt");
	Flight f;
	f = flightgetdata(read);
	while (!read.eof()) {
		//Update data
		if (f.ColumnId == ColumnId) {
			cout << "\n\tEnter a Column Id: " << ColumnId;
			ShowAddNewFlight(write);
		}
		else {
write << f.ColumnId<< endl <<f.FlightNum<< endl <<f.FlightName<< endl <<f.Destination<< endl <<f.FlightTime<< endl <<
          f.FlightAmount<< endl <<f.FlightAvail<< endl <<f.FlightFrom<< endl <<f.FlightClass;
 
		}
	f = flightgetdata(read);
	}

	write.close();
	read.close();
	remove("record.txt");
	rename("temp1.txt", "record.txt");
}