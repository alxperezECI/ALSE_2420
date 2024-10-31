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
    void asigna_salario_mensual( double salarioMensual );    
    double Empleado::calcular_horas_extras( double salarioMensual, float horasExtras );

    std::string getNombre() const { return _nombre; }
    std::string getApellido() const { return _apellido; }
    unsigned int getCedula() const { return _cedula; }
    double getSalarioMensual() const { return _salarioMensual; }
    std::vector<HorasExtras> getHorasExtras() const { return _horasExDia; }

    void setNombre( std::string nombre ) { _nombre = nombre; }
    void setApellido( std::string apellido ) { _apellido = apellido; }
    void setCedula( unsigned int cedula ) { _cedula = cedula; }
    void setSalarioMensual( double salarioMensual ) { _salarioMensual = salarioMensual; }
    void setHorasExtras( std::vector<HorasExtras> horasExtras ) { _horasExDia = horasExtras; }
};

#endif // EMPLEADO_H