#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int menu;
void ChooseUser()
{
    cout<<"------------------------------------------------------"<<endl;
    cout<<"                 WELCOME TO T.I.P.                    "<<endl;
    cout<<"                      AIRLINE                         "<<endl;
    cout<<"------------------------------------------------------"<<endl;
    cout<<"                   [1] CUSTOMER                       "<<endl;
    cout<<"                   [2] ADMIN                          "<<endl;
    cout<<"------------------------------------------------------"<<endl<<endl;

    cout<<"Enter your choice";
    cin<< menu;


}
//CUSTOMER PART ----------------------------------------------------
int CID;
struct Customer
{
    int cid;
    string customername;
    int passportid;
    int age;
    string gender;
    string birthdate;
    string nationality;
}
void bookflight()
{
    Customer customer;
    int id;
    cout << "\n\tEnter Flight you want to book: ";
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
    cout<< "\n\tEnter your Name: ";
    cin.get();
    getline(cin,customer.customername);
    cout<< "\n\tEnter your Age: ";
    cin>> customer.age;
    cout<< "\n\tEnter your Gender: ";
    cin>> customer.gender;
    cout<< "\n\tEnter your Birthdate: ";
    cin>> customer.birthdate;
    cout<< "\n\tEnter your Nationality: ";
    cin>> customer.nationality;
    cout<< "\n\tEnter your Passport Number: ";
    cin>> customer.passportid;
    CID++;
    

     ofstream write;
    write.open("customerbookflight.txt", ios::app);
    write << "\n"
          << CID;
    write << "\n"<< customer.customername;
    write << "\n"<< customer.age;
    write << "\n"<< customer.gender;
    write << "\n"<< customer.birthdate;
    write << "\n"<< customer.nationality;
    write << "\n"<< customer.passportid;
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
    write.open("CID.txt");
    write>> CID;
    write.close();
    cout << "\n\tSuccessfully booked flight...";
}
void displayticketflight(Customer c)
{
   cout << "\n\tYour ticket Flight Information"<< endl;

cout<<"\n\tPassport Number: "<< c.passportid;
   cout<<"\n\tName: "<< c.customername;
   cout<<"\n\tAge: "<< c.age;
   cout<<"\n\tGender: "<< c.gender;
   cout<<"\n\tBirthdate: "<< c.birthdate;
   cout<<"\n\tNationality: "<< c.nationality<< endl;
   
    cout << "\n\tID: " << c.id;
    cout << "\n\tFlight Number: " << c.flightnum;
    cout << "\n\tFlight Name: " << c.flightname;
    cout << "\n\tFlight From: " << c.flightfrom;
    cout << "\n\tFlight Destination: " << c.destination;
    cout << "\n\tFlight Time: " << c.flighttime;
    cout << "\n\tFlight Class: " << c.flightclass;
    cout << "\n\nFlight Date: " << c.flightdate;
    cout << "\n\tFlight Amount: " << c.flightamount;
}

