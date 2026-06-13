#include "AlmacenamientoMemoria.h"

void AlmacenamientoMemoria::guardarProducto(const Producto& producto) {
    inventario.push_back(producto);
}

Producto* AlmacenamientoMemoria::buscarProducto(std::string nombre) {
    for (auto& prod : inventario) {
        if (prod.getNombre() == nombre) {
            return &prod;
        }
    }
    return nullptr;
}

std::vector<Producto> AlmacenamientoMemoria::obtenerTodos() {
    return inventario;
}

void AlmacenamientoMemoria::actualizarProducto(const Producto& productoActualizado) {
    for (auto& prod : inventario) {
        if (prod.getId() == productoActualizado.getId()) {
            prod = productoActualizado;
            break;
        }
    }
}