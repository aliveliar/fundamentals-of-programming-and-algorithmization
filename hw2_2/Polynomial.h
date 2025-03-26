#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <string>
#include <algorithm> // Для max_element

using namespace std;

class Polynomial {
private:
    vector<double> coefficients; // Вектор коэффициентов
    vector<int> exponents;      // Вектор степеней

public:
    // Конструкторы
    Polynomial(); // По умолчанию
    Polynomial(const vector<double>& coeffs, const vector<int>& exps); // По параметрам
    Polynomial(const Polynomial& other); // Копирования

    // Деструктор
    ~Polynomial();

    // Сеттеры и геттеры
    void setCoefficients(const vector<double>& coeffs);
    void setExponents(const vector<int>& exps);
    vector<double> getCoefficients() const;
    vector<int> getExponents() const;

    // Метод для печати полинома
    void print() const;

    // Метод для вычисления значения полинома при заданном x
    double evaluate(double x) const;

    // Метод для определения степени полинома
    int degree() const;

    // Операторы сложения и вычитания полиномов
    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
};

class VectPolynomial {
private:
    vector<Polynomial> polynomials; // Вектор полиномов

public:
    // Конструкторы
    VectPolynomial(); // По умолчанию
    VectPolynomial(const vector<Polynomial>& polys); // По параметрам
    VectPolynomial(const VectPolynomial& other); // Копирования

    // Деструктор
    ~VectPolynomial();

    // Сеттеры и геттеры
    void setPolynomials(const vector<Polynomial>& polys);
    vector<Polynomial> getPolynomials() const;

    // Метод для печати всех полиномов
    void print() const;

    // Метод для вычисления суммы и разности полиномов
    VectPolynomial computeSumAndDifference(const VectPolynomial& other) const;
};

#endif // POLYNOMIAL_H