/*
Find me at Social Platform :-

GitHub Account :-
https://github.com/usmanrajj

YouTube Channel :-
RAJJ YT	
https://www.youtube.com/channel/UCUBI4kNNtUJdxj_nxCFPURQ

Linked In Profile :-
https://www.linkedin.com/in/muhammad-usman-rajj-67802323a

Insta Account :-
https://www.instagram.com/usmanrajj0

TikTok Account :-
https://www.tiktok.com/@rajjyt0

Twitter Account :-
https://twitter.com/Rajj379
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
struct acc{
	int acc_no,amount;
	string f_name,l_name;
	acc *next;
	acc *prev;
};
int call();	
class bank{
	acc *account;
	acc *head;
	acc *tail;
public:
	bank(){
		head=NULL;
		tail=NULL;
	}
	void readfile();
	void n_acc();
	void Acc(acc* Receive);
	void dep(int Receive_Account_number);
	void wd(int Receive_Account_number);
	void remove(int Receive_Account_Number);
	void show_all_end();
	void show_all_top();
	void update_old_account(int Receive_Account_Number);
	int count();
	int check_account(int Receive_Account_Number);
	void update();
};
int main(){
	bank c1;
	char ch;
	do {
	c1.readfile();
	int temp=0,ACC=0;
	int index=call();
	switch (index){
	case 1:					// Create New Account
		system("CLS");
		cout<<"You Select Create New Account\n";
		c1.readfile();
		c1.n_acc();
		break;	
	case 2:					// Check Account
		system("CLS");
		cout<<"You Select Check Account\n";
		cout<<"Enter Account Number : ";
		cin>>ACC;
		c1.check_account(ACC);
		break;
	case 3:					//Deposite Cash
		system("CLS");
		cout<<"You Select Deposite Cash\n";
		cout<<"Enter Account Number : ";
		cin>>ACC;
		temp=c1.check_account(ACC);
		if (temp==1){
		c1.dep(ACC);
		c1.update();
		}
		break;
	case 4:					// Withdraw Cash
		system("CLS");
		cout<<"You Select WithDraw Cash\n";
		cout<<"Enter Account Number : ";
		cin>>ACC;
		temp=c1.check_account(ACC);
		if (temp==1){
		c1.wd(ACC);
		c1.update();
		}
		else
		cout<<"Invalid Account Number\n";
		break;
	case 5:					// Delete Account
		system("CLS");
		cout<<"You Select Delete Account\n";
		cout<<"Enter Account Number : ";
		cin>>ACC;
		temp=c1.check_account(ACC);
		if (temp==1)
		{
		cout<<"Press Y to Confirm to Delete this Account : ";
		cin>>ch;	
			if(ch=='Y'||ch=='y')
			{
			c1.remove(ACC);
			c1.update();
			}
		}
		break;
	case 6:					// Update Old Account
		system("CLS");
		cout<<"You Select Update Old Account\n";
		cout<<"Enter Account Number : ";
		cin>>ACC;
		temp=c1.check_account(ACC);
		if (temp==1)
		{
			c1.update_old_account(ACC);
			c1.update();
		}
		break;
	case 7:					// Total Accounts with Numbers
		system("CLS");
		cout<<"You Select Check Totsl Accounts with Numbers\n";
		c1.count();
		break;
	case 8:					// Check All details From End of List
		system("CLS");
		cout<<"Check All From Bottom To Top\n\n";
		c1.show_all_end();	
		break;
	case 9:					// Check All Details From Top of List
		system("CLS");
		cout<<"Check All From Top To Bottom\n\n";
		c1.show_all_top();		
		break;
	default:
		cout<<"Invalid Input! Enter Again :";
		index=call();
	}
	cout<<"Press Y to start Again This Program :)";
	cin>>ch;
	system("CLS");
}while(ch=='y'||ch=='Y');
}
int bank::count(){								// Done
	int i=0;
		acc *temp=head;
	while(temp!=NULL){
		cout<<++i<<" : Account No. "<<temp->acc_no<<endl;
		temp=temp->next;
		}
	cout<<"Total Accounts : "<<i<<endl;
	return i;
}
int bank::check_account(int account_no){		// Done
		acc *temp=head;
		int x=0;
	while(temp!=NULL){
		if (temp->acc_no==account_no)
		{
			system("CLS");
		cout<<"Account Found! : "<<endl;
		cout<<"Account No. : "<<account_no<<endl;
		cout<<"Account Holder : "<<temp->f_name<<" "<<temp->l_name<<endl;
		cout<<"Amount : "<<temp->amount<<endl;
		x=1;
		temp=NULL;
		}
		else
		temp=temp->next;
		}
		if (x==1){
		return 1;
		}
		else{
		cout<<"Record Not Found\n";
		return 0;
		}
}
void bank::dep(int account_no){					// Done
	acc *temp=head;
	while(temp!=NULL){
		if (temp->acc_no==account_no)
		{
			int cash;
		cout<<"Enter Cash : ";
		cin>>cash;
		if (cash>0){
			temp->amount=(temp->amount+cash);
			cout<<"Cash Deposite Successfully\n";
			temp=NULL;
			}
		else{
			cout<<"Invalid Cash, Please Enter Again : \n";
			}
		}
		else
		temp=temp->next;
		}
}
void bank::wd(int account_no){					// Done
	acc *temp=head;
	while(temp!=NULL){
		if (temp->acc_no==account_no)
		{
		int cash;
		cout<<"Enter Cash : ";
		cin>>cash;
		if (cash>=0&&cash<=temp->amount){
			temp->amount=temp->amount-cash;
			cout<<"Cash WithDraw Successfully\n";
			temp=NULL;
			}
		else
			cout<<"Invalid Cash, Please Enter Again : \n";
		}
		else
		temp=temp->next;
		}
}
void bank::show_all_top(){						// Done
	int id,pin,i=0;
	cout<<"Enter Manager ID : ";
	cin>>id;
	cout<<"Enter Pin : ";
	cin>>pin;
	if (id==786&&pin==0000)
	{	system("CLS");
		cout<<"Welcome : Bank Of Friends :) \n";
		acc *temp=head;
		if(head!=NULL)
		while(temp!=NULL){
		cout<<"\nDetail of Account "<<++i<<" :- \n";
		cout<<"Account No. : "<<temp->acc_no<<endl;
		cout<<"Account Holder : "<<temp->f_name<<" "<<temp->l_name<<endl;
		cout<<"Amount. : "<<temp->amount<<endl;
		temp=temp->next;
		}
		cout<<"Total Accounts : "<<i<<endl;
	}
	else
	cout<<"Invalid User id or Password (id:786 , Pass:0000)\n";
}
void bank::show_all_end(){						// Done
	int id,pin,i=0;
	cout<<"Enter Manager ID : ";
	cin>>id;
	cout<<"Enter Pin : ";
	cin>>pin;
	if (id==786&&pin==0000)
	{
	system("CLS");
		cout<<"Welcome : Bank Of Friends :) \n";
		acc *temp=tail;
	while(temp!=NULL){
		cout<<"\nDetail of Account "<<++i<<" :- \n";
		cout<<"Account No. : "<<temp->acc_no<<endl;
		cout<<"Account Holder : "<<temp->f_name<<" "<<temp->l_name<<endl;
		cout<<"Amount. : "<<temp->amount<<endl;
		temp=temp->prev;
		}
		cout<<"Total Accounts : "<<i<<endl;
	}
	else 
	cout<<"Invalid User id or Password (id:786 , Pass:0000)\n";	
}
void bank::remove(int acc_num){					// Done
	acc *temp=head;
	int x=0;
	while(temp!=NULL){
		if (temp->acc_no==acc_num)
		{
			if (head==temp)
			{
				if(head->next==tail){
				tail->prev=NULL;
				tail->next=NULL;
				head=tail;
				delete temp;
				temp=head;
				}
				else if(head==tail)
				{
				delete head;
				head=NULL;
				tail=NULL;
				temp=NULL;
				}
				else{
					head=head->next;
					head->prev=NULL;
					delete temp;
					temp=head;
				}
			}
			else if (tail==temp)
			{
				if(head->next==tail){
				tail->prev=NULL;
				tail->next=NULL;
				tail=head;
				delete temp;
				temp=tail;
				}
				else if(tail==head)
				{
				delete tail;
				head=NULL;
				tail=NULL;
				}
				else{
					tail=tail->prev;
					tail->next=NULL;
					delete temp;
					temp=tail;
				}
			}
			else{
				acc *helper;
				if (temp->next==tail){
					helper=temp->prev;
					tail->prev=helper;
					helper->next=tail;
					delete temp;
					temp=helper;
				}
				else if(temp->prev==head){
					helper=temp->next;
					head->next=helper;
					helper->prev=head;
					delete temp;
					temp=helper;
				}
				else if(temp->prev==head&&temp->next==tail){
					head->next=tail;
					tail->prev=head;
					delete temp;
					temp=head;
				}
				else{
					helper=temp->prev;
					temp->next->prev=helper;
					delete temp;
					temp=helper;
				}
			}
		}
		else
			temp=temp->next;
			}
	cout<<"Account Deleted Succesfully\n";
}
void bank::readfile(){							// Done
	ifstream fin;
	head=NULL;
	tail=NULL;
	fin.open("Accounts.csv",ios::in);
	string line;
while(getline(fin,line)){
	string temp="y_raaz_hai";
	istringstream iss(line);
	acc *readacc=new acc;
	iss>>readacc->acc_no;
	getline(iss,temp,',');

	iss>>readacc->f_name;
	getline(iss,temp,',');
	
	iss>>readacc->l_name;
	getline(iss,temp,',');
	iss>>readacc->amount;
	getline(iss,temp,',');
	Acc(readacc);
}
}
void bank::update(){							// Done
	ofstream fout;
	fout.open("Accounts.csv", ios::out);		
	acc* upload=head;
	while(upload!=NULL){
fout<<upload->acc_no<<" ,"<<upload->f_name<<" ,"<<upload->l_name<<" ,"<<upload->amount<<" \n";
	upload=upload->next;
}
}
void bank::Acc(acc* temp){						// Done Making all nodes runtime
	acc* newacc=new acc;
	newacc->acc_no=temp->acc_no;
	newacc->f_name=temp->f_name;
	newacc->l_name=temp->l_name;
	newacc->amount=temp->amount;
	newacc->next=NULL;
	newacc->prev=NULL;
	if (head==NULL){
	head=newacc;
	tail=newacc;
	tail->next=NULL;
	head->next=NULL;
	tail->prev=NULL;
	head->prev=NULL;
//	cout<<"Tail is Created\n";
	}
	else 
	{
	newacc->next=head;
	head->prev=newacc;
	if(head->next==NULL){
		head->next=tail;
		tail->prev=newacc;
		tail->next=NULL;
	}
	head=newacc;
	}
}
void bank::n_acc(){								// Done
	ofstream fout;
	acc* newacc=new acc;
	acc* test=head;
	newacc->next=NULL;
	newacc->prev=NULL;
	cout<<"Thank You For Choosing Friends Bank *_*\n";
	cout<<"Enter Account no. : ";
	cin>>newacc->acc_no;
	if (test!=NULL)
	{
	while(test!=NULL)
	{
	if(test->acc_no==newacc->acc_no){
		cout<<"Account number already exist try another number : ";
		cin>>newacc->acc_no;
		test=head;
	}
	else
	test=test->next;
	}
	}
	cout<<"Enter First Name : ";
	cin>>newacc->f_name;
	cout<<"Enter Last Name : ";
	cin>>newacc->l_name;
	cout<<"Enter Amount : ";
	cin>>newacc->amount;
	cout<<"\nAccount Created Successfully :)\n";
	if (head==NULL){
	fout.open("Accounts.csv", ios::out);		
	head=newacc;
	tail=newacc;
//	head->next=tail;
//	tail->prev=head;
	}
	else 
	{
	fout.open("Accounts.csv", ios::app);		
	newacc->next=head;
	head->prev=newacc;
	head=newacc;
	test=head;
	while(test!=NULL){
		if (test->next==NULL){
			tail=test;
		}
		test=test->next;
	}
	}// Now Enter Data in File
fout << newacc->acc_no<<" ,"<<newacc->f_name<<" ,"<<newacc->l_name<<" ,"<<newacc->amount<<" \n";
	}
void bank::update_old_account(int account_no){
	acc *temp=head;
	while(temp!=NULL){
		if(temp->acc_no==account_no){
		int x;
		cout<<"Press 1: Update First Name \n";
		cout<<"Press 2: Update Last Name \n";	
		cout<<"Press 3: Update Amount \n";	
		cout<<"Press Any Key to update All\n";
		cout<<"\nPlease Enter Number : ";
		cin>>x;
		cout<<"\n";
		switch(x){
			case 1:
			cout<<"Update First Name : ";
			cin>>temp->f_name;
			break;
			case 2:
			cout<<"Update Last Name : ";
			cin>>temp->l_name;
			break;
			case 3:
			cout<<"Update Amount : ";
			cin>>temp->amount;
			break;
			default:
			cout<<"Update First Name : ";
			cin>>temp->f_name;
			cout<<"Update Last Name : ";
			cin>>temp->l_name;
			cout<<"Update Amount : ";
			cin>>temp->amount;
			}
		cout<<"\nAccount Updated Successfully :)\n";
			}
		temp=temp->next;
	}
}
int call(){
	int x;
	cout<<"Press 1 : New Account \n";
	cout<<"Press 2 : Check Account \n";
	cout<<"Press 3 : Deposite Cash \n";
	cout<<"Press 4 : With Draw Cash \n";
	cout<<"Press 5 : Delete Account \n";
	cout<<"Press 6 : Update old Account\n";
	cout<<"Press 7 : Total Accounts with Numbers \n";
	cout<<"Press 8 : Show All Accounts Details from END (For Manager)\n";
	cout<<"Press 9 : Show All Accounts Details from TOP (For Manager)\n";	
	cout<<"\nPlease Enter Index : ";
	cin>>x;
	cout<<endl;
	return x;
}
