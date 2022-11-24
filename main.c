#include "stdio.h"
#include "my_mat.h"
#define infinty 1000
#define True 1
#define False 0
int main(){
int matrix[10][10];
char order;
int bad_choice;
int check = True;
while(check){
    scanf("%c",&order);
    if(order=='A'){//func 1
        get_matrix(matrix);
        scanf("%d",&bad_choice);
        } 
        else if(order=='B'){
        //func 2
        int i,j;
        scanf("%d",&i);
        scanf("%d",&j);
        if_there_path(i,j,matrix);
        scanf("%d",&bad_choice);
        }
        else if(order=='C'){
        //func 3
        int i,j;
        scanf("%d",&i);
        scanf("%d",&j);
        printf("%d \n",shortest_path(i,j,matrix));
        scanf("%d",&bad_choice);
        }
        else if(order=='D'){
        //exit loop
        check = False;
        }
        else{
            scanf("%d",&bad_choice);
        }
    }
    return 0;
}