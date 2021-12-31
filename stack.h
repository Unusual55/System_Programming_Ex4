#ifndef STACK
#define STACK
#include "graph.h"

typedef struct stack{
    pnode* ver;
    struct stack* next;
} stack_t;

void push(stack_t** head, pnode node);

pnode* pop(stack_t** head);

void contains(stack_t* head);

#endif