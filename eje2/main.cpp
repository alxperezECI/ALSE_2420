#include <iostream>
#include <stdlib.h>

int main()
{
    //randomizer vector

    int numero, size, M, N, z;
    M = 90;
    N = 250;
    size = 49;
    float vector[size];

    for (int i =0; i<=size; i++)
    {
        numero = rand() % (N-M+1) + M;   // Este está entre M y N
        vector[i] = numero;
    }

    vector[25] = 0; // setea numero 25 en 0
    
    for (int i = 0; i <= size; i++)
    {
        std::cout << vector[i] << " ";

        if ((i + 1) % 5 == 0) 
        {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl << std::endl;

    //ordenamiento burbuja
    do{
        z = 0;
        for (int i = 0; i<size; i++)
        {
            int res;
            if (vector[i]>vector[i+1])
            {
                res = vector[i];
                vector[i]=vector[i+1];
                vector[i+1] = res;
                z = i;
            }
        }
    }
    while(z!=0);
    
    for (int i = 0; i <= size; i++)
    {
        std::cout << vector[i] << " ";

        if ((i + 1) % 5 == 0) 
        {
            std::cout << std::endl;
        }
    }
    return 0;
}