#include <stdio.h>
#include <stdlib.h>
#include "singlyll.h"

int check_empty(singly_ll_t* p_ll)
{
    return (!p_ll->head) ? 1 : 0;
}

int get_length(singly_ll_t* p_ll)
{
    return p_ll->_len;
}

void display(singly_ll_t* p_ll)
{
    singly_node_t* p_node = p_ll->head;

    while (p_node)
    {
        printf("%d-->", p_node->data);
        p_node = p_node->p_next;
    }

    printf("NULL\n");

    return;
}

int count(singly_node_t* p_node)
{
    if (!p_node)
    {
        return 0;
    }
    else
    {
        return 1 + count(p_node->p_next);
    }
}

singly_node_t* get_node(singly_ll_t* p_ll, int pos)
{
    if (pos < 1 || pos > p_ll->_len) return NULL;
    if (pos == 1) return p_ll->head;

    singly_node_t* p_node = p_ll->head;

    for (int i = 1; i < pos; i++)
    {
        p_node = p_node->p_next;
    }

    return p_node;
}

int search_node(singly_ll_t* p_ll, int data)
{
    int count = 1;
    singly_node_t* p_node = p_ll->head;

    while (p_node)
    {
        if (p_node->data == data) return count;

        p_node = p_node->p_next;
        count++;
    }

    return count;
}

void push_front(singly_ll_t** pp_ll, int data)
{
    singly_node_t* p_new_node = (singly_node_t*)malloc(sizeof(singly_node_t));

    p_new_node->data = data;
    p_new_node->p_next = (*pp_ll)->head;
    (*pp_ll)->head = p_new_node;
    (*pp_ll)->_len += 1;

    return;
}

void push_back(singly_ll_t** pp_ll, int data)
{
    singly_node_t* p_new_node = (singly_node_t*)malloc(sizeof(singly_node_t));

    p_new_node->data = data;
    p_new_node->p_next = NULL;

    if (!(*pp_ll)->head)
    {
        (*pp_ll)->head = p_new_node;
        (*pp_ll)->_len += 1;

        return;
    }

    singly_node_t* p_node = (*pp_ll)->head;

    while (p_node->p_next != NULL)
    {
        p_node = p_node->p_next;
    }

    p_node->p_next = p_new_node;
    (*pp_ll)->_len += 1;

    return;
}

void push_after(singly_ll_t** pp_ll, int pos, int data)
{
    if (pos < 0 || pos > (*pp_ll)->_len) return;

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

    singly_node_t* p_node = get_node(*pp_ll, pos);

    if (!p_node) return;

    singly_node_t* p_new_node = (singly_node_t*)malloc(sizeof(singly_node_t));

    p_new_node->data = data;
    p_new_node->p_next = p_node->p_next;
    p_node->p_next = p_new_node;
    (*pp_ll)->_len += 1;

    return;
}

void push_before(singly_ll_t** pp_ll, int pos, int data)
{
    int prev_pos = pos - 1;

    if (pos < 1 || prev_pos > (*pp_ll)->_len) return;

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

    push_after(pp_ll, prev_pos, data);

    return;
}

void push_at(singly_ll_t** pp_ll, int pos, int data)
{
    push_before(pp_ll, pos, data);

    return;
}

void pop_front(singly_ll_t** pp_ll)
{
    if (!(*pp_ll)->head) return;

    singly_node_t* p_tmp = (*pp_ll)->head;

    (*pp_ll)->head = p_tmp->p_next;
    free(p_tmp);
    (*pp_ll)->_len -= 1;

    return;
}

void pop_back(singly_ll_t** pp_ll)
{
    if (!(*pp_ll)->head) return;

    if (!(*pp_ll)->head->p_next)
    {
        free((*pp_ll)->head);
        (*pp_ll)->head = NULL;
        (*pp_ll)->_len -= 1;

        return;
    }

    singly_node_t* p_tmp = (*pp_ll)->head;

    while (p_tmp->p_next->p_next != NULL)
    {
        p_tmp = p_tmp->p_next;
    }

    singly_node_t* p_last = p_tmp->p_next;

    p_tmp->p_next = NULL;
    free(p_last);
    (*pp_ll)->_len -= 1;

    return;
}

