#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>parents,ranks;
int res,res2;
typedef struct arista{
    int a;
    int b;
    int c;
}arista;
vector<arista>aristals;
bool comparador(arista a, arista b){
    return b.c>a.c; //mayor es menor-mayor menor es  mayor - menor
}
void iniciarUF(int n){
    parents.reserve(n);
    ranks.reserve(n);
    for(int i=1;i<n;i++){
        parents[i]=i;
        ranks[i]=0;
    }
}
int parent(int a){
    return parents[a]==a?a:parent(parents[a]);
}
bool mismoSet(int a,int b){
    return parent(a)==parent(b);
}
void unir(arista a){
    if(!mismoSet(a.a,a.b)){
        int pa = parent(a.a);
        int pb = parent(a.b);
        if(ranks[pa]>ranks[pb]){
            parents[pb]=pa;
        }else{
            parents[pa]=pb;
            if(ranks[pa]==ranks[pb]) ranks[pb]++;
        }
        res +=a.c;
        //printf("%i %i %i\n",a.a,a.b,a.c);
    }
}
int main(){
    int n,k,m,a,b,c;
    bool ini=true;
    while(scanf("%i",&n)!=EOF){
        aristals.reserve(n+10);
        iniciarUF(n+11);
        res2=0;
        while(n>1){
            arista ar;
            scanf("%i %i %i",&ar.a,&ar.b,&ar.c);
            res2 +=ar.c;
            aristals.push_back(ar);
            n--;
        }
        scanf("%i",&k);
        while(k){
            arista ar;
            scanf("%i %i %i",&ar.a,&ar.b,&ar.c);
            aristals.push_back(ar);
            k--;
        }
        sort(aristals.begin(),aristals.end(),comparador);
        /*for(auto&x :aristals){
            printf("%i ",x.c);
        }
        puts("");*/
        res =0;
        for(auto&x:aristals){
            unir(x);
        }
        scanf("%i",&m);
        while(m){
            scanf("%i %i %i",&a,&b,&c);
            m--;
        }
        if(!ini){
            puts("");
        }
        printf("%i\n%i\n",res2,res);
        aristals.clear();
        ini=false;
    }
    return 0;
}
