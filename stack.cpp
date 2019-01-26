#include "stack.h"

typedef struct Node
{
  struct Node* next;
  void* data;
}Node;

struct StackImplementation
{
  int counter;
  struct Node* head;
};



Stack create_stack()
{
  Stack stack = (Stack)smalloc(sizeof(StackImplementation));
  stack->counter = 0;
  stack->head = 0;

  return stack;
}

void delete_stack(Stack stack)
{
  while (stack->head != 0)
  {
    Node* toDelete = stack->head;
    stack->head = stack->head->next;
    sfree(toDelete);
  }
  sfree(stack);
}

void push_stack(Stack stack, void *data)
{
  Node* node = (Node*)smalloc(sizeof(Node));
  node->data = data;
  node->next = stack->head;
  stack->head = node;
  stack->counter++;
}

int get_count(Stack stack)
{
  return stack->counter;
}

void* pop_stack(Stack stack)
{
  /*if (stack->counter == 0)
  {
    return 0;
  }

  Node* result = stack->head;
  void* data = result->data;
  stack->head = result->next;
  sfree(result);
  stack->counter--;
  return data;*/
}

void* peek_stack(Stack stack)
{
  return 0;
}
