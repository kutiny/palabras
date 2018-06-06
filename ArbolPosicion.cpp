#include <stdio.h>
#include <iostream>
#include "Lista.cpp"
using namespace std;

class Arbol{
	private:
		Nodo *raiz = new Nodo();
		void shellSort(int n);
    	void quickSort(int left , Lista lista);
    	Nodo *get(int ind, bool a);
    	void swap(int a, int b);
		void join(Lista *list);
	public:
		Arbol(int a){Nodo *b = new Nodo(a); *raiz=*b;}
		int izq(){ return raiz->getHijoIzquierdo()->getValue();}
};

Nodo * Arbol::get(int ind, bool returnUno=false){
	int aux = ind;
	Nodo *s = raiz;
	int par = returnUno?1:0;
	while(s->getValue() > par || s->getValue() != NULL){
		if(s->getValue() < ind){
			aux/=2;
			ind-=aux;
			s = s->getHijoDerecho();	
		}
		else{
			aux/=2;
			s = s->getHijoIzquierdo();
		}
	}
	return s;
}

void Arbol::swap(int a, int b){
	string temp =	this->get(a, false)->getCadena();
	this->get(a)->setCadena( this->get(b)->getCadena() );
	this->get(b)->setCadena( temp );	
}

void Arbol::shellSort(int n){
	int m=0,c=0;

  for (int gap = n/2; gap > 0; gap /= 2){
  	c++;

    for (int i = gap; i < n; i += 1){

      int temp = this->get(i, false)->getValue();
 			c++;
 			m++;
      int j;            
      for (j = i; j >= gap && this->get(j - gap)->getValue() > temp; j -= gap)
        this->swap(j,j - gap); m++; c++;
             
        this->get(j)->setValue(temp); m++;
    }
  }
  printf("\n ShellSort --> cantidad de comparaciones= %d  movimientos= %d",c,m);
    
}

void Arbol::quicksort(int left = 0, Lista lista){
		int right = *lista->size()
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

void Arbol::join(Lista *list){
	int size = list->size();
	int cont = 0;
	Lista *lista = list;
	while(cont<size){
		Nodo *aLink = this->get(cont,true);
		Nodo lLink = lista->cabeza();
 		if(cont%2 == 0){
			aLink->setHijoIzquierdo(&lLink);
		}else{
			aLink->setHijoDerecho(&lLink);
		}
		lista = lista->resto();
		cont++;
	}
}
