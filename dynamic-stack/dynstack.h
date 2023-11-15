#ifndef DYNSTACK_H
#define DYNSTACK_H

typedef struct dyn_stack dyn_stack_t;
struct dyn_stack
{
    int _top;
    int _size;
    int* p_data;

    int (*is_full)(dyn_stack_t*);
    int (*is_empty)(dyn_stack_t*);
    int (*length)(dyn_stack_t*);

    void (*traverse)(dyn_stack_t*);

    void (*push)(dyn_stack_t*, int);
    int (*pop)(dyn_stack_t*);
    int (*peek)(dyn_stack_t*);

    void (*reverse)(dyn_stack_t*);
    void (*sort)(dyn_stack_t*);
};

dyn_stack_t create_dyn_stack(int);
void destroy_dyn_stack(dyn_stack_t*);

#endif
