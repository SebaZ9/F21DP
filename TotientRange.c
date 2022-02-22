// TotientRance.c - Sequential Euler Totient Function (C Version)
// compile: gcc -Wall -O -o TotientRange TotientRange.c
// run:     ./TotientRange lower_num uppper_num

// Greg Michaelson 14/10/2003
// Patrick Maier   29/01/2010 [enforced ANSI C compliance]

// This program calculates the sum of the totients between a lower and an 
// upper limit using C longs. It is based on earlier work by:
// Phil Trinder, Nathan Charles, Hans-Wolfgang Loidl and Colin Runciman

#include <stdio.h>
#include <time.h>
#include <inttypes.h>

// hcf x 0 = x
// hcf x y = hcf y (rem x y)

long hcf(long x, long y)
{
  long t;

  while (y != 0) {
    t = x % y;
    x = y;
    y = t;
  }
  return x;
}


// relprime x y = hcf x y == 1

int relprime(long x, long y)
{
  return hcf(x, y) == 1;
}


// euler n = length (filter (relprime n) [1 .. n-1])

uint64_t euler(long n)
{
  uint64_t length;
  long i;

  length = 0;
  for (i = 1; i < n; i++)
    if (relprime(n, i))
      length++;
  return length;
}


// sumTotient lower upper = sum (map euler [lower, lower+1 .. upper])

uint64_t sumTotient(long lower, long upper)
{
  long i;
  uint64_t sum;

  sum = 0;
  for (i = lower; i <= upper; i++)
    sum = sum + euler(i);
  return sum;
}


int main(int argc, char ** argv)
{
  long lower, upper;


  if (argc != 3) {
    printf("not 2 arguments\n");
    return 1;
  }
  sscanf(argv[1], "%ld", &lower);
  sscanf(argv[2], "%ld", &upper);
  clock_t start_time = clock();
  printf("C: Sum of Totients  between [%ld..%ld] is %"PRIu64"\n", lower, upper, sumTotient(lower, upper));
  printf("Elapsed time: %f secs", (double)(clock() - start_time) / CLOCKS_PER_SEC);
  return 0;
}

