#include "Domain/Producto.h"
#include "Adapters/AlmacenamientoMemoria.h"
#include "Adapters/ConsolaUI.h"

int main() {
    // 1. Instanciamos el Adaptador de Salida (Persistencia temporal en memoria RAM)
    AlmacenamientoMemoria dbMemoria;

    // 2. Poblamos el inventario inicial simulando la persistencia Postgres (5 Items con sedes de Caracas)
    dbMemoria.guardarProducto(Producto("001", "Agua Mineral Pureza", 10, 5, 
        "Minalba", 1.50, "Agua mineral de manantial pura extraida de la Cordillera de los Andes de Venezuela. pH neutro equilibrado.", "Sede Chacao", "850 ml", "1 Botella"));
    
    dbMemoria.guardarProducto(Producto("002", "Cafe Arabica Gourmet", 20, 8, 
        "Fama de America", 12.50, "Granos selectos de cafe Arabica 100% gourmet, tueste oscuro tradicional con notas florales.", "Sede Las Mercedes", "500 gramos", "1 Bolsa"));
    
    dbMemoria.guardarProducto(Producto("003", "Azucar Refinada Premium", 12, 10, 
        "Montalban", 2.20, "Azucar blanca refinada de cana de azucar con un estandar de pureza del 99.8%. Granulacion ultra-fina.", "Sede La Trinidad", "1 Kilogramo", "1 Saco")); 
    
    dbMemoria.guardarProducto(Producto("004", "Leche Organica Descremada", 15, 6, 
        "Parmalat", 3.80, "Leche liquida descremada pasteurizada, enriquecida con vitaminas A y D. 0% grasas trans.", "Sede Chacao", "1 Litro", "1 Empaque"));
    
    dbMemoria.guardarProducto(Producto("005", "Galletas de Avena Crujiente", 30, 15, 
        "McVitie's", 4.50, "Galletas de avena integral horneadas a fuego lento, ricas en fibra dietetica y endulzadas con miel natural.", "Sede La Trinidad", "300 gramos", "12 Galletas"));

    // 3. Inicializamos el Adaptador de Entrada (Consola de Usuario)
    ConsolaUI interfaz(&dbMemoria);

    // 4. Se arranca la aplicación
    interfaz.iniciar();

    return 0;
}