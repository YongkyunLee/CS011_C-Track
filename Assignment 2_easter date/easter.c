/* This program calculates the date of Easter in the given year. */
#include <stdio.h>
int calculate_Easter_date(int year);

int calculate_Easter_date(int year)
{
  /* The purpose of this function is to calculate date of Easter. */
  /* Arguments: year - year in which we want to find the Easter date. */
  /* Return Value: number representing month and date. */
  int gold_yr; /* It is golden year in the 19_year Metonic cycle. */
  int century;
  int skip_lp_yr; /* It means skipped leap years. */
  int corr_fac; /* It means correction factor for moon's orbit. */
  int day;
  int epact; /* It specifies when a full moon occurs. */
  int date; /* It represents Sunday after full moon. */

  /* The function only accepts input year between 1582 and 39999  */
  if (year < 1582 || year > 39999)
  {
    return 0;
  }

  gold_yr = (year % 19) + 1;
  century = (int) ((year / 100) + 1);
  skip_lp_yr = (int) ((3 * century) / 4 - 12);
  corr_fac = (int) ((8 * century + 5) / 25 - 5);
  day = (int) ((5 * year) / 4 - skip_lp_yr - 10);
  epact = (11 * gold_yr + 20 + corr_fac - skip_lp_yr) % 30;
  if ((epact == 25 && gold_yr > 11) || (epact == 24))
  {
    epact++;
  }
  date = 44 - epact;
  if (date < 21)
  {
    date += 30;
  }
  date = date + 7 - ((day + date) % 7);
  /* If-else expresses March with - sign  and April with + sign */
  if (date > 31)
  {
    date -= 31;
  }
  else
  {
    date -= 2 * date;
  }
  return date;
}

int main(void)
{
  /* Main function: reads input file, calculates, and prints output file. */
  while(1)
  {
    int date, input, result;
    result = scanf("%d", &input);
    date = calculate_Easter_date(input);
    if (date == 0) /* For input out of range, print an error message. */
    {
      fprintf(stderr, "Input year is out of range.\n");
      /* Question: Isn't message supposed to be printed on output file? */
      /* The message is only printed on terminal. I don't get why. */
      continue;
    }
    if (result == EOF) /* At end of file, code escapes the while loop. */
    {
      break;
    }
    if (date > 0) /* If year is positive, it means the month is April. */
    {
      printf("%d - April %d\n", input, date);
    }
    else /* If year is negative, it means the month is March. */
    {
      printf("%d - March %d\n", input, (-date));
    }
  }

  return 0;
}
