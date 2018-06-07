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
				//cout << "seteando valor: " << x << endl;
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
	void quicksort(int primero, int ultimo, int&c, int&m);
	void shellSort(int n);
	
	public:
	Arbol(Lista *list);
	void setHijoIzquierdo(Nodo *n);
	void setHijoDerecho(Nodo *n);
	//void cargar();
	//void buscar();
	Nodo * getRama(){return this->rama;};
	string search(int v, Nodo * raiz);
	void QuickSort(){
			int comp = 0;
			int mov = 0;
			quicksort(0,lista->size()-1,comp,mov);
			cout << "***\tOrdenamiento QuickSort\t***\n\tComparaciones: " << comp << "\n\tMovimientos: " << mov << endl;
		};
	void ShellSort(){shellSort(lista->size());};
	Nodo* dameElNodo(int a){ return this->getNodo(a, false);	};
	void guardarArchivo(string file){
			ofstream salida(file);
			for (int i = lista->size() -1 ; i > 0 ; i--){
				salida << this->search(i,rama);
				salida << "\n";
			}
		}
};

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
	if(v < raiz->getValue()){ //si es menor trabaja por la izquierda
		if (raiz->getValue() == 1 && v == 1){ // si el nodo tiene el valor 1
			// significa que el siguiente nivel son los nodos de la lista.
			return raiz->getHijoDerecho()->getCadena();
		}else if(raiz->getValue() == 1 && v == 0){
			return raiz->getHijoIzquierdo()->getCadena();
		}
		return this->search(v,raiz->getHijoIzquierdo());
	}else{ // si es mayor o igual
		if (raiz->getValue() == 1 && v == 1){
			return raiz->getHijoDerecho()->getCadena();
		}else if(raiz->getValue() == 1 && v == 0){
			return raiz->getHijoIzquierdo()->getCadena();
		}else{
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
		if(s->getValue() <= ind){
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
	int cont = 0;
	Nodo *lLink = lista->cabeza();
	while(cont<size){
		Nodo *aLink = this->getNodo(cont,true);
		
 		if(cont%2 == 0){
			aLink->setHijoIzquierdo(lLink);
		}else{
			aLink->setHijoDerecho(lLink);
		}
		lLink = lLink->getHijoDerecho();
		cont++;
	}
}

void Arbol::quicksort(int primero, int ultimo,int&c, int&m){
	int i,j;
	string pivot, aux;
      if(ultimo>primero){
				c++;
				pivot=this->search(ultimo,rama);
				i=primero-1; j=ultimo;      
				for(;;){
					while(this->search(++i,rama)<pivot && (i<ultimo));
					while(this->search(--j,rama)>pivot && (j>primero));
					if(i>=j)break;
					aux=this->search(i,rama);
					this->dameElNodo(i)->setCadena(this->search(j,rama));
					this->dameElNodo(j)->setCadena(aux);
					m++;
					aux.clear();      
				}// fin for
				aux=this->search(i,rama);
				this->dameElNodo(i)->setCadena(this->search(ultimo, rama));
				this->dameElNodo(ultimo)->setCadena(aux);
				quicksort(primero,i-1,c,m);
				quicksort(i+1,ultimo,c,m);
      }
}

void Arbol::shellSort(int n){
	int m=0,c=0;
	int gap, i, j;
	string temp;
	for (gap = n/2; gap > 0; gap /= 2){
		c++;
		for (i = gap; i < n; i++){
			c++; m++;
			for (j=i-gap; j>=0 && search(j,rama)>search(j+gap,rama); j-=gap) {
				temp = search(j,rama); 
				getNodo(j)->setCadena(search(j+gap,rama));
				getNodo(j+gap)->setCadena(temp);
				m++;
			}
		}
	}
	cout << "\n***\tOrdenamiento ShellSort\t***\n\tComparaciones: " << c << "\n\tMovimientos: " << m << "\n"; 
}

void Arbol::swap(int a, int b){
	string temp =	this->getNodo(a)->getCadena();
	this->getNodo(a)->setCadena( this->getNodo(b)->getCadena() );
	this->getNodo(b)->setCadena( temp );	
}

Lista crearlista(string a){
	Lista list = *new Lista();
	string linea;
	ifstream txt;
	txt.open(a);
	if(!txt.is_open()){
		cout<< "Error al leer el archivo" << endl;
		return NULL;
	}else{
		while(!txt.eof()){
			getline(txt,linea);
			istringstream iss (linea);
			while(!iss.eof()){
				string palabra;
				iss >> palabra;
				list.add(palabra);
			}
		}
		txt.close();
		return list;
	}
}
	

							//MAIN
int main(){
	string file_name;
	//CREAMOS EL ARBOL PARA APLICAR SHELLSORT
	Lista shellList = crearlista("file.txt");
	Arbol *shelly = new Arbol(&shellList);
	cout << "SIZE: " << shellList.size() << "\n\n";
	shelly->ShellSort();
	file_name = "shell.txt";
	cout << "\n$> guardando archivo como '" << file_name << "'\n";
	shelly->guardarArchivo(file_name);
	
	cout << "\n\n";
	
	//CREAMOS EL ARBOL PARA APLICAR QUICKSORT
	Lista quickList = crearlista("file.txt");
	Arbol *quicky = new Arbol(&quickList);
	cout << "SIZE: " << quickList.size() << "\n\n";
	quicky->QuickSort();
	file_name = "quick.txt";
	cout << "\n$> guardando archivo como '" << file_name << "'\n";
	quicky->guardarArchivo(file_name);
	
	cout << "\n\n";
	
	//CREAMOS EL ARBOL AVL
}
