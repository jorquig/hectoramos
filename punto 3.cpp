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
        inicio=nullptr;
        fin=nullptr;
        cant =0;
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
    int buscar_indice(int valor) {
        Nodo* actual = inicio;
        int pos = 0;
        while (actual != nullptr) {
            if (actual->getDato() == valor) {
                return pos;
            }
            actual = actual->getSiguiente();
            pos++;
        }
        return -1;
    }
    Nodo* buscar_por_indice(int indice) {
        if (indice < 0 || indice >= cant) {
            return nullptr; 
        }
        Nodo* actual = inicio;
        int pos = 0;
        while (actual != nullptr) {
            if (pos == indice) {
                return actual;
            }
            actual = actual->getSiguiente();
            pos++;
        }
        return nullptr;
    }
};
int main() {
    Lista lista;
    lista.agregarFinal(7);
    lista.agregarFinal(54);
    lista.agregarFinal(32);
    lista.agregarFinal(15);
    lista.MostrarLista();
    int valor = 54;
    int pos = lista.buscar_indice(valor);
    cout << "El valor " << valor << " esta en " << pos << endl;
    int indice = 2;
    Nodo* nodo = lista.buscar_por_indice(indice);
    if (nodo != nullptr) {
        cout << "El nodo en la posicion " << indice << " tiene valor: " << nodo->getDato() << endl;
    } else {
        cout << "No existe nodo en la posición " << indice << endl;
    }
    return 0;
}