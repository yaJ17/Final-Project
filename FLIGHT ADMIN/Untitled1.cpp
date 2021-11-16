#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int ID;
struct Flight
{
    int id;
    string flightname;
    int flightnum;
    string flightfrom;
    string destination;
    string flighttime;
    string flightclass;
    int flightamount;
    string flightdate;
};

void addflight()
{
    Flight flight;
    cout << "\n\tEnter Flight No.: ";
    cin >> flight.flightnum;
    cout << "\n\tEnter Flight Name: ";
    cin.get();
    getline(cin, flight.flightname);
    cout << "\n\tEnter Flight From: ";
    cin >> flight.flightfrom;
    cout << "\n\tEnter Flight Destination: ";
    cin >> flight.destination;
    cout << "\n\tEnter Flight time: ";
    cin >> flight.flighttime;
    cout << "\n\tEnter a Class: ";
    cin >> flight.flightclass;
    cout << "\n\tEnter Flight Amount: ";
    cin >> flight.flightamount;
    cout << "\n\tEnter Flight Date: ";
    cin >> flight.flightdate;
    ID++;

    ofstream write;
    write.open("flightrecord.txt", ios::app);
    write << "\n"
          << ID;
    write << "\n"
          << flight.flightnum;
    write << "\n"
          << flight.flightname;
    write << "\n"
          << flight.flightfrom;
    write << "\n"
          << flight.destination;
    write << "\n"
          << flight.flighttime;
    write << "\n"
          << flight.flightclass;
    write << "\n"
          << flight.flightamount;
    write << "\n"
          << flight.flightdate;

    write.close();
    write.open("id.txt");
    write << ID;
    write.close();
    cout << "\n\tData save to file";
}

void printflight(Flight f)
{
    cout << "\n\tFlight Record";
    cout << "\n\tID: " << f.id;
    cout << "\n\tFlight Number: " << f.flightnum;
    cout << "\n\tFlight Name: " << f.flightname;
    cout << "\n\tFlight From: " << f.flightfrom;
    cout << "\n\tFlight Destination: " << f.destination;
    cout << "\n\tFlight Time: " << f.flighttime;
    cout << "\n\tFlight Class: " << f.flightclass;
    cout << "\n\nFlight Date: " << f.flightdate;
    cout << "\n\tFlight Amount: " << f.flightamount;
}

void readflight()
{
    Flight flight;
    ifstream read;
    read.open("flightrecord.txt");
    while (!read.eof())
    {
        read >> flight.id;
        read >> flight.flightnum;
        read.ignore();
        getline(read, flight.flightname);
        read >> flight.flightfrom;
        read >> flight.destination;
        read >> flight.flighttime;
        read >> flight.flightclass;
        read >> flight.flightdate;
        read >> flight.flightamount;
        printflight(flight);
    }
    read.close();
}

int searchflight()
{
    int id;
    cout << "\n\tEnter Flight ID: ";
    cin >> id;
    Flight flight;
    ifstream read;
    read.open("flightrecord.txt");
    while (!read.eof())
    {
        read >> flight.id;
        read >> flight.flightnum;
        read.ignore();
        getline(read, flight.flightname);
        read >> flight.flightfrom;
        read >> flight.destination;
        read >> flight.flighttime;
        read >> flight.flightclass;
        read >> flight.flightdate;
        read >> flight.flightamount;
        if (flight.id == id)
        {
            printflight(flight);
            return id;
        }
    }
}

