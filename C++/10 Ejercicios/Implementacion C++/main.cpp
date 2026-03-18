#include <iostream>
#include <string>
using namespace std;

int main() {
    int pedirCredencial, tiempoIngreso, faltas;
    string materiaActual, materiaEstudiante;

    cout << "Administrador ingrese la materia actual: ";
    getline(cin, materiaActual);

    cout << "Estudiante tiene credencial (1=Si, 0=No): ";
    cin >> pedirCredencial;
    cin.ignore(); // limpiar buffer

    if (pedirCredencial == 1) {

        cout << "Estudiante ingrese su materia: ";
        getline(cin, materiaEstudiante);

        if (materiaActual == materiaEstudiante) {

            cout << "Ingrese tiempo de atraso (minutos): ";
            cin >> tiempoIngreso;

            cout << "Ingrese numero de faltas: ";
            cin >> faltas;

            // Lógica completa
            if (faltas >= 5) {
                cout << "NO INGRESA - Exceso de faltas";
            }
            else if (tiempoIngreso > 10) {
                cout << "NO INGRESA - Demasiado tarde";
            }
            else if (faltas >= 3) {
                cout << "INGRESA CON ADVERTENCIA - Muchas faltas";
            }
            else if (tiempoIngreso > 0 && tiempoIngreso <= 10) {
                cout << "INGRESA CON ADVERTENCIA - Llego tarde";
            }
            else {
                cout << "INGRESA SIN PROBLEMA";
            }

        } else {
            cout << "NO INGRESA - No pertenece a la materia";
        }

    } else {
        cout << "NO INGRESA - Sin credencial";
    }

    return 0;
}








