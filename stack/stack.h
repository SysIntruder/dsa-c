#ifndef STACK_H
#define STACK_H

typedef struct stack stack_t;
struct stack
{
    int _top;
    int _size;
    int* p_data;

    int (*is_full)(stack_t*);
    int (*is_empty)(stack_t*);
    int (*length)(stack_t*);

    void (*traverse)(stack_t*);

    void (*push)(stack_t*, int);
    int (*pop)(stack_t*);
    int (*peek)(stack_t*);

    void (*reverse)(stack_t*);
    void (*sort)(stack_t*);
};

stack_t create_stack(int);
void destroy_stack(stack_t*);

#endif
