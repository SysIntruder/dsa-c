#include <stdio.h>
#include <stdlib.h>
#include "singlyll.h"
#include "../color.h"

__attribute__((pure)) int is_empty(struct singly_ll* p_self)
{
    return !p_self->p_head;
}

void traverse(struct singly_ll* p_self)
{
    struct singly_node* p_node = p_self->p_head;

    printf(GRN);

    while (p_node) {
        if (!p_node->p_next) printf(YEL);

        printf("%d" BLU " -> " RESET, p_node->data);
        p_node = p_node->p_next;
    }

    printf(RED "NULL\n" RESET);

    return;
}

int count(struct singly_ll* p_self, struct singly_node* p_node)
{
    return !p_node ? 0 : 1 + p_self->fn.count(p_self, p_node->p_next);
}

int length(struct singly_ll* p_self)
{
    return p_self->fn.count(p_self, p_self->p_head);
}

struct singly_node* get_node(struct singly_ll* p_self, int pos)
{
    int len = p_self->fn.length(p_self);

    if (pos < 1 || pos > len) return NULL;
    if (pos == 1) return p_self->p_head;

    struct singly_node* p_node = p_self->p_head;

    for (int i = 1; i < pos; i++) {
        p_node = p_node->p_next;
    }

    return p_node;
}

int search(struct singly_ll* p_self, int data)
{
    int count = 1;
    struct singly_node* p_node = p_self->p_head;

    while (p_node) {
        if (p_node->data == data) return count;

        p_node = p_node->p_next;
        count++;
    }

    return -1;
}

void push_front(struct singly_ll* p_self, int data)
{
    struct singly_node* p_new_node = (struct singly_node*)malloc(sizeof(struct singly_node));

    if (!p_new_node) return;

    p_new_node->data = data;
    p_new_node->p_next = p_self->p_head;
    p_self->p_head = p_new_node;

    return;
}

void push_back(struct singly_ll* p_self, int data)
{
    if (!p_self->p_head) {
        p_self->fn.push_front(p_self, data);
        return;
    }

    struct singly_node* p_node = p_self->p_head;

    while (p_node->p_next) {
        p_node = p_node->p_next;
    }

    struct singly_node* p_new_node = (struct singly_node*)malloc(sizeof(struct singly_node));

    if (!p_new_node) return;

    p_new_node->data = data;
    p_new_node->p_next = NULL;
    p_node->p_next = p_new_node;

    return;
}

void push_after(struct singly_ll* p_self, int pos, int data)
{
    int len = p_self->fn.length(p_self);

    if (pos < 0 || pos > len) return;

    if (pos == 0) {
        p_self->fn.push_front(p_self, data);
        return;
    }

    if (pos == len) {
        p_self->fn.push_back(p_self, data);
        return;
    }

    struct singly_node* p_node = p_self->fn.get_node(p_self, pos);

    if (!p_node) return;

    struct singly_node* p_new_node = (struct singly_node*)malloc(sizeof(struct singly_node));

    if (!p_new_node) return;

    p_new_node->data = data;
    p_new_node->p_next = p_node->p_next;
    p_node->p_next = p_new_node;

    return;
}

void push_before(struct singly_ll* p_self, int pos, int data)
{
    int len = p_self->fn.length(p_self);
    int prev_pos = pos - 1;

    if (pos < 1 || prev_pos > len) return;

    if (pos == 1) {
        p_self->fn.push_front(p_self, data);
        return;
    }

    if (prev_pos == len) {
        p_self->fn.push_back(p_self, data);
        return;
    }

    p_self->fn.push_after(p_self, prev_pos, data);
    return;
}

void pop_front(struct singly_ll* p_self)
{
    if (!p_self->p_head) return;

    struct singly_node* p_tmp = p_self->p_head;

    p_self->p_head = p_tmp->p_next;
    free(p_tmp);

    return;
}

