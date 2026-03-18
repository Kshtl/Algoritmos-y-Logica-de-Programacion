#include <iostream>
using namespace std;

int main() {

    float ladoA, ladoB, ladoC, altura, angulo;
    string tipoLados, tipoAngulo, mensaje;
    float area;

    cout << "Ingrese lado 1: ";
    cin >> ladoA;

    cout << "Ingrese lado 2: ";
    cin >> ladoB;

    cout << "Ingrese lado 3: ";
    cin >> ladoC;

    cout << "Ingrese altura: ";
    cin >> altura;

    cout << "Ingrese angulo principal: ";
    cin >> angulo;


    if (ladoA + ladoB > ladoC && ladoA + ladoC > ladoB && ladoB + ladoC > ladoA) {

        cout << "\nValidez: TRIANGULO VALIDO" << endl;

        if (ladoA == ladoB && ladoB == ladoC) {
            tipoLados = "Equilatero";
        } else {
            if (ladoA == ladoB || ladoA == ladoC || ladoB == ladoC) {
                tipoLados = "Isosceles";
            } else {
                tipoLados = "Escaleno";
            }
        }

        // 3. Clasificacion por angulo
        if (angulo == 90) {
            tipoAngulo = "Rectangulo";
        } else {
            if (angulo < 90) {
                tipoAngulo = "Acutangulo";
            } else {
                tipoAngulo = "Obtusangulo";
            }
        }

        area = (ladoA * altura) / 2;

        if (altura > ladoA || altura > ladoB || altura > ladoC) {
            mensaje = "Advertencia: altura inconsistente";
        } else {
            mensaje = "Altura consistente";
        }

        cout << "Tipo por lados: " << tipoLados << endl;
        cout << "Tipo por angulos: " << tipoAngulo << endl;
        cout << "Area: " << area << endl;
        cout << mensaje << endl;

    } else {
        cout << "Validez: NO ES TRIANGULO" << endl;
    }

    return 0;
}
