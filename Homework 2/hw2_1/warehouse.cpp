#include <iostream>
#include <cstring>
#include <iomanip>
#include "libwarehouse.h"

using namespace std;

Warehouse::Warehouse(){    
    this->index = 0;
    this->list = nullptr;
}

Warehouse::~Warehouse(){
    delete[] this->list;
}

void Warehouse::menu(int &opc){
    cout<<left;
    cout<<"--------------------"<<endl;
    cout<<"MENU OF PRODUCTS"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"[1]. Insert product"<<endl;
    cout<<"[2]. Print list of products"<<endl;
    cout<<"[3]. Search product by description"<<endl;
    cout<<"[4]. Update product"<<endl;
    cout<<"[5]. Delete productt"<<endl;
    cout<<"[6]. Exit"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Enter option: "; cin>>opc;
}

void Warehouse::insert_product(){
    cout<<"Insert new product..."<<endl;
    this->index++;
    cout<<"Description "; cin>> this->list[this->index].descr;
    
    this->size++;
    this->set_size(this->size);
}