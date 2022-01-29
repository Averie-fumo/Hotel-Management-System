#include <iostream>
#include "Room.h"
using namespace std;
#ifndef JUNIOR_SUITE 
#define JUNIOR_SUITE
class Junior_suite : public Room
{
private:
    int price;
    bool** occupied;
public:
    Junior_suite();
    virtual int reserveroom(int,int);
    void checkout(int n);
    int getreserved();
    int getempty();
    bool** getarray();
    ~Junior_suite();
};
#endif