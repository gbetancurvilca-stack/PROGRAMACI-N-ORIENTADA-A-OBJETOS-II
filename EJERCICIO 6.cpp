#include <iostream>
#include <string>
using namespace std;
class EntradaCine {
private:
	string pelicula;
	double precio;
	int asientos;
public:
	EntradaCine(string p, double pr, int a) : pelicula(p), precio(pr), asientos(a) {}
	string getPelicula() const { return pelicula; }
	double getPrecio() const { return precio; }
	int getAsientos() const { return asientos; }
	bool descontarAsientos(int cant) {
		if (cant <= 0 || cant > asientos) return false;
		asientos -= cant;
		return true;
	}
};
class CarritoDeCompra {
private:
	string pelicula = "";
	double total = 0.0;
	bool cuponAplicado = false;
public:
	bool agregarProducto(EntradaCine &funcion, int cant) {
		if (!funcion.descontarAsientos(cant)) {
			cout << "1. Error: No hay suficientes asientos disponibles." << endl;
			return false;
		}
		pelicula = funcion.getPelicula();
		total = funcion.getPrecio() * cant;
		cout << "1. Agregado: " << cant << " entradas para '" << pelicula << "'. Total: S/ " << total << endl;
		return true;
	}
	bool aplicarCupon(double descuento) {
		if (total <= 0 || cuponAplicado || descuento <= 0 || descuento >= total) {
			cout << "2. Error: Cupon invalido o ya aplicado." << endl;
			return false;
		}
		total -= descuento;
		cuponAplicado = true;
		cout << "2. Cupon aplicado. Nuevo total: S/ " << total << endl;
		return true;
	}
	bool procesarPago(double saldo) {
		if (total <= 0 || saldo < total) {
			cout << "3. Pago rechazado: Saldo insuficiente o carrito vacio." << endl;
			return false;
		}
		cout << "3. Pago exitoso de S/ " << total << ". Saldo restante: S/ " << (saldo - total) << endl;
		total = 0.0;
		return true;
	}
	double getTotal() const { return total; }
};
int main() {
	EntradaCine funcion("Avengers", 20.0, 5);
	CarritoDeCompra carrito;
	cout << "=== COMPRA EN LINEA (POO OPTIMIZADO) ===" << endl;
	carrito.agregarProducto(funcion, 2);
	carrito.aplicarCupon(10.0);
	carrito.procesarPago(15.0);
	cout << "\n--- ESTADO DEL SISTEMA ---" << endl;
	cout << "Asientos cine: " << funcion.getAsientos() << endl;
	cout << "Total carrito: S/ " << carrito.getTotal() << endl;
	return 0;
}
