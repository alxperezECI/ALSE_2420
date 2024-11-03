#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>
#include <vector>

typedef std::pair<int, float> HorasExtras; // (día, horas)

class Empleado {
    std::string _nombre, _apellidos;
    unsigned int _cedula;
    double _salarioMensual;
    std::vector<HorasExtras> _horasExDia;
public:
    Empleado();
    Empleado(const std::string& nombre, const std::string& apellido, 
        const unsigned int& cedula, double salarioMensual);

    void agregarHorasExtras(int dia, float horas);
    void setSalarioMensual(double salario);

    double CAL_salarioHorasExtras()const;
    std::string setTrabajador () const;
    double obtener_Salariomensual()const;
    std::vector<std::pair<int, float>> obtener_horasextras()const;
    double Total_horaEx()const;
};
#endif
