#include "stdio.h"
#include "my_mat.h"
#define infinty 1000
#define True 1
#define False 0
#define nV 10

int get_matrix(int matrix [][nV]){
    int value=0;
    for(int i=0;i<nV;i++){
        for(int j=0;j<nV;j++){
            scanf("%d",&value);
            if(i==j){
                matrix[i][j] = 0;
             }
             else if(value==0){
                matrix[i][j]=infinty;
             }
             else{
             matrix[i][j]=value;
             }
        }
    }
    return 0;
}
int if_there_path(int i, int j,int matrix [][nV]){

    int matrix2[nV][nV], x, y, k;

  for (x = 0; x < nV; x++){
    for (y = 0; y < nV; y++){
      matrix2[x][y] = matrix[x][y];
        }
  }
  int tmp1;
  int tmp2;
  int tmp3;

  for (k = 0; k < nV; k++) {
    for (x = 0; x < nV; x++) {
      for (y = 0; y < nV; y++) {
        tmp1=matrix2[x][y];
        tmp2=matrix2[x][k];
        tmp3=matrix2[k][y];
        if (tmp1 > tmp2+tmp3)
          matrix2[x][y] = tmp2 + tmp3;
      }

    }
  }
    
    if(matrix2[i][j]==0 || matrix2[i][j]==infinty){
        printf("False\n");
        return False;
    }
    else{
        printf("True\n");
        return True;
    }
}
int shortest_path(int i, int j , int matrix[][nV]){
    int matrix2[nV][nV], x, y, k;

  for (x = 0; x < nV; x++){
    for (y = 0; y < nV; y++){
      matrix2[x][y] = matrix[x][y];
        }
  }

int tmp1;
  int tmp2;
  int tmp3;
  // Adding vertices individually
  for (k = 0; k < nV; k++) {
    for (x = 0; x < nV; x++) {
      for (y = 0; y < nV; y++) {
        tmp1=matrix2[x][y];
        tmp2=matrix2[x][k];
        tmp3=matrix2[k][y];
        if (tmp1 > tmp2+tmp3)
          matrix2[x][y] = tmp2 + tmp3;
      }

    }
  }
    if(matrix2[i][j]==0||matrix2[i][j]==infinty){
        return -1;
    }
    return matrix2[i][j];
}


