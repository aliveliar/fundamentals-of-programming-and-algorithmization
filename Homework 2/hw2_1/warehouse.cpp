#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include "libwarehouse.h"

using namespace std;

void input_max_products(int &n){
    do{
        cout<<"Max products: "; cin>>n;
    }while(n<=0);
}

Warehouse::Warehouse(){    
    this->index = 100;
    this->type = CENTER;
    this->w_longitude = 0.0;
    this->w_latitude = 0.0;
    this->max_capacity = 0;
    this->total_stock = 0;
    this->size = 0;
    this->list = nullptr;
}

Warehouse::Warehouse(int index, TYPE type, double w_longitude, double w_latitude, int max_capacity, int n){
    if(100 + index > 999){
        cout<<"Wrong";
    }else{
        this->index = index + 100;
    }
    this->type = type;
    this->w_latitude = w_latitude;
    this->w_longitude = w_longitude;
    this->max_capacity = max_capacity;
    this->total_stock = max_capacity;
    this->size = 0;
    this->list = new Product[n];
}

Warehouse::Warehouse(const Warehouse &w){
    this->index = w.index;
    this->type = w.type;
    this->w_latitude = w.w_latitude;
    this->w_longitude = w.w_longitude;
    this->max_capacity = w.max_capacity;
    this->total_stock = w.total_stock;
    this->size = w.size;
    this->list = new Product[w.size];

    for(int i=0; i<w.size; i++){
        this->list[i] = w.list[i];
    }
}

Warehouse::~Warehouse(){
    delete[] this->list;
}

void Warehouse::set_size(int n){
    this->size = n;
}

int Warehouse::get_size(){
    return this->size;
}

void Warehouse::insert_product(char descr[50], double price, int quantity, double tp_longitude, double tp_latitude){
    this->list[this->size].code = (1 + rand()%2) * 1000000000 + (1 + rand() % 999999);
    strcpy(this->list[this->size].descr, descr);
    this->list[this->size].price = price;
    this->list[this->size].quantity = quantity;

    if (this->list[this->size].quantity > this->total_stock){
        this->list[this->size].quantity = this->total_stock;
        this->total_stock = 0;
    }else{
        this->total_stock = this->max_capacity - this->list[this->size].quantity;
    }
    
    this->list[this->size].tp_longitude = tp_longitude;
    this->list[this->size].tp_latitude = tp_latitude;
    this->size++;
    this->set_size(this->size);
}

Product Warehouse::get_product(int pos){
    return this->list[pos];
}

void Warehouse::print_warehouse(){
    cout<< setw(10) << "Code" <<
    setw(10) << "Description" <<
    setw(10) << "Price" <<
    setw(10) << "Quantity" <<
    setw(10) << "Longitude" <<
    setw(10) << "Lattitude" <<endl;
    
    for (int i=0; i<this->size; i++){
        this->list[i].print();
    }
}

int Warehouse::search_product(char crit[50]){
    int pos;
    for (int i=0; i< this->get_size(); i++){
        if (strcmp(this->list[i].descr, crit) == 0){
            pos = i;
            return pos;
        }
    }

    return -1;
}

void Warehouse::delete_product(char crit[50]){
    int pos = this->search_product(crit);

    if (pos != -1){
        if (pos == this->size - 1){
            this->list[pos] = this->list[pos - 1];
        }

        for (int i=pos; i< this->get_size() - 1; i++){
            this->list[i] = this->list[i+1];
            this->size--;
            this->set_size(this->size);
            cout << "Product deleted" <<endl;
        }
    }else{
        cout<<"Product not found" << endl;
    }
}

void menu(int &opc){
    cout<<left;
    cout<<"--------------------"<<endl;
    cout<<"MENU OF PRODUCTS"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"[1]. Insert product"<<endl;
    cout<<"[2]. Print list of products"<<endl;
    cout<<"[3]. Search product by description"<<endl;
    cout<<"[4]. Delete product"<<endl;
    cout<<"[5]. Exit"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Enter option: "; cin>>opc;
}

double calculate_dist(Warehouse w, double tp_longitude, double tp_latitude){
    return abs(w.w_longitude - tp_longitude) + abs(w.w_latitude - tp_latitude);
}

