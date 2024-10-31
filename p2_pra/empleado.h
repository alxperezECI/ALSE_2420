#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <vector>

typedef std::pair<int, float> HorasExtras; // (día, horas)

class Empleado {
    std::string _nombre;
    std::string _apellido;
    unsigned int _cedula;
    double _salario;
    std::vector<HorasExtras> _horasExDia;

public:
    Empleado(const std::string& nombre, const std::string& apellido, 
        const unsigned int& cedula, double salarioMensual);

    void agregarHorasExtras(int dia, float horas);

    void setSalario(double salario);
    double calcular_horas(double valor_hora_extra) const;
    std::string getNombre() const;
    std::string getApellido() const;
    unsigned int getCedula() const;
    double getSalario() const;
};

#endif // EMPLEADO_H