#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "Vector.h"

using namespace std;

class Computer {
public:
    string name;
    double frequency;
    int ram;
    bool hasDVD;
    double price;

    Computer();
    Computer(string n, double f, int r, bool d, double p);

    void display() const;
};


void showAll(MyVector<Computer>& v);
void findByName(MyVector<Computer>& v);
void removeSlowest(MyVector<Computer>& v);
void countDVD(MyVector<Computer>& v);
void updatePrices(MyVector<Computer>& v);
void sortByPrice(MyVector<Computer>& v);