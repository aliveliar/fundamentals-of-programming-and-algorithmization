#include <iostream>
#include <cstring>
#include <iomanip>
#include "libproduct.h"

using namespace std;

Product::Product(){
    this->code = -1;
    strcpy(this->descr, "");
    this->price = 0.0;
    this->quantity = 0.0;
    this->tp_longitude = 0.0;
    this->tp_latitude = 0.0;
}

Product::Product(int code, char descr[50], double price, int quantity, double tp_longitude, double tp_latitude){
    this->code = code;
    strcpy(this->descr, descr);
    this->price = price;
    this->quantity = quantity;
    this->tp_longitude = tp_longitude;
    this->tp_latitude = tp_latitude;
}

Product::Product(const Product &p){
    this->code = p.code;
    strcpy(this->descr, p.descr);
    this->price = p.price;
    this->quantity = p.quantity;
    this->tp_longitude = p.tp_longitude;
    this->tp_latitude = p.tp_latitude;
}

Product::~Product(){}

void Product::print(){

    cout<<setw(10)<<this->code<<
            setw(10)<<this->descr<<
            setw(10)<<this->price<<
            setw(10)<<this->quantity<<
            setw(10)<<this->tp_longitude<<
            setw(10)<<this->tp_latitude<<endl;
}