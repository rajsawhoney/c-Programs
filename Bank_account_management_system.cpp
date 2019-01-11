//  Bank Account Management:  //

#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
double cbalance,sbalance;
class Account
{
    protected:
        char name[30];
        char accNo[25];
        char mo_No[15];
        char accType[20];
   public:
       void GetAccountInfo()
       {
           cout<<"Enter Name: ";
           cin>>name;
           cout<<"Enter contact No.: ";
           cin>>mo_No;
           cout<<"Enter Account No: ";
           cin>>accNo;
           cout<<"Enter Account Type: ";
           cin>>accType;
       }
       void DisplayAccountInfo()
       {
           cout<<"Name: "<<name<<endl<<"Account No: "<<accNo<<endl<<"Account Type: "<<accType<<endl<<"Mob. No: "<<mo_No;
       }
};
class CurrentAccount:public Account
{
   public:
       void DisplayBalance()
       {
           cout<<"Your current balance  is "<<cbalance;
       }
       void Deposit()
       {
           double amount;
           cout<<"Enter amount for deposit: ";
           cin>>amount;
           cbalance+=amount;
           DisplayBalance();
       }
       void Withdraw()
       {
           double amount;
           char choice;
           cout<<"Enter the withdrawing amount: ";
           cin>>amount;
           if(amount>cbalance)
               cout<<"You do not have sufficient balance!!" ;
           else
               {
                   cbalance-=amount;
                   DisplayBalance();
                   if(cbalance<10000)
                   {
                       cout<<"Your balance is less than fixed minimum i.e Rs 10000"<<endl<<"10% penalty will be imposed."<<endl<<"Would u like to continue anyway?(y/n) ";
                       cin>>choice;
                       if(choice=='n')
                           {
                           cbalance+=amount;
                           DisplayBalance();
                           }
                       else
                       {
                           cbalance-=amount*0.1;
                           DisplayBalance();
                       }
                           }
               }
       }
        
};
class SavingAccount:public Account
{
   public:
       void DisplayBalance()
       {
           cout<<endl<<"Your Current balance is "<<sbalance;
       }
       void Deposit()
       {
           double amount;
           cout<<"Enter deposit amount: ";
           cin>>amount;
           sbalance+=amount;
           DisplayBalance();
       }
       void Withdraw()
       {
           double amount;
           cout<<"Enter the withdrawing amount: ";
           cin>>amount;
           if(amount<sbalance)
           {
               sbalance-=amount;
               DisplayBalance();
           }
          else
          {
              cout<<"Insufficient balance!!";
              DisplayBalance();
          }
       }     
};
void Menu()
{
    cout<<endl<<"*********Menu*********";
    cout<<endl<<"1-->Create New Amount";
    cout<<endl<<"2-->Deposit Amount";
    cout<<endl<<"3-->Withdraw Amount";
    cout<<endl<<"4-->Display Amount";
    cout<<endl<<"5-->Display Account Info.";
    cout<<endl<<"6-->Exit";
}
int main()
{
    SavingAccount save;
    CurrentAccount current;
    char AccType;
    int option;
    cout<<"Enter account type: (c=current/s=saving)";
    cin>>AccType;
    if(AccType=='c')
    {
        while(1)
        {
            Menu();
            cin>>option;
            switch(option)
            {
                case 1:
                    current.GetAccountInfo();
                    cout<<"Enter the starting Balance: ";
           cin>>cbalance;
                    break;
                case 2:
                    current.Deposit();
                    break;
                case 3:
                    current.Withdraw();
                    break;
                case 4:
                    current.DisplayBalance();
                    break;
                case 5:
                    current.DisplayAccountInfo();
                    break;
               case 6:
                   exit(1);
               default:
                   cout<<"Invalid option!!!";
            }
        }
    }
else
{
    while(1)
    {
        Menu();
        cin>>option;
        switch(option)
        {
         case 1:
                    save.GetAccountInfo();
                    cout<<"Enter the starting Balance: ";
           cin>>sbalance;
                    break;
         case 2:
                    save.Deposit();
                    break;
                case 3:
                    save.Withdraw();
                    break;
                case 4:
                    save.DisplayBalance();
                    break;
                case 5:
                    save.DisplayAccountInfo();
                    break;
               case 6:
                   exit(1);
               default:
                   cout<<"Invalid option!!!";   
        }
    }
}
return 0;
}