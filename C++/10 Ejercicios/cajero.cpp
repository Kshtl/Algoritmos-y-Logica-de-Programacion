#include <iostream>
using namespace std;

int main() {

    double saldoUsuario = 0, montoDeposito, montoRetiro;
    string opcionMenu;

    // Billetes disponibles en el cajero
    int billetes20Disponibles = 10;
    int billetes10Disponibles = 10;
    int billetes5Disponibles = 10;
    int billetes1Disponibles = 10;

    do {

        cout << "\nMenu de Operaciones\n";
        cout << "1 - Ver saldo\n";
        cout << "2 - Depositar\n";
        cout << "3 - Retirar\n";
        cout << "4 - Salir\n";

        cin >> opcionMenu;

        switch (stoi(opcionMenu)) {

        case 1:
            cout << "Saldo actual: " << saldoUsuario << endl;

            if (saldoUsuario == 0) {
                cout << "Saldo en 0, ingrese un deposito: ";
                cin >> saldoUsuario;
                cout << "Nuevo saldo: " << saldoUsuario << endl;
            }
            break;

        case 2:
            cout << "Ingrese monto a depositar: ";
            cin >> montoDeposito;

            if (montoDeposito > 0) {
                saldoUsuario += montoDeposito;
                cout << "Deposito exitoso. Saldo: " << saldoUsuario << endl;
            } else {
                cout << "Error: monto invalido" << endl;
            }
            break;

        case 3: {
            cout << "Ingrese monto a retirar: ";
            cin >> montoRetiro;

            if (montoRetiro <= 0) {
                cout << "Error: monto invalido" << endl;
                break;
            }

            if (montoRetiro > saldoUsuario) {
                cout << "Error: saldo insuficiente" << endl;
                break;
            }

            int efectivoTotalCajero =
                billetes20Disponibles * 20 +
                billetes10Disponibles * 10 +
                billetes5Disponibles * 5 +
                billetes1Disponibles;

            if (montoRetiro > efectivoTotalCajero) {
                cout << "Error: cajero sin efectivo suficiente" << endl;
                break;
            }

            int montoRestante = montoRetiro;

            int billetes20Entregados = min(montoRestante / 20, billetes20Disponibles);
            montoRestante -= billetes20Entregados * 20;

            int billetes10Entregados = min(montoRestante / 10, billetes10Disponibles);
            montoRestante -= billetes10Entregados * 10;

            int billetes5Entregados = min(montoRestante / 5, billetes5Disponibles);
            montoRestante -= billetes5Entregados * 5;

            int billetes1Entregados = min(montoRestante / 1, billetes1Disponibles);
            montoRestante -= billetes1Entregados * 1;

            if (montoRestante != 0) {
                cout << "Error: no se puede entregar el monto exacto" << endl;
            } else {

                // Actualizar cajero
                billetes20Disponibles -= billetes20Entregados;
                billetes10Disponibles -= billetes10Entregados;
                billetes5Disponibles -= billetes5Entregados;
                billetes1Disponibles -= billetes1Entregados;

                saldoUsuario -= montoRetiro;

                cout << "Retiro exitoso\n";
                cout << "Billetes entregados:\n";
                cout << "20: " << billetes20Entregados << endl;
                cout << "10: " << billetes10Entregados << endl;
                cout << "5: " << billetes5Entregados << endl;
                cout << "1: " << billetes1Entregados << endl;

                cout << "Saldo restante: " << saldoUsuario << endl;

                int efectivoRestanteCajero =
                    billetes20Disponibles * 20 +
                    billetes10Disponibles * 10 +
                    billetes5Disponibles * 5 +
                    billetes1Disponibles;

                cout << "Efectivo restante en cajero: " << efectivoRestanteCajero << endl;
            }

            break;
        }

        case 4:
            cout << "Saliendo..." << endl;
            break;

        default:
            cout << "Opcion invalida" << endl;
        }

    } while (opcionMenu != "4");

    cout << "Saldo final: " << saldoUsuario << endl;

    return 0;
}
