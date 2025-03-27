#pragma once
#include "libproduct.h"

enum TYPE{CENTER = 1, WEST, EAST};

class Warehouse{

    public:
        Product *list;
        char code_letter='W';
        int index;
        int size;
        TYPE type;
        double w_longitude;
        double w_latitude;
        int max_capacity;
        int total_stock;
        
    public:
        Warehouse();
        Warehouse(int index, TYPE type, double w_longitude, double w_latitude, int max_capacity, int n);
        Warehouse(const Warehouse &w);
        ~Warehouse();
        void set_size(int n);
        int get_size();
        void insert_product(char descr[50], double price, int quantity, double tp_longitude, double tp_latitude);        
        Product get_product(int pos);
        void print_warehouse();
        int search_product(char crit[50]);
        void delete_product(char crit[50]);
};

void input_max_products(int &n);
double calculate_dist(Warehouse w, double tp_longitude, double tp_latitude);
void insert_products(Warehouse list[3]);
void search_product(Warehouse list[3]);
void delete_product(Warehouse list[3]);
void print_list(Warehouse list[3]);
void menu(int &opt);
