#include <stdlib.h>
#include <stdio.h>
double** Matrix(int row, int col) {
    double** matrix = (double**)malloc(sizeof(double*) * row);
    int i, j;
    for (i = 0; i < row; i++) {
      matrix[i] = (double*)malloc(sizeof(double) * col);
    }
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
    matrix[i][j] = 0;
	}
    }
    return matrix;
}
void PrintMatrix(double** matrix, int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%0.0lf",matrix[i][j]);
        }
        printf("\n");
    }
}
void ReadMatrix(double** matrix, int row, int col, FILE* fp) {
  int i, j,r ;
   char com;
  double num;
   for(i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            r = fscanf(fp, " %lf%c ", &num,&com);
	    if (r == EOF||r==0) {
	//  printf("end");
	  return;
            }
            matrix[i][j] = num;
        }
    }
}

void ReadMatrixX(double** matrix, int row, int col, FILE* fp) {
  int i, j,r ;
   char com;
  double num;
   for(i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            r = fscanf(fp, " %lf%c ", &num,&com);
	    if (r == EOF||r==0) {
	//  printf("end");
	  return;
            }
            matrix[i][j] = num;
        }
    }
}
void popY(double** Y,double** X,int xrow, int xcol){
  int x;
  int y;
  for (x=0; x<xrow;x++){
    for(y=0;y<xcol;y++){
      if(y==0){
	Y[x][0]=X[x][y];
	X[x][y]=1;
      }
    }
  }
}
void insert(double** matrix,int row,int col, double value){
matrix[row][col]= value;
return;
}
double** transpose(double** matrix,int row,int col){

int x;
int y;


double** transMatrix=Matrix(col, row);
double currNum;
  for(x=0;x<row; x++){
    for (y=0;y<col;y++){
  currNum= matrix[x][y];
  insert(transMatrix,y,x,currNum);
    }
  }
  return transMatrix;
}
void freeMat(double** Matrix,int row,int col){
int x;
for(x=0;x<row;x++){
  free(Matrix[x]);
}
free(Matrix);
}


double ** IdentityMaker(int row){
int x;
int y;
double** id= Matrix(row,row);

for(x=0;x<row;x++){
for (y=0;y<row;y++){
if(x==y){
id[x][y]=1;

}else{
id[x][y]=0;
        }
    }
  }
  return id;
}


