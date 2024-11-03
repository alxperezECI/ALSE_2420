#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <vector>

typedef std::pair<int, float> HorasExtras; // (día, horas)
class Empleado {
    std::string _nombre;
    std::string _apellido;
    unsigned int _cedula;
    double _salarioMensual;
    std::vector<HorasExtras> _horasExDia;

public:
    Empleado(const std::string& nombre, const std::string& apellido, 
        const unsigned int& cedula, double salarioMensual);

    void agregarHorasExtras(const int &dia, const float &horas) ;
    float numhorasextra();
    float valorhorasextra();
    //Funciones get
    std::string getnombre_apellido();
    unsigned int getsalariomensual();
    int getdia();
    float gethorasdia();
    std::vector<HorasExtras> gethoras_exdia();
    //funcion set para asignar el salario mensual
    void asignarsalario(const double &s);
};

#endif // EMPLEADO_H