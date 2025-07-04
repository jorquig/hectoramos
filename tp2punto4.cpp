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
    p = new nodo{valor, nullptr, nullptr};
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
bool obtenerMayorMenor(const lista &l, int &mayor, int &menor) {
    if (!l.inicio) return false;      
    mayor = menor = l.inicio->dato;   
    for (nodo *p = l.inicio->sig; p; p = p->sig) {
        if (p->dato > mayor) mayor = p->dato;
        if (p->dato < menor) menor = p->dato;
    }
    return true;
}
int main() {
    lista l; iniciar(l);
    int nElementos;
    cout << "¿Cuantos valores desea cargar? ";
    cin  >> nElementos;
    for (int i = 0; i < nElementos; ++i) {
        int v; cout << "Valor " << i+1 << ": "; cin >> v;
        nodo *nuevo; crear(nuevo, v);
        agregarFinal(l, nuevo);
    }
    int mayor, menor;
    if (obtenerMayorMenor(l, mayor, menor)) {
        cout << "Mayor valor: " << mayor << "\n";
        cout << "Menor valor: " << menor << "\n";
    } else {
        cout << "La lista esta vacia" << endl;;
    }
    return 0;
}