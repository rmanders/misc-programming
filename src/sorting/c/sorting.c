
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

/*
===============================================================================
Generate list
===============================================================================
*/
int* random_list(int len, int max) {
    int i;
    int* list;
    list = NULL;
    list = (int*) malloc (sizeof(int) * len);
    if (NULL == list) {
        printf("Out of memory. Can't generate a random list of ints\n");
        return NULL;
    }

    srand(time(NULL));
    for (i=0; i<len; i++) {
        list[i] = rand() % max;
    }
    return list;
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
================================================================================
Max
================================================================================
 */
int max(int* list, int len) {
  int max, i;
  max = INT_MIN;
  for (i=0; i<len; i++) {
    if (list[i] > max)
      max = list[i];
  }
  return max;
}

/*
================================================================================
Merge
================================================================================
 */
void merge (int* list_a, int len_a, int* list_b, int len_b, int* list_c) {
  // Merges two lists that are assumed to be sorted, resulting in a sorted list
  int len_c, i, j, k;
  len_c = len_a + len_b;
  
  i = j = k = 0;
  while (k < len_c && i < len_a && j < len_b) {
    if (list_a[i] < list_b[j])
      list_c[k++] = list_b[j++];
    else
      list_c[k++] = list_a[i++];
  }
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

/*
================================================================================
Count Sort
================================================================================
*/
void count_sort(int* list, int len);

/*
================================================================================
Main 
================================================================================
 */
int main(void) {
  int* list;
  int len, i, max;
  list = NULL;
  len = 10;
  max = 100;
  
  list = random_list(len, max);

  print_list(list, len);
  printf("Sorting list...\n");
  bubble_sort(list, len);
  print_list(list, len);

  return 0;
}
