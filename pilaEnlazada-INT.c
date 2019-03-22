#include<stdio.h>
#include<stdlib.h>
typedef struct nodo{
    int dato;
    struct nodo * ant;
}nodo;
typedef struct pila{
    nodo * top;
    int size;
}pila;
pila newPila(){
    pila pp;
    pp.size = 0;
    pp.top=NULL;
    return pp; 
}
int isEmpty(pila *p){
    return p->size ==0;
}
void push(pila * p,int d){
    nodo * aux = p-> top;
    p->top = malloc(sizeof(nodo));
    p->top->dato = d;
    p->top->ant = aux;
    p->size +=1; 
    aux=NULL;
    free(aux);
}
void pop(pila * p){
    if(!isEmpty(p)){
        nodo *aux = p->top->ant;
        p->top=NULL;
        free(p->top);
        p->top = aux;
        p->size -=1;
        aux=NULL;
        free(aux);
    }
    
}
int front(pila * p){
    return p->top->dato;
}
/*
    iniciar pila:
        pila nombrePila= newPila();
    empujar:
        push(&nombrePila,int dato);
    eliminar:
        pop(&nombrePila);
    elementoFrente:
        front(&nombrePila);
    pilaVacia:
        isEmpty(&nombrePila);

*/
int main(){
    pila p = newPila();
    
    push(&p,4);
    push(&p,90);
    //printf("%d \n",front(&p));
    push(&p,92);
    pop(&p);
    pop(&p);
    //printf("%d \n",p.top->dato);
    //printf("%d \n",p.top->ant->ant->dato);
    printf("%d \n",front(&p));
    pop(&p);
    printf("%d \n",isEmpty(&p));
    //printf("%d \n",front(&p));
}