#include <cs50.h>
#include <stdio.h>

int main(void)
{
int years = 0;

    // TODO: Prompt for start size
    int n;
  do
  {
      n = get_int("Start size: ");
  }
  while (n < 9);


    // TODO: Prompt for end size
    int i;
  do
  {
    i = get_int("End size: ");
  }
  while (i < n);

    // TODO: Calculate number of years until we reach threshold
    while (n < i)
    {
      int x = n + (n / 3) - (n / 4);
      n = x;
      years++;
    }

    // TODO: Print number of years
    printf("Years: %d\n", years);
    return 0;
}