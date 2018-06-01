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
    pnodo raiz, q;
    void ArbolBusq(tarbol x, pnodo &nuevo);
    void rid(pnodo aux);
    void ird(pnodo aux);
    void idr(pnodo aux);
    void show(pnodo aux, int n);

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
//-------------------------------------------------------
