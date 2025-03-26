#include "Polynomial.h"
#include <iostream>
#include <stdexcept>
#include <algorithm> // Для max_element
#include <cmath>     // Для pow()

using namespace std;
// Реализация методов класса Polynomial

Polynomial::Polynomial() {}

Polynomial::Polynomial(const vector<double>& coeffs, const vector<int>& exps) 
    : coefficients(coeffs), exponents(exps) {
    if (coeffs.size() != exps.size()) {
        throw invalid_argument("Coefficients and exponents must have the same size.");
    }
}

Polynomial::Polynomial(const Polynomial& other) 
    : coefficients(other.coefficients), exponents(other.exponents) {}

Polynomial::~Polynomial() {}

void Polynomial::setCoefficients(const vector<double>& coeffs) {
    coefficients = coeffs;
}

void Polynomial::setExponents(const vector<int>& exps) {
    exponents = exps;
}

vector<double> Polynomial::getCoefficients() const {
    return coefficients;
}

vector<int> Polynomial::getExponents() const {
    return exponents;
}

void Polynomial::print() const {
    for (size_t i = 0; i < coefficients.size(); ++i) {
        cout << coefficients[i] << "x^" << exponents[i];
        if (i < coefficients.size() - 1) {
            cout << " + ";
        }
    }
    cout << endl;
}

double Polynomial::evaluate(double x) const {
    double result = 0.0;
    for (size_t i = 0; i < coefficients.size(); ++i) {
        result += coefficients[i] * pow(x, exponents[i]);
    }
    return result;
}

int Polynomial::degree() const {
    if (exponents.empty()) {
        return -1; // Полином нулевой степени
    }
    return *max_element(exponents.begin(), exponents.end());
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    vector<double> newCoeffs = coefficients;
    vector<int> newExps = exponents;

    for (size_t i = 0; i < other.coefficients.size(); ++i) {
        newCoeffs.push_back(other.coefficients[i]);
        newExps.push_back(other.exponents[i]);
    }

    return Polynomial(newCoeffs, newExps);
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    vector<double> newCoeffs = coefficients;
    vector<int> newExps = exponents;

    for (size_t i = 0; i < other.coefficients.size(); ++i) {
        newCoeffs.push_back(-other.coefficients[i]);
        newExps.push_back(other.exponents[i]);
    }

    return Polynomial(newCoeffs, newExps);
}

// Реализация методов класса VectPolynomial

VectPolynomial::VectPolynomial() {}

VectPolynomial::VectPolynomial(const vector<Polynomial>& polys) 
    : polynomials(polys) {}

VectPolynomial::VectPolynomial(const VectPolynomial& other) 
    : polynomials(other.polynomials) {}

VectPolynomial::~VectPolynomial() {}

void VectPolynomial::setPolynomials(const vector<Polynomial>& polys) {
    polynomials = polys;
}

vector<Polynomial> VectPolynomial::getPolynomials() const {
    return polynomials;
}

void VectPolynomial::print() const {
    for (const auto& poly : polynomials) {
        poly.print();
    }
}

VectPolynomial VectPolynomial::computeSumAndDifference(const VectPolynomial& other) const {
    vector<Polynomial> result;

    for (size_t i = 0; i < polynomials.size(); ++i) {
        if (i < other.polynomials.size()) {
            result.push_back(polynomials[i] + other.polynomials[i]);
            result.push_back(polynomials[i] - other.polynomials[i]);
        }
    }

    return VectPolynomial(result);
}