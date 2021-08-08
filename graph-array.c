#include<stdio.h>
#define MAX_R 20
#define MAX_C 20

int mat[MAX_R][MAX_C];//5
char vertex[MAX_R];

void main(){

    int totalV,r,c,i,j;
    int choice;
    printf("\nHow many Vertex you want to create?");
    scanf("%d",&totalV);
    r=totalV;
    c=totalV;

    for(i=0;i<r;i++){//0 A  1 B  2 C
        for(j=i;j<c;j++){
            printf("\n%c is connected with %c ??",65+i,65+j);
            printf("\n1 For Yes\n0 For No");
           scanf("%d",&choice);
            mat[i][j] = choice;//A - B = 1
            mat[j][i] = choice;// B - A = 1
        }
    }
    printf("\n\n");

    for(i=0;i<r;i++){
        printf("   %c",65+i);
    }
   printf("\n");
    for(i=0;i<r;i++){
        printf("%c ",65+i);
        for(j=0;j<c;j++){
            printf(" %d ",mat[i][j]);
        }
        printf("\n");
    }

    // A?
    //B C
    //C?
    //A B  D


}
