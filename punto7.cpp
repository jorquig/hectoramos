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

    int getDato() { return dato; }
    Nodo* getSiguiente() { return siguiente; }
    void setSiguiente(Nodo* sig) { siguiente = sig; }
};
void enigma(Nodo* nodo) {
    if(nodo != nullptr) {
        if(nodo->getSiguiente() == nullptr)
            cout << nodo->getDato() << endl;
        else {
            enigma(nodo->getSiguiente());
            cout << nodo->getDato() << endl;
        }
    }
}
int misterio(Nodo* nodo) {
    if(nodo == nullptr)
        return 0;
    else
        return misterio(nodo->getSiguiente()) + 1;
}
Nodo* desconocido(Nodo* nodo) {
    if(nodo == nullptr || nodo->getSiguiente() == nullptr)
        return nodo;
    else
        return desconocido(nodo->getSiguiente());
}
int main() {
    Nodo* n1 = new Nodo(6);
    Nodo* n2 = new Nodo(4);
    Nodo* n3 = new Nodo(9);
    Nodo* n4 = new Nodo(5);
    Nodo* n5 = new Nodo(8);
    n1->setSiguiente(n2);
    n2->setSiguiente(n3);
    n3->setSiguiente(n4);
    n4->setSiguiente(n5);

    cout << "Resultado de enigma:" << endl;
    enigma(n1);
    cout << "Cantidad de nodos: " << misterio(n1) << endl;
    Nodo* ultimo = desconocido(n1);
    cout << "Ultimo nodo: " << ultimo->getDato() << endl;
    return 0;
}
