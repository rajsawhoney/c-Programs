#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<string.h>
#include<stdio.h>
using namespace std;
const char* filename="RazzPvtBankLtd.txt";
class Account
{
    private:
	char name[30];
	char accNo[25];
	char mo_No[15];
	char accType[20];
	char loginPassword[40];
	long balance;
    public:
	void CreateNewAccount()
	{
	    int check=0;
	   cout<<endl<<"**Please fill up the following form correctly**"<<endl<<"1.Name:"<<endl<<"2.Contact No.:"<<endl<<"3.A/c No:"<<endl<<"4.A/c type:"<<endl<<"5.Initial Deposit(balance):"<<endl<<"6.LoginPassword:"<<endl;
	   cout<<"Enter Name: ";
	   cin>>name;
	   cout<<"Enter contact No.: ";
	   cin>>mo_No;
	   cout<<"Provide a new A/C No: ";
	   cin>>accNo;  //provided by banker
	   cout<<"Enter Account Type(current/saving/fixed): ";
	   cin>>accType;
	   cout<<"Enter the starting Balance: ";
	   cin>>balance;
	   cout<<"Supply a login password: ";
	   cin>>loginPassword;
	  while(check!=1)
	  {
	       char checkPass[40];
	   cout<<"Enter password again to confirm: ";
	   cin>>checkPass;
	   if(strcmp(loginPassword,checkPass)==0)
	       check=1;
	   else
	    {
	       cout<<"Password not matching with the previous one!!! "<<endl<<"Enter again correctly..."<<endl;
	       check=0;
	     }
	   }
     }
       void DisplayAccountInfo()
	 {
	    cout<<"Name: "<<name<<endl<<"Account No: "<<accNo<<endl<<"Account Type: "<<accType<<endl<<"Mob. No: "<<mo_No;
	 }
	 char* Get_loginPassword()
	  {
	    return loginPassword;
	  }
	  void Deposit()
	  {
	      double amount;
	      cout<<"Enter the Deposit amount: ";
	      cin>>amount;
	      balance+=amount;
	      //return balance; //Now update the new balance in file storage
	  }
	  void Withdraw()
	  {
	      double amount;
	      char confirm;
	      cout<<"Enter the Withdrawing amount: ";
	      cin>>amount;
	      if(amount>balance)
	      cout<<"Insufficient balance!!!";
	    else
	      {
		  balance-=amount;
		  if(strcmp(accType,"fixed")==0)
		  {
		      cout<<endl<<"Really sorry! We cannot proceed your request right now. The  fixed time has not been completed yet!! "<<endl;
		      balance+=amount;
		  }
		  if(strcmp(accType,"current")==0 && balance<10000)
		  {
		  cout<<"Your balance is less than the minimum balance i.e Rs 10000"<<endl<<"10% penalty will be imposed"<<endl<<"Would you like to continue anyway??(y/n): ";
		  cin>>confirm;
		  if(confirm!='y')
		  {
		  balance+=amount;
		  }
		  else
		  {
		  balance-=amount*0.1;
		  cout<<endl<<"Successfully withdrawn!"<<endl;
		  }
	  }
    }
 }
	  void ChangeloginPassword()
	  {
	      cout<<endl<<"Enter new and more secure loginPassword: ";
	      cin>>loginPassword;
	  }
	  void DisplayBalance()
	    {
	      cout<<endl<<"Your current balance is "<<balance;
	   }
};
void Menu1() // main menu
{
    cout<<endl<<"********Please Choose Option*********";
    cout<<endl<<"1--->Resister for a new A/C >";  //calls CreateNewAccount()
    cout<<endl<<"2--->Login the Existing Account";
    cout<<endl<<"3--->Exit";   //exit the program
    cout<<endl<<endl<<"******Its Razz Sawhoney Pvt Bank Ltd*******"<<endl<<endl;
 }
