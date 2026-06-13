#pragma once
#include "../Ports/IAlmacenamiento.h"
#include <iostream>
#include <limits>
#include <vector>

// Adaptador de entrada que maneja la interfaz por consola interactiva
class ConsolaUI {
private:
    IAlmacenamiento* almacenamiento; // Inyección de dependencias

    // Método seguro para evitar fallas ante entradas erróneas del usuario (UX)
    int leerEnteroSeguro();

public:
    ConsolaUI(IAlmacenamiento* db);
    void iniciar();
};