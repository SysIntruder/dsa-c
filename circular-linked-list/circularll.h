#ifndef CIRCULARLL_H
#define CIRCULARLL_H

struct circular_node {
    int data;
    struct circular_node* p_prev;
    struct circular_node* p_next;
};

struct circular_ll {
    struct circular_node* p_head;

    int (*is_empty)(struct circular_ll*);

    int (*count)(struct circular_ll*, struct circular_node*, struct circular_node*);
    int (*length)(struct circular_ll*);
    void (*traverse)(struct circular_ll*);

    struct circular_node* (*get_node)(struct circular_ll*, int);
    int (*search)(struct circular_ll*, int);

    void (*_insert_node)(struct circular_ll*, struct circular_node**, int);
    void (*insert_first)(struct circular_ll*, int);
    void (*insert_last)(struct circular_ll*, int);
    void (*insert_after)(struct circular_ll*, int, int);
    void (*insert_before)(struct circular_ll*, int, int);
    void (*insert_at)(struct circular_ll*, int, int);

    void (*_delete_node)(struct circular_ll*, struct circular_node**);
    void (*delete_first)(struct circular_ll*);
    void (*delete_last)(struct circular_ll*);
    void (*delete_after)(struct circular_ll*, int);
    void (*delete_before)(struct circular_ll*, int);
    void (*delete_at)(struct circular_ll*, int);

    void (*reverse)(struct circular_ll*);
    void (*sort)(struct circular_ll*);
};

struct circular_ll create_circular_ll();
void destroy_circular_ll(struct circular_ll*);

#endif