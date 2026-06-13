#include "Producto.h"

Producto::Producto(std::string id, std::string nombre, int stockInicial, int stockMinimo,
                   std::string marca, double precio, std::string fichaTecnica, std::string sede,
                   std::string contenido, std::string unidades)
    : id(id), nombre(nombre), stockActual(stockInicial), stockMinimo(stockMinimo),
      marca(marca), precio(precio), fichaTecnica(fichaTecnica), sede(sede),
      contenido(contenido), unidades(unidades) {}

bool Producto::reducirStock(int cantidadVendida) {
    if (cantidadVendida > stockActual) {
        throw std::runtime_error("Existencias insuficientes. No se puede realizar el despacho.");
    }
    if (cantidadVendida <= 0) {
        throw std::runtime_error("La cantidad de despacho obligatoriamente debe ser mayor a cero.");
    }
    
    stockActual -= cantidadVendida;
    return stockActual < stockMinimo;
}

std::string Producto::getId() const { return id; }
std::string Producto::getNombre() const { return nombre; }
int Producto::getStockActual() const { return stockActual; }
int Producto::getStockMinimo() const { return stockMinimo; }
std::string Producto::getMarca() const { return marca; }
double Producto::getPrecio() const { return precio; }
std::string Producto::getFichaTecnica() const { return fichaTecnica; }
std::string Producto::getSede() const { return sede; }
std::string Producto::getContenido() const { return contenido; }
std::string Producto::getUnidades() const { return unidades; }