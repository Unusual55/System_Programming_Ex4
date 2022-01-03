#include "queue.h"

qnode* new_queue_node(pnode data, int p) {
    qnode* temp = (qnode*)malloc(sizeof(qnode));
    temp->nodedata = data;
    temp->priority = p;
    temp->next = NULL;
    return temp;
}

pnode pop(qnode** head) {
    pnode temp = (*head)->nodedata;
    qnode* temptofree = *head;
    (*head) = (*head)->next;
    free(temptofree);
    return temp;
}

void push(qnode** head, pnode d, int p) {
    qnode* start = (*head);
    qnode* temp = new_queue_node(d, p);
    if (is_empty(head)) {
        (*head) = temp;
        return;
    }

    if ((*head)->priority > p) {
        temp->next = *head;
        (*head) = temp;
    } else {
        while (start->next != NULL && start->next->priority < p) {
            start = start->next;
        }

        temp->next = start->next;
        start->next = temp;
    }
}

int is_empty(qnode** head) {
    return (*head) == NULL;
}
