#include <iostream>
#include <string>
using namespace std;
// Clases mal disenadas: atributos publicos y sin metodos
class EntradaCine {
public:
	string pelicula;
	double precio;
	int asientosDisponibles;
};
class CarritoDeCompra {
public:
	int cantidadEntradas;
	double totalAPagar;
	bool pagado;
};
int main() {
	EntradaCine funcion;
	funcion.pelicula = "Avengers";
	funcion.precio = 20.0;
	funcion.asientosDisponibles = 5;
	CarritoDeCompra carrito;
	carrito.cantidadEntradas = 0;
	carrito.totalAPagar = 0;
	carrito.pagado = false;
	cout << "=== COMERCIO ELECTRONICO (EJEMPLO INCORRECTO) ===" << endl;
	// FUNCIONALIDAD 1: agregar entradas (la logica esta en el main)
	int cantidad = 2;
	if (funcion.asientosDisponibles >= cantidad) {
		carrito.cantidadEntradas = cantidad;
		carrito.totalAPagar = funcion.precio * cantidad;
		funcion.asientosDisponibles = funcion.asientosDisponibles - cantidad;
	}
	cout << "1. Entradas agregadas. Total: S/ " << carrito.totalAPagar << endl;
	// Cualquiera puede corromper los datos sin validacion
	funcion.asientosDisponibles = -8;
	// FUNCIONALIDAD 2: aplicar cupon (se resta a mano, sin validar)
	carrito.totalAPagar = carrito.totalAPagar - 100.0;
	cout << "2. Cupon aplicado. Total: S/ " << carrito.totalAPagar << endl;
	// FUNCIONALIDAD 3: pagar (no se verifica el saldo)
	double saldoTarjeta = 15.0;
	carrito.totalAPagar = carrito.totalAPagar - saldoTarjeta;
	carrito.pagado = true;
	cout << "3. Pago realizado con solo S/ " << saldoTarjeta << endl;
	cout << "Total final: S/ " << carrito.totalAPagar << endl;
	cout << "Asientos disponibles: " << funcion.asientosDisponibles << endl;
	return 0;
}


