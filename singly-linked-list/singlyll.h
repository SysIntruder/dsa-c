#ifndef SINGLYLL_H
#define SINGLYLL_H

typedef struct singly_node singly_node_t;
struct singly_node
{
    int data;
    singly_node_t* p_next;
};

typedef struct singly_ll singly_ll_t;
struct singly_ll
{
    singly_node_t* head;

    int (*check_empty)(singly_ll_t*);

    void (*traverse)(singly_ll_t*);
    int (*count)(singly_node_t*);
    int (*length)(singly_ll_t*);

    singly_node_t* (*get_node)(singly_ll_t*, int);
    int (*search)(singly_ll_t*, int);

    void (*push_front)(singly_ll_t**, int);
    void (*push_back)(singly_ll_t**, int);
    void (*push_after)(singly_ll_t**, int, int);
    void (*push_before)(singly_ll_t**, int, int);
    void (*push_at)(singly_ll_t**, int, int);

    void (*pop_front)(singly_ll_t**);
    void (*pop_back)(singly_ll_t**);
    void (*pop_after)(singly_ll_t**, int);
    void (*pop_before)(singly_ll_t**, int);
    void (*pop_at)(singly_ll_t**, int);

    void (*reverse)(singly_ll_t**);
    void (*sort)(singly_ll_t**);
};

singly_ll_t* create_singly_ll();
void destroy_singly_ll(singly_ll_t*);

#endif