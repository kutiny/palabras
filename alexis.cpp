#include <iostream>
#include <cmath>
using namespace std;

class Nodo{
	private: 
		Nodo * hi;
		Nodo * hd;
		string cadena;
		int valor;
		
	public:
		Nodo(){
			this->hi = NULL;
			this->hd = NULL;
		}
		Nodo(int x){
			if(x >= 1){
				cout << "seteando valor: " << x << endl;
				this->valor = x;
				if (x > 1){
					this->setHijoIzquierdo(new Nodo(x/2));
					this->setHijoDerecho(new Nodo(x/2));
				}
			}else{
				return;
			}
		}
		Nodo(string c){
			this->cadena = c;
		}
		Nodo * getHijoIzquierdo(){
			return this->hi;
		}
		void setHijoIzquierdo(Nodo * n){
			this->hi = n;
		}
		Nodo * getHijoDerecho(){
			return this->hd;
		}
		void setHijoDerecho(Nodo * n){
			this->hd = n;
		}
		string getCadena(){
			return this->cadena;
		}
		int getValor(){
			return this->valor;
		}
};

class Arbol{
	private:
	Nodo *rama;
	void crear(int a);
	
	public:
	Arbol(int a);
	void setHijoIzquierdo(Nodo *n);
	void setHijoDerecho(Nodo *n);
	//void cargar();
	//void buscar();
	Nodo * getRama(){return this->rama;};
};

Arbol::Arbol(int x){
	this->rama = new Nodo(x);
}

void Arbol::setHijoDerecho(Nodo * n){
	this->rama->setHijoDerecho(n);
}

void Arbol::setHijoIzquierdo(Nodo * n){
	this->rama->setHijoIzquierdo(n);
}

int main(){
	cout << "Testing...\n\n";
	int datos = 10;
	cout << "Datos: " << datos << endl;
	int pot2 = log10(datos)/log10(2);
	int valRaiz = pow(2,pot2);
	cout << "potencia base 2: " << pot2 << endl << "valRaiz: " << valRaiz << "\n\n";
	Arbol *a = new Arbol(valRaiz);
	Nodo * n = a->getRama();
	cout << "a->getRama()->getValor(): " << n->getValor() << endl;
	n = n->getHijoIzquierdo();
	cout << "Primero Hijo Izquierdo: " << n->getValor() << endl;
	n = n->getHijoIzquierdo();
	cout << "Segundo Hijo Izquierdo: " << n->getValor() << endl;
	n = n->getHijoIzquierdo();
	cout << "Tercer Hijo Izquierdo: " << n->getValor() << endl;
	cout << "Cuarto Hijo NULL? " << ((n->getHijoIzquierdo() == NULL)? "SI" : "NO") << endl;
		
	//AGREGAR LISTA A ESTE ARCHIVO Y LOS METODOS DE NACHO AL ARBOL.
}
