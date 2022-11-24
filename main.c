#include "stdio.h"
#include "my_mat.c"
#include "my_mat.h"
#define true 1;
#define false 0;
int main(){

int matrix[10][10];
enum run{A=1,B,C,D} state;
int check = true;
char order;
while(check){
    scanf("%c",order);
    switch(state){
        case(1):
        //func 1
        get_matrix(matrix);
        break;
        case(2):
        //func 2
        int i,j;
        scanf("%d",&i);
        scanf("%d",&j);
        printf("%d",if_there_path(i,j,matrix));
        break;
        case(3):
        //func 3
        scanf("%d",&i);
        scanf("%d",&j);
        printf("%d",shortest_path(i,j,matrix));
        break;
        case(4):
        //exit loop
        check = false;
        break;
        default:
        printf("pls enter a char from A,B,C,D only");
        }
    }
    return 0;
}