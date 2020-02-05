#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int power(int base,int power){
  int result=1;
 if(power==0){
   result=1;
    return result;
 }else if(base==0){
   result=0;
   return result;
}else{
  int x=0;
  while(x<power){
    result= result*base;
    x=x+1;
}
 }
 return result;
}
unsigned short get (unsigned short num,int position ){
  if(position<0){
    return 0;
}
  // printf("%d %d\n",num, position);
 unsigned short compNum=power(2,position) ;
 // printf("%d\n", compNum);
 unsigned answer= num&compNum;
 // printf("answer after comp %d\n",answer);
  answer= answer>>(position);
  printf("%d\n",answer);
   return answer;
}


unsigned short comp(unsigned short num, int position){
  if(position<0){
    return 0;
}
  unsigned short compNum= power(2,position);
  unsigned short answer= num^compNum;
  // printf("%d\n", answer);
  return answer;
}
unsigned short set(unsigned short num,int position,int numChange){
 if(position<0){
    return 0;
}
 unsigned short compNum;
  unsigned short answer;
  unsigned short temp;
if (numChange==1){
  compNum=power(2,position);
  answer= num|compNum;
  // printf("%d\n",answer);

}else if(numChange==0){
  temp= num&0;
  // printf("After &0: %d",temp);
  temp=~temp;
  // printf("After compliment: %d",temp);

  compNum=temp-power(2,position);
  answer= num&compNum;

  // printf("%d\n",answer);

}
 return answer;
}

//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
int main(int argc, char** argv) {
 if(argc!=2){
    printf("first\n");
    return 0;
}
  FILE* fptr= fopen(argv[1],"r");
  if(fptr==NULL){
     printf("second\n");
    return 0;
}
  int num;
  unsigned short x;
  int r;
  r=fscanf(fptr," %d ",&num);
  x=num;
if(r==EOF||r!=1){
   printf("third\n");
    return 0;
}
// char funct[5];
 int n;
 int v;
 //int g;

 //int c;
  //  int s;
 // int c;
 char funct[5];

  while(!feof(fptr)){
 fscanf(fptr ," %s ",funct);
     //  fgets(funct,5,fptr);
 fscanf(fptr," %d %d ", &v,&n);

 if(strcmp("get",funct)==0){
   // printf("function: %s\n",funct);

 // 	printf("give\n");
	get(x,v);
      }else
if(strcmp("comp",funct)==0) {
  // printf("function: %s\n",funct);

	x=comp(x,v);
	printf("%d\n",x);
	//	printf("comp\n");
 }else
 if(strcmp(funct,"set")==0){
   // printf("function: %s\n",funct);

 //	printf("set\n");
	  x=set(x,v,n);
	printf("%d\n",x);
 }
  }
  fclose(fptr);


  return 0;
}
/*
 while(!feof(fptr)){
     fscanf(fptr ," %s",&funct);
    //  fgets(funct,5,fptr);
    printf("function: %s\n",funct);
      if(strcmp("get",funct)){
	//	printf("give\n");
	fscanf(fptr," %d %d ",&v,&n);
	  unsigned short got;
	 got= get(x,n);
	 printf("Me:%d\n",got);
      }
if(strcmp("comp",funct)) {
	fscanf(fptr," %d %d ",&v,&n);
	x=comp(x,n);
	printf("%d\n",x);
	//	printf("comp\n");
 }
 if(strcmp(funct,"set")){
   //	printf("set\n");
	fscanf(fptr," %d %d ", &v,&n);
	  x=set(x,n,v);
	printf("%d\n",x);
      }

  }
*/
/*
 fscanf(fptr ," %s ",funct);
     //  fgets(funct,5,fptr);
  	fscanf(fptr," %d %d ", &v,&n);

 if(strcmp(g,funct)==1){
 printf("function: %s\n",funct);

       	printf("give\n");
	get(x,n);
      }
if(strcmp(c,funct)==1) {
 printf("function: %s\n",funct);

	x=comp(x,n);
	printf("%d\n",x);
	//	printf("comp\n");
 }
 if(strcmp(funct,s)==1){
 printf("function: %s\n",funct);

 //	printf("set\n");
	  x=set(x,n,v);
	printf("%d\n",x);
      }

*/
