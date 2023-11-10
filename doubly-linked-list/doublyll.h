#ifndef DOUBLYLL_H
#define DOUBLYLL_H

typedef struct doubly_node doubly_node_t;
struct doubly_node
{
    int data;
    doubly_node_t* p_prev;
    doubly_node_t* p_next;
};

typedef struct doubly_ll doubly_ll_t;
struct doubly_ll
{
    doubly_node_t* head;
    int _len;

    int (*check_empty)(doubly_ll_t*);
    int (*get_length)(doubly_ll_t*);

    void (*traverse)(doubly_ll_t*);
    int (*count)(doubly_node_t*);

    doubly_node_t* (*get_node)(doubly_ll_t*, int);
    int (*search)(doubly_ll_t*, int);

    void (*push_front)(doubly_ll_t**, int);
    void (*push_back)(doubly_ll_t**, int);
    void (*push_after)(doubly_ll_t**, int, int);
    void (*push_before)(doubly_ll_t**, int, int);
    void (*push_at)(doubly_ll_t**, int, int);
};

doubly_ll_t* create_doubly_ll();
void destroy_doubly_ll(doubly_ll_t*);

#endif