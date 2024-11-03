#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <limits>

#include "empleado.h"

using namespace std;

void cargarArchivo(char* file, vector<Empleado>& trabajadores) {
    string nombre, apellido;
    unsigned int cedula;
    double salario;
    int dia;
    float horas;
    string texto;
    stringstream ss;

    ifstream archivo(file); // Intenta abrir el archivo
    if (archivo.is_open()) { // Verifica si se abrió correctamente
        while (!archivo.eof() && getline(archivo, texto)) {
            ss.clear();
            ss << texto; 
            ss >> nombre >> apellido >> cedula >> salario;
            Empleado e(nombre, apellido, cedula, salario);
            while (ss >> dia >> horas) {
                e.agregarHorasExtras(dia, horas);
            }
            trabajadores.push_back(e);
        }
        archivo.close(); // Cierra el archivo
    } else {
        cerr << "No se pudo abrir el archivo: " << file << endl; // Mensaje de error si no se abre
    }
}

int main(int argc, char** argv) {
    vector<Empleado> _trabajadores;
    cargarArchivo(argv[1], _trabajadores); // carga bien
    size_t tam = _trabajadores.size();
    cout << "Número de trabajadores: " << tam << endl;

    // Valor de las horas extra
    double valor_HORA_EXTRA = 1.5; // Define el valor de la hora extra

    // Imprimir encabezado
    cout << "Empleado (Nombre y Apellido) | Salario mensual | Valor de horas extras | Total a pagar" << endl;

    // Variables para almacenar datos necesarios
    int maxHorasExtras = 0, minHorasExtras = numeric_limits<int>::max();
    Empleado* empleadoMaxHoras = nullptr;
    Empleado* empleadoMinHoras = nullptr;
    int diaMaxHoras = 0;
    map<int, float> horasPorDia; // Para registrar horas por día

    // Procesar cada empleado
    for (auto& empleado : _trabajadores) {
        double totalHorasExtras = empleado.calcularValorHorasExtras(valor_HORA_EXTRA);
        double salarioTotal = empleado.getSalarioMensual() + totalHorasExtras;

        cout << empleado.getNombre() << " " << empleado.getApellido() << " | "
             << empleado.getSalarioMensual() << " | " << totalHorasExtras << " | "
             << salarioTotal << endl;

        // Determinar el empleado con más y menos horas extras
        int totalHoras = empleado.obtenerTotalHorasExtras();
        if (totalHoras > maxHorasExtras) {
            maxHorasExtras = totalHoras;
            empleadoMaxHoras = &empleado;
        }
        if (totalHoras < minHorasExtras) {
            minHorasExtras = totalHoras;
            empleadoMinHoras = &empleado;
        }

        // Registrar horas por día para encontrar el día con más horas extras
        for (const auto& horas : empleado.obtenerHorasExtras()) {
            horasPorDia[horas.first] += horas.second;
        }
    }

    // Encontrar el día con mayor número de horas extras
    for (const auto& diaHoras : horasPorDia) {
        if (diaHoras.second > horasPorDia[diaMaxHoras]) {
            diaMaxHoras = diaHoras.first;
        }
    }

    // Reportar el empleado con mayor número de horas extras
    if (empleadoMaxHoras) {
        cout << "\nEmpleado con mayor número de horas extras: "
             << empleadoMaxHoras->getNombre() << " " << empleadoMaxHoras->getApellido()
             << " con " << maxHorasExtras << " horas." << endl;
    }

    // Reportar el empleado con menor número de horas extras
    if (empleadoMinHoras) {
        cout << "Empleado con menor número de horas extras: "
             << empleadoMinHoras->getNombre() << " " << empleadoMinHoras->getApellido()
             << " con " << minHorasExtras << " horas." << endl;
    }

    // Reportar el día con mayor número de horas extras
    cout << "Día con mayor número de horas extras: Día " << diaMaxHoras
         << " con " << horasPorDia[diaMaxHoras] << " horas." << endl;

    return 0;
}
