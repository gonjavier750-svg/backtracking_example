#include <iostream>
#include "problema.h"

using namespace std;


list <SolucionColoreado> Problema::ejecutaBacktracking(){

	
	SolucionColoreado sol(tablero_inicial); //tablero inicial
	
	Estado e(sol);//estado inicial
	
	bt(e); //backtracking
	
	return soluciones;

}

void Problema::bt(Estado & e){

	if(e.esFinal()){
	
	actualizarSoluciones(e);
	}else{
	
	list <string> alts = e.getAlternativas();
	list<string>::iterator it = alts.begin();
	
	while(it!=alts.end()){
	
	string color = *it;
	
	e.getSolucion().ponColor(e.getFila(), e.getCol(), color); //poner color
	
	e.avanza();
	
	bt(e);
	
	e.retrocede();
	
	e.getSolucion().quitaColor(e.getFila(),e.getCol()); //quitar color 
	
	it++;
	}
	
	}

}

void Problema::actualizarSoluciones(Estado & e){

	if(e.getSolucion().MinimoMaximo()){
		soluciones.push_back(e.getSolucion());
	}

}
