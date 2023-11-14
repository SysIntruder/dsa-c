#ifndef STACKARR_H
#define STACKARR_H

typedef struct stack_arr stack_arr_t;
struct stack_arr
{
    int top;
    int size;
    int* p_data;

    int (*is_full)(stack_arr_t*);
    int (*is_empty)(stack_arr_t*);
    int (*length)(stack_arr_t*);

    void (*traverse)(stack_arr_t*);

    void (*push)(stack_arr_t*, int);
    int (*pop)(stack_arr_t*);
    int (*peek)(stack_arr_t*);

    void (*reverse)(stack_arr_t*);
    void (*sort)(stack_arr_t*);
};

stack_arr_t create_stack_arr(int);
void destroy_stack_arr(stack_arr_t*);

#endif
