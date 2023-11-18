#ifndef DYNSTACK_H
#define DYNSTACK_H

struct dyn_stack {
    int _top;
    int _size;
    int* p_data;

    int (*is_full)(struct dyn_stack*);
    int (*is_empty)(struct dyn_stack*);
    int (*length)(struct dyn_stack*);

    void (*traverse)(struct dyn_stack*);

    void (*push)(struct dyn_stack*, int);
    int (*pop)(struct dyn_stack*);
    int (*peek)(struct dyn_stack*);

    void (*reverse)(struct dyn_stack*);
    void (*sort)(struct dyn_stack*);
};

struct dyn_stack create_dyn_stack(int);
void destroy_dyn_stack(struct dyn_stack*);

#endif
