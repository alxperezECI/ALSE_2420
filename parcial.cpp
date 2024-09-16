#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double vector_x[100] = {0.0};
    double vector_f[100] = {0.0};

    double incremento = 0;
    cout << "Ingrese incremento: " << endl;
    cin >> incremento;

    for (int i = 0; i < 100; i++)
    {
        vector_x[i] = incremento * i;
    }

    for (int i = 0; i < 100; i++)
    {
        vector_f[i] = sin(2 * M_PI * vector_x[i]);
    }

    cout << "x\tf(x)" << endl;
    for (int i = 0; i < 100; i++)
    {
        cout << vector_x[i] << "\t" << vector_f[i] << endl;
    }

    return 0;
}