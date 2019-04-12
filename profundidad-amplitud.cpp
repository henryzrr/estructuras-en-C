#include<stdio.h>
#include<stack>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

typedef struct arista{
    int a;
    int b;
    int c;
}arista;

typedef struct vertice{
    int padre;
    int costoMinimo;
}vertice;

int vertices,aristas;
unordered_map<int,vector<arista>>grafo;
vector<bool>visitado;
vector<vertice>
void profundidad(int ini){

}
void amplitud(int ini){

}

int main(){
    int a,b,c;
    scanf("%i %i",&vertices,&aristas);
    
    while(aristas--){
        scanf("%i %i %i",&a,&b,&c);
        arista ara,arb;
        ara.a = a;
        ara.b=b;
        ara.c=c;
        arb.a=b;
        arb.b=a;
        arb.c=c;
        grafo[a].push_back(ara);
        grafo[b].push_back(arb);
    }
    visitado.assign(vertices+1,false);
    profundidad();
    visitado.assign(vertices+1,false);
    amplitud();
    return 0;
}