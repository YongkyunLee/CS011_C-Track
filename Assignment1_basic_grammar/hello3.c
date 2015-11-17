#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  char name[100];
  int rand_num;
  srand(time(0));
  rand_num = rand() % 10 + 1;
  
  printf("Enter your name: ");
  scanf("%99s", name);
  
  if (rand_num % 2 == 0)
  {
    int i;
    for (i = 0; i < rand_num; i++)
    {
      printf("%d: hello, %s!\n", rand_num, name );
    }
  }
  else
  {
    int j;
    for (j = 0; j < rand_num; j++)
    {
      printf("%d: hi there, %s!\n", rand_num, name);
    }
  }

  return 0;
}
