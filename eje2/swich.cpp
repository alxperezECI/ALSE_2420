#include <iostream>

//ejercicio en clase
int main(){
    int x;
    std::cout << "Ingrese un número de 1 a 5 \n";
    std::cin>>x;
    switch (x)
    {
    case 1 /* constant-expression */:
        /* code */
        std::cout<< "Ingresó 1\n";
        break;
    case 2 /* constant-expression */:
        /* code */
        std::cout<< "Ingresó 2\n";
        break;
    case 3 /* constant-expression */:
        /* code */
        std::cout<< "Ingresó 3\n";
        break;
    case 4 /* constant-expression */:
        /* code */
        std::cout<< "Ingresó 4\n";
        break;
    case 5 /* constant-expression */:
        /* code */
        std::cout<< "Ingresó 5\n";
        break;
    
    default:
    std::cout << "No ingresó l número en el rango indicado \n";
        break;
    }

    return 0;
}