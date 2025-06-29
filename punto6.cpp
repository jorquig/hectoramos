#include <bits/stdc++.h>
using namespace std;
class NodoInt {
public:
    int dato;
    NodoInt* siguiente;
    NodoInt(int val) : dato(val), siguiente(nullptr) {}
};
class ListaInt {
private:
    NodoInt* inicio;
public:
    ListaInt() : inicio(nullptr) {}

    void insertarFinal(int val) {
        NodoInt* nuevo = new NodoInt(val);
        if (!inicio) {
            inicio = nuevo;
        } else {
            NodoInt* temp = inicio;
            while (temp->siguiente) temp = temp->siguiente;
            temp->siguiente = nuevo;
        }
    }
    NodoInt* getInicio() { return inicio; }
    void mostrar() {
        NodoInt* temp = inicio;
        while (temp) {
            cout << temp->dato << " ";
            temp = temp->siguiente;
        }
        cout << endl;
    }
};
bool esPrimo(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i*i <= n; i+=2) {
        if (n % i == 0) return false;
    }
    return true;
}
void contarPrimos(ListaInt& lista) {
    int contador = 0;
    NodoInt* actual = lista.getInicio();
    while (actual) {
        if (esPrimo(actual->dato)) contador++;
        actual = actual->siguiente;
    }
    cout << "Cantidad de primos: " << contador << endl;
}
class NodoChar {
public:
    char dato;
    NodoChar* siguiente;
    NodoChar(char val) : dato(val), siguiente(nullptr) {}
};
class ListaChar {
private:
    NodoChar* inicio;
public:
    ListaChar() : inicio(nullptr) {}
    void insertarFinal(char val) {
        NodoChar* nuevo = new NodoChar(val);
        if (!inicio) {
            inicio = nuevo;
        } else {
            NodoChar* temp = inicio;
            while (temp->siguiente) temp = temp->siguiente;
            temp->siguiente = nuevo;
        }
    }

    NodoChar* getInicio() { return inicio; }
    void mostrar() {
        NodoChar* temp = inicio;
        while (temp) {
            cout << temp->dato << " ";
            temp = temp->siguiente;
        }
        cout << endl;
    }
};
void contarMayMin(ListaChar& lista) {
    int mayus = 0, minus = 0;
    NodoChar* actual = lista.getInicio();
    while (actual) {
        if (actual->dato >= 'A' && actual->dato <= 'Z') mayus++;
        else if (actual->dato >= 'a' && actual->dato <= 'z') minus++;
        actual = actual->siguiente;
    }
    cout << "Mayusculas: " << mayus << endl;
    cout << "Minusculas: " << minus << endl;
}
int main() {
    ListaInt li;
    li.insertarFinal(2);
    li.insertarFinal(7);
    li.insertarFinal(9);
    li.insertarFinal(13);
    li.insertarFinal(4);
    cout << "Lista enteros: ";
    li.mostrar();
    contarPrimos(li);
    ListaChar lc;
    lc.insertarFinal('A');
    lc.insertarFinal('b');
    lc.insertarFinal('Z');
    lc.insertarFinal('m');
    lc.insertarFinal('x');
    cout << "Lista caracteres: ";
    lc.mostrar();
    contarMayMin(lc);
    return 0;
}
