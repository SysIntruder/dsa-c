#include <stdio.h>
#include <stdlib.h>
#include "circularll.h"
#include "../color.h"

int check_empty(circular_ll_t* p_ll)
{
    return !p_ll->head;
}

int count(circular_node_t* p_node, circular_node_t* p_head)
{
    static circular_node_t* start = NULL;

    if (p_node == start)
    {
        start = NULL;

        return 0;
    }

    start = p_head ? p_head : start;

    return 1 + count(p_node->p_next, NULL);
}

int length(circular_ll_t* p_ll)
{
    return count(p_ll->head, p_ll->head);
}

void traverse(circular_ll_t* p_ll)
{
    circular_node_t* p_node = p_ll->head;
    circular_node_t* p_prev = NULL;
    int len = length(p_ll);
    int count = 0;

    if (p_node) p_prev = p_ll->head->p_prev;

    if (p_ll->head) printf(YEL "%d" RESET, p_ll->head->p_prev->data);
    else printf(YEL "NULL" RESET);

    printf(BLU " <");

    while (p_node && count < len)
    {
        if (p_prev == p_node->p_prev) printf("=");

        printf("> " RESET "%d" BLU " <", p_node->data);
        p_prev = p_node;
        p_node = p_node->p_next;
        count++;
    }

    printf("=> " RESET);

    if (p_ll->head) printf(YEL "%d\n" RESET, p_ll->head->data);
    else printf(YEL "NULL\n" RESET);

    return;
}

circular_node_t* get_node(circular_ll_t* p_ll, int pos)
{
    int len = length(p_ll);

    if (pos < 1 || pos > len) return NULL;
    if (pos == 1) return p_ll->head;

    circular_node_t* p_node = p_ll->head;

    for (int i = 1; i < pos; i++)
    {
        p_node = p_node->p_next;
    }

    return p_node;
}

int search(circular_ll_t* p_ll, int data)
{
    int count = 1;
    circular_node_t* p_node = p_ll->head;

    do
    {
        if (p_node->data == data) return count;

        p_node = p_node->p_next;
        count++;
    } while (p_node != p_ll->head);

    return 0;
}

void push_new(circular_ll_t** pp_ll, int data, circular_node_t** node)
{
    circular_node_t* p_new_node = (circular_node_t*)malloc(sizeof(circular_node_t));

    p_new_node->data = data;

    if (!(*pp_ll)->head)
    {
        p_new_node->p_prev = p_new_node;
        p_new_node->p_next = p_new_node;
        (*pp_ll)->head = p_new_node;

        return;
    }

    p_new_node->p_next = (*pp_ll)->head;
    p_new_node->p_prev = (*pp_ll)->head->p_prev;
    (*pp_ll)->head->p_prev->p_next = p_new_node;
    (*pp_ll)->head->p_prev = p_new_node;
    *node = p_new_node;

    return;
}

void push_front(circular_ll_t** pp_ll, int data)
{
    push_new(pp_ll, data, &(*pp_ll)->head);
    return;
}

void push_back(circular_ll_t** pp_ll, int data)
{
    push_new(pp_ll, data, &(*pp_ll)->head->p_prev);
    return;
}

void push_after(circular_ll_t** pp_ll, int pos, int data)
{
    int len = length(*pp_ll);

    if (pos < 0 || pos > len) return;

    if (pos == 0)
    {
        push_front(pp_ll, data);
        return;
    }

    if (pos == len)
    {
        push_back(pp_ll, data);
        return;
    }

    circular_node_t* p_node = get_node(*pp_ll, pos);

    if (!p_node) return;

    circular_node_t* p_new_node = (circular_node_t*)malloc(sizeof(circular_node_t));

    p_new_node->data = data;
    p_new_node->p_next = p_node->p_next;
    p_new_node->p_prev = p_node;
    p_node->p_next->p_prev = p_new_node;
    p_node->p_next = p_new_node;

    return;
}

void push_before(circular_ll_t** pp_ll, int pos, int data)
{
    int len = length(*pp_ll);
    int prev_pos = pos - 1;

    if (pos < 1 || prev_pos > len) return;

    if (pos == 1)
    {
        push_front(pp_ll, data);
        return;
    }

    if (prev_pos == len)
    {
        push_back(pp_ll, data);
        return;
    }

    circular_node_t* p_node = get_node(*pp_ll, pos);

    if (!p_node) return;

    circular_node_t* p_new_node = (circular_node_t*)malloc(sizeof(circular_node_t));

    p_new_node->data = data;
    p_new_node->p_next = p_node;
    p_new_node->p_prev = p_node->p_prev;
    p_node->p_prev->p_next = p_new_node;
    p_node->p_prev = p_new_node;

    return;
}

void pop_node(circular_ll_t** pp_ll, circular_node_t** node)
{
    if (!(*pp_ll)->head) return;
    if ((*pp_ll)->head == (*pp_ll)->head->p_next)
    {
        free((*pp_ll)->head);
        (*pp_ll)->head = NULL;

        return;
    }

    circular_node_t* p_tmp = *node;

    p_tmp->p_prev->p_next = p_tmp->p_next;
    (*pp_ll)->head = p_tmp->p_next;
    (*pp_ll)->head->p_prev = p_tmp->p_prev;
    free(p_tmp);

    return;
}

