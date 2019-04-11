#include<stdio.h>
#include<list>
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;

typedef struct arista{
    string dest;
    int peso;
    arista * sig;
}arista;

typedef struct nodo{
    string nombre;
    arista * aristas;
}nodo;
typedef struct grafo{
    int nroVertices;
    int nroAristas;
    bool dirigido;
    int posaux;
    nodo * ls;
}grafo;
grafo iniciarGrafo(int v, int a, bool dirig){
    grafo g;
    g.nroVertices=v;
    g.nroAristas=a;
    g.dirigido = dirig;
    g.posaux=0;
    g.ls = (nodo*)malloc(sizeof(nodo)*v);
    return g;
}
nodo* addVertice(grafo& g, string nombreNodo){
    nodo n;
    n.nombre = nombreNodo;
    n.aristas = NULL;
    g.ls[g.posaux]=n;
    //cout<<&g.ls[g.posaux]<<" "<<&n<<endl;
    return &g.ls[g.posaux];
}
void addArista(nodo& n,string nododest,int weight){
    arista * aux = n.aristas;
    n.aristas =(arista*)malloc(sizeof(arista));
    n.aristas->dest=nododest;
    n.aristas->peso = weight;
    n.aristas->sig=aux;
}
int main(){
    grafo g = iniciarGrafo(3,9,true);
    nodo* n = addVertice(g,"nodo1");
    //cout<<n.nombre;
    addArista(*n,"nodo2",2);
    addArista(*n,"nodoe",2); 
    cout<<g.ls[0].nombre<<" "<<g.ls[0].aristas->dest<<g.ls[0].aristas->sig->dest <<endl;
    return 0;
}