void pop_after(singly_ll_t** pp_ll, int pos)
{
    int next_pos = pos + 1;

    if (pos < 0 || next_pos > (*pp_ll)->_len) return;

    if (pos == 0)
    {
        pop_front(pp_ll);

        return;
    }

    if (next_pos == (*pp_ll)->_len)
    {
        pop_back(pp_ll);

        return;
    }

    singly_node_t* p_node = get_node(*pp_ll, pos);

    if (!p_node) return;
    if (!p_node->p_next) return;

    singly_node_t* p_tmp = p_node->p_next;

    p_node->p_next = p_tmp->p_next;
    free(p_tmp);
    (*pp_ll)->_len -= 1;

    return;
}

void pop_before(singly_ll_t** pp_ll, int pos)
{
    int max_pos = (*pp_ll)->_len + 1;

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

    int dbl_prev_pos = pos - 2;

    pop_after(pp_ll, dbl_prev_pos);

    return;
}

void pop_at(singly_ll_t** pp_ll, int pos)
{
    if (pos < 1 || pos > (*pp_ll)->_len) return;

    if (pos == 1)
    {
        pop_front(pp_ll);

        return;
    }

    if (pos == (*pp_ll)->_len)
    {
        pop_back(pp_ll);

        return;
    }

    int prev_pos = pos - 1;

    pop_after(pp_ll, prev_pos);

    return;
}

void reverse(singly_ll_t** pp_ll)
{
    if (!(*pp_ll)->head) return;
    if (!(*pp_ll)->head->p_next) return;

    singly_node_t* p_cur = (*pp_ll)->head->p_next;
    singly_node_t* p_res = (*pp_ll)->head;
    singly_node_t* p_tmp = NULL;

    p_res->p_next = NULL;

    while (p_cur)
    {
        p_tmp = p_cur;
        p_cur = p_cur->p_next;
        p_tmp->p_next = p_res;
        p_res = p_tmp;
    }

    (*pp_ll)->head = p_res;

    return;
}

void sort(singly_ll_t** pp_ll)
{
    if (!(*pp_ll)->head) return;
    if (!(*pp_ll)->head->p_next) return;

    singly_node_t* p_cur = (*pp_ll)->head;
    singly_node_t* p_next = NULL;
    int tmp = 0;

    while (p_cur)
    {
        p_next = p_cur->p_next;

        while (p_next)
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
    }

    return;
}

singly_ll_t* create_singly_ll()
{
    singly_ll_t* p_self = (singly_ll_t*)malloc(sizeof(singly_ll_t));

    p_self->head = NULL;
    p_self->_len = 0;

    p_self->check_empty = &check_empty;
    p_self->get_length = &get_length;

    p_self->display = &display;
    p_self->count = &count;

    p_self->get_node = &get_node;
    p_self->search_node = &search_node;

    p_self->push_front = &push_front;
    p_self->push_back = &push_back;
    p_self->push_after = &push_after;
    p_self->push_before = &push_before;
    p_self->push_at = &push_at;

    p_self->pop_front = &pop_front;
    p_self->pop_back = &pop_back;
    p_self->pop_after = &pop_after;
    p_self->pop_before = &pop_before;
    p_self->pop_at = &pop_at;

    p_self->reverse = &reverse;
    p_self->sort = &sort;

    return p_self;
}

void destroy_singly_ll(singly_ll_t* p_ll)
{
    singly_node_t* p_tmp = p_ll->head;

    while (p_ll->head)
    {
        p_tmp = p_ll->head->p_next;
        free(p_ll->head);
        p_ll->head = p_tmp;
    }

    free(p_ll);

    return;
}