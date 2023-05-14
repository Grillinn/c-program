#include<iostream.h>	// for std. input/output 
#include<conio.h>		// for clrscr(), getch() functions
#include<string.h> 		// for string operations
#include<stdio.h> 		// for gets() function

/* CLASS DEFINITION */
class bank	
{
		long int accno;
		char name[20];
		char type; //no significance across the program
		float balance;
	public:
		bank()  //constructor to initialize null values
		{
			accno=0;
			strcpy(name,"NA");
			type=' ';
			balance=0;
		}
		long int returnacc();
		void deposit();
		void withdraw();
		void transfer();
		void openacc();
		void viewacc();
}c[5]; //global object array of size 5

/* DEFINITIONS OF MEMBER FUNCTIONS OF THE CLASS */
long int bank::returnacc()
{
	return accno;  //returns acc no of the object
}

void bank::deposit()
{
	float amt;
	cout<<"Enter amount: ";
	cin>>amt;
	balance+=amt;  //amt is added with existing balance
	cout<<"Rs. "<<amt<<" has been deposited to A/C No."<<returnacc();
	cout<<"\nCurrent Balance - Rs."<<balance;
	getch();
}

void bank::withdraw()
{
	float amt;
	cout<<"Enter amount: ";
	cin>>amt;
	if((balance-amt)>=5000)  //checks for minimum required balance of 5000
	{
		balance-=amt; //amt is subtracted from existing balance
		cout<<"Rs. "<<amt<<" has been withdrawn from A/C No."<<accno;
		cout<<"\nCurrent Balance: Rs."<<balance;
	}
	else
	cout<<"Sorry! Insufficient balance.";
	getch(); //works for both if & else
}

void bank::transfer()
{
	long int acno;
	float amt;
	int flag=1;
	cout<<"Enter A/C of receiver: ";
	cin>>acno;
	cout<<"Enter amount to be transferred: ";
	cin>>amt;
	if((balance-amt)>=5000)
	{
		for(int i=0; i<5; i++)
		{
			if(acno==c[i].returnacc())
			{
				flag=1;
				balance-=amt;	//amt subtracted from current user
				c[i].balance+=amt;	//amt added to receivers account
				cout<<"Rs."<<amt<<" has been transfered to "<<acno;
				cout<<"\nYour Current Balance: Rs."<<balance;
			}
		}
		if(flag==0)	cout<<"Account not found.";
	}
	else cout<<"Sorry! Insufficient Balance.";
	getch();
}

void bank::openacc()
{
	cout<<"A/C No.: ";
	cin>>accno;
	cout<<"Holder Name: ";
	gets(name);
	cout<<"A/C Type (S/C): ";
	cin>>type;
	cout<<"Opening Balance: ";
	cin>>balance;
	cout<<"The A/C of Mr./Mrs."<<name<<" has been opened.\n";
	getch();
}

void bank::viewacc()
{
	cout<<"\n\nAccount Details";
	cout<<"\n A/C No.: #"<<accno;
	cout<<"\n Holder Name: "<<name;
	cout<<"\n Type: "<<type;
	cout<<"\n Balance: "<<balance;
}


/* FUNCTION PROTOTYPES */
void createacc();
void login();
void manageacc(int);

/*	MAIN PROGRAM	*/
void main()
{
	int op;
	/* ADMIN AREA */
	do{
		clrscr();
		cout<<"E-BANKING PORTAL";
		cout<<"\n1. Open a New A/C \n2. Manage A/C \n0. Exit";
		cout<<"\nEnter Option: ";
		cin>>op;
		switch(op)
		{
			case 1: createacc(); break; //creates account
			case 2: login(); break;  //login to user area
			case 0: cout<<"Thank you for banking with us"; getch(); break;
			default: cout<<"Invalid Option. Try Again."; getch();
		}
	}while(op>0);
}

/* INTERFACE PROGRAMS */
void createacc()
{
	int n;
	clrscr();
	cout<<"No of Accounts to be created (<5): ";  
	cin>>n; //limited to 5 due to array size
	for(int i=0; i<n; i++)
	{
		cout<<endl;
		c[i].openacc();
	}

}

void login()	//LOGIN BY A/C NO
{
	clrscr();
	long int ac;
	int flag=0; //checks if a/c exists, false by default
	cout<<"Enter A/C No.: ";
	cin>>ac;
	for(int i=0; i<5; i++)
	{
		if(ac==c[i].returnacc())
		{
			manageacc(i);
			flag=1;
		}
	}
	if(flag==0) cout<<"Account Not Found. Try Again!.";
}

void manageacc(int i)	//USER PORTAL - AFTER LOGIN
{
	int op;
	clrscr();
	/* USER AREA */
	cout<<"E-BANKING PORTAL - USER SESSION";
	cout<<"\n1. Deposit \n2. Withdraw \n3. Transfer";
	cout<<"\n4. View A/C Details \n0. Logout";
	do{
		cout<<"\nEnter Option: ";
		cin>>op;
		switch(op)
		{
			case 1: c[i].deposit(); break;
			case 2: c[i].withdraw(); break;
			case 3: c[i].transfer(); break;
			case 4: c[i].viewacc(); break;
			case 0: cout<<"You have been sucessfully logged-out."; 
					getch(); break;
			default: cout<<"Invalid Option. Try Again."; getch();
		}
		cout<<endl;
	}while(op>0);
}
