#include <stdio.h>
#include <stdlib.h>
#include "singlyll.h"
#include "../color.h"

int is_empty(singly_ll_t* p_ll)
{
    return !p_ll->p_head;
}

void traverse(singly_ll_t* p_ll)
{
    singly_node_t* p_node = p_ll->p_head;

    while (p_node)
    {
        printf("%d" BLU " -> " RESET, p_node->data);
        p_node = p_node->p_next;
    }

    printf("NULL\n");

    return;
}

int count(singly_node_t* p_node)
{
    return !p_node ? 0 : 1 + count(p_node->p_next);
}

int length(singly_ll_t* p_ll)
{
    return count(p_ll->p_head);
}

singly_node_t* get_node(singly_ll_t* p_ll, int pos)
{
    int len = length(p_ll);

    if (pos < 1 || pos > len) return NULL;
    if (pos == 1) return p_ll->p_head;

    singly_node_t* p_node = p_ll->p_head;

    for (int i = 1; i < pos; i++)
    {
        p_node = p_node->p_next;
    }

    return p_node;
}

int search(singly_ll_t* p_ll, int data)
{
    int count = 1;
    singly_node_t* p_node = p_ll->p_head;

    while (p_node)
    {
        if (p_node->data == data) return count;

        p_node = p_node->p_next;
        count++;
    }

    return -1;
}

void push_front(singly_ll_t* p_ll, int data)
{
    singly_node_t* p_new_node = (singly_node_t*)malloc(sizeof(singly_node_t));

    if (!p_new_node) return;

    p_new_node->data = data;
    p_new_node->p_next = p_ll->p_head;
    p_ll->p_head = p_new_node;

    return;
}

void push_back(singly_ll_t* p_ll, int data)
{
    if (!p_ll->p_head)
    {
        push_front(p_ll, data);
        return;
    }

    singly_node_t* p_node = p_ll->p_head;

    while (p_node->p_next)
    {
        p_node = p_node->p_next;
    }

    singly_node_t* p_new_node = (singly_node_t*)malloc(sizeof(singly_node_t));

    if (!p_new_node) return;

    p_new_node->data = data;
    p_new_node->p_next = NULL;
    p_node->p_next = p_new_node;

    return;
}

void push_after(singly_ll_t* p_ll, int pos, int data)
{
    int len = length(p_ll);

    if (pos < 0 || pos > len) return;

    if (pos == 0)
    {
        push_front(p_ll, data);
        return;
    }

    if (pos == len)
    {
        push_back(p_ll, data);
        return;
    }

    singly_node_t* p_node = get_node(p_ll, pos);

    if (!p_node) return;

    singly_node_t* p_new_node = (singly_node_t*)malloc(sizeof(singly_node_t));

    if (!p_new_node) return;

    p_new_node->data = data;
    p_new_node->p_next = p_node->p_next;
    p_node->p_next = p_new_node;

    return;
}

void push_before(singly_ll_t* p_ll, int pos, int data)
{
    int len = length(p_ll);
    int prev_pos = pos - 1;

    if (pos < 1 || prev_pos > len) return;

    if (pos == 1)
    {
        push_front(p_ll, data);
        return;
    }

    if (prev_pos == len)
    {
        push_back(p_ll, data);
        return;
    }

    push_after(p_ll, prev_pos, data);
    return;
}

void pop_front(singly_ll_t* p_ll)
{
    if (!p_ll->p_head) return;

    singly_node_t* p_tmp = p_ll->p_head;

    p_ll->p_head = p_tmp->p_next;
    free(p_tmp);

    return;
}

void pop_back(singly_ll_t* p_ll)
{
    if (!p_ll->p_head) return;

    if (!p_ll->p_head->p_next)
    {
        free(p_ll->p_head);
        p_ll->p_head = NULL;

        return;
    }

    singly_node_t* p_tmp = p_ll->p_head;

    while (p_tmp->p_next->p_next)
    {
        p_tmp = p_tmp->p_next;
    }

    singly_node_t* p_last = p_tmp->p_next;

    p_tmp->p_next = NULL;
    free(p_last);

    return;
}

void pop_after(singly_ll_t* p_ll, int pos)
{
    int len = length(p_ll);
    int next_pos = pos + 1;

    if (pos < 0 || next_pos > len) return;

    if (pos == 0)
    {
        pop_front(p_ll);
        return;
    }

    if (next_pos == len)
    {
        pop_back(p_ll);
        return;
    }

    singly_node_t* p_node = get_node(p_ll, pos);

    if (!p_node || !p_node->p_next) return;

    singly_node_t* p_tmp = p_node->p_next;

    p_node->p_next = p_tmp->p_next;
    free(p_tmp);

    return;
}

void pop_before(singly_ll_t* p_ll, int pos)
{
    int max_pos = length(p_ll) + 1;

    if (pos < 2 || pos > max_pos) return;

    if (pos == 2)
    {
        pop_front(p_ll);
        return;
    }

    if (pos == max_pos)
    {
        pop_back(p_ll);
        return;
    }

    int dbl_prev_pos = pos - 2;

    pop_after(p_ll, dbl_prev_pos);
    return;
}

void pop_at(singly_ll_t* p_ll, int pos)
{
    int len = length(p_ll);

    if (pos < 1 || pos > len) return;

    if (pos == 1)
    {
        pop_front(p_ll);
        return;
    }

    if (pos == len)
    {
        pop_back(p_ll);
        return;
    }

    int prev_pos = pos - 1;

    pop_after(p_ll, prev_pos);
    return;
}

void reverse(singly_ll_t* p_ll)
{
    if (!p_ll->p_head || !p_ll->p_head->p_next) return;

    singly_node_t* p_cur = p_ll->p_head->p_next;
    singly_node_t* p_res = p_ll->p_head;
    singly_node_t* p_tmp = NULL;

    p_res->p_next = NULL;

    while (p_cur)
    {
        p_tmp = p_cur;
        p_cur = p_cur->p_next;
        p_tmp->p_next = p_res;
        p_res = p_tmp;
    }

    p_ll->p_head = p_res;

    return;
}

void sort(singly_ll_t* p_ll)
{
    if (!p_ll->p_head || !p_ll->p_head->p_next) return;

    singly_node_t* p_cur = p_ll->p_head;
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

singly_ll_t create_singly_ll()
{
    singly_ll_t self;

    self.p_head = NULL;

    self.is_empty = &is_empty;

    self.traverse = &traverse;
    self.count = &count;
    self.length = &length;

    self.get_node = &get_node;
    self.search = &search;

    self.push_front = &push_front;
    self.push_back = &push_back;
    self.push_after = &push_after;
    self.push_before = &push_before;
    self.push_at = &push_before;

    self.pop_front = &pop_front;
    self.pop_back = &pop_back;
    self.pop_after = &pop_after;
    self.pop_before = &pop_before;
    self.pop_at = &pop_at;

    self.reverse = &reverse;
    self.sort = &sort;

    return self;
}

void destroy_singly_ll(singly_ll_t* p_ll)
{
    singly_node_t* p_tmp = p_ll->p_head;

    while (p_ll->p_head)
    {
        p_tmp = p_ll->p_head->p_next;
        free(p_ll->p_head);
        p_ll->p_head = p_tmp;
    }

    return;
}