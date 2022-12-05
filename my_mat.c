#include "stdio.h"
#include "my_mat.h"
#define infinity 1000
#define True 1
#define False 0
#define size 10

int get_matrix(int matrix [][size]){
    int value=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            scanf("%d",&value);
            if(i==j){// There is no path from vertice to himself
                matrix[i][j] = 0;
             }
             else if(value==0){//in order to use warshall algorithm we need infinity because we are cheking with min
                matrix[i][j]=infinity;
             }
             else{
             matrix[i][j]=value;//Getting the input and putting it in the matrix
             }
        }
    }
    return 0;
}
int if_there_path(int i, int j,int matrix [][size]){ 

    int matrix2[size][size], x, y, k;//setting parameters

  for (x = 0; x < size; x++){
    for (y = 0; y < size; y++){
      matrix2[x][y] = matrix[x][y];//copying the matrix to matrix2
        }
  }

  for (k = 0; k < size; k++) {//runnig on Ai matrix. the lsat matrix is the matrix with the shortest path 
    for (x = 0; x < size; x++) {
      for (y = 0; y < size; y++) {
        if (matrix2[x][k] + matrix2[k][y] < matrix2[x][y])//By the given formula in the exercise
          matrix2[x][y] = matrix2[x][k] + matrix2[k][y];
      }

    }
  }
    
    if(matrix2[i][j]==0 || matrix2[i][j]==infinity){//checking whether the val in the matrix in the given cordinates is ilegal
        printf("False\n");
        return False;
    }
    else{
        printf("True\n");
        return True;
    }
}
int shortest_path(int i, int j , int matrix[][size]){// same notes as privious function
    int matrix2[size][size], x, y, k;

  for (x = 0; x < size; x++){
    for (y = 0; y < size; y++){
      matrix2[x][y] = matrix[x][y];
        }
  }
  for (k = 0; k < size; k++) {
    for (x = 0; x < size; x++) {
      for (y = 0; y < size; y++) {
        if (matrix2[x][k] + matrix2[k][y] < matrix2[x][y])
          matrix2[x][y] = matrix2[x][k] + matrix2[k][y];
      }
    }
  }
    if(matrix2[i][j]==0||matrix2[i][j]==infinity){
        return -1;
    }
    return matrix2[i][j];
}



