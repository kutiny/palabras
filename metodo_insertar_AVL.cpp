//CREAR METODO setRaiz(Nodo);
crearAVL(){
	rama = new Nodo();
}

void insertarPalabra(string palabra,Nodo * raiz){
	if (palabra == raiz->getCadena()){
		raiz->setValue(raiz->getValue + 1);
	}else	if (palabra < raiz->getCadena()){
		if(raiz->getHijoIzquierdo() == NULL){
				Nodo * n = new Nodo();
				n->setValue = 1;
				n->setCadena = palabra;
				raiz->setHijoIzquierdo();
		}else{
			insertarPalabra(palabra,raiz->getHijoIzquierdo());
		}
	}else if(palabra > raiz->getCadena){
		if(raiz->getHijoDerecho() == NULL){
				Nodo * n = new Nodo();
				n->setValue = 1;
				n->setCadena = palabra;
				raiz->setHijoDerecho();
		}else{
			insertarPalabra(palabra,raiz->getHijoDerecho());
		}
	}
}

int Nodo::altura(){
	if(this->getHijoDerecho()!=NULL && this->getHijoIzquierdo()!=NULL){
		int de = this->getHijoDerecho()->altura();
		int iz = this->getHijoIzquierdo()->altura();
		return 1+(de >= iz?de:iz); 
	}
	else if(this->getHijoDerecho()!=NULL){
		return 1+this->getHijoDerecho()->altura();	
	}
	else if(this->getHijoIzquierda()!=NULL){
		return 1+this->getHijoDerecho()->altura();	
	}
	else{
		return 0;
	}
}

void caso1 (){
	if(raiz->getHijoIzquierda()->altura() < raiz->altura()-1 &&
		 raiz->getHijoIzquierda()->getHijoIzquierda()->altura() > raiz->getHijoIzquierda()->getHijoDerecha()->altura()){
		Nodo * aux = raiz->getHijoIzquierda();
		raiz->setHijoIzquierda(raiz->getHijoIzquierda()->getHijoDerecha());
		aux->setHijoDerecha(raiz);
		this->setRaiz(aux);
		cout<<"Caso 1"<endl;
	}
}

void caso2 (){
	if(raiz->getHijoIzquierda()->altura() < raiz->altura()-1 &&
		 raiz->getHijoDerecha()->getHijoDerecha()->altura() > raiz->getHijoDerecha()->getHijoIzquierda()->altura()){	
		Nodo * aux = raiz->getHijoDerecha();
		raiz->setHijoDerecha(raiz->getHijoDerecha()->getHijoIzquierda());
		aux->setHijoIzquierda(raiz);
		this->setRaiz(aux);
		cout<<"Caso 2"<endl;
	}
}

void caso3 (){
	if(raiz->getHijoIzquierda()->altura() > raiz->getHijoDerecha()->altura()+1 &&
		 raiz->getHijoIzquierda()->getHijoDerecha()->altura() > raiz->getHijoIzquierda()->getHijoIzquierda()->altura()){
		Nodo * aux = raiz->getHijoDerecha();
		aux->setHijoDerecha(raiz);
		aux->getHijoDerecha()->setHijoIzquierda(raiz->getHijoIzquierda()->getHijoDerecha()->getHijoDerecha());
		raiz->getHijoIzquierda()->setHijoDerecha(raiz->getHijoIzquierda()->getHijoDerecha()->getHijoIzquierda());
		aux->setHijoIzquierda(raiz->getHijoIzquierda());
		this->setRaiz(aux);
		cout<<"Caso 3"<endl;
	}
}

void caso4 (){
	if(raiz->getHijoIzquierda()->altura() > raiz->getHijoDerecha()->altura()+1 &&
		 raiz->getHijoDerecha()->getHijoIzquierda()->altura() > raiz->getHijoDerecha()->getHijoDerecha()->altura()){
		Nodo * aux = raiz->getHijoDerecha()->getHijoIzquierda();
		aux->setHijoIzquierda(raiz);
		aux->getHijoIzquierda()->setHijoDerecha(raiz->getHijoDerecha()->getHijoIzquierda()->getHijoIzquierda());
		raiz->getHijoDerecha()->setHijoIzquierda(raiz->getHijoDerecha()->getHijoIzquierda()->getHijoDerecha());
		aux->setHijoDerecha(raiz->getHijoDerecha());
		this->setRaiz(aux);
		cout<<"Caso 4"<endl;
	}	
}
