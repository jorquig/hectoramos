#include <bits/stdc++.h>
using namespace std;

class Nodo{
private:
	int dato;
	Nodo* sig;
public:
	Nodo(int dato){
		this->dato = dato;
		sig = nullptr;
	}

	int getDato(){
		 return dato;
		}
	Nodo* getSiguiente(){ 
		return sig; 
	}
	void setSiguiente(Nodo* nuevo){ 
		sig = nuevo; 
	}
};

class Lista{
private:
	Nodo* inicio;
	int cant;
public:
	Lista(){
		inicio = nullptr;
		cant = 0;
	}

	bool estaVacia(){ 
		return inicio == nullptr;
	}

	void AgregarInicio(Nodo* nuevo){
		nuevo->setSiguiente(inicio);
		inicio = nuevo;
		cant++;
	}

	void MostrarLista(){
		Nodo* i = inicio;
		while(i != nullptr){
			cout << i->getDato() << " ";
			i = i->getSiguiente();
		}
		cout << endl;
	}
	Nodo* Minimo(){
		if (estaVacia()) return nullptr;

		Nodo* minNodo = inicio;
		Nodo* actual = inicio;
		Nodo* anteriorMin = nullptr;
		Nodo* anterior = nullptr;

		while (actual != nullptr){
			if (actual->getDato() < minNodo->getDato()){
				minNodo = actual;
				anteriorMin = anterior;
			}
			anterior = actual;
			actual = actual->getSiguiente();
		}
		if (minNodo == inicio){
			inicio = inicio->getSiguiente();
		}else{
			anteriorMin->setSiguiente(minNodo->getSiguiente());
		}
		minNodo->setSiguiente(nullptr);
		cant--;
		return minNodo;
	}
};
int main(){
	Lista lista;
	lista.AgregarInicio(new Nodo(30));
	lista.AgregarInicio(new Nodo(10));
	lista.AgregarInicio(new Nodo(50));
	lista.AgregarInicio(new Nodo(5));
	lista.AgregarInicio(new Nodo(20));
	cout << "Lista original: ";
	lista.MostrarLista();
	Nodo* min = lista.Minimo();
	if(min != nullptr)
		cout << "Nodo minimo extraido: " << min->getDato() << endl;
	cout << "Lista luego de eliminar el minimo: ";
	lista.MostrarLista();
	return 0;
}
