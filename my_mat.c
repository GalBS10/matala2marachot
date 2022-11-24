#include "stdio.h"
#include "my_mat.h"
#define size 10
#define infinty 1000000
#define true 1
#define false 0

int find_min(int a,int b){
    return (a<b)?a:b;
}

int get_matrix(int matrix [][size]){
    int matrix[size][size];
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            scanf("%d",matrix[i][j]);
        }
    }
    return 0;
}

int calculate_matrix(int matrix [][size] ){
int help_mat [size][size];
for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
        if(matrix[i][j]==0){
            help_mat[i][j]=infinty;
        }
        else if(i==j){
            help_mat[i][j]=0;
        }
        else{
        help_mat[i][j]=matrix[i][j];
        }
    }
}

for(int k=1;k<size;k++){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(k%2==0){
                help_mat[i][j]=matrix[i][k]+matrix[k][j];
            }
            else{//k%2==1
                matrix[i][j]=find_min(help_mat[i][j],help_mat[i][k]+help_mat[k][j]);
            }
        }
    }
}
return 1;
}

int if_there_path(int i, int j,int matrix [][size]){
    if(matrix[i][j]!=0){
        return true;
    }
    else{
        return false;
    }
}
int shortest_path(int i, int j , int matrix[][size]){
    if(matrix[i][j]==0){
        return -1;
    }
    return matrix[i][j];
}


