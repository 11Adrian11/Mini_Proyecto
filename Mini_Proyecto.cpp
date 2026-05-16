/*
Bootcamp Programación Cero a POO
Clase 11 - Mini-proyecto de C++
Sistema: TecnoStock - Control de Inventario y Ventas
Autor: Adria Mero Sobenis
Fecha: 16/05/2026
*/

#include <iostream>
using namespace std;

const int MAX_PRODUCTOS = 5;

void mostrarMenu();
void inicializarInventario(string nombres[], double precios[], int stock[]);
void registrarProductos(string nombres[], double precios[], int stock[]);

int main() {
    string nombres[MAX_PRODUCTOS];
    double precios[MAX_PRODUCTOS];
    int stock[MAX_PRODUCTOS];

    inicializarInventario(nombres, precios, stock);

    int opcion;
    do {
        mostrarMenu();
        cout << "Seleccione una opcion (1-6): ";
        
        if (!(cin >> opcion)) {
            cout << "Error: Entrada invalida.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            opcion = 0;
            continue;
        }

        if (opcion == 1) {
            registrarProductos(nombres, precios, stock);
        } 
        else if (opcion == 2) {
            cout << "\n[Proximamente] Reporte general de inventario..." << endl;
        } 
        else if (opcion == 3) {
            cout << "\n[Proximamente] Estadisticas..." << endl;
        } 
        else if (opcion == 4) {
            cout << "\n[Proximamente] Buscar producto..." << endl;
        } 
        else if (opcion == 5) {
            cout << "\n[Proximamente] Verificar alertas..." << endl;
        } 
        else if (opcion == 6) {
            cout << "\nSaliendo del sistema..." << endl;
        } 
        else {
            cout << "\nOpcion no valida. Intente de nuevo." << endl;
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

void inicializarInventario(string nombres[], double precios[], int stock[]) {
    nombres[0] = "Mouse_Gamers";  precios[0] = 25.50;  stock[0] = 12;
    nombres[1] = "Teclado_Mec";   precios[1] = 45.00;  stock[1] = 2;   
    nombres[2] = "Monitor_24'";   precios[2] = 180.00; stock[2] = 5;
    nombres[3] = "Audifonos_BT";  precios[3] = 35.99;  stock[3] = 1;   
    nombres[4] = "Laptop_I5";     precios[4] = 750.00; stock[4] = 4;
}

void registrarProductos(string nombres[], double precios[], int stock[]) {
    cout << "\n--- REGISTRO COMPLETO DE PRODUCTOS ---\n";
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        cout << "\nProducto #" << i + 1 << endl;
        cout << "Nombre (use guiones bajos para espacios): ";
        cin >> nombres[i];

        do {
            cout << "Precio unitario ($): ";
            cin >> precios[i];
        } while (precios[i] < 0);

        do {
            cout << "Cantidad en Stock: ";
            cin >> stock[i];
        } while (stock[i] < 0);
    }
    cout << "\n¡Inventario actualizado con exito!\n";
}