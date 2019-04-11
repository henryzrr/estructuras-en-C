#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

//-------------------------------------
typedef struct arista{
    int orig;
    int dest;
    int peso;
}arista;
struct comparador{
    bool operator()(const arista& a,const arista& b){
        return a.peso>b.peso; //menor
    }
};
unordered_map<int,vector<arista>>grafo;
vector<bool>visitado;
priority_queue<arista,vector<arista>,comparador> cola;
int resa,resb;

void procesar(int n){
    visitado[n]=true;
    vector<arista> v = grafo[n];
    for(int i=0;i<v.size();i++){
        cola.push(v[i]);
    }
}
int main(){
    int n,m,k,a,b,c;
    bool ini=true;
    while(scanf("%i",&n)!=EOF){
        visitado.assign(n+1,false);
        resa=0;
        while(n>1){
            scanf("%i %i %i",&a,&b,&c);
            arista ara,arb;
            ara.orig=a;
            ara.dest=b;
            ara.peso=c;
            arb.orig=b;
            arb.dest=a;
            arb.peso=c;
            grafo[a].push_back(ara);
            grafo[b].push_back(arb);
            resa +=c;
            n--;
        }
        
        scanf("%i",&k);
        while(k--){
            scanf("%i %i %i",&a,&b,&c);
            arista ara,arb;
            ara.orig=a;
            ara.dest=b;
            ara.peso=c;
            arb.orig=b;
            arb.dest=a;
            arb.peso=c;
            grafo[a].push_back(ara);
            grafo[b].push_back(arb);
        }
        procesar(1);
        int i=2;
        resb=0;
        while(!cola.empty()){
            arista ar = cola.top();
            cola.pop();
            if(!visitado[ar.dest]){
                resb +=ar.peso;
                procesar(ar.dest);
            }
            
            i++;
        }
        scanf("%i",&m);
        while(m--){
            scanf("%i %i %i",&a,&b,&c);
        }
        if(!ini) puts("");
        printf("%i\n%i\n",resa,resb);
        ini=false;
        grafo.clear();
    }
    return 0;
}