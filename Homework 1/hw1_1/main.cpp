#include <iostream>
#include <cmath>
#include "libellipse.h"

using namespace std;

int main(){

    Ellipse e1, e2;
    double h, k, a, b;
    bool x_main;
    cout<<"Enter h:"<<endl;
    cin>>h;
    cout<<"Enter k:"<<endl;
    cin>>k;
    cout<<"Enter a:"<<endl;
    cin>>a;
    cout<<"Enter b:"<<endl;
    cin>>b;
    cout<<"Enter 1 if the large axis is x else 0 :"<<endl;
    cin>>x_main;
    e1 = Ellipse(h, k, a, b, x_main);
    cout<<"Ellipse 01: "<<endl;
    e1.print();
    cout<<"Perimeter: "<<e1.perimeter()<<endl;
    cout<<"Area: "<<e1.area()<<endl;
    cout<<"Focal chord: "<<e1.focal_chord()<<endl;
    cout<<"Eccentriaty: "<<e1.eccentriaty()<<endl;

    e2 = e1;
    cout<<"Ellipse 02: "<<endl;
    e2.print();
    double h2, k2, a2, b2;
    bool x_main2;
    cout<<"Enter h:"<<endl;
    cin>>h2;
    cout<<"Enter k:"<<endl;
    cin>>k2;
    cout<<"Enter a:"<<endl;
    cin>>a2;
    cout<<"Enter b:"<<endl;
    cin>>b2;
    cout<<"Enter 1 if the large axis is x else 0 :"<<endl;
    cin>>x_main2;

    e2.set_all(h2, k2, a2, b2, x_main2);
    cout<<"New coordinates for E2: "<<endl;
    e2.print();

    double h3, k3, a3, b3;
    bool x_main3;
    e2.get_all(h3, k3, a3, b3, x_main3);
    cout<<h3<<", "<<k3<<", "<<a3<<", "<<b3<<", "<<x_main3<<endl;

    cout<<"Where is the point (ellipse 1)?"<<endl;
    double x, y;
    cout<<"Enter X:"<<endl;
    cin>>x;
    cout<<"Enter Y:"<<endl;
    cin>>y;
    e1.affiliation(x, y);

    double c;
    bool ax_main;
    cout<<"Find secord coordinate in ellipse 1"<<endl;
    cout<<"Enter first coordinate: "<<endl;
    cin>>c;
    cout<<"Enter 1 if first coordinate is X and 0 if not:"<<endl;
    cin>>ax_main;
    cout<<"Second coordinate: "<<e1.calculate_coord(c, ax_main)<<endl;

    return 0;
}