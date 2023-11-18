#include <stdio.h>
#include <stdlib.h>
#include "singlyll.h"
#include "../color.h"

__attribute__((pure)) int is_empty(struct singly_ll* p_self) {
    return !p_self->p_head;
}

void traverse(struct singly_ll* p_self) {
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

int count(struct singly_ll* p_self, struct singly_node* p_node) {
    return !p_node ? 0 : 1 + p_self->count(p_self, p_node->p_next);
}

int length(struct singly_ll* p_self) {
    return p_self->count(p_self, p_self->p_head);
}

struct singly_node* get_node(struct singly_ll* p_self, int pos) {
    int len = p_self->length(p_self);

    if (pos < 1 || pos > len) return NULL;
    if (pos == 1) return p_self->p_head;

    struct singly_node* p_node = p_self->p_head;

    for (int i = 1; i < pos; i++) {
        p_node = p_node->p_next;
    }

    return p_node;
}

int search(struct singly_ll* p_self, int data) {
    int count = 1;
    struct singly_node* p_node = p_self->p_head;

    while (p_node) {
        if (p_node->data == data) return count;

        p_node = p_node->p_next;
        count++;
    }

    return -1;
}

void insert_first(struct singly_ll* p_self, int data) {
    struct singly_node* p_new_node = malloc(sizeof * p_new_node);

    if (!p_new_node) return;

    p_new_node->data = data;
    p_new_node->p_next = p_self->p_head;
    p_self->p_head = p_new_node;

    return;
}

void insert_last(struct singly_ll* p_self, int data) {
    if (!p_self->p_head) {
        p_self->insert_first(p_self, data);
        return;
    }

    struct singly_node* p_node = p_self->p_head;

    while (p_node->p_next) {
        p_node = p_node->p_next;
    }

    struct singly_node* p_new_node = malloc(sizeof * p_new_node);

    if (!p_new_node) return;

    p_new_node->data = data;
    p_new_node->p_next = NULL;
    p_node->p_next = p_new_node;

    return;
}

void insert_after(struct singly_ll* p_self, int pos, int data) {
    int len = p_self->length(p_self);

    if (pos < 0 || pos > len) return;

    if (pos == 0) {
        p_self->insert_first(p_self, data);
        return;
    }

    if (pos == len) {
        p_self->insert_last(p_self, data);
        return;
    }

    struct singly_node* p_node = p_self->get_node(p_self, pos);

    if (!p_node) return;

    struct singly_node* p_new_node = malloc(sizeof * p_new_node);

    if (!p_new_node) return;

    p_new_node->data = data;
    p_new_node->p_next = p_node->p_next;
    p_node->p_next = p_new_node;

    return;
}

void insert_before(struct singly_ll* p_self, int pos, int data) {
    int len = p_self->length(p_self);
    int prev_pos = pos - 1;

    if (pos < 1 || prev_pos > len) return;

    if (pos == 1) {
        p_self->insert_first(p_self, data);
        return;
    }

    if (prev_pos == len) {
        p_self->insert_last(p_self, data);
        return;
    }

    p_self->insert_after(p_self, prev_pos, data);
    return;
}

void delete_first(struct singly_ll* p_self) {
    if (!p_self->p_head) return;

    struct singly_node* p_tmp = p_self->p_head;

    p_self->p_head = p_tmp->p_next;
    free(p_tmp);

    return;
}

void delete_last(struct singly_ll* p_self) {
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

void delete_after(struct singly_ll* p_self, int pos) {
    int len = p_self->length(p_self);
    int next_pos = pos + 1;

    if (pos < 0 || next_pos > len) return;

    if (pos == 0) {
        p_self->delete_first(p_self);
        return;
    }

    if (next_pos == len) {
        p_self->delete_last(p_self);
        return;
    }

    struct singly_node* p_node = p_self->get_node(p_self, pos);

    if (!p_node || !p_node->p_next) return;

    struct singly_node* p_tmp = p_node->p_next;

    p_node->p_next = p_tmp->p_next;
    free(p_tmp);

    return;
}

void delete_before(struct singly_ll* p_self, int pos) {
    int max_pos = p_self->length(p_self) + 1;

    if (pos < 2 || pos > max_pos) return;

    if (pos == 2) {
        p_self->delete_first(p_self);
        return;
    }

    if (pos == max_pos) {
        p_self->delete_last(p_self);
        return;
    }

    p_self->delete_after(p_self, pos - 2);
    return;
}

void delete_at(struct singly_ll* p_self, int pos) {
    int len = p_self->length(p_self);

    if (pos < 1 || pos > len) return;

    if (pos == 1) {
        p_self->delete_first(p_self);
        return;
    }

    if (pos == len) {
        p_self->delete_last(p_self);
        return;
    }

    p_self->delete_after(p_self, pos - 1);
    return;
}

void reverse(struct singly_ll* p_self) {
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

void sort(struct singly_ll* p_self) {
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

struct singly_ll create_singly_ll() {
    struct singly_ll self;

    self.p_head = NULL;

    self.is_empty = &is_empty;

    self.traverse = &traverse;
    self.count = &count;
    self.length = &length;

    self.get_node = &get_node;
    self.search = &search;

    self.insert_first = &insert_first;
    self.insert_last = &insert_last;
    self.insert_after = &insert_after;
    self.insert_before = &insert_before;
    self.insert_at = &insert_before;

    self.delete_first = &delete_first;
    self.delete_last = &delete_last;
    self.delete_after = &delete_after;
    self.delete_before = &delete_before;
    self.delete_at = &delete_at;

    self.reverse = &reverse;
    self.sort = &sort;

    return self;
}

void destroy_singly_ll(struct singly_ll* p_self) {
    struct singly_node* p_tmp = p_self->p_head;

    while (p_self->p_head) {
        p_tmp = p_self->p_head->p_next;
        free(p_self->p_head);
        p_self->p_head = p_tmp;
    }

    return;
}