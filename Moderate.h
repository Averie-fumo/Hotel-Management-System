#include <iostream>
#include "Room.h"
using namespace std;

#ifndef MODERATE_H
#define MODERATE_H
class Moderate : public Room
{
private:
    int price;
    bool** occupied;
public:
    Moderate();
    virtual int reserveroom(int ,int);
    void checkout(int n );
    int getreserved();
    int getempty();
    bool** getarray();
    ~Moderate();
};
#endif