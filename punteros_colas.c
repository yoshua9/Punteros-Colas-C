#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

/************************************************************
Autor: Yoshua Lino Troncoso
Fecha: 02/05/2020
Modo: Punteros
************************************************************/

#define MAXSIZE 4

struct nodo {
    int info;
    struct nodo *sig;
};

//Declaramos estos dos punteros para detectar cuanto está vacia la cola y tambien para facilitar la 
//insercción de nuevos elementos en la cola
struct nodo *inicio=NULL;
struct nodo *final=NULL;

//Admitira un parametro, que sera el elemento que se inserta en la estructura
bool empty()
{
    if (inicio == NULL)
        return true;
    else
        return false;
}

//Devolverá un valor booleano verdadero cuando la estructura esté llena
bool full()
{
    struct nodo *reco = inicio;
    int cont= 0;
    while (reco != NULL)
    {
        reco = reco->sig;
        cont++;
    }
    
    if (cont == MAXSIZE)
        return true;
    else
        return false;
}

//Inserta elementos en la estructura
void insert(int x)
{
    struct nodo *nuevo;
    nuevo=malloc(sizeof(struct nodo));
    nuevo->info=x;
    nuevo->sig=NULL;
    if (empty())
    {
        printf("Elemento que se inserta en la estructura. %i\n",x);
        inicio = nuevo;
        final = nuevo;
    }
    else if(!full())
    {
        printf("Elemento que se inserta en la estructura. %i\n",x);
        final->sig = nuevo;
        final = nuevo;
    }else{
        printf("Error Estructura llena.\n");
    }
}

//Devolverá un valor entero, el elemento retirado de la estructura
int extract()
{
    if (!empty())
    {
        int informacion = inicio->info;
        struct nodo *bor = inicio;
        if (inicio == final)
        {
            inicio = NULL;
            final = NULL;
        }
        else
        {
            inicio = inicio->sig;
        }
        free(bor);
        return informacion;
    }
    else{
        printf("Error Estructura Vacia.\n");
        return -1;
    }
        
}

//Mostrara por pantalla el listado de posiciones (numeradas) junto al valor que tienen.
void status()
{
    struct nodo *reco = inicio;
    int cont= 1;
    while (reco != NULL)
    {
        printf("%i - ", cont);
        printf("%i\n", reco->info);
        reco = reco->sig;
        cont++;
    }
    printf("\n");
}

//Borramos todas las estructuras
void extractAll()
{
    struct nodo *reco = inicio;
    struct nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        free(bor);
    }
}

void main()
{
    insert(5);
    insert(10);
    insert(50);
    insert(25);
    extract();
    extract();
    insert(9);
    insert(19);
    insert(99);
    extract();
    extract();
    extract();
    extract();
    extract();
    status();
    extractAll();
    getch();
    return;
}
