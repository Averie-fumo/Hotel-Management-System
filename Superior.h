#include <iostream>
#include "Room.h"
using namespace std;

#ifndef SUPERIOR_H
#define SUPERIOR_H
class Superior : public Room
{
private:
    int price;
    bool** occupied;
public:
    Superior();
   virtual int reserveroom(int,int);
    void checkout(int n);
    int getreserved();
    int getempty();
    bool** getarray();
    ~Superior();
};
#endif