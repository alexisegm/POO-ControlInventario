#pragma once
#include "../Ports/IAlmacenamiento.h"
#include <vector>

class AlmacenamientoMemoria : public IAlmacenamiento {
private:
    std::vector<Producto> inventario; // Nuestra base de datos temporal

public:
    void guardarProducto(const Producto& producto) override;
    Producto* buscarProducto(std::string id) override;
    std::vector<Producto> obtenerTodos() override;
    void actualizarProducto(const Producto& producto) override;
};