void readcustomer()
{
    Customer customer;
    ifstream read;
    read.open("customerbookflight.txt");
    while (!read.eof())
    {
    read.ignore();
    getline(read, customer.customername);
    read << customer.age;
    read << customer.gender;
    read << customer.birthdate;
    read << customer.nationality;
    read << customer.passportid;
        read >> customer.id;
        read >> customer.flightnum;
        read.ignore();
        getline(read, customer.flightname);
        read >> customer.flightfrom;
        read >> customer.destination;
        read >> customer.flighttime;
        read >> customer.flightclass;
        read >> customer.flightdate;
        read >> customer.flightamount;
        displayticketflight(customer);
    }
    read.close();
}
int searchticket()
{
    int passportid;
    cout << "\n\tEnter Flight ID: ";
    cin >> passportid;
    Customer customer;
    ifstream read;
    read.open("customerbookflight.txt");
    while (!read.eof())
    {
            read.ignore();
    getline(read, customer.customername);
    read << customer.age;
    read << customer.gender;
    read << customer.birthdate;
    read << customer.nationality;
    read << customer.passportid;
        read >> customer.id;
        read >> customer.flightnum;
        read.ignore();
        getline(read, customer.flightname);
        read >> customer.flightfrom;
        read >> customer.destination;
        read >> customer.flighttime;
        read >> customer.flightclass;
        read >> customer.flightdate;
        read >> customer.flightamount;
        if (customer.passportid == passportid)
        {
           displayticketflight(customer);
            return passportid;
        }
    }
}
void updatebookflight()
{
    int id = searchticket();
    cout << "\n\tYou want to change your info.? (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        Customer newdata;
    cout<< "\n\tEnter your Name: ";
    cin.get();
    getline(cin,customer.customername);
    cout<< "\n\tEnter your Age: ";
    cin>> customer.age;
    cout<< "\n\tEnter your Gender: ";
    cin>> customer.gender;
    cout<< "\n\tEnter your Birthdate: ";
    cin>> customer.birthdate;
    cout<< "\n\tEnter your Nationality: ";
    cin>> customer.nationality;
    cout<< "\n\tEnter your Passport Number: ";
    cin>> customer.passportid;
        Customer customer;
        ofstream tempFile;
        tempFile.open("tempcustomer.txt");
        ifstream read;
        read.open("customerbookflight.txt");
        while (!read.eof())
        {
         read.ignore();
         getline(read, customer.customername);
         read << customer.age;
         read << customer.gender;
         read << customer.birthdate;
         read << customer.nationality;
         read << customer.passportid;
         read >> customer.id;
          read >> customer.flightnum;
          read.ignore();
          getline(read, customer.flightname);
          read >> customer.flightfrom;
          read >> customer.destination;
         read >> customer.flighttime;
         read >> customer.flightclass;
          read >> customer.flightdate;
         read >> customer.flightamount;
            if (customer.id != id)
            {
                tempFile<< "\n"<<customer.customername;
                 tempFile<< "\n"<<customer.age;
                  tempFile<< "\n"<<customer.gender;
                   tempFile<< "\n"<<customer.birthdate;
                    tempFile<< "\n"<<customer.nationality;
                     tempFile<< "\n"<<customer.passportid;
                tempFile << "\n"
                         << customer.id;
                tempFile << "\n"
                         << customer.flightnum;
                tempFile << "\n"
                         << customer.flightname;
                tempFile << "\n"
                         << customer.flightfrom;
                tempFile << "\n"
                         << customer.destination;
                tempFile << "\n"
                         << customer.flighttime;
                tempFile << "\n"
                         << customer.flightclass;
                tempFile << "\n"
                         << customer.flightdate;
                tempFile << "\n"
                         << customer.flightamount;
            }
            else
            {
                tempFile<< "\n"<<newdata.customername;
                 tempFile<< "\n"<<newdata.age;
                  tempFile<< "\n"<<newdata.gender;
                   tempFile<< "\n"<<newdata.birthdate;
                    tempFile<< "\n"<<newdata.nationality;
                     tempFile<< "\n"<<newdata.passportid;
                tempFile << "\n"
                         << customer.id;
                tempFile << "\n"
                         << customer.flightnum;
                tempFile << "\n"
                         << customer.flightname;
                tempFile << "\n"
                         << customer.flightfrom;
                tempFile << "\n"
                         << customer.destination;
                tempFile << "\n"
                         << customer.flighttime;
                tempFile << "\n"
                         << customer.flightclass;
                tempFile << "\n"
                         << customer.flightdate;
                tempFile << "\n"
                         << customer.flightamount;
            }
        }
        read.close();
        tempFile.close();
        remove("customerbookflight.txt");
        rename("tempcustomer.txt", "customerbookflight.txt");
        cout << "\n\tInformation updated successfully";
    }
    else
    {
        cout << "\n\tRecord not deleted";
    }
}
//CUSTOMER PART ----------------------------------------------------

//ADMIN PART -------------------------------------------------------
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
//ADMIN PART -------------------------------------------------------
int main()
{
    ChooseUser();
    if (menu==1)
    {
  ifstream read;
    read.open("cid.txt");
    if (!read.fail())
    {
        read >> CID;
    }
    else
    {
        CID;
    }
    read.close();

    while (true)
    {
        cout << "\n\t1.book Flight data";
        cout << "\n\t2.Search Flight data";
        cout << "\n\t3.Update Flight data";

        int choice;
        cout << "\n\tEnter choice : ";
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
            updatebookflight();
            break;
        }
    }
    }
    else if (menu==2)
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
}

