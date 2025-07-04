#include <bits/stdc++.h>
using namespace std;


struct nodo {
    int dato; 
    nodo* sig;
    nodo* ant;
};
struct lista {
    nodo* inicio;
    nodo* fin;
};

void iniciar(lista& l){
            l.inicio = l.fin = nullptr; 
        }
void crear(nodo*& n, int val){ 
    n = new nodo{val,nullptr,nullptr}; 
}
void agregarInicio(lista& l, nodo* n) {
    if (!l.inicio)  l.inicio = l.fin = n;
    else {
        n->sig = l.inicio;
        l.inicio->ant = n;
        l.inicio = n;
    }
}

void vaciar(lista& l) {
    while (l.inicio) {
        nodo* aux = l.inicio;
        l.inicio  = aux->sig;
        delete aux;
    }
    l.fin = nullptr;
}
void decimalABinario(int num, lista& bin) {
    iniciar(bin);

    if (num == 0) {    
        nodo* n; crear(n,0); agregarInicio(bin,n);
        return;
    }

    while (num > 0) {
        int bit = num % 2;
        nodo* n; crear(n,bit);
        agregarInicio(bin,n);
        num /= 2;
    }
}

void mostrar(const lista& l) {
    for (nodo* p=l.inicio; p; p=p->sig) cout << p->dato;
    cout << " (bin)\n";
}

int main() {
    int valor;
    cout << "Ingrese un numero decimal: ";
    cin >> valor;

    lista bin;
    decimalABinario(valor, bin);

    cout << "Binario: ";
    mostrar(bin);

    vaciar(bin);
    return 0;
}