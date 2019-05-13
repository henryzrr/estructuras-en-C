#include<cstdio>
#include<stack>
#include<vector>
#include<forward_list>

using namespace std;
typedef struct grafo{
    int visitado;
    forward_list<int> ls;
    int padre;
    int costo;
    //nroAristas=0;
}grafo;

typedef struct nodo{
    int padre;
    int costo;
    int visitado = -1;
}nodo;

int nroVertices,nroAristas,a,b,aux,tamaux;
vector<grafo> g;
stack<int> pila;
//stack<int> msa;

int main(){
    scanf("%i %i",&nroVertices,&nroAristas);
    g.reserve(nroVertices);
    int ma[nroVertices][nroVertices]={{-1}};
    nodo g2[nroVertices];
    //for(int i=0;i<nroVertices;)
    while(nroAristas--){
        scanf("%i %i",&a,&b);
        g[a].ls.push_front(b);
        //g[a].nroAristas++;
        ma[a][b]=1;
        //printf("%i ",g[a].ls.front());
    }

    puts("");

    /*for(int i=0;i<nroVertices;i++){
        /*for(auto x=g[i].ls.begin();x!=g[i].ls.end();x++){
            printf("%i ",*x);
        }
        puts("");
        printf("%i ",g[i].visitado);
    }*/
    puts("");
    pila.push(0);
    g[0].costo=0;
    g[0].padre=-1;
    while(!pila.empty()){
        aux = pila.top();
        pila.pop();
        g[aux].visitado=2;
        for(auto x=g[aux].ls.begin();x!=g[aux].ls.end();x++){
            printf("%i ",g[*x].visitado);
            if(g[*x].visitado==0){
                pila.push(*x);
                g[*x].visitado=1;
                g[*x].padre=aux;
                g[*x].costo=g[aux].costo+1;
            }else {
                if(g[*x].costo>g[aux].costo+1){
                    g[*x].padre=aux;
                    g[*x].costo =g[aux].costo+1;
                }
            }
        }
        puts("");
    }
    puts("");
    for(int i=0;i<nroVertices;i++){
        printf("vertice:%i costo%i padre%i\n",i,g[i].costo,g[i].padre);
    }
    pila.push(0);
    g2[0].costo=0;
    g2[0].padre=-1;
    while(!pila.empty()){
        aux = pila.top();
        pila.pop();
        g2[aux].visitado=1;
        for(int i=0;i<nroVertices;i++){
            if(ma[aux][i]==1){
                if(g2[i].visitado==-1){
                    g2[i].costo = g2[aux].costo+1;
                    g2[i].padre =aux;
                    g2[i].visitado=0;
                    pila.push(i);
                }else{
                    if(g2[i].costo>g2[aux].costo+1){
                        g2[i].padre=aux;
                        g2[i].costo = g2[aux].costo+1;
                    }
                }
            }
        }
    }
    puts("");
    for(int i=0;i<nroVertices;i++){
        printf("vertice:%i costo%i padre%i\n",i,g2[i].costo,g2[i].padre);
    }
    
    return 0;
}