void deleteflight()
{
    int id = searchflight();
    cout << "\n\tYou want to delete record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y')
    {
        Flight flight;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("flightrecord.txt");
        while (!read.eof())
        {
            read >> flight.id;
            read >> flight.flightnum;
            read.ignore();
            getline(read, flight.flightname);
            read >> flight.flightfrom;
            read >> flight.destination;
            read >> flight.flighttime;
            read >> flight.flightclass;
            read >> flight.flightdate;
            read >> flight.flightamount;

            if (flight.id != id)
            {
                tempFile << "\n"
                         << flight.id;
                tempFile << "\n"
                         << flight.flightnum;
                tempFile << "\n"
                         << flight.flightname;
                tempFile << "\n"
                         << flight.flightfrom;
                tempFile << "\n"
                         << flight.destination;
                tempFile << "\n"
                         << flight.flighttime;
                tempFile << "\n"
                         << flight.flightclass;
                tempFile << "\n"
                         << flight.flightdate;
                tempFile << "\n"
                         << flight.flightamount;
            }
        }
        read.close();
        tempFile.close();
        remove("flightrecord.txt");
        rename("temp.txt", "Flightrecord.txt");
        cout << "\n\tData deleted successfuly";
    }
    else
    {
        cout << "\n\tRecord not deleted";
    }
}

void updateflight()
{
    int id = searchflight();
    cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        Flight newdata;
        cout << "\n\tEnter Flight No.: ";
        cin >> newdata.flightnum;
        cout << "\n\tEnterFlight Name: ";
        cin >> newdata.flightname;
        cout << "\n\tEnter Flight From: ";
        cin >> newdata.flightfrom;
        cout << "\n\tEnter Flight Destination: ";
        cin >> newdata.destination;
        cout << "\n\tEnter Flight time: ";
        cin >> newdata.flighttime;
        cout << "\n\tEnter a Class: ";
        cin >> newdata.flightclass;
        cout << "\n\tEnter Flight Date: ";
        cin >> newdata.flightdate;
        cout << "\n\tEnter Flight Amount: ";
        cin >> newdata.flightamount;
        Flight flight;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("flightrecord.txt");
        while (!read.eof())
        {
            read >> flight.id;
            read >> flight.flightnum;
            read.ignore();
            getline(read, flight.flightname);
            read >> flight.flightfrom;
            read >> flight.destination;
            read >> flight.flighttime;
            read >> flight.flightclass;
            read >> flight.flightdate;
            read >> flight.flightamount;
            if (flight.id != id)
            {
                tempFile << "\n"
                         << flight.id;
                tempFile << "\n"
                         << flight.flightnum;
                tempFile << "\n"
                         << flight.flightname;
                tempFile << "\n"
                         << flight.flightfrom;
                tempFile << "\n"
                         << flight.destination;
                tempFile << "\n"
                         << flight.flighttime;
                tempFile << "\n"
                         << flight.flightclass;
                tempFile << "\n"
                         << flight.flightdate;
                tempFile << "\n"
                         << flight.flightamount;
            }
            else
            {
                tempFile << "\n"
                         << flight.id;
                tempFile << "\n"
                         << newdata.flightnum;
                tempFile << "\n"
                         << newdata.flightname;
                tempFile << "\n"
                         << newdata.flightfrom;
                tempFile << "\n"
                         << newdata.destination;
                tempFile << "\n"
                         << newdata.flighttime;
                tempFile << "\n"
                         << newdata.flightclass;
                tempFile << "\n"
                         << flight.flightdate;
                tempFile << "\n"
                         << newdata.flightamount;
            }
        }
        read.close();
        tempFile.close();
        remove("flightrecord.txt");
        rename("temp.txt", "flightrecord.txt");
        cout << "\n\tData updated successfuly";
    }
    else
    {
        cout << "\n\tRecord not deleted";
    }
}

int main()
{
    ifstream read;
    read.open("id.txt");
    if (!read.fail())
    {
        read >> ID;
    }
    else
    {
        ID;
    }
    read.close();

    while (true)
    {
        cout << "\n\t1.Add Flight data";
        cout << "\n\t2.See Flight data";
        cout << "\n\t3.Search Flight data";
        cout << "\n\t4.Delete Flight data";
        cout << "\n\t5.Update Flight data";

        int choice;
        cout << "\n\tEnter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addflight();
            break;
        case 2:
            readflight();
            break;
        case 3:
            searchflight();
            break;
        case 4:
            deleteflight();
            break;
        case 5:
            updateflight();
            break;
        }
    }
}
