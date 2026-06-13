#include "ConsolaUI.h"

ConsolaUI::ConsolaUI(IAlmacenamiento* db) : almacenamiento(db) {}

int ConsolaUI::leerEnteroSeguro() {
    int valor;
    while (!(std::cin >> valor)) {
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << "[ERROR] Entrada invalida. Ingrese un numero entero: ";
    }
    return valor;
}

void ConsolaUI::iniciar() {
    int opcion = 0;
    while (opcion != 3) {
        std::cout << "\n======================================================\n";
        std::cout << "          CORESTOCK v2.0 - POSTGRES SQL SCHEMA        \n";
        std::cout << "======================================================\n";
        std::cout << "1. Registrar Despacho (Validacion de stock)\n";
        std::cout << "2. Ver Monitor de Stock Activo (Ficha Completa)\n";
        std::cout << "3. Salir del Sistema\n";
        std::cout << "Seleccione una opcion: ";
        
        opcion = leerEnteroSeguro();

        if (opcion == 1) {
            std::cout << "\nIngrese el nombre del producto (ej. 'Agua Mineral Pureza'): ";
            std::string nombre;
            std::cin.ignore(); 
            std::getline(std::cin, nombre); 

            Producto* p = almacenamiento->buscarProducto(nombre);
            if (p != nullptr) {
                std::cout << "Ubicacion asignada: " << p->getSede() << "\n";
                std::cout << "Cantidad a retirar: ";
                int cantidad = leerEnteroSeguro();
                
                try {
                    bool alerta = p->reducirStock(cantidad);
                    almacenamiento->actualizarProducto(*p);

                    std::cout << "\n[OK] Despacho completado con exito desde PostgreSQL.\n";
                    if (alerta) {
                        std::cout << "\n[!!!] REORDEN DE SEGURIDAD REQUERIDO [!!!]\n";
                        std::cout << "Las existencias de '" << p->getNombre() << "' cayeron por debajo de su minimo de seguridad en " << p->getSede() << ".\n";
                    }
                } catch (const std::exception& e) {
                    std::cout << "\n[TRANSACCION RECHAZADA] " << e.what() << "\n";
                }
            } else {
                std::cout << "\n[ERROR] Producto no registrado en CoreStock.\n";
            }
        } 
        else if (opcion == 2) {
            std::cout << "\n=========================================================================================================\n";
            std::cout << "                         MONITOR DE INVENTARIO CENTRALIZADO (PostgreSQL MODE)                             \n";
            std::cout << "=========================================================================================================\n";
            std::vector<Producto> todos = almacenamiento->obtenerTodos();
            for (const auto& prod : todos) {
                std::string estado = (prod.getStockActual() == 0) ? "Agotado" : 
                                     (prod.getStockActual() < prod.getStockMinimo()) ? "Reorden" : "Conforme";
                
                std::cout << "ID: #" << prod.getId() 
                          << "\t| " << prod.getNombre() << " (" << prod.getMarca() << ")"
                          << "\t| Precio: $" << prod.getPrecio()
                          << "\t| Sede: " << prod.getSede()
                          << "\t| Stock: " << prod.getStockActual() << " / " << prod.getStockMinimo()
                          << "\t| Estado: [" << estado << "]\n";
                std::cout << "   [Ficha Tecnica]: " << prod.getFichaTecnica() << "\n";
                std::cout << "   [Contenido]: " << prod.getContenido() << " | [Unidades]: " << prod.getUnidades() << "\n";
                std::cout << "---------------------------------------------------------------------------------------------------------\n";
            }
        }
    }
    std::cout << "\nCerrando conexion de base de datos Postgres de forma segura. Adios.\n";
}