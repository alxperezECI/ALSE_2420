#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip> // Añadir esta línea para usar std::fixed y std::setprecision

#include "empleado.h"

using namespace std;

void cargarArchivo(const char* file, vector<Empleado> &trabajadores) {
    string nombre, apellido;
    unsigned int cedula;
    double salario;
    int dia;
    float horas;
    
    string texto;
    stringstream ss;
    
    ifstream archivo(file);
    if (archivo.is_open()) {
        while (getline(archivo, texto)) {
            ss.clear();
            ss.str(texto);
            ss >> nombre >> apellido >> cedula >> salario;
            Empleado e(nombre, apellido, cedula, salario);
            while (ss >> dia >> horas) {
                e.agregarHorasExtras(dia, horas);
            }
            trabajadores.push_back(e);
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo: " << file << endl;
    }
}

void imprimirEmpleados(const vector<Empleado>& trabajadores) {
    cout << "Empleado (Nombre y Apellido) | Salario mensual | Horas extras | Valor Horas Extras" << endl;
    for (const auto& empleado : trabajadores) {
        cout << fixed << setprecision(2); // Establecer formato fijo y precisión de 2 decimales
        cout << empleado.nombre() << " " << empleado.apellido() << " | "
             << empleado.salario() << " | "
             << empleado.horasExtras() << " | "
             << empleado.ValorHE() << endl;
    }
}

void calcularHorasExtras(vector<Empleado>& trabajadores) {
    for (auto& empleado : trabajadores) {
        double salario = empleado.salario();
        double salarioPorHora = salario / 240;
        double totalHorasExtras = 0;
        for (const auto& horasExtra : empleado.obtenerHorasExtras()) {
            totalHorasExtras += horasExtra.second;
        }
        double ValorHorasExtras = (totalHorasExtras * salarioPorHora);
        empleado.setValorHE(ValorHorasExtras);
    }
}

void MayorHE(vector<Empleado>& trabajadores) {
    double mayor = 0;
    string nombre;
    string apellido;
    for (const auto& empleado : trabajadores) {
        if (empleado.horasExtras() > mayor) {
            mayor = empleado.horasExtras();
            nombre = empleado.nombre();
            apellido = empleado.apellido();
        }
    }
    cout << "El empleado con mayor número de horas extras es: " << nombre << " " << apellido << " con " << mayor << " horas extras." << endl;
}

void MenorHE(vector<Empleado>& trabajadores) {
    if (trabajadores.empty()) {
        cout << "No hay empleados para evaluar." << endl;
        return;
    }

    double menor = trabajadores[0].horasExtras();
    string nombre = trabajadores[0].nombre();
    string apellido = trabajadores[0].apellido();

    for (const auto& empleado : trabajadores) {
        if (empleado.horasExtras() < menor) {
            menor = empleado.horasExtras();
            nombre = empleado.nombre();
            apellido = empleado.apellido();
        }
    }
    cout << "El empleado con menor número de horas extras es: " << nombre << " " << apellido << " con " << menor << " horas extras." << endl;
}

void DiaMayorHE(const vector<Empleado>& trabajadores) {
    vector<double> horasPorDia(31, 0.0); // Asumiendo que los días van del 1 al 30

    // Sumar las horas extras por día
    for (const auto& empleado : trabajadores) {
        for (const auto& horasExtra : empleado.obtenerHorasExtras()) {
            horasPorDia[horasExtra.first] += horasExtra.second;
        }
    }

    // Encontrar el día con mayor número de horas extras
    int diaMayor = -1;
    double maxHoras = 0;
    for (int dia = 1; dia <= 30; ++dia) {
        if (horasPorDia[dia] > maxHoras) {
            maxHoras = horasPorDia[dia];
            diaMayor = dia;
        }
    }

    if (diaMayor != -1) {
        cout << "El día con mayor número de horas extras es el día " << diaMayor << " con " << maxHoras << " horas extras." << endl;
    } else {
        cout << "No se encontraron horas extras." << endl;
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <nombre_del_archivo>" << endl;
        return 1;
    }

    vector<Empleado> _trabajadores;
    
    cargarArchivo(argv[1], _trabajadores);
    size_t tam = _trabajadores.size();
    cout << "Número de trabajadores: " << tam << endl;

    calcularHorasExtras(_trabajadores);
    imprimirEmpleados(_trabajadores);

    MayorHE(_trabajadores);
    MenorHE(_trabajadores);
    DiaMayorHE(_trabajadores);

    return 0;
}
