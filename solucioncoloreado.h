#ifndef SOLUCIONCOLOREADO_H
#define SOLUCIONCOLOREADO_H

#include "Tablero.h"
#include "Color.h"

#include <iostream>
#include <string>
#include <map>


class SolucionColoreado{

private:

	Tablero tablero;
	map<string,Color> colores_usados;
	int num_colores;
	
	void recalcularUsados();
	
public:
	SolucionColoreado(Tablero const& t);
	SolucionColoreado();
	SolucionColoreado(SolucionColoreado const& s);
	SolucionColoreado(Tablero const& t, map<string,Color> const& colores);
	
	Tablero getTablero() const {return tablero;}
	map<string,Color> getColoresUsados() const {return colores_usados;}
	
	void setTablero(Tablero const& t) {
	
	tablero = t; 
	recalcularUsados();
	}
	void addColor(Color c);
	
	SolucionColoreado & operator=(SolucionColoreado const& s);
	
	void mostrar() const;
	
	void ponColor(int i, int j, string color);
	void quitaColor(int i, int j);
	
	bool esFija(int i, int j) const;
	bool MinimoMaximo() const;
	bool esAdyacente() const;
	
	int getUsosColor(string nColor) const;
	int getMaxColor(string nColor) const;
	int getMinColor(string nColor) const;
};
#endif
