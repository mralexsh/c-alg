#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>

#define NUMBER_OF_TRIES 10000000

#define NUMBER_OF_DOORS_EXPERIMENT1 3
#define NUMBER_OF_DOORS_EXPERIMENT2 4
#define NUMBER_OF_DOORS_EXPERIMENT3 6
#define NUMBER_OF_DOORS_EXPERIMENT4 8
#define NUMBER_OF_DOORS_EXPERIMENT5 10


int switch_door(int q, int a, int total)
{
  int result = q;
  while (result == q || result == a)
  {
    result = rand() % total;
  }
  return result;
}

bool simple_guess(size_t number_of_doors)
{
  int q = rand() % number_of_doors;
  int a = rand() % number_of_doors;
  return q == a;
}

bool switching_guess(size_t number_of_doors)
{
  int q = rand() % number_of_doors;
  int a = rand() % number_of_doors;

  int empty = switch_door(q, a, number_of_doors);

  assert(empty != q);
  assert(empty != a);
  
  return q == switch_door(empty, a, number_of_doors);
}

float do_experiment(bool (*experiment_fn)(size_t number_of_doors), size_t number_of_tries, size_t number_of_doors)
{
  assert(number_of_tries != 0);
  size_t guesses = 0;
  for (size_t i = 0; i < number_of_tries; i++)
    if ((*experiment_fn)(number_of_doors))
      guesses++;
  return guesses * 100.0 / number_of_tries;
}

int main()
{
  srand(time(NULL));
  printf("Number of tries: %d  Number of doors: %d\n", NUMBER_OF_TRIES, NUMBER_OF_DOORS_EXPERIMENT1);
  printf("(simple) guesses %.2f %%\n", do_experiment(simple_guess, NUMBER_OF_TRIES, NUMBER_OF_DOORS_EXPERIMENT1));
  printf("(switching) guesses %.2f %%\n", do_experiment(switching_guess, NUMBER_OF_TRIES, NUMBER_OF_DOORS_EXPERIMENT1));

  printf("Number of tries: %d  Number of doors: %d\n", NUMBER_OF_TRIES, NUMBER_OF_DOORS_EXPERIMENT2);
  printf("(simple) guesses %.2f %%\n", do_experiment(simple_guess, NUMBER_OF_TRIES, NUMBER_OF_DOORS_EXPERIMENT2));
  printf("(switching) guesses %.2f %%\n", do_experiment(switching_guess, NUMBER_OF_TRIES, NUMBER_OF_DOORS_EXPERIMENT2));

  printf("Number of tries: %d  Number of doors: %d\n", NUMBER_OF_TRIES, NUMBER_OF_DOORS_EXPERIMENT3);
  printf("(simple) guesses %.2f %%\n", do_experiment(simple_guess, NUMBER_OF_TRIES, NUMBER_OF_DOORS_EXPERIMENT3));
  printf("(switching) guesses %.2f %%\n", do_experiment(switching_guess, NUMBER_OF_TRIES, NUMBER_OF_DOORS_EXPERIMENT3));

  printf("Number of tries: %d  Number of doors: %d\n", NUMBER_OF_TRIES, NUMBER_OF_DOORS_EXPERIMENT4);
  printf("(simple) guesses %.2f %%\n", do_experiment(simple_guess, NUMBER_OF_TRIES, NUMBER_OF_DOORS_EXPERIMENT4));
  printf("(switching) guesses %.2f %%\n", do_experiment(switching_guess, NUMBER_OF_TRIES, NUMBER_OF_DOORS_EXPERIMENT4));

  printf("Number of tries: %d  Number of doors: %d\n", NUMBER_OF_TRIES, NUMBER_OF_DOORS_EXPERIMENT5);
  printf("(simple) guesses %.2f %%\n", do_experiment(simple_guess, NUMBER_OF_TRIES, NUMBER_OF_DOORS_EXPERIMENT5));
  printf("(switching) guesses %.2f %%\n", do_experiment(switching_guess, NUMBER_OF_TRIES, NUMBER_OF_DOORS_EXPERIMENT5));

  return 0;
}