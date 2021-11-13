#include <iostream>
using namespace std;

class Banking{
    
    int PIN;
    float acc_balance;
    public:
   
    Banking(int p,float b){
        PIN=p;
        acc_balance=b;
    }
    int getPIN(){
        return PIN;
    }
    float check_balance(){
        return acc_balance;
    }

    void deposit(float dVal){
        acc_balance+=dVal;
        cout<<"\nDeposit is done...";
    }
    
    void withdraw(float wAmt){
        
        if((acc_balance-wAmt)>=5000){
            acc_balance-=wAmt;
            cout<<"\nWithdrawl is done...";
        }
        else
            cout<<"Insufficient balance.";
    }
};

 


int main()
{
    Banking b(445236,10000);
    int pin_val,inp_count=1,trans_num;
    float amt;
    char contOp;
    while(1){
    cout<<"Enter the PIN value: ";
    cin>>pin_val;
    inp_count++;
    if(inp_count>3 || pin_val==b.getPIN())
        break;
    cout<<endl;
    }
    if(pin_val==445236){
        while(1) {
            cout<<"1. Check Balance"<<endl;
            cout<<"2. Deposit"<<endl;
            cout<<"3. Withdraw"<<endl;
            cout<<"4. Exit"<<endl;
            cout<<"Enter Transaction Number Here: ";
            cin>>trans_num;
            switch(trans_num){
                case 1:
                cout<<"\nAvailable Balance: "<<b.check_balance();
                break;
                case 2:
                cout<<"\nEnter amount: ";
                cin>>amt;
                if(amt>0)
                    b.deposit(amt);
                else
                    cout<<"\nAmount should be positive.";
                break;
                case 3:
                cout<<"\nEnter amount: ";
                cin>>amt;
                if(amt>0)
                    b.withdraw(amt);
                else
                    cout<<"\nAmount should be positive.";
                break;
                case 4:
                exit(0);
                break;
                default:
                cout<<"Invalid transaction number.";
                break;
            } // end switch
        cout<<"\nDo you want to continue?\n[Y or y] Yes\n[N or n] No"<<endl;
        cout<<"Enter Here: ";
        cin>>contOp;
        if(contOp=='N' || contOp=='n'){
            cout<<"\nThank you for using this system… Have a great day!";
            break;
        }
        }//end while 
    } //end if block
    return 0;
}


