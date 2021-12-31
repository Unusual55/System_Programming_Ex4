#include<stdio.h>
#include "stack.h"
#include<stdlib.h>
void push(stack_t** head, pnode node){
    stack_t* newstack;
    newstack = (stack_t*)malloc(sizeof(stack_t));
    if(newstack == NULL){
        return;
    }
    newstack->ver = node;
    newstack->next = *head;
    *head = newstack;
}

pnode* pop(stack_t** head){
    pnode ret;
    stack_t* next_node = NULL;
    if(*head == NULL){
        return -1;
    }
    next_node = (*head)->next;
    ret = (*head)->ver;
    free(*head);
    *head = next_node;
    return ret;
}