
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

/*
===============================================================================
Generate list
===============================================================================
*/
void random_list(int* list, int len) {
    int i;    
    list = NULL;
    list = (int*) malloc (sizeof(int) * len);
    if (NULL == list) {
        printf("Out of memory. Can't generate a random list of ints\n");
        return;
    }

    srand(time(NULL));
    for (i=0; i<len; i++) {
        list[i] = rand() % INT_MAX;
    }
}

/*
===============================================================================
Print list
===============================================================================
*/
void print_list(int* list, int len) {
  int i;
  printf("[");
  for (i=0; i<len-1; i++) {
    printf("%d,", list[i]);
  }
  printf("%d]\n", list[len-1]);
}

/*
===============================================================================
Bubble Sort
===============================================================================
*/
void bubble_sort(int* list, int len) {
  int i, j, temp;
  for (i=0; i<len; i++) {
    for (j=0; j<len; j++) {
      if (j < len-1 && list[j] > list[j+1]) {
	temp = list[j+1];
        list[j+1] = list[j];
        list[j] = temp;
      }
    }
  }
}

int main(void) {
  int* list;
  int len = 10;
  list = NULL;
  
  printf("generating list..");
  random_list(list, len);
  print_list(list, len);

  printf("Sorting list...");
  bubble_sort(list, len);
  print_list(list, len);

  return 0;
}
