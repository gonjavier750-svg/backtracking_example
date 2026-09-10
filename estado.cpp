
#include<iostream>
#include <list>
#include"estado.h"

using namespace std;

	bool Estado::esValido(string color)const{
		
	if(sol.getUsosColor(color)+1>sol.getMaxColor(color)){
		return false;
	}
	
	int dimension=sol.getTablero().getDimension();
	
	if(fila>0 and sol.getTablero().getColorAt(fila-1,col)==color){
		return false;
	}
	if(col>0 and sol.getTablero().getColorAt(fila,col-1)==color){
		return false;
	}
	if(fila<dimension-1 and sol.getTablero().getColorAt(fila+1,col)==color){
		return false;
	}
	if(col<dimension-1 and sol.getTablero().getColorAt(fila,col+1)==color){
		return false;
	}
	return true;
	}
	
	void Estado::avanza(){
		int dimension=sol.getTablero().getDimension();
		do{
			col++;
			
			if(col>=dimension){
				col=0;
				fila++;
				if(fila>=dimension){
					return;
				}
			}
			
			
			
		}while(sol.esFija(fila,col));
	}
	
	void Estado::retrocede(){	
	int dimension = sol.getTablero().getDimension();
    
    do {
        col--;
        
        if (col < 0) {
            col = dimension - 1;
            fila--;
            if (fila < 0) return;
        }
    
		} while(sol.esFija(fila, col));
	}
	
	list <string> Estado::getAlternativas()const{
		list<string> alt;
		map<string,Color> coloresDisponibles=sol.getColoresUsados();
		map<string,Color>::const_iterator it=coloresDisponibles.begin();
		
		while(it!=coloresDisponibles.end()){
			string color= it->first;
			if(	esValido(color)){
				alt.push_back(color);
			}
			it++;
		}
		return alt;
	}
	bool Estado::esFinal(){
		
		return fila >= sol.getTablero().getDimension();
	}
