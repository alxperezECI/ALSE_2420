#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "empleado.h"

void cargarArchivo(const char* file, std::vector<Empleado>& trabajadores) {
    std::string nombre, apellido;
    unsigned int cedula;
    double salario;
    int dia;
    float horas;
    std::string texto;
    std::stringstream ss;

    std::ifstream archivo(file);
    if (archivo.is_open()) {
        while (!archivo.eof() && getline(archivo, texto)) {
            ss.clear();
            ss << texto;
            ss >> nombre >> apellido >> cedula >> salario;
            Empleado e(nombre, apellido, salario, std::to_string(cedula));
            while (ss >> dia >> horas) {
                e.agregarHorasExtras(dia, horas);
            }
            trabajadores.push_back(e);
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo " << file << std::endl;
    }
}

int main() {
    std::vector<Empleado> empleados;
    cargarArchivo("datos.txt", empleados);

    if (empleados.empty()) {
        std::cout << "No se encontraron empleados en el archivo." << std::endl;
        return 1;
    }

    Empleado empleadoConMasHorasExtras = empleados[0];
    Empleado empleadoConMenosHorasExtras = empleados[0];
    
    for (const Empleado& empleado : empleados) {
        if (empleado.obtenerTotalHorasExtras() > empleadoConMasHorasExtras.obtenerTotalHorasExtras()) {
            empleadoConMasHorasExtras = empleado;
        }
        if (empleado.obtenerTotalHorasExtras() < empleadoConMenosHorasExtras.obtenerTotalHorasExtras()) {
            empleadoConMenosHorasExtras = empleado;
        }
    }

    std::cout << "El empleado con más horas extra es: " 
              << empleadoConMasHorasExtras.obtenerNombreCompleto() 
              << " con " << empleadoConMasHorasExtras.obtenerTotalHorasExtras() 
              << " horas." << std::endl;

    std::cout << "El empleado con menos horas extra es: " 
              << empleadoConMenosHorasExtras.obtenerNombreCompleto() 
              << " con " << empleadoConMenosHorasExtras.obtenerTotalHorasExtras() 
              << " horas." << std::endl;

    // Reporte detallado de cada empleado
    std::cout << "\nReporte de Empleados:\n";
    std::cout << std::fixed << std::setprecision(2);

    for (const Empleado& empleado : empleados) {
        int diaConMasHoras = empleado.obtenerDiaConMasHorasExtras();
        std::cout << "Cedula: " << empleado.obtenerCodigo() 
                  << " | Nombre: " << empleado.obtenerNombreCompleto() 
                  << " | Salario Base: " << empleado.obtenerSalarioBase()
                  << " | Salario Total: " << empleado.calcularSalarioTotal() 
                  << " | Horas Extras: " << empleado.obtenerTotalHorasExtras()
                  << " | Día con más horas extras: " << diaConMasHoras 
                  << std::endl;
    }

    
    int diaConMasHorasGlobal = -1;
    float maxHorasGlobal = 0.0;

    for (const auto& empleado : empleados) {
        int diaConMasHoras = empleado.obtenerDiaConMasHorasExtras();
        float horasEnEseDia = empleado.obtenerHorasEnDia(diaConMasHoras);

        if (horasEnEseDia > maxHorasGlobal) {
            maxHorasGlobal = horasEnEseDia;
            diaConMasHorasGlobal = diaConMasHoras;
        }
    }

    std::cout << "\nEl día con más horas extras entre todos los empleados es el día " 
              << diaConMasHorasGlobal << " con " << maxHorasGlobal << " horas." << std::endl;

    return 0;
}