void Menu2() //Types of a/c
{
    cout<<endl<<"*******Select a/c type*******"<<endl;
    cout<<endl<<"1--->Current a/c";
    cout<<endl<<"2--->Saving a/c";
    cout<<endl<<"3--->Fixed a/c";
    cout<<endl<<"4--->Back"<<endl;
}
void Menu3() // common for all types of a/c
{
    cout<<endl<<"********Select your options*******"<<endl;
    cout<<endl<<"1--->Terms and Conditions";
    cout<<endl<<"2--->Req. documents";
    cout<<endl<<"3--->Register a/c";
    cout<<endl<<"4--->Back"<<endl;
}
void Menu4()  //After login
{
    cout<<endl<<"*********Menu*********";
    cout<<endl<<"1--->Deposit Amount";
    cout<<endl<<"2--->Withdraw Amount";
    cout<<endl<<"3--->Display Amount";
    cout<<endl<<"4--->Display Account Info.";
    cout<<endl<<"5--->Change loginPassword";
    cout<<endl<<"6--->Logout"<<endl<<endl;
}
void main()
{
    Account Apm,Atm;
    char option1,option2,option3,option4;
    char loginPass[40];
    fstream file;
    file.open(filename,ios::ate|ios::in|ios::out|ios::binary);
    clrscr();
 while(1)
 {
   Menu1();
   cin>>option1;
   switch(option1)
 {
       case '1':
       int check1=0,check2=0;
       while(check1!=1)
       {
       Menu2();
       cin>>option2;
       switch(option2)
       {
	   case '1':  // Current a/c
		 while(check2!=1)
		 {
		     Menu3();
		     cin>>option3;
		     switch(option3)
		     {
			 case '1':
				 cout<<endl<<"System under development!";
				 break;
			 case '2':
				 cout<<endl<<"1. Xerox copy original Citizenship";
				 cout<<endl<<"2.Digital photo(autosize)";
				 cout<<endl<<"etc...";
				 break;
			 case '3':
		    		Apm.CreateNewAccount();
				    file.clear();
				    file.seekp(0,ios::end);
				    file.write((char*)&Apm,sizeof(Apm));
				    cout<<endl<<"Congratulations! Your have successfully registered your Account";
			   	 check1=1;
				 break;
			 case '4':
			      check2=1;
			      break;
			 default:
			     cout<<endl<<"Invalid option";
		     }
		 }
		 break;
	   case '2':  // For saving a/c
		while(check2!=1)
		 {
		     Menu3();
		     cin>>option3;
		     switch(option3)
		     {
			 case '1':
				 cout<<endl<<"System under development!";
				 break;
			 case '2':
				 cout<<endl<<"1. Xerox copy original Citizenship";
				 cout<<endl<<"2.Digital photo(autosize)";
				 cout<<endl<<"etc...";
				 break;
			 case '3':
			 	  Apm.CreateNewAccount();
				   file.clear();
			 	  file.seekp(0,ios::end);
				   file.write((char*)&Apm,sizeof(Apm));
				   cout<<endl<<"Congratulations! Your have successfully registered your Account";
				   check1=1;
				 break;
			 case '4':
			      check2=1;
			      break;
			 default:
			     cout<<endl<<"Invalid option";
		     }
		 }
		break;
	   case '3':  // For fixed account
		 while(check2!=1)
		 {
		     Menu3();
		     cin>>option3;
		     switch(option3)
		     {
			 case '1':
				 cout<<endl<<"System under development!"<<endl;
				 break;
			 case '2':
				 cout<<endl<<"1. Xerox copy of original Citizenship";
				 cout<<endl<<"2.Digital photo(autosize)";
				 cout<<endl<<"3.etc..."<<endl;
				 break;
			 case '3':
			    	Apm.CreateNewAccount();
			 	   file.clear();
				    file.seekp(0,ios::end);
				    file.write((char*)&Apm,sizeof(Apm));
				    cout<<endl<<"Congratulations! Your have successfully registered your Account"<<endl;
				    check1=1;
				 break;
			 case '4':
			      check2=1;
			      break;
			 default:
			     cout<<endl<<"Invalid option";
		     }
		 }
		 break;
	   case '4':
	       check1=1;
	       break;
	   default:
	       cout<<endl<<"Invalid option";

	   }
       }
	   break;
	case '2':
	    int isFound;
	    int recordNo=0;
	    int check3=0;
	    cout<<"Please enter your login password: ";
	    cin>>loginPass;
	    file.seekg(0,ios::beg);
	    file.read((char*)&Atm,sizeof(Atm));
	    file.clear();
	    while(!file.eof())
	     {
	       recordNo++;
	      if(strcmp(Atm.Get_loginPassword(),loginPass)==0)
		{
		   cout<<endl<<"Record No. "<<recordNo;
		       cout<<endl<<"Successfully loginned!";
		       isFound=1;
		       break;
		}
		 else
		   {
		    isFound=0;
		   }
		   file.read((char*)&Atm,sizeof(Atm));
	     }
	     if(isFound==0)
		 cout<<endl<<"Wrong Password! please try again"<<endl;
	     if(isFound==1)
	      {
	      while(check3!=1)
		  {
		   Menu4();
		   cin>>option4;
		   switch(option4)
		  {
		     case '1':
	    	  int location=(recordNo-1)*sizeof(Atm);
 	         file.seekp(location,ios::beg);
   	       Atm.Deposit();
	          file.write((char*)&Atm,sizeof(Atm));
  	   	 cout<<endl<<"Successfully deposited!"<<endl;
			  Atm.DisplayBalance();
			  break;
		      case '2':
		      location=(recordNo-1)*sizeof(Atm);
	          file.seekp(location,ios::beg);
   	       Atm.Withdraw();
   	       file.write((char*)&Atm,sizeof(Atm));
			  Atm.DisplayBalance();
			  break;
		      case '3':
			  Atm.DisplayBalance();
			  break;
		      case '4':
			  Atm.DisplayAccountInfo();
			  break;
		      case '5':
			  location=(recordNo-1)*sizeof(Atm);
	    	  file.seekp(location,ios::beg);
   		  Atm.ChangeloginPassword();
	   	  file.write((char*)&Atm,sizeof(Atm));
		     cout<<endl<<"Your loginPassword successfully changed!!"<<endl;
	   	  check3=1;
			  break;
		      case '6':
			  check3=1;
			  break;
		      default:
		  cout<<"Invalid option!!";
		  }
		}
	  }
break;
   case '3':
	     exit(1);
   default:
	  cout<<"Invalid option selected!!";
      }
    }
}
