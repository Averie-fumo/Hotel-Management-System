#include "Moderate.h"
#include "Room.h"

Moderate::Moderate()
{
    price = 500;
    occupied = new bool* [5];
    for (int i = 0;i < 5;i++)
        occupied[i] = new bool[10];

    for (int i = 0;i < 5;i++)
    {
        for (int j = 0;j < 10;j++)
            occupied[i][j] = false;
    }
}
int Moderate::reserveroom(int floornumber, int roomnumber)
{
            if (occupied[floornumber-1][roomnumber] == false)
            {
                occupied[floornumber-1][roomnumber] = true;
                return ((floornumber-1) * 50) + roomnumber;
            }
    return -1;
}

void Moderate::checkout(int n)
{
    int floor = n / 50;
    int number = n % 50 -10;
    occupied[floor][number] = false;

}

int Moderate::getempty()
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

int Moderate::getreserved()
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
bool** Moderate::getarray()
{
    return occupied;
}
Moderate :: ~Moderate()
{
    for (int i = 0;i < 5;i++)
        delete[] occupied[i];
    delete occupied;
    occupied = nullptr;
}
