#include "Polynomial.h"
#include <iostream>

using namespace std;

int main() {
    // Создаем полиномы
    Polynomial p1({1, 2, 3}, {0, 1, 2}); // 1 + 2x + 3x^2
    Polynomial p2({4, 5}, {1, 2});       // 4x + 5x^2

    // Печать полиномов
    cout << "Polynomial 1: ";
    p1.print();
    cout << "Polynomial 2: ";
    p2.print();

    // Сложение и вычитание полиномов
    Polynomial p3 = p1 + p2;
    Polynomial p4 = p1 - p2;

    cout << "Sum: ";
    p3.print();
    cout << "Difference: ";
    p4.print();

    // Вычисление значения полинома при x = 2
    cout << "Value of p1 at x = 2: " << p1.evaluate(2) << endl;

    // Создаем вектор полиномов
    VectPolynomial v1({p1, p2});
    VectPolynomial v2({p3, p4});

    // Печать векторов полиномов
    cout << "Vector 1: " << endl;
    v1.print();
    cout << "Vector 2: " << endl;
    v2.print();

    // Вычисление суммы и разности векторов полиномов
    VectPolynomial v3 = v1.computeSumAndDifference(v2);
    cout << "Sum and Difference of vectors: " << endl;
    v3.print();

    return 0;
}