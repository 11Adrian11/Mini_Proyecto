/*
Bootcamp Programación Cero a POO
Clase 11 - Mini-proyecto de C++
Sistema: TecnoStock - Control de Inventario y Ventas
Autor: Adrian Mero Sobenis
Fecha: 16/05/2026
*/

#include <iostream>
using namespace std;

void mostrarMenu();

int main() {
    int opcion = 0;
    
   
    do {
        mostrarMenu();
        cout << "Seleccione una opcion (1-6): ";
        cin >> opcion;
        
        if (opcion == 6) {
            cout << "\nSaliendo del sistema..." << endl;
        } else if (opcion < 1 || opcion > 6) {
            cout << "\nOpcion no valida." << endl;
        } else {
            cout << "\n Opcion en desarrollo..." << endl;
        }
    } while (opcion != 6);

    return 0;
}

void mostrarMenu() {
    cout << endl;
    cout << "=========================================" << endl;
    cout << "     TECNOSTOCK - MENU DE GESTION        " << endl;
    cout << "=========================================" << endl;
    cout << "1. Reiniciar/Registrar todos los productos" << endl;
    cout << "2. Mostrar Reporte General de Inventario" << endl;
    cout << "3. Calcular Estadisticas (Totales, Max, Min)" << endl;
    cout << "4. [MEJORA] Buscar Producto por Nombre" << endl;
    cout << "5. [MEJORA] Alertas de Stock Critico" << endl;
    cout << "6. Salir del Sistema" << endl;
    cout << "=========================================" << endl;
}