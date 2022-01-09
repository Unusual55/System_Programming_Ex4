#include <float.h>
#include <stdio.h>
#include <stdlib.h>

#include "edges.h"
#include "graph.h"
#include "nodes.h"

qnode* new_queue_node(pnode data, int p);
pnode pop(qnode** head);
void push(qnode** head, pnode d, int p);
int is_empty(qnode** head);
int peek(qnode** head);