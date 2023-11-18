#ifndef DOUBLYLL_H
#define DOUBLYLL_H

struct doubly_node
{
    int data;
    struct doubly_node* p_prev;
    struct doubly_node* p_next;
};

struct doubly_ll
{
    struct doubly_node* p_head;

    int (*is_empty)(struct doubly_ll*);

    void (*traverse)(struct doubly_ll*);
    int (*count)(struct doubly_ll*, struct doubly_node*);
    int (*length)(struct doubly_ll*);

    struct doubly_node* (*get_node)(struct doubly_ll*, int);
    int (*search)(struct doubly_ll*, int);

    void (*_create_head)(struct doubly_ll*, int);
    void (*insert_first)(struct doubly_ll*, int);
    void (*insert_last)(struct doubly_ll*, int);
    void (*insert_after)(struct doubly_ll*, int, int);
    void (*insert_before)(struct doubly_ll*, int, int);
    void (*insert_at)(struct doubly_ll*, int, int);

    void (*delete_first)(struct doubly_ll*);
    void (*delete_last)(struct doubly_ll*);
    void (*delete_after)(struct doubly_ll*, int);
    void (*delete_before)(struct doubly_ll*, int);
    void (*delete_at)(struct doubly_ll*, int);

    void (*reverse)(struct doubly_ll*);
    void (*sort)(struct doubly_ll*);
};

struct doubly_ll create_doubly_ll();
void destroy_doubly_ll(struct doubly_ll*);

#endif