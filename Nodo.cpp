#include <iostream>
#include <cmath>
using namespace std;


class Nodo{
	private:
		int value;
		string cadena;
		Nodo *hi;
		Nodo *hd;
		Nodo *next;
		
	public:
		Nodo();
		Nodo(int x);
		Nodo(int value, Nodo *hi, Nodo *hd);
		Nodo(string palabra);
		void set_next(Nodo *n) {next=n; }; //podria usar hi o hd??
		Nodo *get_next() {return next; }; //Tengo que agregarlo???
		bool es_vacio() {return next==NULL;} //mmmm
		int getValue();
		void setValue(int value);
		string getCadena();
		void setCadena(string cadena);
		void setHijoIzquierdo(Nodo *hijo);
		Nodo* getHijoIzquierdo();
		void setHijoDerecho(Nodo *hijo);
		Nodo* getHijoDerecho();
};

Nodo::Nodo(){
	this->hi=NULL;
	this->hd=NULL;
}

Nodo::Nodo(int x){
	if(x > 1){
		this->value = x;
		this->setHijoIzquierdo(new Nodo(x/2));
		this->setHijoDerecho(new Nodo(x/2));
	}else{
		return;
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
