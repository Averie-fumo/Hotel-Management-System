#include <iostream>
#include <fstream>
using namespace std;

class customer
{
private :
	friend istream& operator >> (istream& in, customer& obj);
	friend ostream& operator << (ostream& out, customer& obj);
public :

	   int check= 0;
	   string checkin= "NULL";
	   string checkout= "NULL";
	   int remaining= 0;
		string bal1 = "advance";
		string bal2 = "later";
		string inp;
		string fname;
		int age = 0;
		string gender;
		string idnumber;
		int balance = 0;
		int bill=0 ;
		int daystoreserve = 0;
		int floornumber = 0;
		string roomtype;
		int roomnumber = 0;
		string lname;
		void filing();
		void calculatebill();
		string getname()
		{
			string s = fname + " " + lname;
			return s;
		}
		void setcheck(int i)
		{
			check = i;
		}
		int getbalance()
		{
			return balance;
		}
		int getdays()
		{
			return daystoreserve;
		}
		void setcheckin(string s)
		{
			checkin = s;
		}
		void setcheckout(string s)
		{
			checkout = s;
		}
		void setremain(int i)
		{
			remaining = i;
		}
		string gettype()
		{
			return roomtype;
		}
		int getfloor()
		{
			return floornumber;
		}
		int getnumber()
		{
			return roomnumber;
		}
	
};

