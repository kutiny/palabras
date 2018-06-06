#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <sstream>
#include "Nodo.cpp"

using namespace std;
class Lista{
    private: Nodo *czo;
    public:
            Lista() {czo=new Nodo();};
            Lista(Nodo *n) {czo=n;};
            //~Lista(void);
            void add(string d);
            bool esvacia(void);
            Nodo cabeza(void);
            Lista *resto(void);
            string toPrint(string p);  //editado y comentado
            void impre(void);
            int size();
            void borrar(void); //borra la cabeza
            void borrar_last();//borra el ultimo
            void tomar(int n);
            
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
Nodo Lista::cabeza(void)
{ 
  if(this->esvacia()){
                cout<<" Error, Cabeza de lista vacia"; //mmmm 
  }
  return *czo;
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
       stm<< this->cabeza().getCadena() << " - " << this->resto()->toPrint(p) << endl;
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
void Lista::tomar(int n)
{ //deja "vivos" los n primeros nodos y borra el resto
/*   if(!(this->esvacia())) {
      if (n>0) this->resto()->tomar(n-1);
      else     czo->setHijoDerecho(NULL);
   }
*/
   if(this->size()>n){
      this->borrar_last();
      this->tomar(n);
   }
}

