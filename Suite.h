#include <iostream>
#include "Room.h"
using namespace std;

#ifndef SUITE_H
#define SUITE_H
class Suite : public Room
{
private:
    int price;
    bool** occupied;
public:
    Suite();
   virtual  int reserveroom(int, int);
    void checkout(int n);
    int getreserved();
    int getempty();
    bool** getarray();
    ~Suite();
};
#endif