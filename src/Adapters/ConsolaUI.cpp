#include "ConsolaUI.h"

ConsolaUI::ConsolaUI(IAlmacenamiento* db) : almacenamiento(db) {}

// Aquí aplicamos la protección contra fallas de usuario
int ConsolaUI::leerEnteroSeguro() {
    int valor;
    while (!(std::cin >> valor)) {
        std::cin.clear(); // Limpia la bandera de error de C++
        // Descarta el texto incorrecto ingresado hasta el salto de línea
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << "[Error] Entrada invalida. Por favor ingrese un numero valido: ";
    }
    return valor;
}

void ConsolaUI::iniciar() {
    int opcion = 0;
    while (opcion != 3) {
        std::cout << "\n--- SISTEMA DE INVENTARIO ---\n";
        std::cout << "1. Registrar Venta (Reducir Stock)\n";
        std::cout << "2. Ver Inventario Completo\n";
        std::cout << "3. Salir\n";
        std::cout << "Seleccione una opcion: ";
        
        opcion = leerEnteroSeguro(); // Usamos nuestra función segura

        if (opcion == 1) {
            std::cout << "Ingrese el nombre del producto vendido (ej. 'Agua'): ";
            std::string nombre;
            std::cin >> nombre;

            Producto* p = almacenamiento->buscarProducto(nombre);
            if (p != nullptr) {
                std::cout << "Ingrese cantidad a vender: ";
                int cantidad = leerEnteroSeguro();
                
                // Llamamos a la lógica de negocio pura
                bool alerta = p->reducirStock(cantidad);
                almacenamiento->actualizarProducto(*p);

                std::cout << "Venta registrada exitosamente.\n";
                if (alerta) {
                    std::cout << "\n[!!!] ALERTA DE REABASTECIMIENTO [!!!]\n";
                    std::cout << "El producto '" << p->getNombre() << "' cayo por debajo del stock minimo.\n";
                }
            } else {
                std::cout << "[Error] Producto no encontrado en el sistema.\n";
            }
        } 
        else if (opcion == 2) {
            std::cout << "\n-- Estado del Inventario --\n";
            for (const auto& prod : almacenamiento->obtenerTodos()) {
                std::cout << "Producto: " << prod.getNombre() 
                          << " | Stock Actual: " << prod.getStockActual() << "\n";
            }
        }
    }
}