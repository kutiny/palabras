#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <typeinfo>
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
		bool es_vacio() {return hd==NULL;}
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
		void setCadena(string cad){
			this->cadena=cad;
		}
		int getValue(){
			return this->valor;
		}
};

										//LISTAA
class Lista{
    private: Nodo *czo;
    public:
            Lista() {czo=new Nodo();};
            Lista(Nodo *n) {czo=n;};
            //~Lista(void);
            void add(string d);
            bool esvacia(void);
            Nodo *cabeza(void);
            Lista *resto(void);
            string toPrint(string p);  //editado y comentado
            void impre(void);
            int size();
            void borrar(void); //borra la cabeza
            void borrar_last();//borra el ultimo
            
};
int Lista::size()
{ 
     if (this->esvacia()) return 0;
     return 1+this->resto()->size();
}
void Lista::impre(void)
{ Nodo *aux;
  aux=czo;
    while(aux->getHijoDerecho()!=NULL){
         cout<<aux->getCadena()<<endl;
         aux=aux->getHijoDerecho();
    }
}
void Lista::add(string d)
{  
     Nodo *nuevo=new Nodo(d);
     nuevo->setHijoDerecho(czo);
     czo=nuevo;
}
bool Lista::esvacia(void)
{   
    return czo->es_vacio();
}
Nodo *Lista::cabeza(void)
{ 
  if(this->esvacia()){
                cout<<" Error, Cabeza de lista vacia"; //mmmm 
  }
  return czo;
}

Lista *Lista::resto(void)
{ 
      Lista *l=new Lista(czo->getHijoDerecho());
      return (l);
}

string Lista::toPrint(string p)
{ 
     if (this->esvacia()) {
     	cout<< "Vacia";
     } else {
	   std::ostringstream stm;
       stm<< this->cabeza()->getCadena() << " - " << this->resto()->toPrint(p) << endl;
       //cout<<endl<<" stm.str()= "<<stm.str()<<endl;
       return stm.str();
     }
}

void Lista::borrar(void)
{ //borra el nodo cabeza
  if(esvacia()){
  } else {
         Nodo *tmp=czo;
         czo=czo->getHijoDerecho();
         delete tmp;
  }
}
void Lista::borrar_last()
{ // borra el ultimo nodo
   if(!this->esvacia()){
      if((czo->getHijoDerecho())->getHijoDerecho()==NULL){
         delete czo->getHijoDerecho();
         czo->setHijoDerecho(NULL);
      }
      else this->resto()->borrar_last(); 
   }  
}

										//ARBOL
class Arbol{
	private:
	Nodo *rama;
	Lista *lista;
	Nodo *getNodo(int ind, bool returnUno);
	void join(Lista *list);
	void swap(int a, int b);
	void quicksort(int left, int right);
	
	public:
	Arbol(Lista *list);
	void setHijoIzquierdo(Nodo *n);
	void setHijoDerecho(Nodo *n);
	//void cargar();
	//void buscar();
	Nodo * getRama(){return this->rama;};
	string search(int v, Nodo * raiz);
	string funciona();
	void QuickSort(){quicksort(0,lista->size());};
	;
};

string Arbol::funciona()
{
	return rama->getHijoIzquierdo()->getHijoIzquierdo()->getHijoDerecho()->getCadena();
}
Arbol::Arbol(Lista *list){
	lista=list;
	int a= list->size();
	int b= log2(a);
	int x;
	if(b==log2(a)){
		x=pow(2,b-1);
	}
	else
		x=pow(2,b);
	this->rama = new Nodo(x);
	join(list);
}

void Arbol::setHijoDerecho(Nodo * n){
	this->rama->setHijoDerecho(n);
}

void Arbol::setHijoIzquierdo(Nodo * n){
	this->rama->setHijoIzquierdo(n);
}

string Arbol::search(int v, Nodo * raiz){
	//cout << "Valor de Raiz actual: " << raiz->getValue() << endl;
	if(v < raiz->getValue()){ //si es menor trabaja por la izquierda
		if (raiz->getValue() == 1 && v == 1){ // si el nodo tiene el valor 1
			// significa que el siguiente nivel son los nodos de la lista.
			return raiz->getHijoDerecho()->getCadena();
		}else if(raiz->getValue() == 1 && v == 0){
			return raiz->getHijoIzquierdo()->getCadena();
		}
		//cout << v << " es menor que " << raiz->getValue() << endl;
		return this->search(v,raiz->getHijoIzquierdo());
	}else{ // si es mayor o igual
		if (raiz->getValue() == 1 && v == 1){
			return raiz->getHijoDerecho()->getCadena();
		}else if(raiz->getValue() == 1 && v == 0){
			return raiz->getHijoIzquierdo()->getCadena();
		}else{
			//cout << v << " es mayor o igual que " << raiz->getValue() << endl; 
			return this->search(v-raiz->getValue(),raiz->getHijoDerecho());
		}
	}
	return "Cadena Vacia";
}