void insert_products(Warehouse list[3]){
    char descr[50];
    int quantity;
    double price, tp_longitude, tp_latitude;

    cout <<"Insert new product. . ."<<endl;
    cout<<"Description "; cin>> descr;
    do{
        cout<<"Price: "; cin>> price;
    }while (price < 0);

    do{
        cout<<"Quantity: "; cin>> quantity;
    }while(quantity <= 0);

    do{
        cout<<"Longitude: "; cin>> tp_longitude;
    }while(tp_longitude < 19 || tp_longitude > 169);

    do{
        cout<<"Latitude: "; cin>>tp_latitude;
    }while(tp_latitude < 41 || tp_latitude > 82);

    if ((calculate_dist(list[0], tp_longitude, tp_latitude) <= calculate_dist(list[1], tp_longitude, tp_latitude))
    && (calculate_dist(list[0], tp_longitude, tp_latitude) <= calculate_dist(list[2], tp_longitude, tp_latitude))){
        if (list[0].total_stock > 0){
            list[0].insert_product(descr, price, quantity, tp_longitude, tp_latitude);
        }else{
            if (calculate_dist(list[2], tp_longitude, tp_latitude) < calculate_dist(list[1], tp_longitude, tp_latitude)){
                if (list[2].total_stock > 0){
                    list[2].insert_product(descr, price, quantity, tp_longitude, tp_latitude);
                }else{
                    if (list[1].total_stock > 0){
                        list[1].insert_product(descr, price, quantity, tp_longitude, tp_latitude);
                    }else{
                        cout<< "Unable to insert on warehouses" <<endl;
                    }
                }   
            }else{
                if (list[1].total_stock > 0){
                    list[1].insert_product(descr, price, quantity, tp_longitude, tp_latitude);
                }else{
                    if (list[2].total_stock > 0){
                        list[2].insert_product(descr, price, quantity, tp_longitude, tp_latitude);
                    }else{
                        cout<< "Unable to insert on warehouses" <<endl;
                    }
                }  
            }
        }
    }

    if ((calculate_dist(list[1], tp_longitude, tp_latitude) <= calculate_dist(list[2], tp_longitude, tp_latitude))
    && (calculate_dist(list[1], tp_longitude, tp_latitude) <= calculate_dist(list[0], tp_longitude, tp_latitude))){
        if (list[1].total_stock > 0){
            list[1].insert_product(descr, price, quantity, tp_longitude, tp_latitude);
        }else{
            if (calculate_dist(list[2], tp_longitude, tp_latitude) < calculate_dist(list[0], tp_longitude, tp_latitude)){
                if (list[2].total_stock > 0){
                    list[2].insert_product(descr, price, quantity, tp_longitude, tp_latitude);
                }else{
                    if (list[0].total_stock > 0){
                        list[0].insert_product(descr, price, quantity, tp_longitude, tp_latitude);
                    }else{
                        cout<< "Unable to insert on warehouses" <<endl;
                    }
                }   
            }else{
                if (list[0].total_stock > 0){
                    list[0].insert_product(descr, price, quantity, tp_longitude, tp_latitude);
                }else{
                    if (list[2].total_stock > 0){
                        list[2].insert_product(descr, price, quantity, tp_longitude, tp_latitude);
                    }else{
                        cout<< "Unable to insert on warehouses" <<endl;
                    }
                }  
            }
        }
    }

    if ((calculate_dist(list[2], tp_longitude, tp_latitude) <= calculate_dist(list[1], tp_longitude, tp_latitude))
    && (calculate_dist(list[2], tp_longitude, tp_latitude) <= calculate_dist(list[0], tp_longitude, tp_latitude))){
        if (list[2].total_stock > 0){
            list[2].insert_product(descr, price, quantity, tp_longitude, tp_latitude);
        }else{
            if (calculate_dist(list[1], tp_longitude, tp_latitude) < calculate_dist(list[0], tp_longitude, tp_latitude)){
                if (list[1].total_stock > 0){
                    list[1].insert_product(descr, price, quantity, tp_longitude, tp_latitude);
                }else{
                    if (list[0].total_stock > 0){
                        list[0].insert_product(descr, price, quantity, tp_longitude, tp_latitude);
                    }else{
                        cout<< "Unable to insert on warehouses" <<endl;
                    }
                }   
            }else{
                if (list[0].total_stock > 0){
                    list[0].insert_product(descr, price, quantity, tp_longitude, tp_latitude);
                }else{
                    if (list[1].total_stock > 0){
                        list[1].insert_product(descr, price, quantity, tp_longitude, tp_latitude);
                    }else{
                        cout<< "Unable to insert on warehouses" <<endl;
                    }
                }  
            }
        }
    }
}

void search_product(Warehouse list[3]){
    char crit[50];
    cout <<"Search criteria: "; cin >> crit;

    for (int i=0; i<3; i++){
        cout<< "---------------" << list[i].code_letter << list[i].index << "---------------" <<endl;
        if (list[i].search_product(crit) != -1){
            list[i].get_product(list[i].search_product(crit)).print();
        }else{
            cout << "Product not found" << endl;
        }
    }
}

void delete_product(Warehouse list[3]){
    int opt;
    char crit[50];
    do{
        cout<< "Choose warehouse: "; cin>>opt;
    }while (opt < 1 && opt > 3);

    cout << "Search criteria: "; cin >> crit;

    switch(opt)
    {
    case 1:
        list[0].delete_product(crit);
        break;
    case 2:
        list[1].delete_product(crit);
        break;
    case 3:
        list[2].delete_product(crit);
        break;
    }
}

void print_list(Warehouse list[3]){
    int opt;
    do{
        cout << "Choose warehouse: "; cin >> opt;
    }while(opt < 1 && opt > 3);

    switch (opt){
        case 1:
            list[0].print_warehouse();
            break;
        case 2:
            list[1].print_warehouse();
            break;
        case 3:
            list[2].print_warehouse();
            break;
    }
}