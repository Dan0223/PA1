#include <stdlib.h>
#include <stdio.h>
struct Node{
    int data;
    struct Node* next;
};
void traverse(struct Node* LL ){
 struct Node* ptr=LL;
 while (ptr!= NULL){
   printf("%d\n",ptr->data);
   ptr= ptr->next;
 }
}

 void search(int num ,struct Node** hashTable){
   int index=abs(num%10000);
   struct Node* ptr= hashTable[index];
   if(ptr==NULL){
     printf("absent\n");
return;
   }
   while(ptr!=NULL){
   if(ptr->data==num){
       printf("present\n");
 return;
}
   ptr=ptr->next;
   }
   printf("absent\n");
   return;
 }
void insertElement(int value,struct Node** hashTable){
  int index= abs(value%10000);
  struct Node* currHead = hashTable[index];
  struct Node* newNode=malloc(sizeof(struct Node));
  newNode->data= value;
  newNode->next=NULL;
 if(currHead==NULL){
   hashTable[index]=newNode;
   printf("inserted\n");
   // at this point, hashTable[index] !=NULL, currHead = NULL
 }else{
   struct Node* ptr=hashTable[index];
   if(ptr->data ==value){
     printf ("duplicate\n");
     return;
   }
 while(ptr->next!=NULL){
   //mm
   if(ptr->data==value){
       printf("duplicate\n");
return;
}
     ptr=ptr->next;
}
ptr->next= newNode;
 printf("inserted\n");
}
return;
}
int main(int argc, char** argv) {

  if (argc!=2){
    return 0;
}
struct Node** resultTable=(struct Node**)malloc(10000*sizeof(struct Node*));
int x;
for(x=0;x<10000;x++){
    resultTable[x]=NULL;
}
 int num;
 char command;
 FILE * fptr = fopen(argv[1],"r");
 if(fptr==NULL){
   return 0;
}

 while(fscanf(fptr," %c %d ",&command,&num)!=EOF){
if (command=='i'){
  insertElement(num,resultTable);
   }else if(command=='s'){
     //searc
  search(num, resultTable);
}
 }
/*
int i;
 for(i=0;i<10000;i++){
  struct Node*currHead=resultTable[i];
  while(currHead!=NULL){
    struct Node* freeing=currHead;
     free(freeing);
     currHead=currHead->next;
   }

}
 free(resultTable);

*/
fclose(fptr);
 return 0;
}
