#include "quaternionlib.h"
using namespace std;


int main() {
    Quaternion q1(1, 2, 3, 4);
    Quaternion q2(2, 3, 4, 5);

    q1.print();
    q2.print();

    Quaternion sum = q1 + q2;
    sum.print();

    Quaternion product = q1 * q2;
    product.print();

    cout << "Norm of q1: " << q1.norm() << endl;
    cout << "Conjugate of q1: ";
    q1.conjugate().print();

    cout << "Normalized q1: ";
    q1.normalize().print();

    cout << "Inverse of q1: ";
    q1.inverse().print();

    cout << "Euclidean distance between q1 and q2: " << q1.euclideanDistance(q2) << endl;
    cout << "Chebyshev norm between q1 and q2: " << q1.chebyshevNorm(q2) << endl;

    return 0;
}
