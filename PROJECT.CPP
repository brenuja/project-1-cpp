#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
 class acc
 {
  int accno;
  char name[50];
  int amt;
   public:
    int view()
    {                                    //checks the account number
       return(accno);
    }
    void createacc()
    {
      cout<<"enter name: ";
      cin>>name;
      cout<<"enter account number: ";
      cin>>accno;
      cout<<"enter amount: ";
      cin>>amt;
      cout<<"\t\t\tAccount has been created successfully\t\t\t"<<endl;
    }
    void displayacc()
    {
      cout<<"account holder's name:"<<name<<endl;
      cout<<"account number:"<<accno<<endl;
      cout<<"balance amount:"<<amt<<endl<<endl;
    }
    void deposit()
     {
       int deposit;
       cout<<"deposit amount:";
       cin>>deposit;
       amt=amt+deposit;
       cout<<"total balance:"<<amt<<endl;
       cout<<"\t\t\tAMOUNT HAS BEEN SUCCESSFULLY DEPOSITED\t\t\t"<<endl;
      }
    void withdraw()
     {
       int withdraw;
       cout<<"withdraw amount:";
       cin>>withdraw;
       if(withdraw<=amt)
       {
	 amt=amt-withdraw;
	 cout<<"total balance:"<<amt<<endl;
	 cout<<"\t\t\tAMOUNT HAS BEEN DEDUCTED\t\t\t"<<endl;

       }
       else
	 cout<<"\t\tinsufficient funds\t\t"<<endl;
     }

 };

 void menu()
  {
   cout<<endl<<"1.Create new account:";
   cout<<endl<<"2.Deposit amount:";
   cout<<endl<<"3.withdraw amount:";
   cout<<endl<<"4.get details of particular account:";
   cout<<endl<<"5.get details of all accounts:";
   cout<<endl<<"6.exit"<<endl;
  }
 void main()
  {
    int x,i;
    acc a;
    clrscr();
    cout<<"\t\t\t\tBANKING SYSTEM\t\t\t\t\t";
      while(1)
	{
	  menu();
	  cout<<"enter your choice:";
	  cin>>x;
	  if(x==6)
	    {
	      exit(0);
	    }
	  else if(x==1)
	  {
		   a.createacc();
		   ofstream f;
		   f.open("info.dat",ios::app);
		   f.write((char*)&a, sizeof(a));
		   f.close();
		   a.displayacc();

	  }
	  else if(x==2)
	  {
		int z;

		ifstream i("info.dat",ios::binary|ios::in|ios::out);
		ofstream o("temp.dat",ios::binary|ios::app);
		cout<<"enter your account number";
		cin>>z;
		while(i.read((char*)&a, sizeof(a)))
		{
		  if(z==a.view())
		      a.deposit();
		  o.write((char*)&a, sizeof(a));
		}
		i.close();
		o.close();
		remove("Info.dat");
		rename("temp.dat","info.dat") ;


	}
	 else if(x==3)
	      {
		int z;
		ifstream i("info.dat",ios::binary|ios::in);
		ofstream o("temp.dat",ios::binary|ios::app);
		cout<<"enter your account number";
		cin>>z;
		while(i.read((char*)&a, sizeof(a)))
		{
		  if(z==a.view())
		      a.withdraw();
		  o.write((char*)&a, sizeof(a));
		}
		i.close();
		o.close();
		remove("Info.dat");
		rename("temp.dat","info.dat") ;

	       }

	 else if(x==4)
	      {
	       ofstream f;
	       int z;
	       cout<<"enter account number";
	       cin>>z;
	       if(z==a.view())
		a.displayacc();
		f.close();
	      }

	 else if(x==5)
	      {
		ifstream f;
		f.open("info.dat",ios::binary);
		cout<<"\t\t\t\tACCOUNT HOLDER LIST\t\t\t\t"<<endl;
		while(f.read((char*)&a, sizeof(a)))
		{
		 a.displayacc();
		}
		 f.close();
	      }
	 if(x>6)
	   cout<<"invaild choice";

      }
    getch();
}
