/* This source code sorts the input integers. */
/* With optional command "-b" the code uses bubble sort. */
/* Otherwise, the code uses minimum element sort. */
/* The maximum number of inputs is 32. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MaxArgc 32

void min_element_sort(int num[], int num_element);
void bubble_sort(int num[], int num_element);

int main(int argc, char *argv[])
{
  int bubble_count = 0; /* Count optional command line argument "-b" */
  int quiet_count = 0; /* Count optional command line argument "-q" */
  int arr_length = 0; /* Keep track of array length */
  int num_list[MaxArgc];
  int i, j, k;
  for (i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "-b") == 0)
    {
      bubble_count = 1;
    }
    else if (strcmp(argv[i], "-q") == 0)
    {
      quiet_count = 1;
    }
    else
    {
      if (arr_length >= MaxArgc)
      {
        fprintf(stderr, "usage: %s [-b] [-q] number 1 [number 2...] (maximum 32 numbers)\n", argv[0]);
        exit(1);
      }
      /* Convert strings into integers and make a new array of them */
      num_list[arr_length] = atoi(argv[i]);
      arr_length ++;
    }
  }
  /* Print error message and exit when 0 or more than 32 numbers */
  if (arr_length == 0)
  {
    fprintf(stderr, "usage: %s [-b] [-q] number 1 [number 2...] (maximum 32 numbers)\n", argv[0]);
    exit(1);
  }
  /* Use bubble sort if there is "-b" in command-ine argument */
  if (bubble_count == 1)
  {
    bubble_sort(num_list, arr_length);
    if (quiet_count == 0)
    {
      for(j = 0; j < arr_length; j++)
      {
        printf("%d\n", num_list[j]);
      }
    }
  }
  else
  {
    min_element_sort(num_list, arr_length);
    if (quiet_count == 0)
    {
      for(k = 0; k < arr_length; k++)
      {
        printf("%d\n", num_list[k]);
      }
    }
  }
  return 0;
}

void min_element_sort(int num[], int num_element)
/* This function uses minimum element sort to sort input array. */
{
  int start = 0;
  int smallest;
  int i, j, temp;
  while (start < num_element)
  {
    smallest = start;
    for (i = start; i < num_element; i++)
    {
      if(num[i] < num[smallest])
      {
        smallest = i; /* Update the position of smallest number */
      }
    }
    /* Swap the start number and smallest number */
    temp = num[smallest];
    num[smallest] = num[start];
    num[start] = temp;
    start ++;
  }
  /* Check that array is sorted correctly */
  for (j = 1; j < num_element; j++)
  {
    assert(num[j] >= num[j-1]);
  }
}

void bubble_sort(int num[], int num_element)
/* This function uses bubble sort to sort input array of integers. */
{
  int i, j, k;
  int temp;
  int swap = 1; /* check whether there was a swap */
  while (swap)
  {
    swap = 0;
    for (j = 1; j < num_element; j++)
    {
      i = j - 1; /* Compare adjacent numbers */
      if (num[i] > num[j])
      /* Swap with the next number if earlier number is larger */
      {
        temp = num[j];
        num[j] = num[i];
        num[i] = temp;
        swap ++; /* if no swap: swap = 0 and the while loop ends */
      }
    }
  }
  /* Check that array is sorted correctly */
  for (k = 1; k < num_element; k++)
  {
    assert(num[k] >= num[k-1]);
  }
}
