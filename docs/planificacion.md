# Planificación y Metodología de Desarrollo

Durante el desarrollo del Sistema de Inventario, se estructuró una metodología iterativa dividida en fases, utilizando herramientas de IA como apoyo técnico mientras se mantenía el control humano estricto sobre el diseño del dominio.

## 1. Fases de Desarrollo (Roadmap)
* **Fase 1: Preparación del Entorno.** Configuración de herramientas (Git, MinGW, CMake) y creación del repositorio base.
* **Fase 2: Estructuración Arquitectónica.** Creación del árbol de directorios separando estrictamente `Domain`, `Ports` y `Adapters`.
* **Fase 3: Lógica de Dominio.** Codificación de las reglas de negocio puras (Entidad Producto y alertas) sin frameworks.
* **Fase 4: Puertos y Adaptadores.** Implementación de las interfaces, la persistencia en memoria y la interacción por consola (UI/UX).
* **Fase 5: Ensamblaje.** Orquestación del sistema mediante `main.cpp` e inyección de dependencias.

## 2. Casos de Uso Específicos de Asistencia (IA)
* **Configuración de CMake:** Apoyo en la sintaxis de `CMakeLists.txt` para vincular correctamente los directorios y configurar el generador de construcción (Makefiles).
* **Estructura C++:** Orientación sobre las mejores prácticas para definir interfaces (clases abstractas con funciones virtuales puras) en C++ para simular los "Puertos".
* **Resolución de Conflictos de Entorno:** Asistencia en la depuración de errores de configuración del compilador local.

## 3. Decisiones Humanas (No delegadas)
* **Selección del Dominio:** Determinación del alcance del sistema (Inventario con alertas) para cumplir con los tiempos de entrega (16/06).
* **Diseño de Reglas de Negocio:** La lógica de validación de umbrales de stock mínimo fue conceptualizada y auditada por el equipo.
* **Manejo de UX:** Decisión deliberada de implementar protección de entradas (`leerEnteroSeguro`) para evitar cierres inesperados por errores de usuario, priorizando la resiliencia del software.