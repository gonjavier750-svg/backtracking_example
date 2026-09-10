#ifndef PROBLEMA_H
#define PROBLEMA_H

#include <iostream>
#include <list>
#include "estado.h"
#include "Tablero.h"
#include "solucioncoloreado.h"



class Problema{

	private:
	
	Tablero tablero_inicial;
	list<SolucionColoreado> soluciones;
	
	public:
	
	Problema(Tablero const & t){
	
	setTableroInicial(t);
	
	}
	
	Tablero getTableroInicial() const {return tablero_inicial;}
	list <SolucionColoreado> getSoluciones() const {return soluciones;}
	
	void setTableroInicial(Tablero const & t) {tablero_inicial=t;}
	void setSoluciones(list <SolucionColoreado> const & sols){soluciones = sols;}
	
	list <SolucionColoreado> ejecutaBacktracking();
	void bt(Estado& e);
	
	void actualizarSoluciones(Estado & e);
};

#endif
