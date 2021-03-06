#include <stdio.h>
#include <stdlib.h>

int CountOddNumbers(int* A, int size) {
  int returnVal = 0;
  int i;
  for (i = 0; i < size; i++) {
    if (abs(A[i]) % 2 == 1) returnVal++;
  }
  return returnVal;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    return 0;
  }

  FILE* fp = fopen(argv[1], "r");
  if (fp == NULL) {
    return 0;
  }

  int size;
  int r = fscanf(fp, " %d ", &size);
  if (r != 1) return 0;
  
  int *A = (int *)malloc(sizeof(int) * size);

  int i;
  for (i = 0; i < size; i++) {
    fscanf(fp, " %d ", &(A[i]));
  }

  int oddCount = CountOddNumbers(A, size);
  int evenCount = size - oddCount;
  int *oddA = (int *)malloc(sizeof(int) * oddCount);
  int *evenA = (int *)malloc(sizeof(int) * evenCount);

  int j = 0;
  int k = 0;
  for (i = 0; i < size; i++) {
    if (abs(A[i]) % 2 == 1) {
      oddA[j] = A[i];
      j++;
    } else {
      evenA[k] = A[i];
      k++;
    }
  }

  for (i = 0; i < oddCount; i++) {
    for (j = i; j < oddCount; j++) {
      if (oddA[i] > oddA[j]) {
	int temp = oddA[i];
	oddA[i] = oddA[j];
	oddA[j] = temp;
      }
    }
  }

  for (i = 0; i < evenCount; i++) {
    for (j = i; j < evenCount; j++) {
      if (evenA[i] < evenA[j]) {
	int temp = evenA[i];
	evenA[i] = evenA[j];
	evenA[j] = temp;
      }
    }
  }

  for (i = 0; i < oddCount; i++) {
    printf("%d\t", oddA[i]);
  }
  
  for (i = 0; i < evenCount; i++) {
    printf("%d\t", evenA[i]);
  }

  free(A);
  free(evenA);
  free(oddA);
  printf("Hello");
  printf("Dan Was Here")
  return 0;
}



