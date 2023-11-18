#ifndef SINGLYLL_H
#define SINGLYLL_H

struct singly_node {
    int data;
    struct singly_node* p_next;
};

struct singly_ll {
    struct singly_node* p_head;

    struct {
        int (*is_empty)(struct singly_ll*);

        void (*traverse)(struct singly_ll*);
        int (*count)(struct singly_ll*, struct singly_node*);
        int (*length)(struct singly_ll*);

        struct singly_node* (*get_node)(struct singly_ll*, int);
        int (*search)(struct singly_ll*, int);

        void (*push_front)(struct singly_ll*, int);
        void (*push_back)(struct singly_ll*, int);
        void (*push_after)(struct singly_ll*, int, int);
        void (*push_before)(struct singly_ll*, int, int);
        void (*push_at)(struct singly_ll*, int, int);

        void (*pop_front)(struct singly_ll*);
        void (*pop_back)(struct singly_ll*);
        void (*pop_after)(struct singly_ll*, int);
        void (*pop_before)(struct singly_ll*, int);
        void (*pop_at)(struct singly_ll*, int);

        void (*reverse)(struct singly_ll*);
        void (*sort)(struct singly_ll*);
    } fn;
};

struct singly_ll create_singly_ll();
void destroy_singly_ll(struct singly_ll*);

#endif