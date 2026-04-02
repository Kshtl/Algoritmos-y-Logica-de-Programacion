#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

double comprobarNumeros(string mensaje, double limiteInferior, double limiteSuperior){
    bool numeroValido;
    double numero;

    do{
        cout << mensaje << endl;
        cin >> numero;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            numeroValido = false;
        }else{
            numeroValido = numero >= limiteInferior && numero <= limiteSuperior;
        }

        if(!numeroValido){
            cout << "! Entrada invalida ! El numero que ingresaste fue: " << numero << endl;
        }

    }while(!numeroValido);

    return numero;
}

char comprobarParelo(string mensaje){
    char paralelo;
    bool validarParalelo;

    do{
        cout << mensaje << endl;
        cin >> paralelo;
        paralelo = toupper(paralelo);

        validarParalelo = paralelo == 'A' || paralelo == 'B' || paralelo == 'C';

        if(!validarParalelo){
            cout << "Ese paralelo no existe " << paralelo << endl;
        }

    }while(!validarParalelo);

    return paralelo;
}

double calcularPromedio(double parcialUno, double parcialDos, double practicas){
    double promedio;
    promedio = ((parcialUno*0.3) + (parcialDos*0.3) + (practicas*0.4)); 
    return promedio;
}

string clasificar(double promedio, double asistencia){
    
    if(asistencia < 70){
        return "Reprobado por asistencia";
    }

    if(promedio >= 9){
        if(asistencia < 80){
            cout << "Alerta academica por inconsistencia" << endl;
        }
        return "Excelente";
    }

    if(promedio >= 8) return "Muy bueno";
    if(promedio >= 7) return "Bueno";
    if(promedio >= 6) return "En riesgo";

    return "Reprobado";
}

string analizarRendimiento(double n1, double n2, double n3){
    
    if(n1 == n2 && n2 == n3){
        return "Rendimiento estable";
    }

    double mayor = max(n1, max(n2, n3));
    double menor = min(n1, min(n2, n3));

    if(mayor - menor > 4){
        return "Rendimiento inestable";
    }

    return "Normal";
}

int main()
{
    int limiteA, limiteB, limiteC;
    char paralelo;

    limiteA = comprobarNumeros("Ingrese el numero de estudiantes del paralelo A",0 ,100);
    limiteB = comprobarNumeros("Ingrese el numero de estudiantes del paralelo B",0 ,100);
    limiteC = comprobarNumeros("Ingrese el numero de estudiantes del paralelo C",0 ,100);

    struct PareleloA{
        string nombreEstudiante;
        char paraleloEstudiante;
        double nota1erParcial;
        double nota2doParcial;
        double notaPracticas;
        double perAsistencia;
        double promedio;
        int estado;
        string categoria;
        bool pase;   
    };

    struct PareleloB{
        string nombreEstudiante;
        char paraleloEstudiante;
        double nota1erParcial;
        double nota2doParcial;
        double notaPracticas;
        double perAsistencia;
        double promedio;
        int estado;
        string categoria;
        bool pase;   
    };
    
    struct PareleloC{
        string nombreEstudiante;
        char paraleloEstudiante;
        double nota1erParcial;
        double nota2doParcial;
        double notaPracticas;
        double perAsistencia;
        double promedio;
        int estado;
        string categoria;
        bool pase;   
    };

    int total = limiteA + limiteB + limiteC;

    for(int i = 0; i < total; i++){
        cout << "\nEstudiante " << i+1 << endl;

        string nombre;
        cin.ignore();
        cout << "Nombre: ";
        getline(cin, nombre);

        paralelo = comprobarParelo("Ingresa el paralelo: A - B - C");

        double n1 = comprobarNumeros("Nota 1er Parcial:",0,10);
        double n2 = comprobarNumeros("Nota 2do Parcial:",0,10);
        double np = comprobarNumeros("Nota Practicas:",0,10);
        double asistencia = comprobarNumeros("Asistencia (%):",0,100);

        double promedio = calcularPromedio(n1, n2, np);
        string categoria = clasificar(promedio, asistencia);
        string rendimiento = analizarRendimiento(n1, n2, np);

        cout << "Promedio: " << promedio << endl;
        cout << "Categoria: " << categoria << endl;
        cout << "Rendimiento: " << rendimiento << endl;
    }

    return 0;
}
