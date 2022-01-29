#include "Suite.h"
#include "Room.h"

Suite::Suite() 
{
    price = 5000;
    occupied = new bool* [5];
    for (int i = 0;i < 5;i++)
        occupied[i] = new bool[10];

    for (int i = 0;i < 5;i++)
    {
        for (int j = 0;j < 10;j++)
            occupied[i][j] = false;
    }
}

bool** Suite::getarray()
{
    return occupied;
}
int Suite::reserveroom(int floor, int roomnumber)
{
   
            if (occupied[floor-1][roomnumber] == false)
            {
                occupied[floor-1][roomnumber] = true;
                return ((floor-1) * 50) + roomnumber;
            }
    return -1;
}

void Suite::checkout(int n)
{
    int floor = n / 50;
    int number = n % 50 - 40;
    occupied[floor][number] = false;

}

int Suite::getempty()
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

int Suite::getreserved()
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
Suite :: ~Suite()
{
    for (int i = 0;i < 5;i++)
        delete[] occupied[i];
    delete occupied;
    occupied = nullptr;
}




