#include <stdio.h>
#include <stdlib.h>
#include "doublyll.h"
#include "../color.h"

int check_empty(doubly_ll_t* p_ll)
{
    return !p_ll->head ? 1 : 0;
}

int get_length(doubly_ll_t* p_ll)
{
    return p_ll->_len;
}

void traverse(doubly_ll_t* p_ll)
{
    doubly_node_t* p_node = p_ll->head;
    doubly_node_t* p_prev = NULL;

    printf("NULL" RED "<");

    while (p_node)
    {
        if (p_prev == p_node->p_prev) printf("-");

        printf(">" RESET "%d" RED "<", p_node->data);
        p_prev = p_node;
        p_node = p_node->p_next;
    }

    printf("->" RESET "NULL\n");

    return;
}

int count(doubly_node_t* p_node)
{
    if (!p_node) return 0;

    return 1 + count(p_node->p_next);
}

doubly_node_t* get_node(doubly_ll_t* p_ll, int pos)
{
    if (pos < 1 || pos > p_ll->_len) return NULL;
    if (pos == 1) return p_ll->head;

    doubly_node_t* p_node = p_ll->head;

    for (int i = 1; i < pos; i++)
    {
        p_node = p_node->p_next;
    }

    return p_node;
}

int search(doubly_ll_t* p_ll, int data)
{
    int count = 1;
    doubly_node_t* p_node = p_ll->head;

    while (p_node)
    {
        if (p_node->data == data) return count;

        p_node = p_node->p_next;
        count++;
    }

    return 0;
}

void push_front(doubly_ll_t** pp_ll, int data)
{
    doubly_node_t* p_new_node = (doubly_node_t*)malloc(sizeof(doubly_node_t));

    p_new_node->data = data;
    p_new_node->p_prev = NULL;

    if (!(*pp_ll)->head)
    {
        p_new_node->p_next = NULL;
        (*pp_ll)->head = p_new_node;
        (*pp_ll)->_len += 1;

        return;
    }

    p_new_node->p_next = (*pp_ll)->head;
    (*pp_ll)->head->p_prev = p_new_node;
    (*pp_ll)->head = p_new_node;
    (*pp_ll)->_len += 1;

    return;
}

void push_back(doubly_ll_t** pp_ll, int data)
{
    doubly_node_t* p_new_node = (doubly_node_t*)malloc(sizeof(doubly_node_t));

    p_new_node->data = data;
    p_new_node->p_next = NULL;

    if (!(*pp_ll)->head)
    {
        p_new_node->p_prev = NULL;
        (*pp_ll)->head = p_new_node;
        (*pp_ll)->_len += 1;

        return;
    }

    doubly_node_t* p_node = (*pp_ll)->head;

    while (p_node->p_next != NULL)
    {
        p_node = p_node->p_next;
    }

    p_new_node->p_prev = p_node;
    p_node->p_next = p_new_node;
    (*pp_ll)->_len += 1;

    return;
}

void push_after(doubly_ll_t** pp_ll, int pos, int data)
{
    if (pos < 0 || pos >(*pp_ll)->_len) return;

    if (pos == 0)
    {
        push_front(pp_ll, data);

        return;
    }

    if (pos == (*pp_ll)->_len)
    {
        push_back(pp_ll, data);

        return;
    }

    doubly_node_t* p_node = get_node(*pp_ll, pos);

    if (!p_node) return;

    doubly_node_t* p_new_node = (doubly_node_t*)malloc(sizeof(doubly_node_t));

    p_new_node->data = data;
    p_new_node->p_next = p_node->p_next;
    p_new_node->p_prev = p_node;
    p_node->p_next->p_prev = p_new_node;
    p_node->p_next = p_new_node;
    (*pp_ll)->_len += 1;

    return;
}

void push_before(doubly_ll_t** pp_ll, int pos, int data)
{
    int prev_pos = pos - 1;

    if (pos < 1 || prev_pos >(*pp_ll)->_len) return;

    if (pos == 1)
    {
        push_front(pp_ll, data);

        return;
    }

    if (prev_pos == (*pp_ll)->_len)
    {
        push_back(pp_ll, data);

        return;
    }

    doubly_node_t* p_node = get_node(*pp_ll, pos);

    if (!p_node) return;

    doubly_node_t* p_new_node = (doubly_node_t*)malloc(sizeof(doubly_node_t));

    p_new_node->data = data;
    p_new_node->p_next = p_node;
    p_new_node->p_prev = p_node->p_prev;
    p_node->p_prev->p_next = p_new_node;
    p_node->p_prev = p_new_node;
    (*pp_ll)->_len += 1;

    return;
}

doubly_ll_t* create_doubly_ll()
{
    doubly_ll_t* p_self = (doubly_ll_t*)malloc(sizeof(doubly_ll_t));

    p_self->head = NULL;
    p_self->_len = 0;

    p_self->check_empty = &check_empty;
    p_self->get_length = &get_length;

    p_self->traverse = &traverse;
    p_self->count = &count;

    p_self->get_node = &get_node;
    p_self->search = &search;

    p_self->push_front = &push_front;
    p_self->push_back = &push_back;
    p_self->push_after = &push_after;
    p_self->push_before = &push_before;
    p_self->push_at = &push_before;

    return p_self;
}

void destroy_doubly_ll(doubly_ll_t* p_ll)
{
    doubly_node_t* p_tmp = p_ll->head;

    while (p_ll->head)
    {
        p_tmp = p_ll->head->p_next;
        free(p_ll->head);
        p_ll->head = p_tmp;
    }

    free(p_ll);

    return;
}