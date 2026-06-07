#pragma once
#include <string>

class Producto {
private:
    std::string id;
    std::string nombre;
    int stockActual;
    int stockMinimo;

public:
    // Constructor para inicializar el producto
    Producto(std::string id, std::string nombre, int stockInicial, int stockMinimo);

    // Método principal de la lógica de negocio
    bool reducirStock(int cantidadVendida);

    // Getters para obtener información
    std::string getNombre() const;
    int getStockActual() const;
};