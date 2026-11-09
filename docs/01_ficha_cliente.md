# Ficha del cliente: Ferretería "El Tornillo Fiel"

## 1. Tipo de tienda

Ferretería de barrio enfocada en la comercialización de herramientas manuales y eléctricas, materiales de construcción vendidos por unidad, por peso o medida (como metros de cable) y accesorios de grifería.

## 2. Necesidad que resuelve la aplicación

La ferretería requiere un sistema de información ágil, en consola, que permita:

- Registrar los productos del inventario (F1).
- Consultar de forma rápida el stock y los precios (F2).
- Registrar ventas con aplicación de impuestos (IVA) y descuentos según la forma de pago (F3 y F4).
- Controlar automáticamente el stock mínimo, con alertas (F5).
- Generar un reporte consolidado de las ventas realizadas (F6).

## 3. Quiénes la usarán

- **Administrador / Cajero:** registra nuevos productos, consulta el inventario disponible, procesa las ventas de los clientes y revisa el reporte final de caja.

## 4. Historias de usuario

| ID | Función | Historia |
|----|---------|----------|
| HU01 | F1 | **Como** cajero, **quiero** registrar nuevos productos indicando su código, nombre, precio, stock y tipo, **para** tenerlos disponibles en el inventario del sistema. |
| HU02 | F2 | **Como** administrador, **quiero** listar todos los productos actuales con su precio y stock disponible, **para** saber qué mercancía hay en la ferretería. |
| HU03 | F3 | **Como** cajero, **quiero** registrar una venta ingresando el código del producto y la cantidad deseada, **para** procesar la compra del cliente. |
| HU04 | F4 | **Como** cajero, **quiero** que el sistema calcule automáticamente el IVA y los recargos según el tipo de producto (por ejemplo, la garantía en herramientas eléctricas), **para** totalizar correctamente la factura. |
| HU05 | F4 | **Como** cliente, **quiero** recibir un descuento cuando pago con tarjeta o transferencia, **para** pagar menos por mi compra. |
| HU06 | F5 | **Como** administrador, **quiero** que el sistema me alerte en pantalla cuando las unidades de un producto queden por debajo del mínimo permitido (stock < 5), **para** solicitar el reabastecimiento a tiempo. |
| HU07 | F6 | **Como** administrador, **quiero** visualizar un reporte con las ventas realizadas y el total acumulado en caja, **para** realizar el cierre del día. |