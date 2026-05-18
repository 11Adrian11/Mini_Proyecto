/*
Bootcamp Programación Cero a POO
Clase 11 - Mini-proyecto de C++
Sistema: TecnoStock - Control de Inventario y Ventas
Autor: Adrian Mero Sobenis
Fecha: 17/05/2026
*/

#include <iostream>
using namespace std;

// Definimos el tamaño maximo de nuestro inventario 
const int MAX_PRODUCTOS = 5;


//                      FUNCIONES

void mostrarMenu();
void inicializarInventario(string nombres[], double precios[], int stock[]);
void registrarProductos(string nombres[], double precios[], int stock[]);
void mostrarInventario(const string nombres[], const double precios[], const int stock[]);
void calcularEstadisticas(const string nombres[], const double precios[], const int stock[]);
void buscarProducto(const string nombres[], const double precios[], const int stock[]);
void verificarAlertas(const string nombres[], const int stock[]);


//                         FUNCION PRINCIPAL

int main() {
    
    string nombres[MAX_PRODUCTOS];
    double precios[MAX_PRODUCTOS];
    int stock[MAX_PRODUCTOS];

    
    inicializarInventario(nombres, precios, stock);

    int opcion;
    // Bucle do-while para mantener el menu activo hasta que se elija la opcion Salir (6)
    do {
        mostrarMenu();
        cout << "Seleccione una opcion (1-6): ";
        
        // Validacion por si el usuario ingresa una letra en lugar de un numero
        if (!(cin >> opcion)) {
            cout << "Error: Entrada invalida. Por favor, ingrese un numero.\n";
            cin.clear(); // Limpia el estado de error del cin (ESTO ME TOCO INVESTIGAR Y VER VIDEOS PARA ENTENDER )
            cin.ignore(1000, '\n'); // (ESTO ME TOCO INVESTIGAR Y VER VIDEOS PARA ENTENDER )
            opcion = 0; // Reinicia la opción para continuar el bucle
            continue;
        }

    
        if (opcion == 1) {
            // Opción 1: Sobrescribir o registrar manualmente todos los productos
            registrarProductos(nombres, precios, stock);
        } 
        else if (opcion == 2) {
            // Opción 2: Mostrar la tabla con el reporte general y totales
            mostrarInventario(nombres, precios, stock);
        } 
        else if (opcion == 3) {
            // Opción 3: Procesar operaciones matemáticas (promedio, maximos y minimos)
            calcularEstadisticas(nombres, precios, stock);
        } 
        else if (opcion == 4) {
            // Opción 4: Busqueda lineal de productos por coincidencia de texto
            buscarProducto(nombres, precios, stock); 
        } 
        else if (opcion == 5) {
            // Opción 5: Evaluacion y escaneo preventivo de stocks bajos
            verificarAlertas(nombres, stock); 
        } 
        else if (opcion == 6) {
            // Opcion 6: Mensaje de despedida y cierre del programa
            cout << "\nSaliendo del sistema. ¡Gracias por usar TecnoStock!\n" << endl;
        } 
        else {
            // Filtro para numeros fuera del rango del 1 al 6
            cout << "\nOpcion no valida. Intente de nuevo." << endl;
        }

    } while (opcion != 6); // El ciclo se repite mientras la opción no sea 6

    return 0;
}

//                      DEFINICION DE FUNCIONES

// Muestra el diseño visual del menu de opciones 
void mostrarMenu() {
    cout << endl;
    cout << "=========================================" << endl;
    cout << "     TECNOSTOCK - MENU DE GESTION        " << endl;
    cout << "=========================================" << endl;
    cout << "1. Registrar todos los productos" << endl;
    cout << "2. Mostrar Reporte General de Inventario" << endl;
    cout << "3. Calcular Estadisticas " << endl;
    cout << "4. Buscar Producto por Nombre" << endl;
    cout << "5. Alertas de Stock Critico" << endl;
    cout << "6. Salir del Sistema" << endl;
    cout << "=========================================" << endl;
}

// Carga datos por defecto 
void inicializarInventario(string nombres[], double precios[], int stock[]) {
    nombres[0] = "Mouse_Gamers";  precios[0] = 25.50;  stock[0] = 12;
    nombres[1] = "Teclado_Mec";   precios[1] = 45.00;  stock[1] = 2;   
    nombres[2] = "Monitor_24'";   precios[2] = 180.00; stock[2] = 5;
    nombres[3] = "Audifonos_BT";  precios[3] = 35.99;  stock[3] = 1;   
    nombres[4] = "Laptop_I5";     precios[4] = 750.00; stock[4] = 4;
}

