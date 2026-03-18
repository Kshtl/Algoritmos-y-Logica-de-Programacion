#include <iostream>
using namespace std;

int main() {

    int hojas, tipoUsuario, horario, anillado, tipoImpresion;
    float precioHoja, subtotal = 0;
    float descuento = 0, recargo = 0, valorAnillado = 0;
    float total;

    // Entradas
    cout << "Numero de hojas: ";
    cin >> hojas;

    cout << "Tipo de impresion (1=Blanco/Negro, 2=Color): ";
    cin >> tipoImpresion;

    cout << "Tipo de usuario (1=Estudiante, 2=Docente): ";
    cin >> tipoUsuario;

    cout << "Horario (1=Normal, 2=Nocturno): ";
    cin >> horario;

    cout << "Desea anillado? (1=Si, 0=No): ";
    cin >> anillado;

    // Precio por hoja segun tramo
    if (hojas <= 20) {
        precioHoja = 0.05;
    } else {
        if (hojas <= 100) {
            precioHoja = 0.04;
        } else {
            precioHoja = 0.03;
        }
    }

    // Aumento por color
    if (tipoImpresion == 2) {
        precioHoja = precioHoja + 0.02;
    }

    // Subtotal
    subtotal = hojas * precioHoja;

    // Descuento (solo el mayor)
    if (tipoUsuario == 2) { // docente
        descuento = subtotal * 0.05;
    }

    if (tipoUsuario == 1 && hojas > 50) { // estudiante
        float descEst = subtotal * 0.08;

        if (descEst > descuento) {
            descuento = descEst;
        }
    }

    // Recargo nocturno
    if (horario == 2) {
        recargo = subtotal * 0.10;
    }

    // Anillado
    if (anillado == 1) {
        valorAnillado = 2.00;

        if (hojas > 100) {
            valorAnillado = valorAnillado * 0.8; // descuento 20%
        }
    }

    // Total
    total = subtotal - descuento + recargo + valorAnillado;

    // Salidas
    cout << "\nSubtotal impresion: " << subtotal << endl;
    cout << "Descuento aplicado: " << descuento << endl;
    cout << "Recargo: " << recargo << endl;
    cout << "Valor anillado: " << valorAnillado << endl;
    cout << "Total a pagar: " << total << endl;

    return 0;
}
