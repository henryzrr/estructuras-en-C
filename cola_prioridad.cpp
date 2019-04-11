#include<queue>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;

struct comparador{
    bool operator()(const int&a, const int&b){
        return a>b;
    }
};
struct comparador2{
    bool operator()(const int& a, const int& b){
        return a<b;
    }
};

bool comp2(int a, int b){
    return a>b;
}
bool comp3(int a, int b){
    return a<b;
}
int main(){
    int ls1[]={21,34,2,3,41,2,3};
    int ls2[]={21,34,2,3,41,2,3};
    int ls3[]={21,34,2,3,41,2,3};

    priority_queue<int> cola1(ls1,ls1+7);
    priority_queue<int,vector<int>,comparador>cola2(ls1,ls1+7);
    priority_queue<int,vector<int>,comparador2> cola3 (ls1,ls1+7);

    sort(ls1,ls1+7);
    sort(ls2,ls2+7,comp2);
    sort(ls3,ls3+7,comp3);

    while(!cola1.empty()){
        printf("%i ",cola1.top());
        cola1.pop();
    }
    puts("");
    for(auto&x:ls1){
        printf("%i ",x);
    }
    puts("");
    while(!cola2.empty()){
        printf("%i ",cola2.top());
        cola2.pop();
    }
    puts("");
    for(auto&x:ls2){
        printf("%i ",x);
    }
    puts("");
    while(!cola3.empty()){
        printf("%i ",cola3.top());
        cola3.pop();
    }
    puts("");
    for(auto&x:ls3){
        printf("%i ",x);
    }
    puts("");

    return 0;
}