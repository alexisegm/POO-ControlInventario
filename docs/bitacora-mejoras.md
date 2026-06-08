# Reporte de Mejoras (Bitácora de Entrenamiento) - Versión 1.0

**Metadatos**
* **Repositorio:** POO-ControlInventario
* **Estado Actual:** Fase 5 (Orquestación y Pruebas Iniciales)
* **Patrón Arquitectónico:** Arquitectura Hexagonal

**Resumen Ejecutivo**
El proyecto se diseñó desde su inicio con una arquitectura modular. Se aisló exitosamente la lógica del control de stock en la capa de Dominio, delegando la persistencia y la interfaz a adaptadores externos. Se logró mitigar el riesgo principal de fallos de entrada de usuario en la terminal (CLI) implementando validaciones robustas.

**Estado de Problemas y Mejoras Aplicadas**

| Problema Identificado | Capa Afectada | Estado Actual | Resolución Aplicada |
| :--- | :--- | :--- | :--- |
| Cierres abruptos por entrada de datos no numéricos en la terminal de comandos. | Adaptador (UI) | **RESUELTO** | Se desarrolló el método `leerEnteroSeguro()` en `ConsolaUI` que limpia el buffer de `std::cin` y previene bucles infinitos o caídas de memoria. |
| Acoplamiento fuerte entre la base de datos y la lógica del producto. | Dominio | **RESUELTO** | Se implementó la interfaz abstracta `IAlmacenamiento.h`. El dominio ahora opera mediante Polimorfismo e Inyección de Dependencias en `main.cpp`. |
| Conflictos en la construcción del ejecutable por rutas de carpetas profundas. | Configuración | **RESUELTO** | Implementación de `CMakeLists.txt` para automatizar la vinculación y compilación estructurada de los módulos C++. |

**Puntos Críticos para Futuras Iteraciones**
* **Should:** Transicionar el `AlmacenamientoMemoria` a un `AlmacenamientoArchivo` (txt/csv) para lograr persistencia permanente de los datos entre sesiones.
* **Could:** Sustituir la búsqueda de productos en la base de datos (actualmente por iteración lineal) a mapas hash (`std::unordered_map`) para optimizar el rendimiento algorítmico si el inventario crece a miles de registros.