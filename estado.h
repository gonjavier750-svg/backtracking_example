#ifndef _ESTADOTAREAS_H_
#define _ESTADOTAREAS_H_

#include<iostream>
#include <list>
#include"solucioncoloreado.h"



class Estado
{
	private:
		SolucionColoreado sol;
		int fila;
		int col;
		
	public:
		//Constructor
		Estado(SolucionColoreado const& s,int f=0,int c=0){
			sol=s;
			fila=f;
			col=c;
			if(sol.esFija(fila,col)){
				avanza();
			}
		}
		
		//Observadores
		SolucionColoreado& getSolucion() { return sol; } 
		SolucionColoreado getSolucion() const { return sol; }
		int getFila() const { return fila; }
		int getCol() const { return col; }
		
		
		
		//Funciones de estado
		bool esValido(string color) const;
		void avanza();
		void retrocede();
		list <string> getAlternativas()const;
		bool esFinal()  ;
};

#endif
