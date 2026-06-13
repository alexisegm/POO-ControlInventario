#pragma once
#include <vector>
#include <string>
#include "../Domain/Producto.h"

// Puerto de salida (Interface en C++): define las reglas de comunicación del Dominio
// con cualquier almacenamiento de base de datos o almacenamiento temporal.
class IAlmacenamiento {
public:
    virtual ~IAlmacenamiento() = default;

    // Métodos obligatorios que cualquier adaptador debe implementar
    virtual void guardarProducto(const Producto& producto) = 0;
    virtual Producto* buscarProducto(std::string nombre) = 0;
    virtual std::vector<Producto> obtenerTodos() = 0;
    virtual void actualizarProducto(const Producto& producto) = 0;
};