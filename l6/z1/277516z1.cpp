#include <iostream>

using namespace std;

class Vector3d {
private:
    double x, y, z;

public:
    Vector3d(double a, double b, double c) : x(a), y(b), z(c) {};

    void display() {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }

    friend Vector3d add(Vector3d v, Vector3d w);

    friend Vector3d multiply_by_scalar(Vector3d v, double scalar);

    friend double dot_product(Vector3d v, Vector3d w);

    friend bool is_parallel(Vector3d v, Vector3d w);
    
    friend bool is_perpendicular(Vector3d v, Vector3d w);
};

Vector3d add(Vector3d v, Vector3d w) {
    Vector3d result_vector = Vector3d(
        v.x + w.x,
        v.y + w.y,
        v.z + w.z
    );

    return result_vector;
}

Vector3d multiply_by_scalar(Vector3d v, double scalar) {
    Vector3d result_vector = Vector3d(
        scalar * v.x,
        scalar * v.y,
        scalar * v.z
    );

    return result_vector;
}

double dot_product(Vector3d v, Vector3d w) {
    return v.x * w.x + v.y * w.y + v.z * w.z;
}

bool is_parallel(Vector3d v, Vector3d w) {
    double cross_x = v.y * w.z - v.z * w.y;
    double cross_y = v.z * w.x - v.x * w.z;
    double cross_z = v.x * w.y - v.y * w.x;
    double cross_norm = cross_x * cross_x + cross_y * cross_y + cross_z * cross_z;
    return cross_norm < 1e-10;
}

bool is_perpendicular(Vector3d v, Vector3d w) {
    return dot_product(v, w) == 0;
}

int main()
{
    double v1, v2, v3, w1, w2, w3, a;
    cin >> v1 >> v2 >> v3 >> w1 >> w2 >> w3 >> a;

    Vector3d v = Vector3d(v1, v2, v3), w = Vector3d(w1, w2, w3);

    Vector3d av = multiply_by_scalar(v, a);
    av.display(); cout << endl;

    Vector3d sum = add(v, w);
    sum.display(); cout << endl;

    double l_dot_product = dot_product(v, w);
    cout << l_dot_product << endl;

    if (is_parallel(v, w)) cout << "v i w sa rownolegle" << endl;
    else cout << "v i w nie sa rownolegle" << endl;

    if (is_perpendicular(v, w)) cout << "v i w sa prostopadle" << endl;
    else cout << "v i w nie sa prostopadle" << endl;

    return 0;
}