// Permite al usuario llenar de forma manual cada arreglo mediante un bucle interactivo
void registrarProductos(string nombres[], double precios[], int stock[]) {
    cout << "\n--- REGISTRO COMPLETO DE PRODUCTOS ---\n";
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        cout << "\nProducto #" << i + 1 << endl;
        cout << "Nombre: ";
        cin >> nombres[i];

        // Bucle iterativo para asegurar que el precio ingresado no sea negativo
        do {
            cout << "Precio unitario ($): ";
            cin >> precios[i];
            if (precios[i] < 0) cout << "Error: El precio no puede ser negativo.\n";
        } while (precios[i] < 0);

        // Bucle iterativo para asegurar que el stock ingresado no sea negativo
        do {
            cout << "Cantidad en Stock: ";
            cin >> stock[i];
            if (stock[i] < 0) cout << "Error: El stock no puede ser negativo.\n";
        } while (stock[i] < 0);
    }
    cout << "\n¡Inventario actualizado con exito!\n";
}

// Imprime una tabla estructurada con tabuladores y calcula el valor monetario acumulado (ESTO ME COSTO MUCHO HACER )
void mostrarInventario(const string nombres[], const double precios[], const int stock[]) {
    cout << "\n-------------------------------------------------------------\n";
    cout << "                REPORTE GENERAL DE INVENTARIO                \n";
    cout << "-------------------------------------------------------------\n";
    cout << "ID\tProducto\t\tPrecio\tStock\tTotal" << endl;
    cout << "-------------------------------------------------------------\n";
    
    double valorTotalInventario = 0; 
    
    
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        double valorFila = precios[i] * stock[i]; // Multiplicacion de precio por cantidad
        valorTotalInventario = valorTotalInventario + valorFila; // Suma acumulativa
        
        
        cout << (i + 1) << "\t" << nombres[i] << "\t\t" << "$" << precios[i] << "\t" << stock[i] << "\t" << "$" << valorFila << endl;
    }
    cout << "-------------------------------------------------------------\n";
    cout << "Valor total acumulado en bodega: $" << valorTotalInventario << endl;
}


void calcularEstadisticas(const string nombres[], const double precios[], const int stock[]) {
    cout << "\n--- ESTADISTICAS Y ANALISIS DE DATOS ---\n";
    double sumaPrecios = 0;
    int totalUnidades = 0;
    int indiceMayor = 0; // Guardara la posicion del producto mas caro
    int indiceMenor = 0; // Guardara la posicion del producto mas barato

    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        sumaPrecios = sumaPrecios + precios[i]; // Sumamos precios para el promedio 
        totalUnidades = totalUnidades + stock[i]; // Sumamos la cantidad de piezas fisicas
        
        // Sirve para hallar el articulo de mayor precio
        if (precios[i] > precios[indiceMayor]) {
            indiceMayor = i;
        }
        // Sirve para hallar el artículo de menor precio
        if (precios[i] < precios[indiceMenor]) {
            indiceMenor = i;
        }
    }

    // Impresion final de resultados 
    cout << "* Promedio de precios en catalogo: $" << (sumaPrecios / MAX_PRODUCTOS) << endl;
    cout << "* Unidades totales almacenadas: " << totalUnidades << " piezas.\n";
    cout << "* Producto de mayor costo: " << nombres[indiceMayor] << " ($" << precios[indiceMayor] << ")\n";
    cout << "* Producto de menor costo: " << nombres[indiceMenor] << " ($" << precios[indiceMenor] << ")\n";
}

// Compara una cadena de texto ingresada 
void buscarProducto(const string nombres[], const double precios[], const int stock[]) {
    string productoBuscado;
    cout << "\n--- BUSQUEDA DE PRODUCTO ---" << endl;
    cout << "Ingrese el nombre exacto del producto a buscar: ";
    cin >> productoBuscado;
    bool encontrado = false;
    
    // Escaneo secuencial posicion por posicion del arreglo de nombres
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        if (nombres[i] == productoBuscado) {
            cout << "\n¡Producto localizado con exito!" << endl;
            cout << "-> Nombre: " << nombres[i] << endl;
            cout << "-> Precio: $" << precios[i] << endl;
            cout << "-> Stock disponible: " << stock[i] << " unidades." << endl;
            encontrado = true; 
        }
    }

    // Condicional if evaluativo final por si  nunca cambia de estado
    if (!encontrado) {
        cout << "\nLo sentimos, el producto '" << productoBuscado << "' no existe en el sistema." << endl;
    }
}


void verificarAlertas(const string nombres[], const int stock[]) {
    cout << "\n--- ALERTAS DE STOCK CRITICO (MENOS DE 3 UNIDADES) ---" << endl;
    
    bool hayAlertas = false;

    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        if (stock[i] < 3) {
            cout << "[ALERTA] El producto '" << nombres[i] << "' tiene stock critico: ¡Solo quedan " << stock[i] << " unidades!" << endl;
            hayAlertas = true; 
        }
    }


    if (!hayAlertas) {
        cout << "Todo en orden. Todos los productos cuentan con suficiente stock en bodega." << endl;
    }
}