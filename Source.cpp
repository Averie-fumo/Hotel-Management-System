#include <iostream>
#pragma warning (disable:4996)
#include <fstream>
#include <string>
#include <ctime>
#include "Room.h"
#include "Standard.h"
#include "Moderate.h"
#include "Superior.h"
#include "Junior_Suite.h"
#include "Suite.h"
#include "customer.h"
using namespace std;


void writefile(Standard* obj, Moderate* obj1, Superior* obj2, Suite* obj3, Junior_suite* obj4)
{
	ofstream fin;
	fin.trunc;
	fin.open("Rooms.dat");
	if (fin.is_open())
	{

		bool** array = new bool* [5];
		for (int i = 0;i < 5;i++)
			array[i] = new bool[10];
		fin << "Standard ";
		fin << obj->getreserved();
		fin << " ";
		array = obj->getarray();
		for (int i = 0;i < 5;i++)
		{
			for (int j = 0;j < 10;j++)
			{
				if (array[i][j] == true)
					fin << (i * 50) + j;
				fin << " ";
			}
		}
		for (int i = 0;i < 5;i++)
			delete[] array[i];
		delete array; 
		array = nullptr;
		array = new bool* [5];
		for (int i=0 ;i < 5 ;i++)
		array[i] = new bool[10];
		fin << endl;
		fin << "Moderate ";
		fin << obj1->getreserved();
		fin << " ";
		array = obj1->getarray();
		for (int i = 0;i < 5;i++)
		{
			for (int j = 0;j < 10;j++)
			{
				if (array[i][j] == true)
					fin << (i * 50) + 10 + j;
				fin << " ";
			}
		}
		for (int i = 0;i < 5;i++)
			delete[] array[i];
		delete array;
		array = nullptr;
		array = new bool* [5];
		for (int i = 0;i < 5;i++)
			array[i] = new bool[10];
		fin << endl <<"Superior ";
		fin << obj2->getreserved();
		fin << " ";
		array = obj2->getarray();
		for (int i = 0;i < 5;i++)
		{
			for (int j = 0;j < 10;j++)
			{
				if (array[i][j] == true)
					fin << (i * 50) + 20 + j;
				fin << " ";
			}
		}
		for (int i = 0;i < 5;i++)
			delete[] array[i];
		delete array;
		array = nullptr;

		array = new bool* [5];
		for (int i = 0;i < 5;i++)
			array[i] = new bool[10];
		fin << endl << "Junior_Suite ";
		fin << obj4->getreserved();
		fin << " ";
		array = obj4->getarray();
		for (int i = 0;i < 5;i++)
		{
			for (int j = 0;j < 10;j++)
			{
				if (array[i][j] == true)
					fin << (i * 50) + 30 + j;
				fin << " ";
			}
		}
		for (int i = 0;i < 5;i++)
			delete[] array[i];
		delete array;
		array = nullptr;
		array = new bool* [5];
		for (int i = 0;i < 5;i++)
			array[i] = new bool[10];
		fin << endl << "Suite";
		fin << obj3->getreserved();
		fin << " ";
		array = obj3->getarray();
		for (int i = 0;i < 5;i++)
		{
			for (int j = 0;j < 10;j++)
			{
				if (array[i][j] == true)
					fin << (i * 50) + 40 + j;
				fin << " ";
			}
		}
		for (int i = 0;i < 5;i++)
			delete[] array[i];
		delete array;
		array = nullptr;
	}
	fin.close();
}
void readfile(Standard* obj, Moderate* obj1, Superior* obj2, Suite* obj3, Junior_suite* obj4)
{
	string standard = "Standard";
	string moderate = "Moderate";
	string superior = "Superior";
	string junior = "Junior_Suite";
	string suite = "Suite";
	string s;
	int total;
	int n;
	int floornumber; 
	int roomnumber;
	ifstream fin;
	fin.open("Rooms.dat");
	if(fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> s;
			if (s == standard)
			{
				fin >> total;
				for (int i = 0; i < total;i++)
				{
					fin >> n;
					floornumber = (n / 50) + 1;
					roomnumber = n % 50;
				  obj->reserveroom(floornumber, roomnumber);
				}
			}
			fin >> s; 
			if (s == moderate)
			{
				fin >> total;
				for (int i = 0; i < total;i++)
				{
					fin >> n;
					floornumber = (n / 50) + 1;
					roomnumber = (n % 50)-10 ;
					n= obj1->reserveroom(floornumber, roomnumber);
					
				}
			}
			fin >> s;
			if (s == superior)
			{
				fin >> total;
				for (int i = 0; i < total;i++)
				{
					fin >> n;
					floornumber = (n / 50) + 1;
					roomnumber = (n % 50) - 20;
					n=obj2->reserveroom(floornumber, roomnumber);
				}
			}
			fin >> s;
			if (s == junior)
			{
				fin >> total;
				for (int i = 0; i < total;i++)
				{
					fin >> n;
					floornumber = (n / 50) + 1;
					roomnumber = (n % 50) - 30;
					obj4->reserveroom(floornumber, roomnumber);
				}
			}
			fin >> s;
			if (s == suite)
			{
				fin >> total;
				for (int i = 0; i < total;i++)
				{
					fin >> n;
					floornumber = (n / 50) + 1;
					roomnumber = (n % 50) - 40;
					obj3->reserveroom(floornumber, roomnumber);
				}
			}
		}
	}
}
void reserveroom(Standard* obj, Moderate* obj1, Superior* obj2, Suite* obj3, Junior_suite* obj4, customer oj)
{
	string type = oj.gettype();
	int floor = oj.getfloor();
	int number = oj.getnumber();
    
	if (type == "standard" || type == "Standard")
		obj->reserveroom(floor, number);
	else if (type == "moderate" || type == "Moderate")
			obj1->reserveroom(floor, number);
	else if (type == "superior" || type == "Superior")
		obj2->reserveroom(floor, number);
	else if (type == "suite" || type == "Suite")
		obj3->reserveroom(floor, number);
	else if (type == "junior_suite" || type == "Junior_suite")
		obj4->reserveroom(floor, number);
}
void menu1(Standard* obj, Moderate* obj1, Superior* obj2, Suite* obj3, Junior_suite* obj4, int& checkin_no)
{
	customer oj;
	int floornumber = 0;
	int roomnumber = 0;
	string custom;
	string custom1 = "new";
	string custom2 = "old";
	cout << "Are you a new customer or an old one ? 1/2" << endl;
	cin >> custom;

	if (custom == custom1)
	{
		oj.filing();
		ofstream fin;
		fin.open("Database.dat");
		fin << oj;
		reserveroom(obj, obj1, obj2, obj3, obj4, oj);
		checkin_no++;
	}
	else if (custom == custom2)
	{
		string id;
		string name;
		string roomtype;
		string search;
		cout << "Fullname: " << endl;
		cin >> name;
		cout << "Roomtype: \n";
		cin >> roomtype;
		cout << "Floor number: \n";
		cin >> floornumber;
		floornumber--;
		cout << "Room number: \n";
		cin >> roomnumber;
		roomnumber--;
		ifstream fin;
		fin.open("Database.dat");
		if (fin.is_open())
		{
			fin >> search;
			if (search == name)
			{
				if (roomtype == "standard")
				{
					obj->reserveroom(floornumber, roomnumber);
				}
				else if (roomtype == "moderate")
				{
					obj1->reserveroom(floornumber, roomnumber);
				}
				else if (roomtype == "superior")
				{
					obj2->reserveroom(floornumber, roomnumber);
				}
				else if (roomtype == "suite")
				{
					obj3->reserveroom(floornumber, roomnumber);
				}
				else if (roomtype == "junior suite")
				{
					obj4->reserveroom(floornumber, roomnumber);
				}
				// assign room 
			}
		}
	}

}
void menu2()
{
	customer custom; 
	string id;
	int count = 0;
	cout << "Enter ID: " << endl;
	cin >> id;
	fstream fin;
	fin.open("Database.dat");
		if (fin.is_open())
		{
			while (fin.eof()==false)
			{
				fin >> custom;
				if (custom.idnumber == id)
				{
					break;
				}
			}
			if (custom.idnumber == id)
			{
				custom.setcheck(1);
				cout << "Checkin time: " << endl;
				time_t current_time;
				tm* current_tm;
				char datec[100];
				char timec[100];
				time(&current_time);
				char date[5];
				current_tm = localtime(&current_time);
				strftime(datec, 50, "  %d %B , %Y", current_tm);
				strftime(timec, 50, "%T", current_tm);
				strftime(date, 50, "%d", current_tm);
				cout << datec << endl;
				cout << timec << endl;
				fin << " ";
				fin << datec << " " << timec << endl;
				int d = custom.getdays() + stoi(date);
				custom.setcheckin(timec);
				cout << "Checkout time: " << endl;
				strftime(datec, 50, " %B , %Y", current_tm);
				strftime(timec, 50, "%T", current_tm);
				cout << d << " " << datec << endl << timec << endl;
				cout << "Remaining time: " << endl << custom.getdays() << " days ( but we will take it as " << custom.getdays() 
					 <<" hours)" << endl;
				fin << " " << datec << " " << timec << endl;
				custom.setcheckout(timec);
			}

		}
		system("pause");
}
void menu3(Standard* obj, Moderate* obj1, Superior* obj2, Suite* obj3, Junior_suite* obj4)
{
	cout<< " ~ " << obj->getreserved()  << " Standard rooms are reserved." << endl
		<< " ~ " << obj1->getreserved() << " Moderate rooms are reserved." << endl
		<< " ~ " << obj2->getreserved() << " Superior rooms are reserved." << endl
		<< " ~ " << obj4->getreserved() << " Junior Suites are reserved." << endl
		<< " ~ " << obj3->getreserved() << " Suites are reserved."   << endl
		<< " ~ " << obj->getempty()  << " Standard rooms are empty." << endl
		<< " ~ " << obj1->getempty() << " Moderate rooms are empty." << endl
		<< " ~ " << obj2->getempty() << " Superior rooms are empty." << endl
		<< " ~ " << obj4->getempty() << " Junior Suites are empty."  << endl
		<< " ~ " << obj3->getempty() << " Suites are empty." << endl;
	system("pause");

}
void menu4(Standard* obj, Moderate* obj1, Superior* obj2, Suite* obj3, Junior_suite* obj4, int& checkin_no, int& checkout_no)
{
	int total_rr = obj->getreserved() + obj1->getreserved() + obj2->getreserved() + obj3->getreserved() + obj4->getreserved();
	int total_er= obj->getempty() + obj1->getempty() + obj2->getempty() + obj3->getempty() + obj4->getempty();
	cout << "\tDAILY REPORT" << endl
		<< " ~ " << checkin_no << " customers have checked in today." << endl
		<< " ~ " << checkout_no << " customers have checked out today." << endl
		<< " ~ " << total_rr << " room(s) are reserved." << endl
		<< " ~ " << obj->getreserved() << " Standard rooms are reserved." << endl
		<< " ~ " << obj1->getreserved() << " Moderate rooms are reserved." << endl
		<< " ~ " << obj2->getreserved() << " Superior rooms are reserved." << endl
		<< " ~ " << obj4->getreserved() << " Junior Suites are reserved." << endl
		<< " ~ " << obj3->getreserved() << " Suites are reserved." << endl
		<< " ~ " << total_er << " room(s) are empty." << endl
		<< " ~ " << obj->getempty() << " Standard rooms are empty." << endl
		<< " ~ " << obj1->getempty() << " Moderate rooms are empty." << endl
		<< " ~ " << obj2->getempty() << " Superior rooms are empty." << endl
		<< " ~ " << obj4->getempty() << " Junior Suites are empty." << endl
		<< " ~ " << obj3->getempty() << " Suites are empty." << endl;
	system("pause");
}
void menu5(Standard* obj, Moderate* obj1, Superior* obj2, Suite* obj3, Junior_suite* obj4, int& checkout_no)
{
	// checkout menu 
	customer custom;
	string id;
	cout << "Enter ID: " ;
	cin >> id;
	ifstream fin;
	fin.open("Database.dat");
	if (fin.is_open())
	{
		while (fin.eof() == false)
		{
			fin >> custom;
			if (custom.idnumber == id)
			{
				break;
			}
		}
		if (custom.idnumber == id)
		{
			custom.setcheck(0);
			string s = custom.gettype();
			int floornumber = custom.getfloor();
			int room = custom.getnumber();
			if (s == "standard")
			{
				obj->checkout(room);
			}
			else if (s == "moderate")
			{
				obj1->checkout(room);
			}
			else if (s == "superior")
			{
				obj2->checkout(room);
			}
			else if (s == "suite")
			{
				obj3->checkout(room);
			}
			else if (s == "junior suite")
			{
				obj4->checkout(room);
			}
			cout << custom.getname() << " has been checked out from " << s << " room number " << room
				<< " their balance is " << custom.getbalance() << endl;
		}
	}
	system("pause");
}
void menu(Standard* obj, Moderate* obj1, Superior* obj2 , Suite* obj3, Junior_suite* obj4, int& checkin_no,int& checkout_no)
{
	int x=0 ;
	while (x != 5)
	{ 
		cout << "[\t HOTEL MANAGEMENT SYSTEM -> Menu\t ]" << endl
			<< "1. Press 1 to Reserve a room" << endl
			<< "2. Press 2 to checkin a visitor/customer" << endl
			<< "3. Press 3 to View Reserved Rooms" << endl
			<< "4. Press 4 to see detailed report" << endl
			<< "5. Press 5 to checkout" << endl
			<< "6. Press 6 to exit" << endl;
		cin >> x;
		if (x == 1)
		{
			menu1(obj, obj1, obj2, obj3, obj4, checkin_no);
		}
		else if (x == 2)
		{
			menu2();
		}
		else if (x == 3)
		{
			menu3(obj, obj1, obj2, obj3, obj4);
		}
		else if (x == 4)
		{
			menu4(obj, obj1, obj2, obj3, obj4, checkin_no, checkout_no);
		}
		else if (x == 5)
		{
			menu5(obj, obj1, obj2, obj3, obj4, checkout_no);
		}
		else
		{
			break;
		}
		system("CLS");
	}
}
void checkout(int &checkout_no , customer oj)
{
	checkout_no++;
	fstream fin;
	int blank=0;
	char a;
	string id;
	fin.open("Database.dat");
	if (fin.is_open())
	{
		fin >>noskipws>> a;
		if (a == ' ')
		{
			blank++;
		}
		while (a >= '0' && a <= '9')
		{
			id+= a;
			fin >> a;
		}

	}
}
void deallocation_function(Standard* obj, Moderate* obj1, Superior* obj2, Suite* obj3, Junior_suite* obj4);
int main()
{
	int checkin_no = 0;
	int checkout_no = 0;
	time_t currenttime;
	time(&currenttime);
	cout << ctime(&currenttime);
	Standard* obj = new Standard;
	Moderate* obj1 = new Moderate;
	Superior* obj2 = new Superior;
	Suite* obj3 = new Suite;
	Junior_suite* obj4 = new Junior_suite;
    readfile(obj, obj1, obj2, obj3, obj4);
	menu(obj, obj1,obj2,obj3,obj4, checkin_no, checkout_no);
	writefile(obj, obj1, obj2, obj3, obj4);
	deallocation_function(obj, obj1, obj2, obj3, obj4);
}
void deallocation_function(Standard* obj, Moderate* obj1, Superior* obj2, Suite* obj3, Junior_suite* obj4)
{
	obj = nullptr;
	obj1 = nullptr;
	obj2 = nullptr;
	obj3 = nullptr;
	obj4 = nullptr;
	delete obj;
	delete obj1;
	delete obj2;
	delete obj3;
	delete obj4;	
}