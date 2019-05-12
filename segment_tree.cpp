#include<cstdio>
#include<vector>

using namespace std;
int n;
vector<int>ls,st;

int funcion(int a, int b){
    return a>b?a:b;
}
int construirST(int a, int b,int p){
    if(a==b){
        st[p]=ls[a];
        return ls[a];
    }
    st[p]=funcion(construirST(a,(a+b)/2,p*2),construirST(((a+b)/2)+1,b,(p*2)+1));
    return st[p];
}

int main(){
    scanf("%i",&n);
    ls.reserve(n);
    st.reserve(2*n);
    for(int i=0;i<n;i++) scanf("%i",&ls[i]);
    construirST(0,n-1,1);
    puts("");
    for(int i=0;i<2*n;i++){
        printf("%i ",st[i]);
    }
    puts("");
    return 0;
}