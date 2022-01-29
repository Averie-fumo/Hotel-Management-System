#include "Junior_Suite.h"
#include "Room.h"

Junior_suite::Junior_suite() 
{
    price = 2000;
    occupied = new bool* [5];
    for (int i = 0;i < 5;i++)
        occupied[i] = new bool[10];

    for (int i = 0;i < 5;i++)
    {
        for (int j = 0;j < 10;j++)
            occupied[i][j] = false;
    }
}
bool** Junior_suite::getarray()
{
    return occupied;
}
int Junior_suite::reserveroom(int floornumber, int roomnumber)
{

            if (occupied[floornumber-1][roomnumber] == false)
            {
                occupied[floornumber-1][roomnumber] = true;
                return ((floornumber-1) * 50) + 30 ;
            }
    return -1;
}

void Junior_suite::checkout(int n)
{
    int floor = n / 50;
    int number = n % 50 - 30;
    occupied[floor][number] = false;

}

int Junior_suite::getempty()
{
    int empty = 50;
    for (int i = 0;i < 5;i++)
    {
        for (int j = 0; j < 10;j++)
        {
            if (occupied[i][j] == true)
                empty--;
        }
    }
    return empty;
}

int Junior_suite::getreserved()
{
    int reserved = 0;
    for (int i = 0;i < 5;i++)
    {
        for (int j = 0; j < 10;j++)
        {
            if (occupied[i][j] == true)
                reserved++;
        }
    }
    return reserved;
}
Junior_suite :: ~Junior_suite()
{
    for (int i = 0;i < 5;i++)
        delete[] occupied[i];
    delete occupied;
    occupied = nullptr;
}



