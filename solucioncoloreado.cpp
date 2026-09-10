#include <iostream>
#include "solucioncoloreado.h"

using namespace std;

SolucionColoreado::SolucionColoreado(Tablero const & t){
	tablero = t;
    

	colores_usados = t.getColoresUsados();
	
	num_colores = colores_usados.size();
	recalcularUsados();
}

SolucionColoreado::SolucionColoreado(){

	Tablero t(0);
	tablero = t;
	num_colores=0;
}



SolucionColoreado::SolucionColoreado(SolucionColoreado const & s){


	*this = s;

}

SolucionColoreado::SolucionColoreado(Tablero const& t, map<string,Color> const& colores){

	tablero = t;
	colores_usados=colores;
	num_colores = colores_usados.size();
	recalcularUsados();

}

SolucionColoreado & SolucionColoreado::operator=(SolucionColoreado const & s){

	if(this!=&s){
	
	tablero = s.tablero;
	colores_usados=s.colores_usados;
	num_colores = s.num_colores;
	}
	
	return *this;

}

void SolucionColoreado::addColor(Color c){

if(colores_usados.count(c.getNombre())){

	colores_usados[c.getNombre()].setMin(c.getMin());
	colores_usados[c.getNombre()].setMax(c.getMax());
	
}else{

	colores_usados[c.getNombre()] = c;
	num_colores++;

}

}

void SolucionColoreado::recalcularUsados(){


	map<string,Color>::iterator it = colores_usados.begin();
	while(it != colores_usados.end()) {
		it->second.setUsado(0);
		it++;
	}


	int dim = tablero.getDimension();
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++){
			string c = tablero.getColorAt(i, j);
			if (c != "" && colores_usados.count(c)) {
				colores_usados[c].aumentarUsado();
			}
		}
	}
}

void SolucionColoreado::mostrar() const{

	cout << "Solution: " << endl;
	
	tablero.mostrar();

}

void SolucionColoreado::ponColor(int i, int j, string color){

    tablero.colorearCasilla(i,j,color);
    colores_usados[color].aumentarUsado();
}



void SolucionColoreado::quitaColor(int i, int j){
    string anterior = tablero.getColorAt(i,j);
    tablero.vaciarCasilla(i,j);
	colores_usados[anterior].disminuirUsado();
}

bool SolucionColoreado::esFija(int i, int j) const{

	return tablero.esFija(i,j); 
}

bool SolucionColoreado::MinimoMaximo() const{

	map<string,Color>::const_iterator it = colores_usados.begin();
	
	while(it != colores_usados.end()) {
		if((it->second.getUsado() < it->second.getMin()) or (it->second.getUsado() > it->second.getMax())) {
			return false;
		}
		it++;
	}
	return true;

}

bool SolucionColoreado::esAdyacente() const{

	return tablero.validacionRestriccionCasillas();

}

int SolucionColoreado::getUsosColor(string nColor) const {
	map<string, Color>::const_iterator it = colores_usados.find(nColor);
	
	if(it != colores_usados.end()){
		return it->second.getUsado();
	}
	return 0;

}

int SolucionColoreado::getMaxColor(string nColor) const{

	map<string, Color>::const_iterator it = colores_usados.find(nColor);
	
	if(it != colores_usados.end()){
		return it->second.getMax();
	}
	return 999;

}

int SolucionColoreado::getMinColor(string nColor) const{

	map<string, Color>::const_iterator it = colores_usados.find(nColor);
	
	if(it != colores_usados.end()){
		return it->second.getMin();
	}
	return 0;
}