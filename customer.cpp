#include "customer.h"
#include <iostream>
using namespace std;

void customer::filing()
{
	ofstream fin;
	fin.open("Database.dat");
	if (fin.is_open())
	{
		cout << "First Name: ";
		cin >> fname;
		cout << "Last Name: " ;
		cin >> lname;
		cout << "ID number: " ;
		cin >> idnumber;
		cout << "Room type: " ;
		cin >> roomtype;
		cout << "Floor Number: " ;
		cin >> floornumber;
		cout << "Room Number: " ;
		cin >> roomnumber;
		cout << "Age: " ;
		cin >> age;
		cout << "Gender: " ;
		cin >> gender;
		calculatebill();
		cout << "Your bill is: " << bill << endl;
		cout << "Pay in advance or later ?" << endl;
		cin >> inp;
		if (inp == bal1)
		{
			cout << "Balance: " ;
			cin >> balance;

			if (bill > balance)
			{
				cout << "Your balance is " << bill - balance;
			}
			else if (bill == balance)
			{
				balance = 0;
			}
			else
			{
				cout << "Your change: " << balance - bill;
			}
		}
		else
		{
			balance = bill;
		}
		cout << "Days to reserve: " << endl;
		cin >> daystoreserve;

		
		fin << endl;
		fin.close();
	}
	else
	{
		cout << "File not found." << endl;
	}
}
void customer:: calculatebill()
{
	if (roomtype == "standard")
	{
		bill = 300 * daystoreserve;
	}
	else if (roomtype == "moderate")
	{
		bill = 500 * daystoreserve;
	}
	else if (roomtype == "superior")
	{
		bill = 1000 * daystoreserve;
	}
	else if (roomtype == "junior suite")
	{
		bill = 2000 * daystoreserve;
	}
	if (roomtype == "standard")
	{
		bill = 5000 * daystoreserve;
	}

}
istream& operator >> (istream& in,  customer& obj)
{
	in >> obj.check;
	in >> obj.idnumber;
	in >> obj.floornumber;
	in >> obj.roomnumber;
	in >> obj.daystoreserve;
	in >> obj.roomtype;
	in >> obj.fname;
	in >> obj.lname;
	in >> obj.gender;
	in >> obj.age;
	in >> obj.balance;

	return in;
}
ostream& operator << (ostream& in, customer& obj)
{
	in << obj.check << " ";
	in << obj.idnumber << " ";
	in << obj.floornumber << " ";
	in << obj.roomnumber << " ";
	in << obj.daystoreserve << " ";
	in << obj.roomtype << " ";
	in << obj.fname << " ";
	in << obj.lname << " ";
	in << obj.gender << " ";
	in << obj.age << " ";
	in << obj.balance << " ";
	in << obj.checkin << " ";
	in << obj.checkout << " ";
	in << endl;
	return in;
}