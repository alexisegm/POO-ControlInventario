#include "Producto.h"

// Inicializamos los valores
Producto::Producto(std::string id, std::string nombre, int stockInicial, int stockMinimo)
    : id(id), nombre(nombre), stockActual(stockInicial), stockMinimo(stockMinimo) {}

// Lógica de negocio: Reducir stock y avisar si hay alerta
bool Producto::reducirStock(int cantidadVendida) {
    if (cantidadVendida <= stockActual) {
        stockActual -= cantidadVendida;
    }
    
    // Si el stock cae por debajo del mínimo, retorna true (¡Alerta!)
    return stockActual < stockMinimo;
}

std::string Producto::getNombre() const { return nombre; }
int Producto::getStockActual() const { return stockActual; }