#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;
// This is the main menu for the program
    int user_decision, FlightPrice, TicketCount;
    char Choice,delchoice,ChoiceEdit,LAchoice;
    string FlightNum,FlightName,Destination,FlightTime,FlightAmount,FlightAvail,FlightFrom, FlightClass;
    string ColumnId,Editflightno,Editflightname,EditFlightFrom,EditDestination,Editflighttime,Editamount;
    string FlightLeave,FlightArrive,FlightlaAvail,LAcolumnid;
    string DelColumnid,Delconfirmation;
//Table MaxRow
const int maxrow= 10;



     // Store Variables
    string storeColumnId = " ";
    string storeFlightNo = " ";
    string storeFlightName = " ";
    string storeFlightFrom = " ";
    string storeFlightDestination = " ";
    string storeFlightTime = " ";
    string storeFlightAmount = " ";
    string storeUserTripPlan2d[500][500];
    int storeIndex1 = 0, storeIndex2 = 0;
    // Variables End

void showMenu()
{
        cout << setw (70) << "*******************************" << endl;
        cout << setw (70) << "*           WELCOME           *" << endl;
        cout << setw (70) << "*             TO              *" << endl;
        cout << setw (70) << "*       T.I.P. AIRLINES       *" << endl;
        cout << setw (70) << "===============================" << endl;
        cout << setw (70) << "*                             *" << endl;
        cout << setw (70) << "*                             *" << endl;
        cout << setw (70) << "*                             *" << endl;
        cout << setw (70) << "*                             *" << endl;
        cout << setw (70) << "*          [1] Customer       *" << endl;
        cout << setw (70) << "*          [2] Admin          *" << endl;
        cout << setw (70) << "*                             *" << endl;
        cout << setw (70) << "*                             *" << endl;
        cout << setw (70) << "*******************************" << endl;


}
// to show the customer menu
void showCustomerMenu()
{
        cout << setw (70) << "|-------------------------------------|" << endl;
        cout << setw (70) << "|                                     |" << endl;
        cout << setw (70) << "|                                     |" << endl;
        cout << setw (70) << "|                                     |" << endl;
        cout << setw (70) << "|       [1] Book Flight               |" << endl;
        cout << setw (70) << "|       [2] Check Flight Details      |" << endl;
        cout << setw (70) << "|       [3] Cancel Flight             |" << endl;
        cout << setw (70) << "|       [4] Exit                      |" << endl;
        cout << setw (70) << "|                                     |" << endl;
        cout << setw (70) << "|                                     |" << endl;
        cout << setw (70) << "|-------------------------------------|" << endl;
}
//Book flights menu
void showAdminMenu()
{
        cout << setw (70) << "|-------------------------------------|" << endl;
        cout << setw (70) << "|                                     |" << endl;
        cout << setw (70) << "|                                     |" << endl;
        cout << setw (70) << "|                                     |" << endl;
        cout << setw (70) << "|       [1] Display Passenger         |" << endl;
        cout << setw (70) << "|       [2] Flight Details            |" << endl;
        cout << setw (70) << "|       [3] Exit                      |" << endl;
        cout << setw (70) << "|                                     |" << endl;
        cout << setw (70) << "|                                     |" << endl;
        cout << setw (70) << "|-------------------------------------|" << endl;
}
//To Show Admin menu
void showFlightDetailsMenu()
{
        cout << setw (70) << "|-------------------------------------|" << endl;
        cout << setw (70) << "|                                     |" << endl;
        cout << setw (70) << "|                                     |" << endl;
        cout << setw (70) << "|                                     |" << endl;
        cout << setw (70) << "|       [1] Add Flight                |" << endl;
        cout << setw (70) << "|       [2] Delete Flight             |" << endl;
        cout << setw (70) << "|       [3] Edit Flight               |" << endl;
        cout << setw (70) << "|       [4] Flight Leave and Arrive   |" << endl;
        cout << setw (70) << "|       [5] Back To Main Menu         |" << endl;
        cout << setw (70) << "|                                     |" << endl;
        cout << setw (70) << "|                                     |" << endl;
        cout << setw (70) << "|-------------------------------------|" << endl;
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
void FlightRecord(){
    int counter =0;
    cout<<setw(80)<<"|------------------------------------------------------------------|"<<endl;
    cout<<setw(80)<<"| Column ID | Flight No. | Flight Name | From | Destination | Time |"<<endl;
    cout<<setw(80)<<"|------------------------------------------------------------------|"<<endl;
   
void showAddNewFlight(){
     //Add Flight
      cout<<"Welcome To T.I.P. Airlines"<< endl;
            cout<<"Add Flight Record"<<endl;
                FlightRecord();
            cout<<"Enter Flight No.: ";
            getline(cin,FlightNum);
            cout<<"Enter Flight Name: ";
            getline(cin,FlightName);
            cout<<"Enter Flight From: ";
            getline(cin, FlightFrom);
            cout<<"Enter Flight DEstination: ";
            getline(cin,Destination);
            cout<<"Enter Flight Time: ";
            getline(cin, FlightTime);
            cout<<"Enter Amount: ";
            getline(cin,FlightAmount);
            cout<<"Enter Flight Availability (A (Available)/ N (Not Available)): ";
            getline(cin,FlightAvail);
            cout<<"Successfully added in database."<<endl;
            cout<<"Press 'M' to go back to Main Menu / 'A' to Insert Again (Press Any Key to Exit): ";
            cin >> Choice;
                if (Choice =='M'||Choice =='m'){
                    //Return to Admin Main Menu
                  showAdminMenu();
                }
                 else{
                //Exit Program
                cout << " exit";
                }
                while(Choice =='A'||Choice =='a'){
                    //Add more Flight
                    showAddNewFlight();
                }

}
void showEditFlight(string search){
    int counter;
             system("cls");
            cout<<"Welcome To T.I.P. Airlines"<< endl;
            cout<<"Edit Flight Record"<<endl;
            //Edit Flight
            FlightRecord();

            cout<<"Enter Column ID you wish to change: ";
            getline(cin, ColumnId);
                if (ColumnId == search){
                    counter++;
                
            cout<<"Enter Flight No. (X to not Change): ";
            getline(cin, Editflightno);
                if (Editflightno=="X"){
                    Editflightno=storeFlightNo;
                }
            cout<<"Enter Flight Name (X to not Change): ";
            getline(cin, Editflightname);
            if (Editflightname=="X"){
                    Editflightname=storeFlightName;
                }
            cout<<"Enter Flight From (X to not Change): ";
            getline(cin, EditFlightFrom);
            if (EditFlightFrom=="X"){
                    EditFlightFrom=storeFlightFrom;
                }
            cout<<"Enter Flight DEstination (X to not Change): ";
            getline(cin, EditDestination);
            if (EditDestination=="X"){
                    EditDestination=storeFlightDestination;
                }
            cout<<"Enter Flight Time (X to not Change): ";
            getline(cin, Editflighttime);
            if (Editflighttime=="X"){
                    Editflighttime=storeFlightTime;
                }
            cout<<"Enter Amount (X to not Change): ";
            getline(cin, Editamount);
            if (Editamount=="X"){
                    Editamount=storeFlightAmount;
                }
                }
            cout<<"Successfully added in database."<<endl;
            cout<<"Press 'M' to go back to Main Menu / 'E' to Edit Another (Press Any Key to Exit): ";
            cin>>LAchoice;
            if (LAchoice=='M'||LAchoice=='m'){
                    //Return to Admin Main Menu
                    showAdminMenu();
                }
                 else{
                    //Exit Program
                     cout << " exit";
                }
                while(LAchoice=='E'||LAchoice=='e'){
                    showEditFlight(search);
                }
}
void showDeleteFlight(){
            system("cls");
            cout<<"Welcome To T.I.P. Airlines"<< endl;
            cout<<"Delete Flight Record"<<endl;

            //Delete Flight
             FlightRecord();
            cout<<"Enter A Column ID you wish to delete: ";
            cin>>DelColumnid;
            cout<<"Are you sure? It will delete this record Y/N.: ";
            cin>>Delconfirmation;
            cout<<"Successfully Deleted from Database."<<endl;
            cout<<"Press 'M' to go back to Main Menu / 'D' to Delete Another (Press Any Key to Exit): ";
            cin>>delchoice;
            if (delchoice=='M'||delchoice=='m'){
                    //Return to Admin Main Menu
                    showAdminMenu();
                }
                else{
                    //Exit Program
                     cout << " exit";
                }
                while (delchoice=='D'||delchoice=='D'){
                    showDeleteFlight();
                }
}
void showFlightLeaveArrive(){
            system("cls");
            cout<<"Welcome To T.I.P. Airlines"<< endl;
            cout<<"Leave and Arrive Flight Record"<<endl;
            //Flight Leave and Arrive
             FlightRecord();

            cout<< "Enter Item Column ID: ";
            cin>> LAcolumnid;
             cout<<"Enter Flight No.: "<< FlightNum;
            cout<<"Enter Flight Name: "<< FlightName;
            cout<<"Enter Flight From: "<< FlightFrom;
            cout<<"Enter Flight DEstination: "<<Destination;
            cout<<"Enter Flight Time: " <<FlightTime;

             cout<<"Enter FLight Leave (X to not Change): ";
            getline(cin,FlightLeave);
            cout<<"Enter Flight Arrive (X to not Change): ";
            getline(cin,FlightArrive);
            cout<<"Enter Flight Destination (X to not Change): ";
            getline(cin,FlightlaAvail);
            cout<<"Successfully Saved in Database.";
             cout<<"Press 'M' to go back to Main Menu / 'E' to Edit Another (Press Any Key to Exit): ";
            cin>>LAchoice;
            if (LAchoice=='M'||LAchoice=='m'){
                    //Return to Admin Main Menu
                     showAdminMenu();
                }
                 else{
                    //Exit Program
                     cout << " exit";
                }

                while(LAchoice=='E'|| LAchoice=='e'){
                    showFlightLeaveArrive();
                }
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
    cout << "Total Ticket Price: " << FlightPrice *TicketCount << endl;
}
int main()
{

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
        if (user_decision ==1)
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
                    FlightTime = "0700h" ;
                    FlightClass = "Economy";
                    FlightPrice = 31000;
                    printFlightDetails();
                }
                else if (user_decision == 2)
                {
                    Destination = "South Korea";
                    FlightNum = "002";
                    FlightName = "SK02";
                    FlightTime = "1300h" ;
                    FlightClass = "Premium Economy";
                    FlightPrice = 39000;
                    printFlightDetails();
                }
                else if (user_decision == 3)
                {
                    Destination = "Hongkong";
                    FlightNum = "003";
                    FlightName = "HK003";
                    FlightTime = "0900h" ;
                    FlightClass = "Economy";
                    FlightPrice = 23000;
                    printFlightDetails();
                }
                else if (user_decision == 4)
                {
                    Destination = "Hongkong";
                    FlightNum = "004";
                    FlightName = "HK004";
                    FlightTime = "1500h" ;
                    FlightClass = "Premium Economy";
                    FlightPrice = 31000;
                    printFlightDetails();
                }
                else if (user_decision == 5)
                {
                    Destination = "Japan";
                    FlightNum = "005";
                    FlightName = "JP005";
                    FlightTime = "1000h" ;
                    FlightClass = "Economy";
                    FlightPrice = 32000;
                    printFlightDetails;
                }
                else if (user_decision == 6)
                {
                    Destination = "Japan";
                    FlightNum = "006";
                    FlightName = "JP006";
                    FlightTime = "1800h" ;
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
        else if(user_decision == 3)
        {
            cout << "3";
        }
        // Exit
        else if (user_decision == 4)
        {
            cout << "Thank you for using our service!" <<endl;
            cout << "Have a nice day!" <<endl;
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
    else if(user_decision == 2)
    {

        system("cls");
        showAdminMenu();
        cout << setw(65) << "Enter your choice here: ";
        cin >> user_decision;
        if(user_decision==1){

            //DisplayFlight();
        }
        else if (user_decision==2)
        {
             system("cls");
           showFlightDetailsMenu();
            if(user_decision==1)
        {
          showAddNewFlight();
        }
        else if (user_decision==2)
        {
           showDeleteFlight();
        }
        else if (user_decision==3)
        {
           showEditFlight();

        }
        else if (user_decision==4)
        {
            showFlightLeaveArrive();

        }
        else{
            //Invalid choice, Exit Program.
        }
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
