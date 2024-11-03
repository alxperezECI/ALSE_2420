#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <vector>


typedef std::pair<int, float> HorasExtras; // (día, horas)

class Empleado {
private:
    std::string _nombre;
    std::string _apellido;
    unsigned int _cedula;
    double _salarioMensual;
    std::vector<HorasExtras> _horasExDia;

public:
    // Constructor
    Empleado(const std::string& nombre, const std::string& apellido, 
             unsigned int cedula, double salarioMensual);

    // Métodos
    void asignarSalarioMensual(double salario);
    void agregarHorasExtras(int dia, float horas);
    double calcularValorHorasExtras(double tarifa) const;
    int obtenerTotalHorasExtras() const;
    const std::vector<HorasExtras>& obtenerHorasExtras() const;

    // Getters
    std::string getNombre() const;
    std::string getApellido() const;
    double getSalarioMensual() const;
};

#endif 
