#ifndef CASILLA_H
#define CASILLA_H

#include <iostream>
#include <string>
#include "Color.h"



class Casilla {
	private:
		int i;
		int j;
		bool fija;
		bool coloreada;
		Color color;
		
	public:
		//Constructores:
		Casilla(){
			setI(0);
			setJ(0);
			setFija(false);
			setColoreada(false);
			color.setNombre("");
		}
		Casilla(int i, int j, bool fija, bool coloreada, string c){
			setI(i);
			setJ(j);
			setFija(fija);
			setColoreada(coloreada);
			color.setNombre(c);
		}
		Casilla(Casilla const & a){
			setI(a.i);
			setJ(a.j);
			setFija(a.fija);
			setColoreada(a.coloreada);
			color.setNombre(a.color.getNombre());
		}
		
		//Observadores:
		int getI() const {return i;}
		int getJ() const {return j;}
		bool getFija() const {return fija;}
		bool getColoreada() const {return coloreada;}
		string getColor() const {return color.getNombre();}
		
		//Modificadores
		void setI(int i) {this->i=i;}
		void setJ(int j) {this->j=j;}
		void setFija(bool f) {fija=f;}
		void setColoreada(bool c) {coloreada=c;}
		void setColor(string c) {if (c!="") {color.setNombre(c); setColoreada(true);} else {color.setNombre(c);}}
		void setColor(string c, int max, int min, int usado) {color.setNombre(c); color.setMax(max); color.setMin(min); color.setUsado(usado);}
		
		//Funciones Específicas:
		void vaciar();
		
		//Sobrecarga De Operadores:
		Casilla & operator=(Casilla const & a);
		bool operator==(Casilla const & a) const;
		bool operator<(Casilla const & a) const;

		//Función De Salida:
		friend ostream& operator<<(ostream & os, const Casilla & c);
		void mostrar() const;
};

#endif


