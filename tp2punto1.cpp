#include <iostream>
using namespace std;
struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};
struct ListaDoble {
    Nodo* inicio;
    Nodo* fin;
    int tamano;
    ListaDoble() {
        inicio = nullptr;
        fin = nullptr;
        tamano = 0;
    }

    Nodo* crearNodo(int dato) {
        Nodo* nuevo = new Nodo;
        nuevo->dato = dato;
        nuevo->siguiente = nullptr;
        nuevo->anterior = nullptr;
        return nuevo;
    }
    void insertarInicio(int dato) {
        Nodo* nuevo = crearNodo(dato);
        if (inicio == nullptr) {
            inicio = fin = nuevo;
        } else {
            nuevo->siguiente = inicio;
            inicio->anterior = nuevo;
            inicio = nuevo;
        }
        tamano++;
    }
    void insertarFinal(int dato) {
        Nodo* nuevo = crearNodo(dato);
        if (inicio == nullptr) {
            inicio = fin = nuevo;
        } else {
            nuevo->anterior = fin;
            fin->siguiente = nuevo;
            fin = nuevo;
        }
        tamano++;
    }
    void insertarOrden(int dato) {
        Nodo* nuevo = crearNodo(dato);
        if (inicio == nullptr) {
            inicio = fin = nuevo;
        } else if (dato <= inicio->dato) {
            nuevo->siguiente = inicio;
            inicio->anterior = nuevo;
            inicio = nuevo;
        } else if (dato >= fin->dato) {
            nuevo->anterior = fin;
            fin->siguiente = nuevo;
            fin = nuevo;
        } else {
            Nodo* actual = inicio;
            while (actual->siguiente != nullptr && actual->dato < dato) {
                actual = actual->siguiente;
            }
            nuevo->siguiente = actual;
            nuevo->anterior = actual->anterior;
            actual->anterior->siguiente = nuevo;
            actual->anterior = nuevo;
        }
        tamano++;
    }
    int extraerInicio() {
        if (inicio == nullptr) {
            cout << "La lista está vacía" << endl;
            return -1;
        }
        int dato = inicio->dato;
        Nodo* temp = inicio;
        if (inicio == fin) {
            inicio = fin = nullptr;
        } else {
            inicio = inicio->siguiente;
            inicio->anterior = nullptr;
        }
        delete temp;
        tamano--;
        return dato;
    }

    int extraerFinal() {
        if (inicio == nullptr) {
            cout << "La lista está vacía" << endl;
            return -1;
        }
        int dato = fin->dato;
        Nodo* temp = fin;
        if (inicio == fin) {
            inicio = fin = nullptr;
        } else {
            fin = fin->anterior;
            fin->siguiente = nullptr;
        }
        delete temp;
        tamano--;
        return dato;
    }

    int extraerEspecifico(int dato) {
        if (inicio == nullptr) {
            cout << "La lista está vacía" << endl;
            return -1;
        }
        Nodo* actual = inicio;
        while (actual != nullptr && actual->dato != dato) {
            actual = actual->siguiente;
        }
        if (actual == nullptr) {
            cout << "El dato no existe en la lista" << endl;
            return -1;
        }
        
        if (actual == inicio) return extraerInicio();
        if (actual == fin) return extraerFinal();

        actual->anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = actual->anterior;
        int valor = actual->dato;
        delete actual;
        tamano--;
        return valor;
    }

    bool buscar(int dato) {
        Nodo* actual = inicio;
        while (actual != nullptr) {
            if (actual->dato == dato) return true;
            actual = actual->siguiente;
        }
        return false;
    }
    void mostrar() {
        if (inicio == nullptr) {
            cout << "La lista está vacía" << endl;
            return;
        }
        cout << "Lista: ";
        Nodo* actual = inicio;
        while (actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << endl;
    }
    ~ListaDoble() {
        while (inicio != nullptr) {
            extraerInicio();
        }
    }
};

int main() {
    ListaDoble lista;
    lista.insertarInicio(3);
    lista.insertarInicio(2);
    lista.insertarFinal(5);
    lista.insertarOrden(4);
    cout << "Despues de insertar:" << endl;
    lista.mostrar();
    cout << "Extraer del inicio: " << lista.extraerInicio() << endl;
    cout << "Extraer del final: " << lista.extraerFinal() << endl;
    cout << "Despues de extraer:" << endl;
    lista.mostrar();
    cout << "Buscar 4: " << (lista.buscar(4) ? "Si" : "No") << endl;
    cout << "Extraer 4: " << lista.extraerEspecifico(4) << endl;
    cout << "Lista final:" << endl;
    lista.mostrar();
    return 0;
}