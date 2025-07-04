#include <bits/stdc++.h>
using namespace std;
struct nodo {
    int   dato;
    nodo* sig;
    nodo* ant;
};
struct lista {
    nodo* inicio;
    nodo* fin;
};
void iniciar(lista &l) {
    l.inicio = l.fin = nullptr;
}
void crear(nodo *&p, int valor) {
    p = new nodo{valor,nullptr,nullptr};
}
void agregarFinal(lista &l, nodo *p) {
    if (!l.inicio) {
        l.inicio = l.fin = p;
    } else {
        l.fin->sig = p;
        p->ant     = l.fin;
        l.fin      = p;
    }
}
void eliminarMultiplosDeTres(lista &l) {
    nodo *p = l.inicio;
    while (p) {
        nodo *siguiente = p->sig; 
        if (p->dato % 3 == 0) {

            if (p == l.inicio && p == l.fin) {      
                l.inicio = l.fin = nullptr;
            } else if (p == l.inicio) {           
                l.inicio = p->sig;
                l.inicio->ant = nullptr;
            } else if (p == l.fin) {            
                l.fin = p->ant;
                l.fin->sig = nullptr;
            } else {                                   
                p->ant->sig = p->sig;
                p->sig->ant = p->ant;
            }
            delete p; 
        }
        p = siguiente;
    }
}
void mostrarLista(const lista &l) {
    if (!l.inicio) {
        cout << "[Lista vacia]\n";
        return;
    }
    for (nodo *p = l.inicio; p; p = p->sig) {
        cout << p->dato << (p->sig ? " -> " : "\n");
    }
}
int main() {
    lista l; 
    iniciar(l);
    int n; cout << "Cuantos valores desea ingresar? "; 
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int v; cout << "Valor " << i+1 << ": "; 
        cin >> v;
        nodo *nuevo; crear(nuevo, v);
        agregarFinal(l, nuevo);
    }
    cout << "Lista original: ";
    mostrarLista(l);
    eliminarMultiplosDeTres(l);
    cout << "Lista luego de eliminar multiplos de 3: ";
    mostrarLista(l);

    return 0;
}