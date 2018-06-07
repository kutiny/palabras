#include <iostream>
#include <cmath>
using namespace std;


class Nodo{
	private:
		int value;
		string cadena;
		Nodo *hi;
		Nodo *hd;
		
	public:
		Nodo(int value, Nodo *hi, Nodo *hd);
		Nodo(string palabra);
		Nodo(){this->hi=NULL; this->hd=NULL;};
		int getValue();
		void setValue(int value);
		string getCadena();
		void setCadena(string cadena);
		void setHijoIzquierdo(Nodo *hijo);
		Nodo* getHijoIzquierdo();
		void setHijoDerecho(Nodo *hijo);
		Nodo* getHijoDerecho();
};
class Arbol{
	private:
	Nodo *rama = new Nodo();
	void crear(Nodo *nodito, int a);
	void crearhijos( Nodo &hijo, int b);
	
	public:
	Arbol(int a);
	void sape() { cout<<"sapeee";};
//	void cargar();
//	void buscar();
	void DameHi();
};

void Arbol::DameHi()
{
	cout<< this->rama->getHijoIzquierdo()->getValue();
}

Arbol::Arbol(int a){
	Nodo *hola = new Nodo(a, new Nodo, new Nodo);
	*rama=*hola;
//	rama->setValue(a);
	crear(rama, a);
}
void Arbol::crearhijos(Nodo &hijo, int b){
	crear(&hijo, b);
}


void Arbol::crear(Nodo *nodito, int a){
	if(a>1){
		int b= a/2;
		nodito-> setHijoIzquierdo(new Nodo(b, new Nodo, new Nodo) );
		nodito-> setHijoDerecho(new Nodo(b, new Nodo, new Nodo) );
		crearhijos(*nodito-> getHijoIzquierdo(), b);
		crearhijos(*nodito-> getHijoDerecho(), b);
	}
}
		
		
Nodo::Nodo(int value, Nodo * hi, Nodo * hd){
	this->value = value;
	this->hi = hi;
	this->hd = hd;
}

Nodo::Nodo(string cadena){
	this->cadena = cadena;
	this->hi = NULL;
	this->hd = NULL;
}

int Nodo::getValue(){
	return value;
}

void Nodo::setValue(int value){
	this->value = value;
}

string Nodo::getCadena(){
	return cadena;
}

void Nodo::setCadena(string cadena){
	this->cadena = cadena;
}

void Nodo::setHijoIzquierdo(Nodo* hijo){
	this->hi = hijo;
}

Nodo* Nodo::getHijoIzquierdo(){
	return this->hi;
}

void Nodo::setHijoDerecho(Nodo* hijo){
	this->hd = hijo;
}

Nodo* Nodo::getHijoDerecho(){
	return this->hd;
}

// MAIN
int main(){
	/*
	Nodo *b = new Nodo(1,new Nodo("Test"),NULL);
	b->setHijoDerecho(new Nodo("Probando"));
	cout << b->getValue() << endl;
	cout << "HI:" << b->getHijoIzquierdo()->getCadena() << endl << endl;
	cout << "HD:" << b->getHijoDerecho()->getCadena() << endl << endl;
	*/
	int a = 1000;
	int b = log10(a)/log10(2);
	Arbol *c= new Arbol(pow(2,b));
	c->sape();
	cout << "Datos: " << a << "\n\nPotencia Base 2 Menor que Datos: " << b << endl;
	cout << "Numero mayor obtenido de la potencia de base 2: " << pow(2,b) << endl;
	c->DameHi();
	// pow(2,b) Sería el numero a establecer en la raiz del arbol
	// SEGUN MIS IDEAS: el numero a setear en el hijo izquierdo es SIEMPRE mitad del valor del padre,
	// peeeero, el valor del hijo derecho depende directamente de la cantidad de los datos.
	
}
