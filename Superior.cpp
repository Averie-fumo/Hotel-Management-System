#include "Superior.h"
#include "Room.h"

Superior::Superior()
{
    price = 1000;
    occupied = new bool* [5];
    for (int i = 0;i < 5;i++)
        occupied[i] = new bool[10];

    for (int i = 0;i < 5;i++)
    {
        for (int j = 0;j < 10;j++)
            occupied[i][j] = false;
    }
}
int Superior::reserveroom(int floor, int roomnumber)
{
 
            if (occupied[floor-1][roomnumber] == false)
            {
                occupied[floor-1][roomnumber] = true;
                return ((floor-1) * 50)+ roomnumber;
            }

    return -1;
}

void Superior::checkout(int n)
{
    int floor = n / 50;
    int number = n % 50 - 20;
    occupied[floor][number] = false;

}

int Superior::getempty()
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

int Superior::getreserved()
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

bool** Superior::getarray()
{
    return occupied;
}
Superior :: ~Superior()
{
    for (int i = 0;i < 5;i++)
        delete[] occupied[i];
    delete occupied;
    occupied = nullptr;
}


