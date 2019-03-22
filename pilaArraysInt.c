#include<stdio.h>
#include<stdlib.h>
typedef struct pila{
    int tam;
    int top;
    int * nodos;
}pila;
int isEmpty(pila * p){
    return p->top==-1;
}
void push(pila * p,int dato){
    if(p->top+1!=p->tam){
        p->top++;
        p->nodos[p->top]=dato;
    }
}
void pop(pila * p){
    if(!isEmpty(p)){
        p->top--;
    }
    
}
int front(pila * p){
    return p->nodos[p->top];
}
int getSize(pila * p){
    return p->top+1;
}
pila newPila(int tam){
    pila pp;
    pp.tam = tam;
    pp.top = -1;
    pp.nodos=malloc(sizeof(int)*tam);
    return pp;
}
/*
    Operaciones:
        pila p = newPila(tamañoPila);
*/
int main(){
    pila p = newPila(10);
    push(&p,30);
    push(&p,33);
    printf("%i\n",front(&p));
    pop(&p);
    printf("%i\n",front(&p));
    printf("%i\n",getSize(&p));
    pop(&p);
    printf("%i\n",getSize(&p));
    push(&p,56);
    printf("%i\n",front(&p));
    return 0;
}