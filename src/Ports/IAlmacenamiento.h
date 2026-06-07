#pragma once
#include <vector>
#include <string>
#include "../Domain/Producto.h"

class IAlmacenamiento {
public:
    // Destructor virtual: Buena práctica obligatoria en C++ para interfaces
    virtual ~IAlmacenamiento() = default;

    // Los "contratos" que deben cumplirse
    virtual void guardarProducto(const Producto& producto) = 0;
    virtual Producto* buscarProducto(std::string id) = 0;
    virtual std::vector<Producto> obtenerTodos() = 0;
    virtual void actualizarProducto(const Producto& producto) = 0;
};