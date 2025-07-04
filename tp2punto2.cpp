#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
                    int dato;
                    pnodo sig;
                    pnodo ant;
                    };
typedef struct tlista{
                    pnodo inicio;
                    pnodo fin;
                    };

void IniciarLista(tlista &lista)
{
    lista.inicio = NULL;
    lista.fin = NULL;
}

void CrearNodo(pnodo &nuevo, int valor)
{
    nuevo = new tnodo;
    if(nuevo != NULL)
    {
        nuevo -> dato = valor;
        nuevo -> sig = NULL;
        nuevo -> ant = NULL;
    }
}

void AgregarInicio(tlista &lista, pnodo nuevo)
{
    if(lista.inicio == NULL){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        nuevo->sig = lista.inicio;
        lista.inicio->ant = nuevo;
        lista.inicio = nuevo;
    }
}

void AgregarFinal(tlista &lista, pnodo nuevo){
    if(lista.inicio == NULL){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        lista.fin->sig = nuevo;
        nuevo->ant = lista.fin;
        lista.fin = nuevo;
    }
}
void QuitarInicio(tlista &lista)
{
    if (lista.inicio == NULL)      
        return;

    pnodo aux = lista.inicio;

    if (lista.inicio == lista.fin) {   
        lista.inicio = NULL;
        lista.fin    = NULL;
    } else {                           
        lista.inicio = aux->sig;
        lista.inicio->ant = NULL;
    }
    delete aux;                        
}
void QuitarFinal(tlista &lista)
{
    if (lista.fin == NULL)             
        return;

    pnodo aux = lista.fin;

    if (lista.inicio == lista.fin) {   
        lista.inicio = NULL;
        lista.fin    = NULL;
    } else {                           
        lista.fin = aux->ant;
        lista.fin->sig = NULL;
    }
    delete aux;    
}               

int main()
{
    tlista lista;
    IniciarLista(lista);
    pnodo n;
    CrearNodo(n, 10);  AgregarInicio(lista, n);
    CrearNodo(n, 5);   AgregarInicio(lista, n);
    CrearNodo(n, 20);  AgregarFinal(lista, n);
    cout << "Lista tras inserciones (inicio -> fin): ";
    for (pnodo p = lista.inicio; p != NULL; p = p->sig)
        cout << p->dato << (p->sig ? " -> " : "\n");
    QuitarInicio(lista);
    cout << "Lista tras quitar inicio (inicio -> fin): ";
    for (pnodo p = lista.inicio; p != NULL; p = p->sig)
        cout << p->dato << (p->sig ? " -> " : "\n");
    QuitarFinal(lista);
    cout << "Lista tras quitar final (fin -> inicio): ";
    for (pnodo p = lista.fin; p != NULL; p = p->ant)
        cout << p->dato << (p->ant ? " <- " : "\n");
    while (lista.inicio != NULL)
        QuitarInicio(lista);
    return 0;
}