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
          //  void toPrint(string p);  //editado y comentado
//            int suma(int i);
            void impre(void);
//            int suma2(void);
            int size();
            void borrar(void); //borra la cabeza
            void borrar_last();//borra el ultimo
           // void concat(Lista *l1); //comentado
           // Lista *copy(void);   //comentado
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
    while(aux->get_next()!=NULL){
         cout<<aux->getCadena()<<endl;
         aux=aux->get_next();
    }
}
void Lista::add(string d)
{  
     Nodo *nuevo=new Nodo(d);
     nuevo->set_next(czo);
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
      Lista *l=new Lista(czo->get_next());
      return (l);
}

//void Lista::toPrint(string p)
//{ 
//     if (this->esvacia()) {
//     	cout<< "Vacia";
//     } else {
//       cout<< this->cabeza()<<" - "<< this->resto()->toPrint(p) << endl;
//     }
//}

void Lista::borrar(void)
{ //borra el nodo cabeza
  if(esvacia()){
  } else {
         Nodo *tmp=czo;
         czo=czo->get_next();
         delete tmp;
  }
}
void Lista::borrar_last()
{ // borra el ultimo nodo
   if(!this->esvacia()){
      if((czo->get_next())->get_next()==NULL){
         delete czo->get_next();
         czo->set_next(NULL);
      }
      else this->resto()->borrar_last(); 
   }  
}
//void Lista::concat(Lista *l1)
//{// le transfiere los datos de l1 a this
//   if (!(l1->esvacia())){
//      this->concat(l1->resto());
//      this->add(l1->cabeza()->getCadena());
//   }
//}
//Lista *Lista::copy(void)
//{ 
//      Lista *aux=new Lista();
//      aux->concat(this);
//      return aux;
//}
void Lista::tomar(int n)
{ //deja "vivos" los n primeros nodos y borra el resto
/*   if(!(this->esvacia())) {
      if (n>0) this->resto()->tomar(n-1);
      else     czo->set_next(NULL);
   }
*/
   if(this->size()>n){
      this->borrar_last();
      this->tomar(n);
   }
}

