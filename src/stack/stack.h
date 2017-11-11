// Define types as abstraction layer to protect against implementation changes
typedef int SVALUE;
// Define a default value representing a pop error

#ifndef SVALUE_ERR
#define SVALUE_ERR -9999;
#endif

// Use abstract types inside definition for robustness
struct stack {
    SVALUE data;
    // Note that this type definition is recursive
    // By convention, the recursion terminates when
    // this pointer has the value NULL, indicating
    // that the end of the data structure has been
    // reached
    struct stack *head;
};

// Alias a pointer to a struct stack as STACK
typedef struct stack * STACK;

// Constructor that initializes an empty stack pointer
STACK new_stack();

// Setter for pushing a value onto the stack (why STACK *?)
void push_stack(STACK *, SVALUE);

// Getter for popping a value off the stack (why STACK *?)
SVALUE pop_stack(STACK *);

// Printer for svalue
void print_svalue(SVALUE);

// Printer for stack
void print_stack(STACK);
