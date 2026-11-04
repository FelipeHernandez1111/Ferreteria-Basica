[README.md](https://github.com/user-attachments/files/34379636/README.md)
# tienda-grupoN · Ferretería "El Tornillo Fiel"

Proyecto final de **Patrones de Software** (código 74362) · Ingeniería de Sistemas · Cotecnova · Periodo 2026-2
Docente: Felipe Gutiérrez Isaza

## Integrantes y roles

| Integrante |       Rol       |
|------------|-----------------|
| Valeri Castillo Gallego      | Responsable de diseño   |
| Jhohan Vasquez               | Responsable de código   |
| Juan Felipe Hernandez Pinzon | Responsable de modelado |

> Completar con los nombres reales. En equipos de dos integrantes, uno asume dos roles.

## Tipo de tienda

Ferretería de barrio: herramientas manuales y eléctricas, materiales por unidad o a granel (metros de cable) y accesorios de grifería.

## Patrones aplicados

_Se completa en el Seguimiento 2._

## Estructura del repositorio

```
tienda-grupoN/
├── README.md
├── .gitignore
├── docs/
│   ├── 01_ficha_cliente.md
│   └── uml/
│       └── clases_v0.png
├── v0/
│   └── tienda_v0.cpp      (versión sin patrones)
└── v1/                    (versión con patrones, seguimientos 2 y 3)
```

## Cómo compilar y ejecutar

Versión 0 (requiere g++ con soporte C++11 o superior):

```bash
g++ -std=c++11 -Wall -Wextra -o v0/tienda_v0 v0/tienda_v0.cpp
./v0/tienda_v0
```

## Entregas

Cada entrega se fija con una etiqueta de Git (`entrega-s1`, `entrega-s2`, `entrega-s3`, `entrega-final`).

## Declaración de herramientas

Herramientas utilizadas: C++, Git/GitHub, Graphviz, draw.io (diagramas).
