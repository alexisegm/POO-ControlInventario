# Versión mínima requerida de CMake
cmake_minimum_required(VERSION 3.10)

# Nombre de tu proyecto
project(ControlInventario)

# Especificamos el estándar de C++ (C++11 es suficiente y muy estable)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Le decimos a CMake dónde están los archivos fuente (.cpp)
# Agregamos el main y todos los adaptadores y dominios
add_executable(InventarioApp 
    src/main.cpp
    src/Domain/Producto.cpp
    src/Adapters/AlmacenamientoMemoria.cpp
    src/Adapters/ConsolaUI.cpp
)