#pragma once
#include <string>
#include <stdexcept>

// Clase de Dominio pura que ahora almacena el Schema extendido de base de datos
class Producto {
private:
    std::string id;
    std::string nombre;
    int stockActual;
    int stockMinimo;
    
    // Atributos extendidos solicitados para integración Postgres
    std::string marca;
    double precio;
    std::string fichaTecnica;
    std::string sede;
    
    // Nuevos atributos agregados
    std::string contenido;
    std::string unidades;

public:
    Producto(std::string id, std::string nombre, int stockInicial, int stockMinimo,
             std::string marca, double precio, std::string fichaTecnica, std::string sede,
             std::string contenido, std::string unidades);

    // Regla de negocio crítica
    bool reducirStock(int cantidadVendida);

    // Getters
    std::string getId() const;
    std::string getNombre() const;
    int getStockActual() const;
    int getStockMinimo() const;
    std::string getMarca() const;
    double getPrecio() const;
    std::string getFichaTecnica() const;
    std::string getSede() const;
    std::string getContenido() const;
    std::string getUnidades() const;
};