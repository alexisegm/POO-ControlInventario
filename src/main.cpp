#include "Domain/Producto.h"
#include "Adapters/AlmacenamientoMemoria.h"
#include "Adapters/ConsolaUI.h"

int main() {
    // 1. Instanciamos el adaptador de infraestructura (La Base de Datos en memoria)
    AlmacenamientoMemoria dbMemoria;

    // 2. Poblamos el inventario con algunos datos iniciales para la demostración
    dbMemoria.guardarProducto(Producto("001", "Agua", 10, 5));
    dbMemoria.guardarProducto(Producto("002", "Cafe", 20, 8));
    dbMemoria.guardarProducto(Producto("003", "Azucar", 3, 10)); // Este ya está por debajo del mínimo para forzar alerta

    // 3. Instanciamos la Interfaz de Usuario y le "inyectamos" la base de datos
    // Fíjate que ConsolaUI espera un "IAlmacenamiento", pero le pasamos "dbMemoria". 
    // ¡Esto es polimorfismo y Arquitectura Hexagonal en acción!
    ConsolaUI interfaz(&dbMemoria);

    // 4. Arrancamos el programa
    interfaz.iniciar();

    return 0;
}