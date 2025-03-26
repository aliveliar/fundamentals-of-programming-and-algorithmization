#include <iostream>
#include <cmath>
#include "libellipse.h"

using namespace std;

Ellipse::Ellipse(double h, double k, double a, double b, bool x_main){
    p_h = h;
    p_k = k;
    p_a = a;
    p_b = b;
    p_main = x_main;

    normalize(p_a, p_b);
}

Ellipse::Ellipse(const Ellipse &e){
    p_h = e.p_h;
    p_k = e.p_k;
    p_a = e.p_a;
    p_b = e.p_b;
    p_main = e.p_main;
}

Ellipse::~Ellipse(){}

void Ellipse::normalize(double &p_a, double &p_b){
    double aux;

    if(p_b > p_a){
        aux = p_b;
        p_b = p_a;
        p_a = aux;
    }
}

double Ellipse::hyperparameter(){
    return sqrt(pow(p_a, 2) - pow(p_b, 2));
}

void Ellipse::tops(){
    cout<<"Tops: "<<endl;
    if(p_main){
        cout<<"V1("<<(p_h - p_a)<<", "<<p_k<<")"<<endl;
        cout<<"V2("<<(p_h + p_a)<<", "<<p_k<<")"<<endl;
    }else{
        cout<<"V1("<<p_h<<", "<<(p_k - p_a)<<")"<<endl;
        cout<<"V2("<<p_h<<", "<<(p_k + p_a)<<")"<<endl;
    }
}

void Ellipse::focuses(){
    double c;
    c = hyperparameter();
    cout<<"Focuses: "<<endl;
    if(p_main){
        cout<<"F1("<<(p_h - c)<<", "<<p_k<<")"<<endl;
        cout<<"F2("<<(p_h + c)<<", "<<p_k<<")"<<endl;
    }else{
        cout<<"F1("<<p_h<<", "<<(p_k - c)<<")"<<endl;
        cout<<"F2("<<p_h<<", "<<(p_k + c)<<")"<<endl;
    }
}

double Ellipse::focal_chord(){
    return (2*pow(p_b, 2) / p_a);
}

double Ellipse::eccentriaty(){
    double c;
    c = hyperparameter();
    return c/p_a;
}

void Ellipse::set_all(double h, double k, double a, double b, bool x_main){
    p_h = h;
    p_k = k;
    p_a = a;
    p_b = b;
    p_main = x_main;
}

void Ellipse::get_all(double &h, double &k, double &a, double &b, bool &x_main){
    h = p_h;
    k = p_k;
    a = p_a;
    b = p_b;
    x_main = p_main;
}

void Ellipse::print(){
    if(p_main){
        cout <<"(x - "<<p_h<<")^2 / "<<pow(p_a, 2)<<" + (y - " << p_k << ")^2 / " << pow(p_b, 2) << " = 1\n" <<endl;
    }else{
        cout <<"(x - "<<p_h<<")^2 / "<<pow(p_b, 2)<<" + (y - " << p_k << ")^2 / " << pow(p_a, 2) << " = 1\n" <<endl;
    }
    cout<<"Center:"<<endl;
    cout<<"C("<<p_h<<", "<<p_k<<")"<<endl;
    tops();
    focuses();
}

void Ellipse::affiliation(double x, double y){
    double res;
    if(p_main){
        res = pow(x - p_h, 2) / pow(p_a, 2) + pow(y - p_k, 2) / pow(p_b, 2);
        if(res > 1){
            cout << "Point is outside ellipse"<<endl;
        }else if (res < 1){
            cout << "Point is inside ellipse"<<endl;
        }else{
            cout << "Point belongs to ellipse"<<endl;
        }
        
    }else{
        res = pow(x - p_h, 2) / pow(p_b, 2) + pow(y - p_k, 2) / pow(p_a, 2);
        if(res > 0){
            cout << "Point is outside ellipse"<<endl;
        }else if (res < 0){
            cout << "Point is inside ellipse"<<endl;
        }else{
            cout << "Point belongs to ellipse"<<endl;
        }
    }
}

double Ellipse::perimeter(){
    return acos(-1) * (3*(p_a + p_b) - sqrt((3*p_a + p_b) * (p_a + 3*p_b)));
}

double Ellipse::area(){
    return acos(-1) * p_a * p_b;
}

double Ellipse::calculate_coord(double c, bool x_given){
    if(x_given){
        if(p_main){
            return (p_b / p_a * sqrt(pow(p_a, 2) - pow(c - p_h, 2)) + p_k);
        }else{
            return (p_a / p_b * sqrt(pow(p_b, 2) - pow(c - p_h, 2)) + p_k);
        }
    }else{
        if(p_main){
            return (p_a / p_b * sqrt(pow(p_b, 2) - pow(c - p_k, 2)) + p_h);
        }else{
            return (p_b / p_a * sqrt(pow(p_a, 2) - pow(c - p_k, 2)) + p_h);
        }
    }
}
