#pragma once

class Product{

    public:
        int code;
        char descr[50];
        double price;
        int quantity;
        double tp_longitude;
        double tp_latitude;

    public:
        Product();
        Product(char descr[50], double price, int quantity, double tp_longitude, double tp_latitude);
        Product(const Product &p);
        ~Product();
        void print();
        void set_all(char descr[50], double price, int quantity, double tp_longitude, double tp_latitude);
        void get_all(int &code, char* &descr, double &price, int &quantity, double &longitude, double &tp_latitude);
};