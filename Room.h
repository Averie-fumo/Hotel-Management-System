#include <iostream>
using namespace std;

#ifndef ROOM_H
#define ROOM_H
class Room
{
public:
    
    Room()
    {

    }
    virtual int reserveroom(int,int) = 0;
    ~Room()
    {

    }
};
#endif 