void pop_front(circular_ll_t** pp_ll)
{
    pop_node(pp_ll, &(*pp_ll)->head);
    return;
}

void pop_back(circular_ll_t** pp_ll)
{
    pop_node(pp_ll, &(*pp_ll)->head->p_prev);
    return;
}

void pop_after(circular_ll_t** pp_ll, int pos)
{
    int len = length(*pp_ll);
    int next_pos = pos + 1;

    if (pos < 0 || next_pos > len) return;

    if (pos == 0)
    {
        pop_front(pp_ll);
        return;
    }

    if (next_pos == len)
    {
        pop_back(pp_ll);
        return;
    }

    circular_node_t* p_node = get_node(*pp_ll, pos);

    if (!p_node || !p_node->p_next) return;

    circular_node_t* p_tmp = p_node->p_next;

    p_node->p_next = p_tmp->p_next;
    p_tmp->p_next->p_prev = p_node;
    free(p_tmp);

    return;
}

void pop_before(circular_ll_t** pp_ll, int pos)
{
    int max_pos = length(*pp_ll) + 1;

    if (pos < 2 || pos > max_pos) return;

    if (pos == 2)
    {
        pop_front(pp_ll);
        return;
    }

    if (pos == max_pos)
    {
        pop_back(pp_ll);
        return;
    }

    circular_node_t* p_node = get_node(*pp_ll, pos);

    if (!p_node || !p_node->p_prev) return;

    circular_node_t* p_tmp = p_node->p_prev;

    p_node->p_prev = p_tmp->p_prev;
    p_tmp->p_prev->p_next = p_node;
    free(p_tmp);

    return;
}

void pop_at(circular_ll_t** pp_ll, int pos)
{
    int len = length(*pp_ll);

    if (pos < 1 || pos > len) return;

    if (pos == 1)
    {
        pop_front(pp_ll);
        return;
    }

    if (pos == len)
    {
        pop_back(pp_ll);
        return;
    }

    circular_node_t* p_tmp = get_node(*pp_ll, pos);

    if (!p_tmp) return;

    if (p_tmp->p_prev)
    {
        p_tmp->p_prev->p_next = p_tmp->p_next;
    }

    if (p_tmp->p_next)
    {
        p_tmp->p_next->p_prev = p_tmp->p_prev;
    }

    free(p_tmp);

    return;
}

void reverse(circular_ll_t** pp_ll)
{
    int len = length(*pp_ll);

    if (!(*pp_ll)->head || len == 1) return;

    circular_node_t* p_cur = (*pp_ll)->head;
    circular_node_t* p_res = (*pp_ll)->head->p_prev;
    circular_node_t* p_tmp = NULL;
    int count = 0;

    p_res->p_next = (*pp_ll)->head;
    p_res->p_prev = p_cur;

    while (p_cur && count < len)
    {
        p_tmp = p_cur;
        p_cur = p_cur->p_next;
        p_tmp->p_next = p_res;
        p_tmp->p_prev = p_cur;
        p_res = p_tmp;
        count++;
    }

    (*pp_ll)->head = p_res;

    return;
}

void sort(circular_ll_t** pp_ll)
{
    int len = length(*pp_ll);

    if (!(*pp_ll)->head || len == 1) return;

    circular_node_t* p_cur = (*pp_ll)->head;
    circular_node_t* p_next = NULL;
    int tmp = 0;

    do
    {
        p_next = p_cur->p_next;

        while (p_next && p_next != (*pp_ll)->head)
        {
            if (p_cur->data > p_next->data)
            {
                tmp = p_cur->data;
                p_cur->data = p_next->data;
                p_next->data = tmp;
            }

            p_next = p_next->p_next;
        }

        p_cur = p_cur->p_next;
    } while (p_cur && p_cur != (*pp_ll)->head);

    return;
}

circular_ll_t* create_circular_ll()
{
    circular_ll_t* p_self = (circular_ll_t*)malloc(sizeof(circular_ll_t));

    p_self->head = NULL;

    p_self->check_empty = &check_empty;

    p_self->count = &count;
    p_self->length = &length;
    p_self->traverse = &traverse;

    p_self->get_node = &get_node;
    p_self->search = &search;

    p_self->push_front = &push_front;
    p_self->push_back = &push_back;
    p_self->push_after = &push_after;
    p_self->push_before = &push_before;
    p_self->push_at = &push_before;

    p_self->pop_front = &pop_front;
    p_self->pop_back = &pop_back;
    p_self->pop_after = &pop_after;
    p_self->pop_before = &pop_before;
    p_self->pop_at = &pop_at;

    p_self->reverse = &reverse;
    p_self->sort = &sort;

    return p_self;
}

void destroy_circular_ll(circular_ll_t* p_ll)
{
    int len = length(p_ll);
    circular_node_t* p_tmp = p_ll->head;

    while (len)
    {
        p_tmp = p_ll->head->p_next;
        free(p_ll->head);
        p_ll->head = p_tmp;
        len -= 1;
    }

    free(p_ll);

    return;
}