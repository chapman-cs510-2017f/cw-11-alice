#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

STACK new_stack() {
    STACK new = NULL;
    return new;
}

void push_stack(STACK *s, SVALUE val) {
    STACK new = (STACK) malloc(sizeof(struct stack));
    if (new == NULL) {
        fprintf(stderr, "ERROR: Unable to push onto stack\n");
        return;
    }
    new->data = val;
    new->head = *s;
    *s = new;
}

SVALUE pop_stack(STACK *s) {
    SVALUE val;
    STACK temp;
    if (*s == NULL) {
      fprintf(stderr, "ERROR: Attempt to pop value from empty stack\n");
      val = SVALUE_ERR;
      //val=-9999;
    }
    else {
      val = (*s)->data;
      temp = (*s);
      *s = (*s)->head;
      free(temp);
    }
    return val;
}


void print_svalue(SVALUE data){
    // Printer for svalue
    printf("%d\n", data);
}


void print_stack(STACK s){
    // Printer for stack
    STACK *tmp;
    int i=0;
    tmp=&s;
    
    while (((*tmp)->head != NULL) && (i<5000)) 
    {
        //printf("head=%LG", (*tmp)->head);
        print_svalue((*tmp)->data);
        *tmp = (*tmp)->head;      
        i++;
    }
    
    //if the last value in the stack(head is NULL), print the value of the tail of the stack 
    print_svalue((*tmp)->data);
}
