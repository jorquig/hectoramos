#include <bits/stdc++.h>
using namespace std;

class Nodo {
public:
    int dato;
    Nodo* siguiente;

    Nodo(int valor) {
        dato = valor;
        siguiente = nullptr;
    }
};
class Lista {
private:
    Nodo* inicio;
public:
    Lista() {
        inicio = nullptr;
    }

    void insertarFinal(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (!inicio) {
            inicio = nuevo;
        } else {
            Nodo* temp = inicio;
            while (temp->siguiente != nullptr)
                temp = temp->siguiente;
            temp->siguiente = nuevo;
        }
    }
    void mostrar() {
        Nodo* temp = inicio;
        while (temp != nullptr) {
            cout << temp->dato << " ";
            temp = temp->siguiente;
        }
        cout << endl;
    }
    Nodo* getInicio() { return inicio; }

    void ordenarSeleccion() {
        for (Nodo* i = inicio; i != nullptr; i = i->siguiente) {
            Nodo* min = i;
            for (Nodo* j = i->siguiente; j != nullptr; j = j->siguiente) {
                if (j->dato < min->dato)
                    min = j;
            }
            if (min != i) {
                int temp = i->dato;
                i->dato = min->dato;
                min->dato = temp;
            }
        }
    }
    Lista clonar() {
        Lista copia;
        Nodo* actual = inicio;
        while (actual != nullptr) {
            copia.insertarFinal(actual->dato);
            actual = actual->siguiente;
        }
        return copia;
    }
    Lista combinarConOrden(Lista& otra) {
        ordenarSeleccion();
        otra.ordenarSeleccion();

        Lista resultado;
        Nodo* a = inicio;
        Nodo* b = otra.getInicio();

        while (a && b) {
            if (a->dato < b->dato) {
                resultado.insertarFinal(a->dato);
                a = a->siguiente;
            } else {
                resultado.insertarFinal(b->dato);
                b = b->siguiente;
            }
        }

        while (a) {
            resultado.insertarFinal(a->dato);
            a = a->siguiente;
        }

        while (b) {
            resultado.insertarFinal(b->dato);
            b = b->siguiente;
        }

        return resultado;
    }
    Lista combinarSinOrden(Lista& otra) {
        Lista resultado = this->clonar();
        Nodo* temp = otra.getInicio();
        while (temp != nullptr) {
            resultado.insertarFinal(temp->dato);
            temp = temp->siguiente;
        }
        return resultado;
    }
};
int main() {
    Lista lista1;
    lista1.insertarFinal(5);
    lista1.insertarFinal(2);
    lista1.insertarFinal(9);
    lista1.insertarFinal(1);
    lista1.insertarFinal(6);

    cout << "Lista 1: ";
    lista1.mostrar();
    lista1.ordenarSeleccion();
    cout << "Lista ordenada 1: ";
    lista1.mostrar();
    Lista lista2;
    lista2.insertarFinal(3);
    lista2.insertarFinal(7);
    lista2.insertarFinal(0);
    cout << "Lista 2: ";
    lista2.mostrar();
    Lista copia1 = lista1.clonar();
    Lista copia2 = lista2.clonar();
    Lista combinadaSinOrden = copia1.combinarSinOrden(copia2);
    cout << "Lista combinada sin importar orden: ";
    combinadaSinOrden.mostrar();
    Lista combinadaConOrden = copia1.combinarConOrden(copia2);
    cout << "Lista combinada con orden: ";
    combinadaConOrden.mostrar();
    return 0;
}
