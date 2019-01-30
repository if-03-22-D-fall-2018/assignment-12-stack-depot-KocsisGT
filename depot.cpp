#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "depot.h"

struct DepotImplementation
{
  Stack stackOfStacks;
};

Depot create_depot()
{
  Depot depot = (Depot) smalloc(sizeof(DepotImplementation));
  depot->stackOfStacks = create_stack();

  return depot;
}

void delete_depot(Depot depot)
{
  while(get_count(depot->stackOfStacks) != 0)
  {
    delete_stack((Stack) pop_stack(depot->stackOfStacks));
  }
  sfree(depot->stackOfStacks);
  sfree(depot);
}

static void add_new_stack(Depot depot, Product *product);

void push_depot(Depot depot, Product* product)
{
  if (get_count(depot->stackOfStacks) == 0)
  {
    add_new_stack(depot, product);
    return;
  }

    Stack current = (Stack) peek_stack(depot->stackOfStacks);
    if(get_count(current) == STACK_SIZE)
    {
      add_new_stack(depot, product);
      return;
    }

    push_stack(current, product);
}

static void add_new_stack(Depot depot, Product *product)
{
  Stack stack = create_stack();
  push_stack(stack, product);
  push_stack(depot->stackOfStacks, stack);
}

int get_count(Depot depot)
{
  return get_count(depot->stackOfStacks);
}

Product* pop_depot(Depot depot)
{
  if(get_count(depot->stackOfStacks) == 0)
  {
    return 0;
  }
  Stack current = (Stack) peek_stack(depot->stackOfStacks);

  if(get_count(current) == 1)
  {
    current = (Stack) pop_stack(depot->stackOfStacks);
    Product *product = (Product*) pop_stack(current);
    delete_stack(current);
    return product;
  }
  return (Product*) pop_stack(current);
}
