# Especificaciones Técnicas (Spec) - Sistema de Inventario Hexagonal

## 1. Descripción General
El proyecto "Control de Inventario" es una aplicación de terminal (CLI) desarrollada en C++ enfocada en gestionar el stock de productos de manera eficiente. Su principal objetivo académico y técnico es demostrar la aplicación rigurosa de la Arquitectura Hexagonal (Ports & Adapters) y principios de Domain-Driven Design (DDD).

## 2. Stack Tecnológico
* **Lenguaje:** C++ moderno (Estándar C++11 o superior).
* **Gestor de Construcción (Build System):** CMake (v3.10+).
* **Compilador Recomendado:** GCC / MinGW-w64.
* **Interfaz:** Consola (CLI) interactiva.
* **Persistencia:** Memoria RAM en tiempo de ejecución (migrable a persistencia en archivos mediante adaptadores).

## 3. Arquitectura (Hexagonal / Ports & Adapters)
El proyecto rompe con el diseño monolítico tradicional aislando las reglas de negocio del mundo exterior:
* **Capa de Dominio (`/src/Domain`):** Contiene la entidad `Producto` y las reglas de negocio puras (ej. alertas de reabastecimiento). No tiene dependencias externas.
* **Capa de Puertos (`/src/Ports`):** Define contratos mediante clases abstractas puras (ej. `IAlmacenamiento.h`) para la Inversión de Dependencias.
* **Capa de Adaptadores (`/src/Adapters`):** Implementaciones concretas de la infraestructura.
  * *Adaptador de Salida:* `AlmacenamientoMemoria` (Persistencia volátil).
  * *Adaptador de Entrada:* `ConsolaUI` (Interacción con el usuario).

## 4. Requerimientos de Funcionalidad y Reglas de Negocio
* **Registro de Ventas:** Reducción dinámica del stock actual.
* **Alertas Automatizadas:** El sistema debe notificar si la venta provoca que el stock actual caiga por debajo del stock mínimo establecido para el producto.
* **Independencia de UI/UX:** El núcleo del negocio debe funcionar sin importar si los datos provienen de una terminal de comandos, un archivo o (en un futuro) un entorno gráfico.