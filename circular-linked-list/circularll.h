#ifndef CIRCULARLL_H
#define CIRCULARLL_H

typedef struct circular_node circular_node_t;
struct circular_node
{
    int data;
    circular_node_t* p_prev;
    circular_node_t* p_next;
};

typedef struct circular_ll circular_ll_t;
struct circular_ll
{
    circular_node_t* head;

    int (*check_empty)(circular_ll_t*);

    int (*count)(circular_node_t*, circular_node_t*);
    int (*length)(circular_ll_t*);
    void (*traverse)(circular_ll_t*);

    circular_node_t* (*get_node)(circular_ll_t*, int);
    int (*search)(circular_ll_t*, int);

    void (*push_front)(circular_ll_t*, int);
    void (*push_back)(circular_ll_t*, int);
    void (*push_after)(circular_ll_t*, int, int);
    void (*push_before)(circular_ll_t*, int, int);
    void (*push_at)(circular_ll_t*, int, int);

    void (*pop_front)(circular_ll_t*);
    void (*pop_back)(circular_ll_t*);
    void (*pop_after)(circular_ll_t*, int);
    void (*pop_before)(circular_ll_t*, int);
    void (*pop_at)(circular_ll_t*, int);

    void (*reverse)(circular_ll_t*);
    void (*sort)(circular_ll_t*);
};

circular_ll_t create_circular_ll();
void destroy_circular_ll(circular_ll_t*);

#endif