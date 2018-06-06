#include <iostream>
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
			if(x > 1){
				this->valor = x;
				this->setHijoIzquierdo(new Nodo(x/2));
				this->setHijoDerecho(new Nodo(x/2));
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
		Nodo *raiz = new Nodo();
	public:
		Arbol(int a){Nodo *b = new Nodo(a); *raiz=*b;}
		int izq(){ return raiz->getHijoIzquierdo()->getValor();}
};

int main(){
//	Nodo *n = new Nodo(512);
	Arbol *sape= new Arbol(512);
	
	cout << sape->izq();
	//cout << n->getValor()<< endl;
	//cout << n->getHijoDerecho()->getValor() << endl;
	//cout << n->getHijoDerecho()->getValor() << endl;
}
