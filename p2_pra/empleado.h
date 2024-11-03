#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <vector>

class Empleado {
private:
    std::string nombre;
    std::string apellido;
    float salarioBase;
    std::string codigo;
    std::vector<std::pair<int, float>> listaHorasExtras;

public:
    Empleado(const std::string& nombre, const std::string& apellido, 
             float salarioBase, const std::string& codigo);

    void agregarHorasExtras(int dia, float horas);
    float calcularSalarioTotal() const;
    float obtenerTotalHorasExtras() const;
    int obtenerDiaConMasHorasExtras() const;
    float obtenerSalarioBase() const;
    std::string obtenerNombreCompleto() const;
    std::string obtenerCodigo() const;
    float obtenerHorasEnDia(int dia) const;
};

#endif 
