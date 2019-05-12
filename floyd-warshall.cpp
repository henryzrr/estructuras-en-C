#include<cstdio>

using namespace std;
int grafofw[100][100],grafoh[100][100],vertices,aristas,i,j,k,a,b,sum;

void prepararGrafo(){
    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
            grafofw[i][j]=grafoh[i][j]=10000;
        }
    }

}
void floydwarshall(){
    for(k=0;k<vertices;k++){
        for(i=0;i<vertices;i++){
            for(j=0;j<vertices;j++){
                sum = grafofw[i][k]+grafofw[k][j];
                grafofw[i][j]=grafofw[i][j]>sum?sum:grafofw[i][j];
            }
        }
    }
}
void henryalg(){
    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
            for(k=0;k<vertices;k++){
                sum = grafoh[j][i]+grafoh[i][k];
                grafoh[j][k]=grafoh[j][k]>sum?sum:grafoh[j][k];
            }
        }
    }
}
int main(){
    scanf("%i %i",&vertices,&aristas);
    prepararGrafo();    
    while(aristas--){
        scanf("%i %i",&a,&b);
        grafoh[b][b]=grafofw[b][b]=grafofw[a][a]=grafoh[a][a]=0;
        grafofw[a][b]=grafofw[b][a]=grafoh[a][b]=grafoh[b][a]=1;
    }
    floydwarshall();
    henryalg();
    puts("");
    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
            printf("%i ",grafofw[i][j]);
        }
        puts("");
    }
    puts("");
    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
            printf("%i ",grafoh[i][j]);
        }
        puts("");
    }
    return 0;
}