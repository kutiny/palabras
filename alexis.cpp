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
	Nodo * search(int v, Nodo * raiz);
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

Nodo * Arbol::search(int v, Nodo * raiz){
	cout << "Valor de Raiz actual: " << raiz->getValor() << endl;
	if(v < raiz->getValor()){ //si es menor trabaja por la izquierda
		if (raiz->getValor() == 1 && v == 1){ // si el nodo tiene el valor 1
			// significa que el siguiente nivel son los nodos de la lista.
			cout << "llegando a la lista.\n\n";
			return raiz->getHijoDerecho(); 
		}else if(raiz->getValor() == 1 && v == 0){
			cout << "llegando a la lista.\n\n";
			return raiz->getHijoIzquierdo();
		}
		cout << v << " es menor que " << raiz->getValor() << endl;
		this->search(v,raiz->getHijoIzquierdo());
	}else{ // si es mayor o igual
		if (raiz->getValor() == 1 && v == 1){
			cout << "llegando a la lista.\n\n";
			return raiz->getHijoDerecho();
		}else if(raiz->getValor() == 1 && v == 0){
			cout << "llegando a la lista.\n\n";
			return raiz->getHijoIzquierdo();
		}else{
			cout << v << " es mayor o igual que " << raiz->getValor() << endl; 
			this->search(v-raiz->getValor(),raiz->getHijoDerecho());
		}
	}
	return NULL;
}

int main(){
	cout << "Testing...\n\n";
	int datos = 10;
	cout << "Datos: " << datos << endl;
	int pot2 = log2(datos);
	int valRaiz = pow(2,pot2);
	cout << "potencia base 2: " << pot2 << endl << "valRaiz: " << valRaiz << "\n\n";
	Arbol *a = new Arbol(valRaiz);
	cout << "Buscando 2: " << a->search(2,a->getRama()) << endl;
	cout << "Buscando 8: " << a->search(8,a->getRama())<< endl;
	cout << "Buscando 3: " << a->search(3,a->getRama())<< endl;
	//AGREGAR LISTA A ESTE ARCHIVO Y LOS METODOS DE NACHO AL ARBOL.
}