double** multiply(double** matrix1,int row1, int col1,double** matrix2,int row2,int col2,int*a,int*b){
*a=row1;
*b=col2;
if (col1 !=row2){
return NULL;
}
int resRow=row1;
int resCol=col2;
double** result= Matrix(resRow,resCol);
int x;
int y;
int z;
double sum=0;
for(x=0; x<row1;x++){
for(y=0; y<col2; y++){
    for(z=0; z<col1;z++){
    //  printf("%lf*%lf",matrix1[x][z],matrix2[z][x]);
      sum+= matrix1[x][z]*matrix2[z][y];
    }
    result[x][y]=sum;
    sum=0;
    }
}
return result;
}
void rowDivide(double*A, int size,double num){
//printf("ROW DIVIDE: %lf\n",num);
  int x;
  double top;
  double bottom=num;
for(x=0; x< size; x++){
top=A[x];
if(top==0){
A[x]=0;
}else{
A[x]=top/bottom;
}
//printf("%lf\n",A[x]);

}
}
void rowAdd(double*A ,double* B, int size,double digit){
int x;
//digit= -1*digit;
double num;
double result;
double curB=0;

digit=-1*digit;
  for(x=0; x<size;x++){
num= A[x];
//printf("num: %lf\n",num);
num= num*digit;
//printf("num: %lf\n",num);

curB= B[x];
//printf("num: %lf\n",curB);
result= num +curB;
//printf("result: %lf\n",result);

B[x]= result;
// could cause problem idk yet
  }
}
void Inverse(double** A, double** ans,int row){
int x;
int y;
int z;
//int colNum;
double zDigit;
double pivot;
for(x=0; x< row; x++){
  for(y=0; y<row;y++ ){
    if(x==y){//At pivot
      pivot= A[x][y];
if(pivot!=1){
rowDivide(A[x],row,pivot);
rowDivide(ans[x],row,pivot);
//printf("Matrix step divide \n");
//PrintMatrix(A, row, row);
//printf("ANswer: \n" );
//PrintMatrix(ans, row, row);
//printf("---------------------------------------------\n");
}
//traverse the column
for (z=0; z<row; z++){
//colNum=A[z][y];

zDigit=A[z][y];
  if(z!=x){
  //printf("add\n");
rowAdd(A[x],A[z],row,zDigit);
rowAdd(ans[x],ans[z],row,zDigit);
//printf("Matrix step add \n");
//PrintMatrix(A, row, row);
//printf("ANswer: \n" );
//PrintMatrix(ans, row, row);
//printf("---------------------------------------------\n");
}

}
}
  }
}


}
//}
int main(int argc, char** argv){
 FILE * fptr = fopen(argv[1],"r");
 int row, col,r;
 r= fscanf(fptr," %d %d ",&col,&row);
 //printf("row:%d, col:%d\n ",row,col);
   if (r == EOF || r != 2) {
                return 0;
            }
double** X=Matrix(row,col+1);
ReadMatrix(X,row,col+1,fptr);
//printf("X:\n");
double** Y=Matrix(row,1);
popY(Y,X,row,col+1);
//printf("X after popY:\n");
//PrintMatrix(X,row,col+1);

//PrintMatrix(X,row, col+1);
//double** X=Matrix(row,col+1);
//double** Y=Matrix(row,1);
//double ** transpose1= transpose(X,row,col+1);
//make a variable for the multiplied matrices and then inverse it.
double ** transpose1= transpose(X,row,col+1);

//printf("transposed matrix: \n");
//PrintMatrix(transpose1,col+1, row);
//printf("X*X^t\n");
//transpose1[0][0]= transpose1[0][0];
//double ** transpose2= transpose(X,row,col+1);
//transpose2[0][0]= transpose2[0][0];
int MMrow;
int MMcol;
double** multipliedMatrix =multiply(transpose1,col+1,row,X,row, col+1,&MMrow,&MMcol);
//PrintMatrix(multipliedMatrix,MMrow,MMcol);
//printf("start");
//PrintMatrix(multipliedMatrix, MMrow,MMcol);
double ** inv= IdentityMaker(MMrow);//could change Idk when

Inverse(multipliedMatrix,inv,MMrow);
//PrintMatrix(inv,MMrow,MMrow);
//printf("(X*X^T)^-1\n");
//PrintMatrix(inv,MMrow,MMrow);
int MM2row;
int MM2col;
//printf("(X*X^T)^-1*X^T:\n");

double**multipliedMatrix2=multiply(inv,MMrow,MMrow,transpose1,col+1,row,&MM2row,&MM2col);
//PrintMatrix(multipliedMatrix2, MM2row,MM2col);
int Wrow, Wcol;
double** W=multiply(multipliedMatrix2,MM2row,MM2col,Y,row,1,&Wrow,&Wcol);

//printf("Y:\n");
//PrintMatrix(Y,row,1);
//printf("W:\n");
//PrintMatrix(W,Wrow,Wcol);
//second equation
int nXrow;
FILE*fptr2 = fopen(argv[2],"r");
int p= fscanf(fptr2," %d ",&nXrow);
if(p!=1||p==EOF){
  return 0;
}

double** newX= Matrix(nXrow,col);
ReadMatrix(newX, nXrow,col,fptr2);
//printf("nXrow:%d, col:%d, Wrow:%d\n",nXrow,col,Wrow);
double** fitX=Matrix(nXrow,Wrow);
int a,b;
for(a=0;a<nXrow;a++){
for(b=0;b<Wrow;b++){
fitX[a][b]=1;
}
}
//printf("other\n");
//PrintMatrix(fitX,nXrow,Wrow);
int x,y;
int val=0;
for(x=0;x<nXrow;x++){
  for(y=0;y<col;y++){

val=newX[x][y];
//printf("val: %d",val);
fitX[x][y+1]=val;

}
}
//

//printf("this\n");
//PrintMatrix(fitX,nXrow,Wrow);
int ansRow,ansCol;

double** ans=multiply(fitX,nXrow,Wrow,W,Wrow,Wcol,&ansRow,&ansCol);
//printf("\n");
PrintMatrix(ans,ansRow,ansCol);
freeMat(ans,ansRow,ansCol);
freeMat(newX,nXrow, Wrow);
freeMat(X,row,col+1);
freeMat(Y,row,1);
freeMat(transpose1,col+1,row);
freeMat(inv,MMrow,MMrow);
freeMat(W,Wrow,Wcol);
freeMat(fitX,nXrow,Wrow);
freeMat(multipliedMatrix2,MM2row,MM2col);
freeMat(multipliedMatrix,MMrow,MMcol);

//double** W=multiply(multipliedMatrix2,MM2row,MM2col,Y,row,1,&Wrow,&Wcol);
//fitX=Matrix(nXrow,Wrow);
//double**multipliedMatrix2=multiply(inv,MMrow,MMrow,transpose1,col+1,row,&MM2row,&MM2col);
//double** multipliedMatrix =multiply(transpose1,col+1,row,X,row, col+1,&MMrow,&MMcol);




//ans[0][0]=ans[0][0];newX= Matrix(nXrow,col);
//newX = fit(newX,nXrow,col,Wrow);
//printf("nXrow:%d, col:%d, Wrow:%d\n",nXrow,col,Wrow);

//PrintMatrix(fitX,nXrow,Wrow);
 fclose(fptr);
 return 0;
}
