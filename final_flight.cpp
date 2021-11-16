#include <iostream>
#include <string>
#include<stdlib.h>
#include <iomanip>
using namespace std;
string destination, flightNum, flightName, timeDeparture, plane_class, email="", email_login="";
int user_decision, price, total, ticketCount,userChoice, seatAvailable, nDiscount;
float change, input_money, balance=0, discount;
char option;
int seatAvailable1 = 0, seatAvailable2 = 15, seatAvailable3 = 8, seatAvailable4 = 24, seatAvailable5 = 7, seatAvailable6 = 13;
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
    //0 15 8 24 7 13
	cout <<  "|----------------------------------------------------------------------------------------------------------------------|" << endl;
	cout <<  "| Flight Destination | Flight No.  | Flight Name  | Time of Departure | Class        |Price           |Seat Available  |" << endl;
    cout <<  "|----------------------------------------------------------------------------------------------------------------------|" << endl;
	cout <<  "|  South Korea    [1]|   001       |  SK001       | 0700h             | Economy      |  7,000 Php     |       "<<seatAvailable1 << "        |" << endl;
	cout <<  "|                 [2]|   002       |  SK002       | 1300h             | Premium Eco. |  10,000 Php    |       "<<seatAvailable2 << "       |" << endl;
	cout <<  "|----------------------------------------------------------------------------------------------------------------------|" << endl;
	cout <<  "|  Hongkong       [3]|   003       |  HK003       | 0900h             | Economy      |  10,000 Php    |       "<<seatAvailable3 << "        |" << endl;
	cout <<  "|                 [4]|   004       |  HK004       | 1500h             | Premium Eco. |  14,000 Php    |       "<<seatAvailable4 << "       |" << endl;
	cout <<  "|----------------------------------------------------------------------------------------------------------------------|" << endl;
	cout <<  "|  Japan          [5]|   005       |  JPN005       | 1000h            | Economy      |  20,000 Php    |       "<<seatAvailable5 << "        |" << endl;
	cout <<  "|                 [6]|   006       |  JPN006       | 1800h            | Premium Eco. |  30,000 Php    |       "<<seatAvailable6 << "       |" << endl;
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
        cout << "You cannot input negative value." << endl;
        system("pause");
        getCustomerPay();
    }
    else if(input_money > 0)
    {
        if (input_money >= total)
        {
            change = input_money - total;
            cout << "The reservation is succesful" << endl;
            cout << "Your change is " << change << endl;
        }
        else if (input_money < total)
        {
            balance = total - input_money;
            while (total > balance && balance!=0 && balance >0)
            {
                cout << "You still have " << balance << " to pay" <<  endl;
                cout << "Input your money here: ";
                cin >> input_money;
                balance = balance - input_money;
                input_money+= input_money;
            }
            if ( balance <0 || balance ==0)
            {
                if (balance ==0)
                {
                    cout << "The reservation is succesful" << endl;
                }
                else
                {
                change = total - input_money;
                cout << "The reservation is succesful" << endl;
                cout << "Your change is " << change << endl;
                }
            }
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
    if (ticketCount <0)
    {
        cout << "You cannot input negative value." << endl;
        system("pause");
        showChosenFlight();
    }
    else if (ticketCount <= seatAvailable)
    {
        total = price * ticketCount;
        if (user_decision ==1)
        {
            seatAvailable1 -=ticketCount;
        }
        else if(user_decision==2)
        {
            seatAvailable2 -=ticketCount;
        }
        else if(user_decision==3)
        {
            seatAvailable3 -=ticketCount;
        }
        else if(user_decision==4)
        {
            seatAvailable4 -=ticketCount;
        }
        else if(user_decision==5)
        {
            seatAvailable5 -=ticketCount;
        }
        else if(user_decision==6)
        {
            seatAvailable6 -=ticketCount;
        }
        cout << "The total amount is: " << total << endl << endl << endl;
        getEmail();
        cout << "To avail the discounted price for PWD/Senior Citizen press [1] if not press [2]" << endl;
        cin >> user_decision;
        if (user_decision ==1)
        {
            cout << "Enter the number of PWDs/Senior Citizen: ";
            cin >> nDiscount;
            if (nDiscount > 0)
            {
                ticketCount -= nDiscount;
                discount = nDiscount * (price * 0.2);
                total -= discount;
                getCustomerPay();
            }
            else
            {
                cout << "You cannot input negative value" << endl;
                system("pause");
                showChosenFlight();
            }

        }
        else if (user_decision ==2)
        {
            getCustomerPay();
        }
        else
        {
            cout << "Invalid Input." << endl;
            system("pause");
            showChosenFlight();
        }

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
            seatAvailable = seatAvailable1;
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
            seatAvailable = seatAvailable2;
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
            seatAvailable = seatAvailable3;
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
            seatAvailable = seatAvailable4;
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
            seatAvailable = seatAvailable5;
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
            seatAvailable = seatAvailable6;
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
        if (email_login.compare(email))
        {
            Menu();
        }
    }
    else
    {
        //exit
        exit(0);
    }
    system("pause");
    system("cls");
    main();
}
