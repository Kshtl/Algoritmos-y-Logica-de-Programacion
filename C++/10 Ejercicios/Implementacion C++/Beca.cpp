#include <iostream>
using namespace std;

int main() {

    float promedio, asistencia, ingresos;
    int materiasPerdidas, participaProyecto;
    string tipoAyuda, razonAcademica, razonEconomica, observacion;


    cout << "Ingrese promedio: ";
    cin >> promedio;

    cout << "Ingrese porcentaje de asistencia: ";
    cin >> asistencia;

    cout << "Ingrese numero de materias perdidas: ";
    cin >> materiasPerdidas;

    cout << "Ingrese ingresos familiares: ";
    cin >> ingresos;

    cout << "Participa en proyectos? (1=Si, 0=No): ";
    cin >> participaProyecto;


    if (promedio < 7) {
        tipoAyuda = "Sin beneficio";
        razonAcademica = "Promedio menor a 7";
    }
    else {

        if (asistencia < 80) {
            tipoAyuda = "Sin beneficio";
            razonAcademica = "Asistencia menor al 80%";
        }
        else {

            if (promedio >= 9 && asistencia >= 90 && materiasPerdidas == 0) {
                tipoAyuda = "Beca completa";
                razonAcademica = "Alto rendimiento academico";
            }
            else {

                if (promedio >= 8 && promedio < 9 && asistencia >= 85) {
                    tipoAyuda = "Beca parcial";
                    razonAcademica = "Buen rendimiento academico";
                }
                else {
                    tipoAyuda = "Ayuda de materiales";
                    razonAcademica = "Cumple condiciones basicas";
                }

                if (materiasPerdidas > 1) {
                    if (tipoAyuda == "Beca completa") {
                        tipoAyuda = "Beca parcial";
                    }
                }
            }
        }
    }


    if (participaProyecto == 1 && ingresos < 500) {

        razonEconomica = "Ingresos bajos y participa en proyectos";

        if (tipoAyuda == "Ayuda de materiales") {
            tipoAyuda = "Beca parcial";
        }
        else if (tipoAyuda == "Beca parcial" && materiasPerdidas == 0) {
            tipoAyuda = "Beca completa";
        }

    } else {
        razonEconomica = "No cumple condiciones economicas especiales";
    }

    observacion = "Evaluacion final realizada";

    cout << "Tipo de ayuda: " << tipoAyuda << endl;
    cout << "Razon academica: " << razonAcademica << endl;
    cout << "Razon economica: " << razonEconomica << endl;
    cout << "Observacion: " << observacion << endl;

    return 0;
}





