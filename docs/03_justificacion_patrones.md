JUSTIFICACION DE PATRONES DE SOFTWARE - Versión 1

1. Patrón Creacional: Factory Method
- Antipatrón que corrige:
El `switch` por tipo de producto y la creación rígida de objetos.
- Justificación:
Se definirá una interfaz o clase base creadora con fábricas concretas para cada categoría de la ferretería
(productos normales, a granel y herramientas con garantía).
Esto desliga la creación de objetos de la lógica principal y permite agregar nuevos tipos de productos sin modificar el código existente.

2. Patrón Estructural: Decorator
- Antipatrón que corrige:
Los números mágicos y el cálculo estático de impuestos/recargos.
- Justificación:
Permite envolver el precio base de los productos dinámicamente con capas de impuestos (IVA),
tasas por empaque a granel o costos de garantía extendida, sin necesidad de alterar la clase base del producto.

3. Patrón de Comportamiento: Strategy
- Antipatrón que corrige:
La lógica acoplada de formas de pago y condicionales `if-else` de descuentos.
- Justificación:
Define una interfaz `EstrategiaPago` con implementaciones concretas (Efectivo, Tarjeta, Transferencia). 
El sistema de venta podrá seleccionar e intercambiar la política de descuento o recargo según el medio de pago utilizado por el cliente.

4. Integración en el Flujo de Venta
Los tres patrones se integran en el proceso principal de **Registrar Venta**:
1. Factory Method instancia la categoría del producto solicitado.
2. Decorator calcula el importe total decorando el precio base con sus impuestos/garantías correspondientes.
3. Strategy aplica la política de descuento sobre el pago total de la factura.