void pop_back(struct singly_ll* p_self)
{
    if (!p_self->p_head) return;

    if (!p_self->p_head->p_next) {
        free(p_self->p_head);
        p_self->p_head = NULL;

        return;
    }

    struct singly_node* p_tmp = p_self->p_head;

    while (p_tmp->p_next->p_next) {
        p_tmp = p_tmp->p_next;
    }

    struct singly_node* p_last = p_tmp->p_next;

    p_tmp->p_next = NULL;
    free(p_last);

    return;
}

void pop_after(struct singly_ll* p_self, int pos)
{
    int len = p_self->fn.length(p_self);
    int next_pos = pos + 1;

    if (pos < 0 || next_pos > len) return;

    if (pos == 0) {
        p_self->fn.pop_front(p_self);
        return;
    }

    if (next_pos == len) {
        p_self->fn.pop_back(p_self);
        return;
    }

    struct singly_node* p_node = p_self->fn.get_node(p_self, pos);

    if (!p_node || !p_node->p_next) return;

    struct singly_node* p_tmp = p_node->p_next;

    p_node->p_next = p_tmp->p_next;
    free(p_tmp);

    return;
}

void pop_before(struct singly_ll* p_self, int pos)
{
    int max_pos = p_self->fn.length(p_self) + 1;

    if (pos < 2 || pos > max_pos) return;

    if (pos == 2) {
        p_self->fn.pop_front(p_self);
        return;
    }

    if (pos == max_pos) {
        p_self->fn.pop_back(p_self);
        return;
    }

    p_self->fn.pop_after(p_self, pos - 2);
    return;
}

void pop_at(struct singly_ll* p_self, int pos)
{
    int len = p_self->fn.length(p_self);

    if (pos < 1 || pos > len) return;

    if (pos == 1) {
        p_self->fn.pop_front(p_self);
        return;
    }

    if (pos == len) {
        p_self->fn.pop_back(p_self);
        return;
    }

    p_self->fn.pop_after(p_self, pos - 1);
    return;
}

void reverse(struct singly_ll* p_self)
{
    if (!p_self->p_head || !p_self->p_head->p_next) return;

    struct singly_node* p_cur = p_self->p_head->p_next;
    struct singly_node* p_res = p_self->p_head;
    struct singly_node* p_tmp = NULL;

    p_res->p_next = NULL;

    while (p_cur) {
        p_tmp = p_cur;
        p_cur = p_cur->p_next;
        p_tmp->p_next = p_res;
        p_res = p_tmp;
    }

    p_self->p_head = p_res;

    return;
}

void sort(struct singly_ll* p_self)
{
    if (!p_self->p_head || !p_self->p_head->p_next) return;

    struct singly_node* p_cur = p_self->p_head;
    struct singly_node* p_next = NULL;
    int tmp = 0;

    while (p_cur) {
        p_next = p_cur->p_next;

        while (p_next) {
            if (p_cur->data > p_next->data) {
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

struct singly_ll create_singly_ll()
{
    struct singly_ll self;

    self.p_head = NULL;

    self.fn.is_empty = &is_empty;

    self.fn.traverse = &traverse;
    self.fn.count = &count;
    self.fn.length = &length;

    self.fn.get_node = &get_node;
    self.fn.search = &search;

    self.fn.push_front = &push_front;
    self.fn.push_back = &push_back;
    self.fn.push_after = &push_after;
    self.fn.push_before = &push_before;
    self.fn.push_at = &push_before;

    self.fn.pop_front = &pop_front;
    self.fn.pop_back = &pop_back;
    self.fn.pop_after = &pop_after;
    self.fn.pop_before = &pop_before;
    self.fn.pop_at = &pop_at;

    self.fn.reverse = &reverse;
    self.fn.sort = &sort;

    return self;
}

void destroy_singly_ll(struct singly_ll* p_self)
{
    struct singly_node* p_tmp = p_self->p_head;

    while (p_self->p_head) {
        p_tmp = p_self->p_head->p_next;
        free(p_self->p_head);
        p_self->p_head = p_tmp;
    }

    return;
}