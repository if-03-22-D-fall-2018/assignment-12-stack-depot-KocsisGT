#ifndef ___DEPOT_H
#define ___DEPOT_H
#include "stack.h"
#define STACK_SIZE 3

struct Product
{
  int serial_no;
};

typedef struct DepotImplementation* Depot;

Depot create_depot();

void delete_depot(Depot depot);

int get_count(Depot depot);

void push_depot(Depot depot, Product* product);

Product* pop_depot(Depot depot);

#endif
