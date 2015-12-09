#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "memcheck.h"
#include "linked_list.h"

node *quicksort(node *list);

node *quicksort(node *list)
{
  node *first_node; /* first node */
  node *list_sorted, *list_sorted_final; /* copied list */
  node *list_left, *list_right, *sorted_list_left, *sorted_list_right; /* left and right side of original list */
  node *item; /* variable used in for loop condition */
  list_left = NULL;
  list_right = NULL;
  if (list == NULL || list->next == NULL)
  {
    list_sorted = copy_list(list);
    return list_sorted;
  }
  first_node = create_node(list->data, NULL); /* Copy the first node of list */
  for (item = list->next; item != NULL; item = item->next)
  {
    if (item->data < first_node->data)
    {
      list_left = create_node(item->data, list_left);
    }
    else /* item >= first_node */
    {
      list_right =  create_node(item->data, list_right);
    }
  }
  sorted_list_left = quicksort(list_left);
  sorted_list_right = quicksort(list_right);
  list_sorted = append_lists(sorted_list_left, first_node);
  list_sorted_final = append_lists(list_sorted, sorted_list_right);
  free_list(list_left);
  free_list(list_right);
  free_list(sorted_list_left);
  free_list(sorted_list_right);
  free_list(list_sorted);
  free_list(first_node);
  assert(is_sorted(list_sorted_final));
  return list_sorted_final;
}

int main(int argc, char *argv[])
{
  int i, item;
  int quiet_count = 0;
  node *list, *list_sorted;
  list = NULL;
  list_sorted = NULL;
  if (argc == 1) /* error message if no number entered on command-line */
  {
    fprintf(stderr, "usage: %s [-q] number1 [number2 number3 ...]", argv[0]);
    exit(1);
  }
  /* check optional argument -q in the command-line */
  for(i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "-q") == 0)
    {
      quiet_count = 1;
    }
    else {
      item = atoi(argv[i]);
      list = create_node(item, list);
    }
  }
  list_sorted = quicksort(list);
  if (quiet_count == 0)
  {
    print_list(list_sorted);
  }
  free_list(list);
  free_list(list_sorted);
  print_memory_leaks();
  return 0;
}
