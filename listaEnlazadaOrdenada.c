#include<stdio.h>
#include<stdlib.h>
typedef struct nodo{
    int dato;
    struct nodo * sig;
}nodo;

typedef struct listaOrdenada{
    nodo * cabeza;
}listaOrdenada;

listaOrdenada newLista(){
    listaOrdenada l;
    l.cabeza = NULL;
    return l;
}
void insert(listaOrdenada * ls,int dato){
    if(ls->cabeza!=NULL){
        nodo * aux=ls->cabeza;
        while(aux!=NULL){
            if()
        }
    }else{
        ls->cabeza = malloc(sizeof(nodo));
        ls->cabeza->dato = dato;
        ls->cabeza->sig = NULL;
    }
}
int main(){

    return 0;
}