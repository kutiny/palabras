#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <sstream>
#include "arbol.cpp"

using namespace std;
class Nodo{
    private: 
        string dato;
        int datosIzquierda;
        Nodo *next;
    public:
        Nodo() {next=NULL;};
        Nodo(string a) {dato=a; next=NULL;};
        void set_dato(int a) {dato=a; };
        void set_next(Nodo *n) {next=n; };
        string get_dato() {return dato; };
        Nodo *get_next() {return next; };
        bool es_vacio() {return next==NULL;}
        int getDatosIzquierda(){return datosIzquierda};
};

class Lista{
    private: Nodo *czo;
    public:
            Lista() {czo=new Nodo();};
            Lista(Nodo *n) {czo=n;};
            //~Lista(void);
            void add(string d);
            bool esvacia(void);
            string cabeza(void);
            Lista *resto(void);
            string toPrint(string p);   
//            int suma(int i);
            void impre(void);
//            int suma2(void);
            int size();
            void borrar(void); //borra la cabeza
            void borrar_last();//borra el ultimo
            void concat(Lista *l1);
            Lista *copy(void);
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
         cout<<aux->get_dato()<<endl;
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
string Lista::cabeza(void)
{ 
  if(this->esvacia()){
                cout<<" Error, Cabeza de lista vacia";
                return "-1"; 
  }
  return czo->get_dato();
}

Lista *Lista::resto(void)
{ 
      Lista *l=new Lista(czo->get_next());
      return (l);
}

string Lista::toPrint(string p)
{ 
     if (this->esvacia()) {
        return p;
     } else {
       std::ostringstream stm;
       stm << this->cabeza()<<" - "<< this->resto()->toPrint(p) << endl;
      //cout<<endl<<" stm.str()= "<<stm.str()<<endl;
       return stm.str();
     }
}

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
void Lista::concat(Lista *l1)
{// le transfiere los datos de l1 a this
   if (!(l1->esvacia())){
      this->concat(l1->resto());
      this->add(l1->cabeza());
   }
}
Lista *Lista::copy(void)
{ 
      Lista *aux=new Lista();
      aux->concat(this);
      return aux;
}
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
string leerArchivo(){
	string file = "file.txt";
	string content;
	string aux;
	ifstream entrada;
	entrada.open(file.c_str());
	if(entrada.fail()){
		cout<<"***Error al abrir archivo***\n\n";
		return 0;
	}else{
		while(!entrada.eof()){
			getline(entrada,aux);
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

int main(){
	string a = leerArchivo();
	//cout<< a << endl;
	Lista despilar= split(a);
	despilar.impre();
	//cin.ignore(2);
	return 0;
}
