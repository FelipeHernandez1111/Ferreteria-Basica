/**
* ==============================================================================
* PROYECTO PATRONES DE SOFTWARE (2026-2) - COTECNOVA
* Versión 1: Aplicación con Patrones de Diseño (Ferretería "El Tornillo Fiel")
* Patrones aplicados: Factory Method, Decorator y Strategy.
* ==============================================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ==============================================================================
// 1. PATRÓN CREACIONAL: Factory Method (Creación desacoplada de productos)
// ==============================================================================
class Producto {
public:
	string codigo;
	string nombre;
	double precioBase;
	int stock;
	
	virtual ~Producto() {}
	virtual double calcularImpuesto() = 0; // Método polimórfico
};

class ProductoNormal : public Producto {
public:
	ProductoNormal(string cod, string nom, double prec, int stk) {
		codigo = cod; nombre = nom; precioBase = prec; stock = stk;
	}
	double calcularImpuesto() override {
		return precioBase * 0.19; // IVA 19%
	}
};

class ProductoGranel : public Producto {
public:
	ProductoGranel(string cod, string nom, double prec, int stk) {
		codigo = cod; nombre = nom; precioBase = prec; stock = stk;
	}
	double calcularImpuesto() override {
		return precioBase * 0.05; // Impuesto de empaque 5%
	}
};

class HerramientaGarantia : public Producto {
public:
	HerramientaGarantia(string cod, string nom, double prec, int stk) {
		codigo = cod; nombre = nom; precioBase = prec; stock = stk;
	}
	double calcularImpuesto() override {
		return (precioBase * 0.19) + 5000.0; // IVA 19% + Recargo fijo de garantía
	}
};

// Fábrica de productos (Factory Method)
class FabricaProducto {
public:
	static Producto* crearProducto(string codigo, string nombre, double precio, int stock, int tipo) {
		if (tipo == 1) {
			return new ProductoNormal(codigo, nombre, precio, stock);
		} else if (tipo == 2) {
			return new ProductoGranel(codigo, nombre, precio, stock);
		} else if (tipo == 3) {
			return new HerramientaGarantia(codigo, nombre, precio, stock);
		} else {
			return new ProductoNormal(codigo, nombre, precio, stock); // Por defecto
		}
	}
};

// ==============================================================================
// 2. PATRÓN ESTRUCTURAL: Decorator (Cálculo dinámico de recargos adicionales)
// ==============================================================================
class ComponentePrecio {
public:
	virtual ~ComponentePrecio() {}
	virtual double obtenerCosto() = 0;
};

class PrecioBaseConcreto : public ComponentePrecio {
private:
	double costo;
public:
	PrecioBaseConcreto(double c) : costo(c) {}
	double obtenerCosto() override {
		return costo;
	}
};

class DecoradorGarantiaExtendida : public ComponentePrecio {
private:
	ComponentePrecio* componente;
public:
	DecoradorGarantiaExtendida(ComponentePrecio* comp) : componente(comp) {}
	double obtenerCosto() override {
		return componente->obtenerCosto() + 3000.0; // Añade valor por soporte extendido
	}
};

// ==============================================================================
// 3. PATRÓN DE COMPORTAMIENTO: Strategy (Políticas de pago intercambiables)
// ==============================================================================
class EstrategiaPago {
public:
	virtual ~EstrategiaPago() {}
	virtual double procesarPago(double totalConImpuestos, double& descuentoAplicado, double& recargoAplicado) = 0;
};

class PagoEfectivo : public EstrategiaPago {
public:
	double procesarPago(double total, double& descuento, double& recargo) override {
		descuento = 0.0;
		recargo = 0.0;
		return total;
	}
};

class PagoTarjeta : public EstrategiaPago {
public:
	double procesarPago(double total, double& descuento, double& recargo) override {
		descuento = total * 0.03; // 3% de descuento
		recargo = 0.0;
		return total - descuento;
	}
};

class PagoTransferencia : public EstrategiaPago {
public:
	double procesarPago(double total, double& descuento, double& recargo) override {
		descuento = total * 0.03; // 3% de descuento
		recargo = 800.0;          // Costo fijo de pasarela bancaria
		return (total - descuento) + recargo;
	}
};

// ==============================================================================
// Clase Gestora de la Tienda (Controlador principal refactorizado)
// ==============================================================================
class Tienda {
private:
	vector<Producto*> productos;
	double totalVentas;
	int cantidadVentasRealizadas;
	
public:
	Tienda() {
		totalVentas = 0.0;
		cantidadVentasRealizadas = 0;
		cargarDatosIniciales();
	}
	
	~Tienda() {
		for (auto p : productos) {
			delete p;
		}
	}
	
	void cargarDatosIniciales() {
		productos.push_back(FabricaProducto::crearProducto("P001", "Tornillo_3_pulgadas", 250.0, 100, 1));
		productos.push_back(FabricaProducto::crearProducto("P002", "Cable_Electrico_Metro", 1800.0, 50, 2));
		productos.push_back(FabricaProducto::crearProducto("P003", "Taladro_Percutor_750W", 185000.0, 4, 3));
		productos.push_back(FabricaProducto::crearProducto("P004", "Martillo_Ua", 25000.0, 12, 1));
	}
	
	void registrarProducto() {
		cout << "\n=========================================\n";
		cout << "      REGISTRAR NUEVO PRODUCTO (F1)      \n";
		cout << "=========================================\n";
		
		string codigo, nombre;
		double precio;
		int stock, tipo;
		
		cout << "Ingrese codigo del producto (Ej: P005): ";
		cin >> codigo;
		
		for (const auto& prod : productos) {
			if (prod->codigo == codigo) {
				cout << "[ERROR] Ya existe un producto con ese codigo.\n";
				return;
			}
		}
		
		// Limpieza de búfer antes de usar getline para evitar saltos de lectura
		cin.ignore(10000, '\n');
		
		cout << "Ingrese nombre del producto: ";
		getline(cin, nombre);
		
		cout << "Ingrese precio unitario ($): ";
		cin >> precio;
		cout << "Ingrese stock inicial (unidades): ";
		cin >> stock;
		cout << "Seleccione el tipo de producto:\n";
		cout << "  1. Producto normal\n  2. Material a granel\n  3. Herramienta con garantia\nOpcion: ";
		cin >> tipo;
		
		Producto* nuevoP = FabricaProducto::crearProducto(codigo, nombre, precio, stock, tipo);
		productos.push_back(nuevoP);
		cout << "\n[EXITO] Producto creado e integrado con Factory Method.\n";
	}
	
	void consultarInventario() {
		cout << "\n=================================================================\n";
		cout << "                   INVENTARIO ACTUAL (F2)                        \n";
		cout << "=================================================================\n";
		cout << left << setw(10) << "CODIGO" << setw(25) << "NOMBRE" << setw(15) << "PRECIO ($)" << setw(10) << "STOCK" << "\n";
		cout << "-----------------------------------------------------------------\n";
		for (const auto& p : productos) {
			cout << left << setw(10) << p->codigo 
				<< setw(25) << p->nombre 
				<< setw(15) << fixed << setprecision(2) << p->precioBase 
				<< setw(10) << p->stock << "\n";
		}
		cout << "=================================================================\n";
	}
	
	void registrarVenta() {
		cout << "\n=========================================\n";
		cout << "          REGISTRAR UNA VENTA (F3)       \n";
		cout << "=========================================\n";
		
		if (productos.empty()) {
			cout << "[ERROR] No hay productos disponibles.\n";
			return;
		}
		
		consultarInventario();
		string codigoBuscado;
		int cantidadDeseada, formaPago;
		
		cout << "\nIngrese codigo del producto a vender: ";
		cin >> codigoBuscado;
		
		Producto* productoEncontrado = nullptr;
		for (auto& p : productos) {
			if (p->codigo == codigoBuscado) {
				productoEncontrado = p;
				break;
			}
		}
		
		if (!productoEncontrado) {
			cout << "[ERROR] Producto no encontrado.\n";
			return;
		}
		
		cout << "Ingrese la cantidad a comprar: ";
		cin >> cantidadDeseada;
		
		if (cantidadDeseada <= 0 || productoEncontrado->stock < cantidadDeseada) {
			cout << "[ERROR] Cantidad invalida o stock insuficiente.\n";
			return;
		}
		
		double subtotal = productoEncontrado->precioBase * cantidadDeseada;
		double impuestoCalculado = productoEncontrado->calcularImpuesto() * cantidadDeseada;
		
		ComponentePrecio* baseCalculo = new PrecioBaseConcreto(subtotal + impuestoCalculado);
		double totalConAdicionales = baseCalculo->obtenerCosto();
		delete baseCalculo;
		
		cout << "\nSeleccione la forma de pago:\n";
		cout << "  1. Efectivo\n  2. Tarjeta Debito/Credito\n  3. Transferencia Bancaria\nOpcion de pago: ";
		cin >> formaPago;
		
		EstrategiaPago* estrategia = nullptr;
		if (formaPago == 1) estrategia = new PagoEfectivo();
		else if (formaPago == 2) estrategia = new PagoTarjeta();
		else estrategia = new PagoTransferencia();
		
		double descuento = 0.0, recargo = 0.0;
		double totalFinal = estrategia->procesarPago(totalConAdicionales, descuento, recargo);
		delete estrategia;
		
		productoEncontrado->stock -= cantidadDeseada;
		totalVentas += totalFinal;
		cantidadVentasRealizadas++;
		
		cout << "\n---------------- FACTURA DE VENTA V1 ----------------\n";
		cout << "Producto      : " << productoEncontrado->nombre << "\n";
		cout << "Cantidad      : " << cantidadDeseada << "\n";
		cout << "Subtotal      : $" << fixed << setprecision(2) << subtotal << "\n";
		cout << "Impuestos/Gar : $" << impuestoCalculado << "\n";
		cout << "Descuentos    : -$" << descuento << "\n";
		cout << "Recargos      : +$" << recargo << "\n";
		cout << "TOTAL A PAGAR : $" << totalFinal << "\n";
		cout << "-----------------------------------------------------\n";
		cout << "[EXITO] Transaccion procesada exitosamente con patrones.\n";
		
		if (productoEncontrado->stock < 5) {
			cout << "\n[! ALERTA DE STOCK MINIMO (F5) !] El producto [" << productoEncontrado->nombre << "] quedo con " << productoEncontrado->stock << " unidades.\n";
		}
	}
	
	void controlarStockMenu() {
		cout << "\n=========================================\n";
		cout << "        CONTROL DE STOCK MINIMO (F5)     \n";
		cout << "=========================================\n";
		bool alerta = false;
		for (const auto& p : productos) {
			if (p->stock < 5) {
				cout << "[ALERTA] " << p->nombre << " tiene stock critico: " << p->stock << "\n";
				alerta = true;
			}
		}
		if (!alerta) cout << "Todos los productos tienen stock adecuado (>= 5).\n";
		cout << "=========================================\n";
	}
	
	void reporteDeVentas() {
		cout << "\n=========================================\n";
		cout << "            REPORTE DE VENTAS (F6)       \n";
		cout << "=========================================\n";
		cout << "Total transacciones : " << cantidadVentasRealizadas << "\n";
		cout << "Dinero en caja      : $" << fixed << setprecision(2) << totalVentas << "\n";
		cout << "=========================================\n";
	}
	
	void ejecutarMenu() {
		int opcion = 0;
		do {
			cout << "\n=================================================\n";
			cout << "    FERRETERIA 'EL TORNILLO FIEL' (VERSION 1)    \n";
			cout << "=================================================\n";
			cout << " 1. Registrar productos (Factory Method)\n";
			cout << " 2. Consultar inventario\n";
			cout << " 3. Registrar una venta (Factory + Decorator + Strategy)\n";
			cout << " 4. Ver politicas de impuestos y pagos\n";
			cout << " 5. Controlar stock minimo (F5)\n";
			cout << " 6. Reporte de ventas (F6)\n";
			cout << " 7. Salir\n";
			cout << "=================================================\n";
			cout << "Seleccione una opcion (1-7): ";
			
			if (!(cin >> opcion)) {
				cout << "\n[ERROR] Entrada invalida. Digite un numero del 1 al 7.\n";
				cin.clear();
				cin.ignore(10000, '\n');
				opcion = 0;
				continue;
			}
			
			switch (opcion) {
			case 1: registrarProducto(); break;
			case 2: consultarInventario(); break;
			case 3: registrarVenta(); break;
			case 4: 
				cout << "\n[Info] Las politicas operan mediante patrones estructurales y de comportamiento.\n"; 
				break;
			case 5: controlarStockMenu(); break;
			case 6: reporteDeVentas(); break;
			case 7: cout << "\nSaliendo de la Version 1. Hasta pronto!\n"; break;
			default: cout << "\n[ERROR] Opcion no valida. Elija entre 1 y 7.\n"; break;
			}
		} while (opcion != 7);
	}
};

int main() {
	Tienda miTienda;
	miTienda.ejecutarMenu();
	return 0;
}
