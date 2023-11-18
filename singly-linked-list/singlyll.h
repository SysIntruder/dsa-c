#ifndef SINGLYLL_H
#define SINGLYLL_H

struct singly_node {
    int data;
    struct singly_node* p_next;
};

struct singly_ll {
    struct singly_node* p_head;

    int (*is_empty)(struct singly_ll*);

    void (*traverse)(struct singly_ll*);
    int (*count)(struct singly_ll*, struct singly_node*);
    int (*length)(struct singly_ll*);

    struct singly_node* (*get_node)(struct singly_ll*, int);
    int (*search)(struct singly_ll*, int);

    void (*insert_first)(struct singly_ll*, int);
    void (*insert_last)(struct singly_ll*, int);
    void (*insert_after)(struct singly_ll*, int, int);
    void (*insert_before)(struct singly_ll*, int, int);
    void (*insert_at)(struct singly_ll*, int, int);

    void (*delete_first)(struct singly_ll*);
    void (*delete_last)(struct singly_ll*);
    void (*delete_after)(struct singly_ll*, int);
    void (*delete_before)(struct singly_ll*, int);
    void (*delete_at)(struct singly_ll*, int);

    void (*reverse)(struct singly_ll*);
    void (*sort)(struct singly_ll*);
};

struct singly_ll create_singly_ll();
void destroy_singly_ll(struct singly_ll*);

#endif