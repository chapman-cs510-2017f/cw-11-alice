#include <stdio.h>
#include "../src/stack/stack.h"

int main(void) {
    STACK s = new_stack();
    SVALUE val;

    puts("Putting items on the stack: 1,2,3");
    push_stack(&s, 1);
    push_stack(&s, 2);
    push_stack(&s, 3);
    puts("Popping items off the stack and printing:");
    val = pop_stack(&s);
    print_svalue(val);
    puts("4");
    push_stack(&s, 4);
    val = pop_stack(&s);
    print_svalue(val);
    puts("5");
    push_stack(&s, 5);
    val = pop_stack(&s);
    print_svalue(val);
    puts("6");
    push_stack(&s, 6);
    val = pop_stack(&s);
    print_svalue(val);
    puts("Putting items on the stack: 4,5,6");
    push_stack(&s, 4);
    push_stack(&s, 5);
    push_stack(&s, 6);
    puts("Printing the stack:");
    print_stack(s);
    return 0;
}
