#include <iostream>
#include <cmath>
using namespace std;

class AVL{
	private:
		Nodo *raiz;
		
	public:
	AVL(Lista a);
	void procesar(Lista a);
	void agregar(Lista a);
}
AVL::AVL(Lista a){
	Nodo temp= new Nodo(a->cabeza());
	*raiz=temp;
	procesar(a=a->resto());
}
void AVL::procesar(Lista a){
	if(a->novacia()){
			agregar(a, *raiz);
			//verficar();
			procesar(a->resto());
		}
}
void AVL::agregar(Lista a, Nodo *nodito){
	if(a->getCadena()<nodito->getCadena()){
		if(getHijoIzquierdo()==null)
			setHijoIzquierdo(new Nodo(a->cabeza->getCadena()));
		else
			agregar(a, nodito->izq);
		}
	else
		if(a->getCadena()>nodito->getCadena()){
			if(getHijoDerecho()==null)
				setHijoDerecho(new Nodo(a->cabeza->getCadena()));	//agrega nodo con valor de lista
		else
			agregar(a, nodito->der);
		}
		else
			raiz->repetida(); // suma 1 a la variable repetida de ese nodo
			
