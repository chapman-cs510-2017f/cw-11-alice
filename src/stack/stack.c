#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//define new_stack function to create a new stack
STACK new_stack() {
    STACK new = NULL;
    return new;
}

// create stack to add to the stack
// use malloc to allocate requested memory and return pointer
// add data to the new stack
// assign pointer to the head of the new stack
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

// Create pop_stack function
// check if the stack is empty; have it print error if == NULL
// Assign val variable to equal the first component in stack data
// Store the stack data to the variable temp
// Assign pointer to equal the head of the pointer of the stack
// use the free function to dealocate memory
// return current stack data
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

// Function to print svalue
void print_svalue(SVALUE data){
    // Printer for svalue
    printf("%d\n", data);
}

// Printer for stack
void print_stack(STACK s){
    
    while (s->head != NULL) 
    {
        print_svalue(s->data);
        s = s->head;      
    }
    
    //if the last value in the stack(head is NULL), print the value of the tail of the stack 
    print_svalue(s->data);
}
