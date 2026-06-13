# CoreStock - Sistema Empresarial de Control de Inventario

## 📋 Resumen del Proyecto
CoreStock es un sistema logístico desarrollado para gestionar el inventario del área metropolitana de la Gran Caracas. Implementado bajo los paradigmas de Arquitectura Hexagonal y Domain-Driven Design (DDD), aísla por completo las reglas de negocio de las interfaces de usuario.

## 🚀 Fases de Desarrollo y Estado

* **Fase 1 a 4 (Completadas):** Diseño del modelo de Dominio (`Producto`), definición de interfaces de abstracción, e implementación de UI interactiva por consola.
* **Fase 5 (Completadas):** Creación del orquestador global (`main.cpp`) y configuración del script de construcción nativo (`CMakeLists.txt`).
* **Fase 6 (Finalizada):** Modularización completa del frontend (HTML/CSS/JS) separando el dominio y los componentes visuales. Auditoría y redacción de especificaciones técnicas.

## ⚙️ Estructura de Ejecución
* El núcleo opera en C++ puro persistiendo datos en memoria RAM de alta velocidad para entornos de presentación.
* El despliegue de interfaz web se ejecuta estáticamente a través del módulo `/frontend`.