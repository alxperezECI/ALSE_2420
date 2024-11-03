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
    double _ValorHE;
    std::vector<HorasExtras> _horasExt;

public:
    Empleado(const std::string &nombre, const std::string &apellido, 
        unsigned int cedula, float salario);

    Empleado();

    std::string nombre() const;
    void setNombre(const std::string &nombre);

    std::string apellido() const;
    void setApellido(const std::string &apellido);

    unsigned int cedula() const;
    void setCedula(unsigned int cedula);

    double salario() const;
    void setSalario(double salario);

    void agregarHorasExtras(int dia, float horas);
    std::vector<HorasExtras> obtenerHorasExtras() const;

    double horasExtras() const;
    double ValorHE() const;
    void setValorHE(double ValorHE);
};

#endif