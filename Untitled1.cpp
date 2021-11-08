#include <iostream>
using namespace std;
string name [20];
int code [20];
float price[20];
int z=0;
void itemAdd();
void itemDelete();
void itemSell();
void itemDisplay();

void itemAdd(){
	system("cls");
	cout<< "\nEnter the item name: ";
	cin>> name[z];
		cout<< "\nEnter the item code: ";
	cin>> code[z];
		cout<< "\nEnter the price of the Item: ";
	cin>> price[z];
	z++;
	cout<<"NEW Item Added..."<< endl;
	system ("pause");
	cin.get();
	system("cls");
}
void itemDelete(){
	int i,j;
	system("cls");
	cout<<"\nPlease enter the item code: ";
	cin>>i;
	if (z!=0){
		for (j=0;j<z;j++){
			if(code[j]==i)
			name[j]=" ";
			code [j]=0;
			price[j]=0;
			cout<< "\nThe item is deleted from the list"<<endl;
			break;
			system("pause");
			cin.get();}
		}
			else{
		cout<< "Nothing to delete..."<< endl;
	}
	system ("pause");
	cin.get();
	system("cls");
	}

void itemSell (){
	char a;
	int i,j;
	float total_price=0;
	system("cls");
	if(z!=0){
		cout<<"\nEnter the item code: ";
		cin>>i;
		for (j=0;j<z;j++){
			if (code[j]==i){
				if(price[j]==0){
					cout<<"\nSorry, There is no item left in this cafetory."<<endl;
					cout<< "\nDo you want to buy another item(y/n)?: "<endl;
					cin>>a;
					if (a=='Y'|| a=='y'){
						cout"\nEnter the item code: ";
						cin>>i;
						j=-1;}
					}
					else{
						if (total_price!=0){
							cout<<"\nYour total price is: ";
							cout<<total_price<<" pesos."<<"\nThank you.";}
							cout<<"GoodBye... Have a nice day...";
							break;
						}
					}
					else{
						cout<<"\nItem name is: "<< name[j];
						cout<<"\nItem price is: "<< price[j]<<" pesos."<endl;
						total_price+=price[j];
						price[j]=0;
						cout<<"\nDo you want to buy another item (y/n): "d;					}
				}
			}
		}


