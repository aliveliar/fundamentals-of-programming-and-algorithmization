#include <iostream>
#include <cstring>
#include <iomanip>
#include "libproduct.h"

using namespace std;

Product::Product(){
    this->code = -1;
    strcpy(this->descr, "");
    this->price = 0.0;
    this->quantity = 0;
    this->tp_longitude = 0.0;
    this->tp_latitude = 0.0;
}

Product::Product(char descr[50], double price, int quantity, double tp_longitude, double tp_latitude)
{
    this->code = (1 + rand() % 2) * 1000000000 + (1 + rand() % 999999);
    strcpy(this->descr, descr);
    this->price = price;
    this->quantity = quantity;
    this->tp_longitude = tp_longitude;
    this->tp_latitude = tp_latitude;
}

Product::Product(const Product &p)
{
    this->code = p.code;
    strcpy(this->descr, p.descr);
    this->price = p.price;
    this->quantity = p.quantity;
    this->tp_longitude = p.tp_longitude;
    this->tp_latitude = p.tp_latitude;
}

Product::~Product(){}

void Product::set_all(char descr[50], double price, int quantity, double tp_longitude, double tp_latitude)
{
    strcpy(this->descr, descr);
    this->price = price;
    this->quantity = quantity;
    this->tp_longitude = tp_longitude;
    this->tp_latitude = tp_latitude;
}

void Product::get_all(int &code, char* &descr, double &price, int &quantity, double &longitude, double &tp_latitude)
{
    code = this->code;
    strcpy(descr, this->descr);
    price = this->price;
    quantity = this->quantity;
    tp_longitude = this->tp_longitude;
    tp_latitude = this->tp_latitude;
}

void Product::print(){

    cout<<setw(3)<<"460"<<setw(12)<<this->code<<
            setw(10)<<this->descr<<
            setw(10)<<this->price<<
            setw(10)<<this->quantity<<
            setw(10)<<this->tp_longitude<<
            setw(10)<<this->tp_latitude<<endl;
}