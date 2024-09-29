#include <iostream>
#include <cmath> // para las operaciones matematicas como atan2 y sqrt
using namespace std;

struct complex {
    double re;// la parte real de tipo double
    double im;// la parte imaginaria de tipo double

    // asignamos valores cualquiera a las variables re y im
    complex(double r = 0.0, double i = 0.0) {
      re= r; 
      im = i;
    }
};

/*Como nos piden crear variables del tipo seguro , lo que hacemos aqui es asignarles un const, que
no permita que los valores que pasen por la funcion, puedan ser cambiados y dañen su ejecucion*/

/*Posteriormente pasamos la parte real e imaginaria de la variable compleja a , por una libreria (atan2)
que nos permita obtener el angulo de dicho elemeto complejo*/
double angle(const complex& a) {
    return atan2(a.im, a.re);
}
/*Para magnitude lo que hacemos es implementar el algoritmo matematico que me permite obtenerla , y este
seria elevar la parte real e imaginaria a la 2 , que seria el equivalente de multiplicarlos por ellos
mismos respectivamente para posteriormente sumarlos y sacar la raiz con (sqrt)*/

double magnitude(const complex& a) {
    return sqrt(a.re * a.re + a.im * a.im); //aqui asignamos a pero tambien le podemos pasar otras variables como b
}

/*Para el conjugado lo unico que hacemos es tomar el numero complejo que nos estan dando y posteriormente
cambiarle el signo de la parte imaginaria multiplicandolo por (-) */
complex conjugate(const complex& a) {
    return complex(a.re, -a.im);
}

// Aqui declaramos un operador que me haga la suma de la parte real de la variable a con la variable b
// y se hace lo mismo para la parte imaginaria
const complex operator+(const complex& a, const complex& b) {
    return complex(a.re + b.re, a.im + b.im);
}
// Se hace lo mismo que en la funcion anterior pero en lugar sumar las partes reales e imaginarias aqui las restan
const complex operator-(const complex& a, const complex& b) {
    return complex(a.re - b.re, a.im - b.im);
}

/*Para la multiplicacion se tiene que hacer aplicar un propiedad distributiva que ejemplifico en la formula
de la parte de abajo
Fórmula final:
(a+bi)×(c+di)=(ac−bd)+(ad+bc)i*/
const complex operator*(const complex& a, const complex& b) {
    return complex(a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re);
}

/*Para la comparacion entre variables usando un booliano lo que hacemos es comparar la parte real y agregamos
una condicion && donde tambien se deben de comparar y ser iguales las partes imaginarias para que arroje un
1 o 0 respectivamente */
bool operator==(const complex& a, const complex& b) {
    return (a.re == b.re && a.im == b.im);
}

/*Al principio establecimos la condicion como magnitude(a) < magnitude(b) && angle(a) < angle(b) , pero no imprimia 
nada al momento de compilar en el main , por lo que usamos el || para que fuera mas flexible en la comparacion ,ademas
de que no agregar el (==) no ejecuta correctamente el ordenamiento*/
bool operator<(const complex& a, const complex& b) {
    return magnitude(a) < magnitude(b) || ( magnitude(a) == magnitude(b) && angle(a) < angle(b));
}

/*Aqui se hace lo mismo que en la anterior funcion la unica diferencia es la comparacion >*/
bool operator>(const complex& a, const complex& b) {
    return magnitude(a) > magnitude(b) || (magnitude(a) == magnitude(b) && angle(a) > angle(b));
}

/*Es una sobrecarga especial por que me permite mediante un unico llamado de ostream obtener todos los resultados
de los parametros que se pasan a las funciones previamente implementadas y para usarlo solo tuvimos que volverlo en 
const y declarar una salida  (out << a.re << " + " << a.im << "i";) para imprimirlo en su forma imaginaria*/

ostream& operator<<(ostream& out, const complex& a) { // quitamos el std:: ya que estamos usando el namespace std;
    out << a.re << " + " <<"(" << a.im << ")"<< "i"; // agregamos unos parentesis por si la parte imaginaria es negativa
    return out;
}

