#ifndef TABLERO_H
#define TABLERO_H

#include "Casilla.h"

#include <set>
using namespace std;

class Tablero {
	private:
		int dimension;
		Casilla casilla[10] [10];
		map<string, Color> colores_usados;
		int num_colores;
	public:
		//Constructores:
		Tablero(int n=0);
		
		//Observadores:
		int getDimension() const {return dimension;}
		set<Casilla> getCasillasIniciales() const {
			set<Casilla> casillas_fijas;
			
			for (int filas=0; filas<dimension; filas++) {
				for (int columnas=0; columnas<dimension; columnas++) {
					if(casilla[filas][columnas].getFija()) {casillas_fijas.insert(casilla[filas][columnas]);}
				}
			}		
			
			return casillas_fijas;
		}
		
		map<string, Color> getColoresUsados() const { return colores_usados; }

		//Modificadores
		void setDimension(int n) {
			if(n<=10){
				dimension=n;
				for (int filas=0; filas<dimension; filas++) {
					for (int columnas=0; columnas<dimension; columnas++) {
						casilla[filas][columnas].setI(filas);
						casilla[filas][columnas].setJ(columnas);
					}
				}		
			}
			else {cout << "\nThe maximum allowed dimension is 10\n";}
		}
		
		
		void setCasillaInicial(int i, int j, string color) { 
			bool existe=false;
			
			map<string,Color>::iterator it = colores_usados.begin();
			while(it!=colores_usados.end()){
			
				if(it->second.getNombre()==color){existe = true;}
					it++;
				}
			
			if(existe){
				casilla[i][j].setColor(color);
				casilla[i][j].setFija(true);
				colores_usados[color].aumentarUsado();
			}	
		}
		
		//Funciones Específicas:
		void vaciarCasilla(int i, int j);
		void colorearCasilla(int i, int j, string c);
		bool vacia(int i, int j) const;
		bool validacionRestriccionCasillas() const;

		bool esFija(int i, int j) const;
		
		void addColor(Color c){
			colores_usados.insert({c.getNombre(),c});
			num_colores++;
		}
		
		string getColorAt(int i, int j) const;
		
		//Sobrecarga De Operadores:
		Tablero & operator=(Tablero const & a);
		bool operator==(Tablero const & a) const;

		//Función De Salida:
		friend ostream& operator<<(ostream & os, const Tablero & c);
		void mostrar() const;
		void mostrarCasillasFijas() const;
};

#endif