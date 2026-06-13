# Especificaciones Técnicas (Spec) - CoreStock v2.0

## 1. Descripción General
CoreStock es un sistema empresarial de control de inventario y despacho logístico para el área metropolitana de la Gran Caracas. Diseñado bajo el paradigma de Arquitectura Hexagonal (Puertos y Adaptadores).

## 2. Stack Tecnológico
* **Backend Core:** C++ moderno (Estándar C++11).
* **Build System:** CMake (v3.10) para modularización.
* **Interfaz Administrativa:** Consola CLI robusta en C++.
* **Interfaz Visual:** Dashboard web modular (HTML5/CSS/JS) con tipografía Plus Jakarta Sans, diseño de componentes y mapa interactivo SVG.

## 3. Capas y Arquitectura
* **Dominio (`/src/Domain`):** Entidad `Producto` con atributos empresariales (marca, precio, ficha técnica y sede) independiente de librerías externas.
* **Puertos (`/src/Ports`):** Contrato abstracto `IAlmacenamiento.h` para inmunidad ante cambios de bases de datos.
* **Adaptadores (`/src/Adapters`):** Entrada controlada mediante `ConsolaUI` y persistencia en memoria RAM mapeada (`AlmacenamientoMemoria`) simulando la velocidad de PostgreSQL.
* **Presentación (`/frontend`):** Estructura modularizada en componentes lógicos, adaptadores de memoria en JS y una carpeta dedicada `/assets` para el manejo de los recursos visuales del inventario.