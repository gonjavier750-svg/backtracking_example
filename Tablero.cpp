#include "Tablero.h"


Tablero::Tablero(int n){

	setDimension(n);

}
//Funciones Específicas:
void Tablero::vaciarCasilla(int i, int j) {
	string colorAnterior = casilla[i][j].getColor();
	if(colorAnterior != "" && colores_usados.count(colorAnterior)){
	
	colores_usados[colorAnterior].disminuirUsado();
	
	}
	casilla[i][j].vaciar();
}

void Tablero::colorearCasilla(int i, int j, string c) {
	
	string colorAnterior = casilla[i][j].getColor(); //habia un color anterior?? disminuir su contador
	if(colorAnterior != "" && colores_usados.count(colorAnterior)){
	colores_usados[colorAnterior].disminuirUsado();
	}
	
	casilla[i][j].setColor(c);
	
	if(c != "" && colores_usados.count(c)){
		colores_usados[c].aumentarUsado();
	}
	
}

bool Tablero::vacia(int i, int j) const {
	if(casilla[i][j].getColor()==""){return true;}
	return false;
}

bool Tablero::validacionRestriccionCasillas() const {
	for (int filas=0; filas<dimension; filas++) {
		for (int columnas=0; columnas<dimension; columnas++) {
            if (vacia(filas, columnas)) {continue;}
            else if (((columnas < (dimension-1)) && (casilla[filas][columnas].getColor() == casilla[filas][columnas + 1].getColor())) || ((filas < (dimension-1)) && (casilla[filas][columnas].getColor() == casilla[filas + 1][columnas].getColor()))) {return false;}
            else {continue;}		
		}
	}
	return true;
}


//Sobrecarga De Operadores:
Tablero & Tablero::operator=(Tablero const & a) {
	dimension=a.dimension;
	num_colores=a.num_colores;
	colores_usados=a.colores_usados;
	
	for (int filas=0; filas<dimension; filas++) {
		for (int columnas=0; columnas<dimension; columnas++) {
			this->casilla[filas][columnas]= a.casilla[filas][columnas];
		}
	}
	
	return *this;
}

bool Tablero::operator==(Tablero const & a) const {
	if(dimension!=a.dimension || num_colores!=a.num_colores) {return false;}
	for (int filas=0; filas<dimension; filas++) {
		for (int columnas=0; columnas<dimension; columnas++) {
		if(!(this->casilla[filas][columnas] == a.casilla[filas][columnas])) {return false;}
		}
	}
	
	return true;
}

//Función De Salida:

ostream& operator<<(ostream & os, const Tablero & a) {
	os << "\nCurrent board:\n";
	
	for (int filas=0; filas<a.dimension; filas++) {
		for (int columnas=0; columnas<a.dimension; columnas++) {
			os << a.casilla[filas][columnas];
		}
		
		os << "\n";
	}
	
	os << "\nThe board has the following constraints:\n";
	
	map<string, Color>::const_iterator it=a.colores_usados.begin();
	
	while(it!=a.colores_usados.end()) {
		os << it->second;
		it++;
	}
	
	return os;
}

void Tablero::mostrar() const{
	cout << *this;
}

void Tablero::mostrarCasillasFijas() const{
	cout << "\nThe current board has the following fixed cells:\n";
	
	for (int filas=0; filas<dimension; filas++) {
		for (int columnas=0; columnas<dimension; columnas++) {
			if (casilla[filas][columnas].getFija()) {cout << casilla[filas][columnas] << "(" << filas << ", " << columnas << ")" << " ";}
		}
	}
}

bool Tablero::esFija(int i, int j) const{

	return casilla[i][j].getFija();

}

string Tablero::getColorAt(int i, int j) const {
    return casilla[i][j].getColor();
}