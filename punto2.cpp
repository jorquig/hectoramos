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
	Nodo* fin;
	int cant;
public:
    Lista(){
        inicio = nullptr;
        fin=nullptr;
        cant = 0;
    }

    bool estaVacia(){ 
        return inicio == nullptr;
    }
    void AgregarInicio(Nodo* nuevo){
        if (estaVacia()) {
            inicio = fin = nuevo;
        } else {
            nuevo->setSiguiente(inicio);
            inicio = nuevo;
        }
        cant++;
    }
    void agregarFinal(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (estaVacia()) {
            inicio = fin = nuevo;
        } else {
            fin->setSiguiente(nuevo);
            fin = nuevo;
        }
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
    void eliminarInicio() {
        if (estaVacia()) return;
        Nodo* borrado = inicio;
        inicio = inicio->getSiguiente();
        if (inicio == nullptr) fin = nullptr;
        delete borrado;
        cant--;
    }
    void eliminarFinal() {
        if (estaVacia()) return;
        if (inicio == fin){
            delete fin;
            inicio = fin=nullptr;
        } else {
            Nodo* actual=inicio;
            while (actual->getSiguiente() != fin) {
                actual= actual->getSiguiente();
            }
            delete fin;
            fin=actual;
            fin->setSiguiente(nullptr);
        }
        cant--;
    }
    int cantElementos(){
        return cant;
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
	std::cout << "Elimino 1 de arriba y uno de abajo:" << std::endl;
	lista.eliminarFinal();
	lista.eliminarInicio();
	lista.MostrarLista();
	cout << lista.cantElementos();
	return 0;
}
