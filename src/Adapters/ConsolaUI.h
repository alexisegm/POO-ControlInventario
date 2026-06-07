#pragma once
#include "../Ports/IAlmacenamiento.h"
#include <iostream>
#include <limits> // Necesario para limpiar errores de entrada

class ConsolaUI {
private:
    IAlmacenamiento* almacenamiento; // Inyección de dependencias (Modularización)

    // Función auxiliar para manejar errores de teclado del usuario
    int leerEnteroSeguro();

public:
    ConsolaUI(IAlmacenamiento* db);
    void iniciar();
};