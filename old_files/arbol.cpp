#include <stdio.h>
#include <iostream>

using namespace std;

typedef int tarbol;

struct nodo{
      tarbol info;
      int hijosIzq;
      nodo *izq,*der;
};

typedef nodo * pnodo;

class arbol{
    Nodo raiz, q;
    void ArbolBusq(tarbol x, pnodo &nuevo);
    void rid(pnodo aux);
    void ird(pnodo aux);
    void idr(pnodo aux);
    void show(pnodo aux, int n);
    void shellSort(int n);
    void quickSort(int left, int right);
    Nodo get(int ind);
    void swap(int a, int b);
    void join(Lista list);

public:
    arbol(){raiz=NULL;};
    ~arbol(){};
    void CreaArbolBus(tarbol x);
    void RID(){ rid(raiz); }
    void IRD(){ ird(raiz); }
    void IDR(){ idr(raiz); }
    void VerArbol(){ show(raiz,0); }
 
};

void arbol::CreaArbolBus(tarbol x)
{ ArbolBusq(x,raiz);
}
void arbol::ArbolBusq(tarbol x, pnodo &nuevo)
{
  if(nuevo==NULL){
      nuevo= new nodo;
      nuevo->info=x; nuevo->der=nuevo->izq=NULL;
  }
  if(x > nuevo->info) ArbolBusq(x, nuevo->der);
  if(x < nuevo->info) ArbolBusq(x, nuevo->izq);
}
void arbol::ird(pnodo aux)
{  if(aux!=NULL){
        ird(aux->izq);
        cout<<"\n"<<aux->info;
        ird(aux->der);
   }
}
void arbol::rid(pnodo aux)
{  if(aux!=NULL){
        cout<<"\n"<<aux->info;
        rid(aux->izq);
        rid(aux->der);
   }
}
void arbol::idr(pnodo aux)
{  if(aux!=NULL){
        idr(aux->izq);
        idr(aux->der);
        cout<<"\n"<<aux->info;
   }
}
void arbol::show(pnodo aux, int n)
{ int i;
   if(aux!=NULL){                      //OjO este es un recorrido dri
       show(aux->der, n+1);
       for(i=1; i<=n; i++) cout<<"     ";
       cout<<aux->info<<"\n";
       show(aux->izq, n+1);
   }
}

pnodo arbol::get(int ind, bool returnUno=false){
	int aux = ind;
	Nodo s = raiz;
	int par = returnUno?1:0;
	while(s->getValor() > par || s->getValor() != NULL){
		if(s->getValor() < ind){
			aux/=2;
			ind-=aux;
			s = s->der;	
		}
		else{
			aux/=2;
			s = s->izq;
		}
	}
	return s;
}


void::swap(int a, int b){
	string temp =	this->get(a)->getCadena();
	this->get(a)->setCadena( this->get(b)->getCadena() );
	this->get(b)->setCadena( temp );	
}

void Arbol::shellSort(int n){
	int m=0,c=0;

  for (int gap = n/2; gap > 0; gap /= 2){
  	c++;

    for (int i = gap; i < n; i += 1){

      int temp = this->get(i);
 			c++;
 			m++;
      int j;            
      for (j = i; j >= gap && this->get(j - gap) > temp; j -= gap)
        this->swap(j,j - gap); m++; c++;
             
        this->get(j) = temp; m++;
    }
  }
  printf("\n ShellSort --> cantidad de comparaciones= %d  movimientos= %d",c,m);
    
}

void arbol::quicksort(int left = 0, int right = this->lista->size()){
		int m=0,c=0;
		int min = (left+right)/2;
	
    int i = left;
    int j = right;
    int pivot = this->get(min);

    while(left<j || i<right)
    {
    		c++;
        while(this->get(i)<pivot)
        i++;c++;
        while(this->get(j)>pivot)
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
    
    printf("\n QuickSort --> cantidad de comparaciones= %d  movimientos= %d",c,m);
}

void arbol::join(Lista list){
	int size = list.size();
	int cont = 0;
	Lista lista = list;
	while(cont<size){
		Nodo aLink = this->get(cont,true);
		Nodo lLink = Lista->cabeza();
 		if(cont%2 == 0){
			aLink->setHijoIzquierda(lLink);
		}else{
			aLink->setHijoDerecha(lLink);
		}
		lista = lista->resto();
		cont++;
	}
}
