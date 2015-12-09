/* This program simulates a 1 dimensional cellular automation
using array method.
An array composed of 0 and 1 will be generated according to the rules:
1. If the current cell is empty, and one of the two adjacent
cells is full (but not both), set the current cell to be full.
2. Otherwise set the current cell to be empty. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "memcheck.h"
#define MaxArgc 2

/* Signature Function */
int *initial_array(int num_element);
int *update(int arr[], int num_element);
void print_arr(int arr[], int num_element);

/* This function generates the initial array of the 1d game of life.
The size of array is decided by the input integer.
The first and last cell are set to be empty, and all the other cells are
designated to be either full or empty randomly.
Arguments:
 num_element: the number of cells in the array
Return value: randomly generated array of cells */
int *initial_array(int num_element)
{
  int i, rand_num;
  int *arr;
  srand(time(0));
  /* initialize array to have num_element elements */
  arr = (int *)calloc(num_element, sizeof(int));
  /* Check that the calloc call succeeded */
  if (arr == NULL)
  {
    fprintf(stderr, "Error! Memory allocation failed.\n");
    exit(1);
  }
  arr[0] = 0; /* first and last elements are empty */
  arr[num_element - 1] = 0;
  for (i = 1; i < num_element - 1; i++)
  {
    rand_num = rand() % 2; /* Generate either 0 or 1 */
    arr[i] = rand_num;
  }
  return arr;
}

/* Produce next generation of array of cells from the given array
Arguments:
 arr[] : input array that is base of the next generation
 int num_element : the number of cells in arr[]
Return value: the next generation produced from arr[] */
int *update(int arr[], int num_element)
{
  int i;
  int *next_arr; /* array of next generation cells */
  /* initialize array to have num_element elements */
  next_arr = (int *)calloc(num_element, sizeof(int));
  /* Check that the calloc call succeeded */
  if (next_arr == NULL)
  {
    fprintf(stderr, "Error! Memory allocation failed.\n");
    exit(1);
  }
  next_arr[0] = 0;   /* The first and the last cells are always empty. */
  next_arr[num_element - 1] = 0;
  /* make next generation array according to the rules:
  Full(1) if one of adjacent cells is full. Empty(0) otherwise */
  for (i = 1; i < num_element - 1; i++)
  {
    if (arr[i] == 0 && arr[i - 1] == 1 && arr[i + 1] == 0)
    {
      next_arr[i] = 1;
    }
    else if (arr[i] == 0  && arr[i - 1] == 0 && arr[i + 1] == 1)
    {
      next_arr[i] = 1;
    }
    else
    {
      next_arr[i] = 0;
    }
  }
  return next_arr;
}

/* Prints the input array in a single row.
Arguments:
 arr[]: the input array to print
 num_element: the number of cells in the input array
Return value: None */
void print_arr(int arr[], int num_element)
{
  int i;
  for (i = 0; i < num_element; i++)
  {
    if (arr[i] == 0)
    {
      printf(".");
    }
    else /* if arr[i] == 1 */
    {
      printf("*");
    }
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  int *arr1, *arr2;
  int i;
  int num_element = atoi(argv[1]);
  int num_generation = atoi(argv[2]);
  /* Check command-line violations */
  if (argc > MaxArgc + 1 || num_element == 0 || num_generation == 0)
  {
    fprintf(stderr, "usage: %s #cells #generations\n", argv[0]);
    exit(1);
  }
  arr1 = initial_array(num_element);
  print_arr(arr1, num_element);
  if (num_generation > 1) /* If there is 1 generation, loop does not work */
  {
    for (i = 1; i < num_generation; i++)
    {
      /* Alternate between arr1, arr2 to store the updated array */
      if (i % 2 == 1)
      {
        arr2 = update(arr1, num_element);
        print_arr(arr2, num_element);
        free(arr1); /* Question!!!!!!! Why does arr1 has to be freed every time if it is going to be replaced by updated arr2 in the next round. */
      }
      else
      {
        arr1 = update(arr2, num_element);
        print_arr(arr1, num_element);
        free(arr2);
      }
    }
    /* Prevent memory leakage of the array used last */
    if (num_generation % 2 == 0)
    {
      free(arr2);
    }
    else
    {
      free(arr1);
    }
  }
  else
  {
    free(arr1);
  }
  print_memory_leaks();
  return 0;
}
