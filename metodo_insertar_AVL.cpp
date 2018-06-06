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
