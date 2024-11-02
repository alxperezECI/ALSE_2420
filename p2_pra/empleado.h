#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <vector>
#include <utility> // Incluir <utility> para std::pair

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

    void agregarHorasExtras(int dia, float horas);
    double calcularHorasExtras() const;
    float getTotalHorasExtras() const;
    const std::vector<HorasExtras>& getHorasExtras() const;

    // Métodos de acceso
    std::string getNombreCompleto() const;
    double getSalarioMensual() const;
    double getTotalAPagar() const;
};

#endif // EMPLEADO_H
