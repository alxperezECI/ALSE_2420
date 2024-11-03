#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <vector>

using namespace std;

typedef pair<int, float> HorasExtras;

class Empleado {
    std::string _nombre;
    std::string _apellido;
    unsigned int _cedula;
    double _salarioMensual;
    std::vector<HorasExtras> _horasExDia;

public:
    // Constructor
    Empleado(const std::string& nombre, const std::string& apellido, 
             const unsigned int& cedula, double salarioMensual);

    void agregarHorasExtras(const int &dia, const float &horas);
    float horasextras() const;
    float valorhorasextra() const;
    string getnombre_apellido() const;
    unsigned int getsalariomensual() const;
    vector<HorasExtras> gethoras() const;
    void asignarsalario(const double &s);
};

#endif
//Entregable por Miguel Angel Pardo y Juan David Ospina