#pragma once

class Ellipse{

    public:
        double p_h, p_k, p_a, p_b;
        bool p_main;

    public:
        Ellipse(double h=0.0, double k=0.0, double a=0.0, double b=0.0, bool x_main=1);
        Ellipse(const Ellipse &e);
        ~Ellipse();
        void normalize(double &p_a, double &p_b);
        double hyperparameter();
        void tops();
        void focuses();
        double focal_chord();
        double eccentriaty();
        void set_all(double h, double k, double a, double b, bool x_main);
        void get_all(double &h, double &k, double &a, double &b, bool &x_main);
        void print();
        void affiliation(double x, double y);
        double perimeter();
        double area();
        double calculate_coord(double x, bool x_given);
};