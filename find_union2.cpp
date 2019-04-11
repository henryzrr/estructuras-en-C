#include<stdio.h>
using namespace std;

int ranks[30001];
int parents[30001];
int tam;

void iniciarFindJoin(){
    for(int i=1;i<=tam;i++){
        ranks[i]=1;
        parents[i]=i;
    }
}
int buscarPadre(int n){
    return parents[n]==n?n:buscarPadre(parents[n]);
}
bool mismoGrafo(int a, int b){
    return buscarPadre(a)==buscarPadre(b);
}

void unir(int a,int b){
    if(!mismoGrafo(a, b)){
        int pa = buscarPadre(a);
        int pb = buscarPadre(b);
        if(ranks[pb]>ranks[pa]){
            parents[pa]=pb;
            ranks[pb] +=ranks[pa];
        }else{
            parents[pb]=pa;
            ranks[pa] +=ranks[pb];
        }
    }
}

int main(){
    int cases,np,a,b;
    scanf("%i",&cases);
    while(cases){
        scanf("%i %i",&tam,&np);
        iniciarFindJoin();
        while(np--){
            scanf("%i %i",&a,&b);
            unir(a,b);
            //np--;
        }
        int res=0;
        for(int i=1;i<=tam;i++) if(ranks[i]>res) res = ranks[i];
        printf("%i\n",res);
        //for(int i=1;i<=tam;i++) printf("%i ",ranks[i]);
        cases--;

    }
    return 0;
}