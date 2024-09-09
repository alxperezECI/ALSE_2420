#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <random>

using namespace std;

int main()
{
    float numeros[50];
    float aleatorio;
    int n = 0;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(90.0, 250.0);

    // llenado de vector con ceros

    for (int i = 0; i < 50; i++)
    {
        numeros[i] = 0.0;
    }

    // llenado de vector con numeros aleatorios

    for (int i = 0; i < 50; i++)
    {
        if (i != 25)
        {
            aleatorio = dist(gen);
            // cout << aleatorio << "ya" << endl;
            numeros[i] = aleatorio;
        }
        else
        {
            numeros[i] = 0.0;
        }
    }

    // impresion en la salida standar 10 columnas 5 filas

    for (int i = 0; i < 50; i++)
    {
        if (n != 9)
        {
            cout << "|" << numeros[i] << " ";
            n++;
        }
        else
        {
            cout << "|" << numeros[i] << endl;
            n = 0;
        }
    }

    // ordenamiento burbuja

    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50 - 1; j++)
        {
            if (numeros[j] > numeros[j + 1])
            {
                float temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }

    // impresion en la salida standar 10 columnas 5 filas
    // otra vez

    cout << "|-------------------------------------------------------" << endl;

    for (int i = 0; i < 50; i++)
    {
        if (n != 9)
        {
            cout << "|" << numeros[i] << " ";
            n++;
        }
        else
        {
            cout << "|" << numeros[i] << endl;
            n = 0;
        }
    }

    return 0;
}