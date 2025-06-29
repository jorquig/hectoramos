#include <bits/stdc++.h>
using namespace std;
class Nodo {
private:
    int dato;
    Nodo* siguiente;
public:
    Nodo(int valor) {
        dato = valor;
        siguiente = nullptr;
    }
    int getDato() { 
        return dato;
    }
    Nodo* getSiguiente() {
        return siguiente; 
    }
    void setSiguiente(Nodo* sig) {
        siguiente = sig; 
    }
};
class Pila {
private:
    Nodo* tope;
public:
    Pila() {
        tope = nullptr;
    }

    bool estaVacia() {
        return tope == nullptr;
    }

    void push(int valor) {
        Nodo* nuevo = new Nodo(valor);
        nuevo->setSiguiente(tope);
        tope = nuevo;
    }

    void pop() {
        if (estaVacia()) return;
        Nodo* borrar = tope;
        tope = tope->getSiguiente();
        delete borrar;
    }

    int cima() {
        if (!estaVacia()) return tope->getDato();
        else throw runtime_error("Pila vacía");
    }

    void mostrar() {
        Nodo* aux = tope;
        while (aux != nullptr) {
            cout << aux->getDato() << " ";
            aux = aux->getSiguiente();
        }
        cout << endl;
    }
};
class Cola {
private:
    Nodo* frente;
    Nodo* fin;
    int cantidad;
public:
    Cola() {
        frente = fin = nullptr;
        cantidad = 0;
    }

    bool estaVacia() {
        return frente == nullptr;
    }

    void push(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (estaVacia()) {
            frente = fin = nuevo;
        } else {
            fin->setSiguiente(nuevo);
            fin = nuevo;
        }
        cantidad++;
    }

    void pop() {
        if (estaVacia()) return;
        Nodo* borrar = frente;
        frente = frente->getSiguiente();
        if (frente == nullptr) fin = nullptr;
        delete borrar;
        cantidad--;
    }

    int frenteCola() {
        if (!estaVacia()) return frente->getDato();
        else throw runtime_error("Cola vacía");
    }

    int contar() {
        return cantidad;
    }

    void mostrar() {
        Nodo* aux = frente;
        while (aux != nullptr) {
            cout << aux->getDato() << " ";
            aux = aux->getSiguiente();
        }
        cout << endl;
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
    cout <<  "PILA" << endl;
    Pila pila;
    pila.push(10);
    pila.push(20);
    pila.push(30);
    pila.mostrar(); 
    cout << "quito uno" << endl;
    pila.pop();
    pila.mostrar(); 
    cout << "Cima: " << pila.cima() << endl;

    cout << "COLA" << endl;
    Cola cola;
    cola.push(100);
    cola.push(200);
    cola.push(300);
    cola.mostrar();
    cout << "quito uno" << endl;
    cola.pop();
    cola.mostrar(); 
    cout << "frente: "<< cola.frenteCola() << endl;
    cout << "Cantidad de elementos en la cola: " << cola.contar() << endl;
    return 0;
}