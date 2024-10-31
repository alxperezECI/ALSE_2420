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

    void agregarHorasExtras(int dia, float horas) ;
    void getSalarioMensual(double salarioMensual) { _salarioMensual = salarioMensual; }
    std::string getNombre() const { return _nombre; }
    std::string getApellido() const { return _apellido; }
    double getSalarioMensual() const { return _salarioMensual; }
    std::vector<HorasExtras> getHorasExtras() const { return _horasExDia; }
    double getSalarioTotal() const;
};

#endif // EMPLEADO_H

// sd