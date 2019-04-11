#include<stdio.h>
#include<map>
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
    return parents[n];
}
bool mismoGrafo(int a, int b){
    return parents[a]==parents[b];
}
void cambiarPadre(int menor,int mayor){
    for(int i=1;i<=tam;i++){
        if(parents[i]==menor){
            parents[i]=mayor;
        }
    }
}
void unir(int a,int b){
    if(!mismoGrafo(a, b)){
        int pa = buscarPadre(a);
        int pb = buscarPadre(b);
        if(ranks[pb]>ranks[pa]){
            cambiarPadre(pa,pb);
            ranks[pb] +=ranks[pa];
        }else{
            cambiarPadre(pb,pa);
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
        }
        int res=0;
        for(int i=1;i<=tam;i++) if(ranks[i]>res) res = ranks[i];
        printf("%i\n",res);
        for(int i=1;i<=tam;i++) printf("%i ",ranks[i]);
        cases--;

    }
    return 0;
}