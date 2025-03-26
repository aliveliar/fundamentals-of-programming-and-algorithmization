#include <iostream>
#include <cmath>
#include <algorithm>

class Quaternion {
private:
    double a = 1.0;
    double b = 1.0;
    double c = 1.0;
    double d = 1.0;
    double i = 0.0;
    double j = 0.0;
    double k = 0.0;

public:
    // Конструкторы
    Quaternion() : a(1), b(0), c(0), d(0) {}
    Quaternion(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {}
    Quaternion(const Quaternion& other) : a(other.a), b(other.b), c(other.c), d(other.d) {}

    // Сеттеры
    void setA(double a) { this->a = a; }
    void setB(double b) { this->b = b; }
    void setC(double c) { this->c = c; }
    void setD(double d) { this->d = d; }

    // Геттеры
    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }
    double getD() const { return d; }

    // Печать кватерниона
    void print() const {
        std::cout << a << " + " << b << "i + " << c << "j + " << d << "k" << std::endl;
    }

    // Норма кватерниона
    double norm() const {
        return std::sqrt(a * a + b * b + c * c + d * d);
    }

    // Сопряжение кватерниона
    Quaternion conjugate() const {
        return Quaternion(a, -b, -c, -d);
    }

    // Нормализация кватерниона
    Quaternion normalize() const {
        double n = norm();
        return Quaternion(a / n, b / n, c / n, d / n);
    }

    // Инверсия кватерниона
    Quaternion inverse() const {
        double n = norm();
        return conjugate() / (n * n);  // Инверсия через сопряжение и деление на квадрат нормы
    }

    // Операторы
    Quaternion operator+(const Quaternion& other) const {
        return Quaternion(a + other.a, b + other.b, c + other.c, d + other.d);
    }

    Quaternion operator-(const Quaternion& other) const {
        return Quaternion(a - other.a, b - other.b, c - other.c, d - other.d);
    }

    Quaternion operator*(const Quaternion& other) const {
        return Quaternion(
            a * other.a - b * other.b - c * other.c - d * other.d,
            a * other.b + b * other.a + c * other.d - d * other.c,
            a * other.c - b * other.d + c * other.a + d * other.b,
            a * other.d + b * other.c - c * other.b + d * other.a
        );
    }

    // Деление на скаляр
    Quaternion operator/(double scalar) const {
        return Quaternion(a / scalar, b / scalar, c / scalar, d / scalar);
    }

    double dot(const Quaternion& other) const {
        return a * other.a + b * other.b + c * other.c + d * other.d;
    }

    // Евклидово расстояние
    double euclideanDistance(const Quaternion& other) const {
        return std::sqrt(
            (a - other.a) * (a - other.a) +
            (b - other.b) * (b - other.b) +
            (c - other.c) * (c - other.c) +
            (d - other.d) * (d - other.d)
        );
    }

    // Норма Чебышева
    double chebyshevNorm(const Quaternion& other) const {
        return std::max({
            std::abs(a - other.a),
            std::abs(b - other.b),
            std::abs(c - other.c),
            std::abs(d - other.d)
        });
    }
};