#include "AlmacenamientoMemoria.h"

void AlmacenamientoMemoria::guardarProducto(const Producto& producto) {
    inventario.push_back(producto);
}

Producto* AlmacenamientoMemoria::buscarProducto(std::string id) {
    for (auto& prod : inventario) {
        if (prod.getNombre() == id) { // Para simplificar, buscaremos por nombre/id temporalmente
            return &prod;
        }
    }
    return nullptr; // No se encontró
}

std::vector<Producto> AlmacenamientoMemoria::obtenerTodos() {
    return inventario;
}

void AlmacenamientoMemoria::actualizarProducto(const Producto& productoActualizado) {
    for (auto& prod : inventario) {
        if (prod.getNombre() == productoActualizado.getNombre()) {
            prod = productoActualizado;
            break;
        }
    }
}