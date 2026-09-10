#include "Color.h"

//Sobrecarga De Operadores:
Color & Color::operator=(Color const & a) {
	nombre=a.nombre;
	min=a.min;
	max=a.max;
	usado=a.usado;
	
	return *this;
}

bool Color::operator==(Color const & a) const {
	return (nombre==a.nombre);
}

bool Color::operator<(Color const & a) const {
	return (nombre<a.nombre);
}

//Función De Salida:
ostream& operator<<(ostream & os, Color const & a) {
	os << "\nColor: " << a.getCodigo() << a.getNombre() << "\033[0m" << " must be used in a minimum of " << a.getMin() << " cells and can be used in a maximum of " << a.getMax() << " cells, currently used in " <<  a.getUsado() << " cells.\n";
	return os;
}

void Color::mostrar() const{
	cout << *this;
}	