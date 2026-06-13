#pragma once
#include "../Ports/IAlmacenamiento.h"
#include <vector>

// Adaptador de infraestructura que implementa la persistencia temporal en RAM
class AlmacenamientoMemoria : public IAlmacenamiento {
private:
    std::vector<Producto> inventario;

public:
    void guardarProducto(const Producto& producto) override;
    Producto* buscarProducto(std::string nombre) override;
    std::vector<Producto> obtenerTodos() override;
    void actualizarProducto(const Producto& producto) override;
};