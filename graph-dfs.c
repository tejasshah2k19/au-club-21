#include<stdio.h>
#define MAX 6

struct vertex{
    char label;
    int isVisited;

};
int vertexCount=0;
int adjMatrix[MAX][MAX];//00 01 02 03 04
struct vertex* allVertices[MAX];

void addVertex(char lbl){
    struct vertex* v = (struct vertex*)malloc(sizeof(struct vertex));
    v->label= lbl; //a
    v->isVisited=0;
    allVertices[vertexCount++] = v;
}
void addEdge(int i,int j){
    adjMatrix[i][j] = 1;
    adjMatrix[j][i] = 1;
}
void displayVertex(){
    int i;
    for(i=0;i<vertexCount;i++){
        printf("\n %c",allVertices[i]->label);
    }
}
void dfs(int start){ //0 1 2 3
    int i,j;
    allVertices[start]->isVisited = 1; //A B C H
    printf("%c ",allVertices[start]->label);//A B C H

    for(j=0;j<MAX;j++){
        if(adjMatrix[start][j] == 1 && allVertices[j]->isVisited == 0 ){
            dfs(j);
        }
    }
}
void main(){

    addVertex('A');//0
    addVertex('B');//1
    addVertex('C');//2
    addVertex('H');//3
    addVertex('F');//4
    addVertex('Z');//5


    addEdge(0,1); // A B
    addEdge(1,2); // B C
    addEdge(2,3); // C H
    addEdge(2,4); // C F
    addEdge(4,5); // F Z
    addEdge(0,5); // A Z

    //displayVertex();
    dfs(0);
}

