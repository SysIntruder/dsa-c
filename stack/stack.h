#ifndef STACK_H
#define STACK_H

struct stack {
    int _top;
    int _size;
    int* p_data;

    int (*is_full)(struct stack*);
    int (*is_empty)(struct stack*);
    int (*length)(struct stack*);

    void (*traverse)(struct stack*);

    void (*push)(struct stack*, int);
    int (*pop)(struct stack*);
    int (*peek)(struct stack*);

    void (*reverse)(struct stack*);
    void (*sort)(struct stack*);
};

struct stack create_stack(int);
void destroy_stack(struct stack*);

#endif
