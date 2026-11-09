# ferreteria-grupoN · Ferretería "El Tornillo Fiel"

Proyecto final de **Patrones de Software** (código 74362) · Ingeniería de Sistemas · Cotecnova · Periodo 2026-2
Docente: Felipe Gutiérrez Isaza

## Integrantes y roles

| Integrante | Rol |
|------------|-----|
| Valeri Castillo Gallego | Responsable de diseño |
| Jhohan Vasquez | Responsable de código |
| Juan Felipe Hernandez Pinzon | Responsable de modelado |

## Tipo de tienda

Ferretería de barrio: comercialización de herramientas manuales y eléctricas, materiales de construcción e insumos por unidad o a granel (como metros de cable o tubería) y accesorios de grifería.

## Patrones aplicados

* **Creacional:** Factory Method (Instanciación desacoplada según la categoría del producto: normal, a granel o herramientas con garantía).
* **Estructural:** Decorator (Envoltorios dinámicos sobre el precio base para aplicar impuestos como el IVA, recargos por empaque o garantía extendida sin alterar la clase base).
* **Comportamiento:** Strategy (Intercambio dinámico de políticas de pago, descuentos y recargos según el medio seleccionado: efectivo, tarjeta o transferencia).

## Estructura del repositorio

```text
ferreteria-grupoN/
├── README.md
├── .gitignore
├── docs/
│   ├── 01_ficha_cliente.md
│   ├── 02_antipatrones.md
│   ├── 03_justificacion_patrones.md
│   └── uml/
│       ├── clases_v0.png
│       ├── clases_v1.png
│       ├── secuencia_venta.png         (Seguimiento 3)
│       └── comunicacion_venta.png      (Seguimiento 3)
├── v0/
│   └── ferreteria_v0.cpp               (Versión sin patrones - Seguimiento 1)
└── v1/                                 (Versión con patrones - Seguimiento 2 y 3)
    ├── main.cpp
    └── salida_esperada.txt             (Seguimiento 3)
```

## Cómo compilar y ejecutar

### Versión 0 (sin patrones)
Requiere `g++` con soporte C++11 o superior:

```bash
g++ -std=c++11 -Wall -Wextra -o v0/ferreteria_v0 v0/ferreteria_v0.cpp
./v0/ferreteria_v0
```

### Versión 1 (con patrones)
Compilación del punto de entrada principal:

```bash
g++ -std=c++11 -Wall -Wextra -o v1/main v1/main.cpp
./v1/main
```

## Entregas

Cada hito del proyecto se fija mediante etiquetas (tags) en Git:
* `entrega-s1`: Análisis, historias de usuario, versión 0 funcional y diagrama `clases_v0.png`.
* `entrega-s2`: Diagnóstico de antipatrones, justificación de patrones y diagrama `clases_v1.png`.
* `entrega-s3`: Avance de versión 1 con patrones, salida esperada y diagramas dinámicos de venta.
* `entrega-final`: Aplicación completa, documentación corregida y sustentación.

## Declaración de herramientas

Herramientas utilizadas: C++, Git/GitHub, Graphviz, draw.io (diagramación UML).
