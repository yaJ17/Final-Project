#include <iostream>
#include <string>
#include<stdlib.h>
#include <iomanip>
using namespace std;
string destination, flightNum, flightName, timeDeparture, plane_class, email="", email_login="";
int user_decision, price, total, ticketCount,userChoice, seatAvailable;
float change, input_money, balance;
char option;
void showMainMenu()
{
    cout << "|------------------------------------|" << endl;
    cout << "|         T.I.P. QC AIRLINES         |" << endl;
    cout << "|------------------------------------|" << endl;
    cout << "|                                    |" << endl;
    cout << "|      [1] See Available Flights     |" << endl;
    cout << "|      [2] Check Your Flight Details |" << endl;
    cout << "|      [3] Change Flight             |" << endl;
    cout << "|      [4] Exit                      |" << endl;
    cout << "|                                    |" << endl;
    cout << "|                                    |" << endl;
    cout << "|                                    |" << endl;
    cout << "|------------------------------------|" << endl;
}
void showAvailableFlights()
{

	cout <<  "|----------------------------------------------------------------------------------------------------------------------|" << endl;
	cout <<  "| Flight Destination | Flight No.  | Flight Name  | Time of Departure | Class        |Price           |Seat Available  |" << endl;
    cout <<  "|----------------------------------------------------------------------------------------------------------------------|" << endl;
	cout <<  "|  South Korea    [1]|   001       |  SK001       | 0700h             | Economy      |  7,000 Php     |       0        |" << endl;
	cout <<  "|                 [2]|   002       |  SK002       | 1300h             | Premium Eco. |  10,000 Php    |       15       |" << endl;
	cout <<  "|----------------------------------------------------------------------------------------------------------------------|" << endl;
	cout <<  "|  Hongkong       [3]|   003       |  HK003       | 0900h             | Economy      |  10,000 Php    |       8        |" << endl;
	cout <<  "|                 [4]|   004       |  HK004       | 1500h             | Premium Eco. |  14,000 Php    |       24       |" << endl;
	cout <<  "|----------------------------------------------------------------------------------------------------------------------|" << endl;
	cout <<  "|  Japan          [5]|   005       |  JPN005       | 1000h            | Economy      |  20,000 Php    |       7        |" << endl;
	cout <<  "|                 [6]|   006       |  JPN006       | 1800h            | Premium Eco. |  30,000 Php    |       13       |" << endl;
    cout <<  "|----------------------------------------------------------------------------------------------------------------------|" << endl;
}
void displayFlight()
{
    cout << "Email : " << email;
    cout << "Destination: " << destination << endl;
    cout << "Flight Number: " << flightNum << endl;
    cout << "Flight Name: " << flightName << endl;
    cout << "Time of Departure: " << timeDeparture << endl;
    cout << "Class: " << plane_class << endl;
    cout << "Total Price: " << total << endl;
}
float getCustomerPay()
{
    cout << "The total is: " << total << endl;
    cout << "Enter your money here: ";
    cin >> input_money;
    if (input_money < 0)
    {
        cout << "You can't add negative value";
        system("pause");
        getCustomerPay();
    }
    else if (input_money >0 && input_money >= total)
    {
        change = input_money - total;
        cout << "The reservation is succesful" << endl;
        cout << "Your change is " << change << endl;
    }
    else if (input_money < total)
    {
        balance = total - input_money;
        while(balance < total)
        {
            cout << "You still have " << balance << endl;
            cout << "Enter your money here: ";
            cin >> balance;
            balance = balance + input_money;
        }
        if (balance >= total)
        {
            change = balance - total;
            cout << "The reservation is succesful" << endl;
            cout << "Your change is " << change << endl;
        }
    }
    else
    {
        cout << "Invalid input";
        system("pause");
        getCustomerPay();
    }
}
int getEmail()
{
        cout << "To Process the transcation please enter your G-mail here: ";
        cin >> email;
        email = userChoice;
        return userChoice;

}
void showChosenFlight()
{
    cout << "To confirm your choice " << endl;
    cout << "You choose " << "[" << user_decision <<"]" << endl;
    cout << "Destination: " << destination << endl;
    cout << "Flight Number: " << flightNum << endl;
    cout << "Flight Name: " << flightName << endl;
    cout << "Time of Departure: " << timeDeparture << endl;
    cout << "Class: " << plane_class << endl;
    cout << "Price: " << price << endl;
    cout << "How many tickets you would to buy? :";
    cin >> ticketCount;
    if (ticketCount <= seatAvailable)
    {
        total = price * ticketCount;
        cout << "The total amount is: " << total << endl << endl << endl;
        getEmail();
        getCustomerPay();
    }
    else
    {
        cout << "We only have " << seatAvailable <<  " seat left" << endl;
        system("pause");
        system("cls");
    }

}
void Menu()
{
     system("cls");
        showAvailableFlights();
        cout << "Enter your choice here: (Example Input '1') " ;
        cin >> user_decision;
        if (user_decision == 1)
        {
            destination = "South Korea";
            flightNum ="001";
            flightName ="SK001";
            timeDeparture ="0700h";
            plane_class = "Economy";
            price = 7000;
            seatAvailable = 0;
            showChosenFlight();
            user_decision = userChoice;
        }
        else if (user_decision == 2)
        {
            destination = "South Korea";
            flightNum ="002";
            flightName ="SK002";
            timeDeparture ="1300h";
            plane_class = "Premium Economy";
            price = 10000;
            seatAvailable = 15;
            showChosenFlight();
            user_decision = userChoice;
        }
        else if (user_decision == 3)
        {
            destination = "Hongkong";
            flightNum ="003";
            flightName ="HK003";
            timeDeparture ="0900h";
            plane_class = "Economy";
            price = 10000;
            seatAvailable = 8;
            showChosenFlight();
            user_decision = userChoice;
        }
        else if (user_decision == 4)
        {
            destination = "Hongkong";
            flightNum ="004";
            flightName ="HK004";
            timeDeparture ="1500h";
            plane_class = "Premium Economy";
            price = 14000;
            seatAvailable = 24;
            showChosenFlight();
            user_decision = userChoice;
        }
        else if (user_decision == 5)
        {
            destination = "Japan";
            flightNum ="005";
            flightName ="JPN005";
            timeDeparture ="1000h";
            plane_class = "Economy";
            price = 20000;
            seatAvailable = 7;
            showChosenFlight();
            user_decision = userChoice;
        }else if (user_decision == 6)
        {
            destination = "Japan";
            flightNum ="006";
            flightName ="JPN006";
            timeDeparture ="1800h";
            plane_class = "Premium Economy";
            price = 30000;
            seatAvailable = 13;
            showChosenFlight();
            user_decision = userChoice;
        }
}
int main()
{
    showMainMenu();
    cout << "Enter your choice here: (Example Input '1') " ;
    cin >> user_decision;
    if (user_decision == 1)
    {
        system("cls");
        showAvailableFlights();
        Menu();
    }
    else if (user_decision ==2)
    {
        cout << "To check your flight please enter the email you provided: ";
        cin >> email_login;
        if (email_login.compare(email))
        {
            displayFlight();
        }
        else
        {
            cout << "invalid email.";
        }

    }
    else if(user_decision == 3)
    {
        cout << "To check your flight please enter the email you provided: ";
        cin >> email_login;
        if (email_login.compare(email)==1)
        {
            cout << "Hello ";
            Menu();
        }
        else
        {
            cout << "Invalid Log in " << endl;
            system("pause");
            system("cls");
            main();
        }
    }
    else
    {
        //exit
        exit(0);
    }
    system("cls");
    main();
}