Nodo *Arbol::getNodo(int ind, bool returnUno=false){
	Nodo *s = rama;
	int aux = s->getValue();
	int par = returnUno?1:0;
	while(s->getValue() > par && s != NULL){
		if(s->getValue() < ind){
			ind-=aux;
			aux/=2;
			s = s->getHijoDerecho();	
		}
		else{
			aux/=2;
			s = s->getHijoIzquierdo();
		}
	}
	return s;
}

								//EXTRA
	string leerArchivo(){
	string file = "file.txt";
	string content = "";
	string aux;
	ifstream entrada;
	entrada.open(file.c_str());
	if(entrada.fail()){
		cout<<"***Error al abrir archivo***\n\n";
		return 0;
	}else{
		while(!entrada.eof()){
			getline(entrada,aux);
			if(content != "")
				content.append(" ");
			content.append(aux);
		}
		for(unsigned int i=0; i<content.length(); i++){
			content[i] = tolower(content[i]);
		}
	}
	return content;
}
Lista split(string palabras){
	istringstream ss(palabras);
	Lista ext = *new Lista();
	while(!ss.eof()){
		string a;
		getline(ss,a,' ');
		ext.add(a);
	}
	return ext;
}

void Arbol::join(Lista *lista){
	int size = lista->size();
	cout<< endl << "EL TAMAÑO ES: " << size << endl;
	int cont = 0;
//	Lista *lista = list;
	Nodo *lLink = lista->cabeza();
	
	while(cont<size){
		Nodo *aLink = this->getNodo(cont,true);
		
 		if(cont%2 == 0){
			aLink->setHijoIzquierdo(lLink);
			cout<< "LA CADENA ES:" << aLink->getHijoIzquierdo()->getCadena() << endl;
		}else{
			aLink->setHijoDerecho(lLink);
		}
		//cout<< "NODO("<<size-cont<<") : "<< lLink->getCadena()<<endl;
		lLink = lLink->getHijoDerecho();
		cont++;
	}
	cout<<"TERMINE PAPURRI"<<endl;
}

void Arbol::quicksort(int left, int right){
		int m=0,c=0;
		int min = (left+right)/2;
	
    int i = left;
    int j = right;
    int pivot = this->getNodo(min)->getValue();

    while(left<j || i<right)
    {
    		c++;
        while(this->getNodo(i)->getValue()<pivot)
        i++;c++;
        while(this->getNodo(j)->getValue()>pivot)
        j--;c++;

        if(i<=j){
        		c++;
        		m++;
            this->swap(i,j);
            i++;
            j--;
        }
        else{
            if(left<j)
            		c++;
                this->quicksort(left, j);
            if(i<right)
            		c++;
                this->quicksort(i,right);
            return;
        }
    }
}

void Arbol::swap(int a, int b){
	string temp =	this->getNodo(a)->getCadena();
	this->getNodo(a)->setCadena( this->getNodo(b)->getCadena() );
	this->getNodo(b)->setCadena( temp );	
}
							//MAIN
int main(){
	
//	cout << "Testing...\n\n";
//	int datos = 10;
//	cout << "Datos: " << datos << endl;
//	int pot2 = log2(datos);
//	int valRaiz = pow(2,pot2);
//	cout << "potencia base 2: " << pot2 << endl << "valRaiz: " << valRaiz << "\n\n";
	string cadena = leerArchivo();
	//cout<< a << endl;
	Lista despilar= split(cadena);
//	Arbol *a = new Arbol(valRaiz);
	Arbol *a = new Arbol(&despilar);
	cout << "La señora cadena es" << a->funciona() << endl;
	cout << "Buscando 2: " << a->search(2,a->getRama()) << endl;
	cout << "Buscando 4: " << a->search(4,a->getRama())<< endl;
	cout << "Buscando 3: " << a->search(3,a->getRama())<< endl;
	//AGREGAR LISTA A ESTE ARCHIVO Y LOS METODOS DE NACHO AL ARBOL.
}
