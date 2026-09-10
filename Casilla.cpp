#include "Casilla.h"

//Funciones Específicas:
void Casilla::vaciar() {
	if (!fija) {
		coloreada=false;
		setColor("");
	}
	else {
		cout << "\nCannot clear a cell initialized as fixed.\n";
	}
}		

//Sobrecarga De Operadores:
Casilla & Casilla::operator=(Casilla const & a) {
	this->i = a.i;
	this->j = a.j;
	this->fija = a.fija;        
	this->coloreada = a.coloreada;
	this->color = a.color;      
    
    return *this;
}
bool Casilla::operator==(Casilla const & a) const {
	return (color==a.color);
}

bool Casilla::operator<(Casilla const & a) const {
	if(i!=a.i) {return (i<a.i);}
	else {return (j<a.j);}
}

//Función De Salida:

ostream& operator<<(ostream & os, Casilla const & a) {
	if(a.getColoreada()) {os << a.color.getCodigo() << "██" << "\033[0m";}
	else {os << "..";}
	
	return os;
}

void Casilla::mostrar() const{
	cout << *this;
}