#include<stdio.h>

using namespace std;
//-------------------------
int ls[1000];
int frec[1000];
int tamlist;

void update(int pos,int val){
    while(pos<=tamlist){
        frec[pos] +=val;
        pos += (pos&-pos); 
    }
}
int query(int n){
    int res=0;
    while(n){
        res +=frec[n];
        n -=n&-n;
    }
    return res;
}
int query(int a, int b){
    return a==1?query(b):query(b)-query(a-1);
}

void reset(){
    for(int i=1;i<=tamlist;i++){
        frec[i]=0;
    }
}
int main(){
    int cases,tam;
    scanf("%i",&cases);
    while(cases--){
        scanf("%i",&tamlist);
        reset();
        for(int i=1;i<=tamlist;i++){
            scanf("%i",&ls[i]);
            update(i,ls[i]);
        }
        for(int i=1;i<=tamlist;i++){
            printf("%i ",frec[i]);
        }
        puts("");
        printf("%i\n",query(1,7));
        printf("%i\n",query(2,9));
        update(4,-ls[4]);
        ls[4]=2;
        update(4,2);
        for(int i=1;i<=tamlist;i++){
            printf("%i ",ls[i]);
        }
        puts("");
        for(int i=1;i<=tamlist;i++){
            printf("%i ",frec[i]);
        }
        puts("");
        printf("%i\n",query(1,7));
        printf("%i\n",query(2,9));
    }
    return 0;
}