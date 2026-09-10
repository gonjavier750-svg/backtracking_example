#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Color {
	private:
		string nombre;
		int min;
		int max;
		int usado;
		map<string, string> codigo;
	
	public:
		//Constructores:
		Color() {
			setMin(0);
			setMax(999);
			setUsado(0);
			setCodigo();
			setNombre("");
		}
		Color(string n) {
			setMin(0);
			setMax(999);
			setUsado(0);
			setCodigo();
			setNombre(n);
		}		
		Color(string color, int min, int max, int usado) {
			setMin(min);
			setMax(max);
			setUsado(usado);
			setCodigo();
			setNombre(color);
		}
		Color(Color const & a) {
			*this=a;
		}
		
		//Observadores:
		string getNombre() const {return nombre;}
		int getMin() const {return min;}
		int getMax() const {return max;}
		int getUsado() const {return usado;}
		string getCodigo() const {
			map<string, string>::const_iterator it=codigo.begin();
			
			while(it!=codigo.end()){
				if(nombre==it->first){
					return it->second;
				}
				it++;
			}
			return "";
		}
		
		//Modificadores
		void setNombre(string n) {
			if(n=="") {
				nombre="";
			}
			else {
				map<string, string>::const_iterator it=codigo.begin();
				bool encontrado=false;
				
				while(it!=codigo.end()){
					if(n==it->first){
						nombre=n;
						encontrado=true;
						break;
					}
					it++;
				}
				if(!encontrado && n!="") {
					cout << "\nColor not found, please enter one of the following colors, using the format: 'White', available colors:\n";
					
					it=codigo.begin();
					
					while(it!=codigo.end()){
						cout << it->first << " "; 
						it++;
					}
					
					cout << "\n";
				}
			}
		}
		void setMin(int m) {min=m;}
		void setMax(int m) {max=m;}
		void setUsado(int u) {usado=u;}
		void setCodigo() {
			codigo.clear();
			
			codigo["Blue"]="\033[34m";
			codigo["Red"]="\033[31m";
			codigo["Green"]="\033[32m";
			codigo["Yellow"]="\033[33m";
			codigo["Orange"]="\033[38;5;208m";
			codigo["Purple"]="\033[35m";
			codigo["Brown"]="\033[38;5;94m";
			codigo["Pink"]="\033[38;5;205m";
			codigo["White"]="\033[37m";
			codigo["Cyan"]="\033[36m";
		}
		void aumentarUsado() {usado++;}
		void disminuirUsado() {usado--;}
		
		//Sobrecarga De Operadores:
		Color & operator=(Color const & a);
		bool operator==(Color const & a) const;
		bool operator<(Color const & a) const;

		//Función De Salida:
		friend ostream& operator<<(ostream & os, Color const & a);		
		void mostrar() const;
};

#endif