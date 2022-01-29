#include <iostream>
#include "Room.h"
using namespace std;

#ifndef STANDARD_H
#define STANDARD_H
class Standard : public Room
{
private:

    int price;
    bool** occupied;
public:
    Standard();
    virtual int reserveroom(int, int);
    void checkout(int n);
    int getreserved();
    int getempty();
    bool** getarray();
    ~Standard();
};
#endif