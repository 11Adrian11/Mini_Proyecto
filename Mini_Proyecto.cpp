/*
Bootcamp Programación Cero a POO
Clase 11 - Mini-proyecto de C++
Sistema: TecnoStock - Control de Inventario y Ventas
Autor: Adrian Mero Sobenis
Fecha: 17/05/2026
*/

#include <iostream>
using namespace std;

const int MAX_PRODUCTOS = 5;

void mostrarMenu();
void inicializarInventario(string nombres[], double precios[], int stock[]);
void registrarProductos(string nombres[], double precios[], int stock[]);
void mostrarInventario(const string nombres[], const double precios[], const int stock[]);
void calcularEstadisticas(const string nombres[], const double precios[], const int stock[]);

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
            mostrarInventario(nombres, precios, stock); 
        } 
        else if (opcion == 3) {
            calcularEstadisticas(nombres, precios, stock); 
        } 
        else if (opcion == 4) {
            cout << "\n Buscar producto por nombre..." << endl;
        } 
        else if (opcion == 5) {
            cout << "\n Verificar alertas de stock..." << endl;
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
    cout << "1. Registrar todos los productos" << endl;
    cout << "2. Mostrar Reporte General de Inventario" << endl;
    cout << "3. Calcular Estadisticas (Totales, Max, Min)" << endl;
    cout << "4. Buscar Producto por Nombre" << endl;
    cout << "5. Alertas de Stock Critico" << endl;
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
        cout << "Nombre: ";
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

void mostrarInventario(const string nombres[], const double precios[], const int stock[]) {
    cout << "\n-------------------------------------------------------------\n";
    cout << "                REPORTE GENERAL DE INVENTARIO                \n";
    cout << "-------------------------------------------------------------\n";
    cout << "ID\tProducto\t\tPrecio\tStock\tTotal" << endl;
    cout << "-------------------------------------------------------------\n";
    
    double valorTotalInventario = 0;
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        double valorFila = precios[i] * stock[i];
        valorTotalInventario = valorTotalInventario + valorFila;
        cout << (i + 1) << "\t" << nombres[i] << "\t\t" << "$" << precios[i] << "\t" << stock[i] << "\t" << "$" << valorFila << endl;
    }
    cout << "-------------------------------------------------------------\n";
    cout << "Valor total acumulado en bodega: $" << valorTotalInventario << endl;
}

void calcularEstadisticas(const string nombres[], const double precios[], const int stock[]) {
    cout << "\n--- ESTADISTICAS Y ANALISIS DE DATOS ---\n";
    double sumaPrecios = 0;
    int totalUnidades = 0;
    int indiceMayor = 0;
    int indiceMenor = 0;

    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        sumaPrecios = sumaPrecios + precios[i];
        totalUnidades = totalUnidades + stock[i];
        if (precios[i] > precios[indiceMayor]) indiceMayor = i;
        if (precios[i] < precios[indiceMenor]) indiceMenor = i;
    }

    cout << "* Promedio de precios en catalogo: $" << (sumaPrecios / MAX_PRODUCTOS) << endl;
    cout << "* Unidades totales almacenadas: " << totalUnidades << " piezas.\n";
    cout << "* Producto de mayor costo: " << nombres[indiceMayor] << " ($" << precios[indiceMayor] << ")\n";
    cout << "* Producto de menor costo: " << nombres[indiceMenor] << " ($" << precios[indiceMenor] << ")\n";
}