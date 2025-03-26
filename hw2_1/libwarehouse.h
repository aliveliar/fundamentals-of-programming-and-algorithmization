#pragma once
#include "libproduct.h"

class Warehouse{

    public:
        Product *list;
        int index;
        char id[4];
        enum TYPE{CENTRE = 1, WEST, EAST};
        double w_longitude;
        double w_latitude;
        int max_capacity;
        int total_stock;
        
    public:
        Warehouse();
        Warehouse(int n);
        Warehouse(const Warehouse &w);
        ~Warehouse();
        void menu(int &opc);
        void set_size(int n);
        int get_size();
        void insert_product();        
        Product get_product(int pos);
        void print_warehouse();
        int search_by_describe();
        void update_client();
        void delete_client();
};
