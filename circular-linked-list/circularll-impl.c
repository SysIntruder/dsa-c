#include <stdio.h>
#include <stdlib.h>
#include "circularll.h"
#include "../color.h"

__attribute__((pure)) int is_empty(struct circular_ll* p_self) {
    return !p_self->p_head;
}

int count(struct circular_ll* p_self, struct circular_node* p_node, struct circular_node* p_head) {
    static struct circular_node* start = NULL;

    if (p_node == start) {
        start = NULL;

        return 0;
    }

    start = p_head ? p_head : start;

    return 1 + p_self->count(p_self, p_node->p_next, NULL);
}

int length(struct circular_ll* p_self) {
    return p_self->count(p_self, p_self->p_head, p_self->p_head);
}

void traverse(struct circular_ll* p_self) {
    struct circular_node* p_node = p_self->p_head;
    struct circular_node* p_prev = NULL;
    int len = p_self->length(p_self);
    int count = 0;

    if (p_node) p_prev = p_self->p_head->p_prev;

    printf("..." BLU "<");

    while (p_node && count < len) {
        if (p_prev == p_node->p_prev) printf("=");

        printf("> " RESET "%d" BLU " <", p_node->data);
        p_prev = p_node;
        p_node = p_node->p_next;
        count++;
    }

    printf("=>" RESET "...\n");

    return;
}

struct circular_node* get_node(struct circular_ll* p_self, int pos) {
    int len = p_self->length(p_self);

    if (pos < 1 || pos > len) return NULL;
    if (pos == 1) return p_self->p_head;

    struct circular_node* p_node = p_self->p_head;

    for (int i = 1; i < pos; i++) {
        p_node = p_node->p_next;
    }

    return p_node;
}

int search(struct circular_ll* p_self, int data) {
    int count = 1;
    struct circular_node* p_node = p_self->p_head;

    do {
        if (p_node->data == data) return count;

        p_node = p_node->p_next;
        count++;
    } while (p_node != p_self->p_head);

    return -1;
}

void insert_node(struct circular_ll* p_self, struct circular_node** node, int data) {
    struct circular_node* p_new_node = malloc(sizeof p_new_node);

    if (!p_new_node) return;

    p_new_node->data = data;

    if (!p_self->p_head) {
        p_new_node->p_prev = p_new_node;
        p_new_node->p_next = p_new_node;
        p_self->p_head = p_new_node;

        return;
    }

    p_new_node->p_next = p_self->p_head;
    p_new_node->p_prev = p_self->p_head->p_prev;
    p_self->p_head->p_prev->p_next = p_new_node;
    p_self->p_head->p_prev = p_new_node;
    *node = p_new_node;

    return;
}

void insert_first(struct circular_ll* p_self, int data) {
    p_self->_insert_node(p_self, &p_self->p_head, data);
    return;
}

void insert_last(struct circular_ll* p_self, int data) {
    p_self->_insert_node(p_self, &p_self->p_head->p_prev, data);
    return;
}

void insert_after(struct circular_ll* p_self, int pos, int data) {
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

    struct circular_node* p_node = get_node(p_self, pos);

    if (!p_node) return;

    struct circular_node* p_new_node = malloc(sizeof p_new_node);

    if (!p_new_node) return;

    p_new_node->data = data;
    p_new_node->p_next = p_node->p_next;
    p_new_node->p_prev = p_node;
    p_node->p_next->p_prev = p_new_node;
    p_node->p_next = p_new_node;

    return;
}

void insert_before(struct circular_ll* p_self, int pos, int data) {
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

    struct circular_node* p_node = p_self->get_node(p_self, pos);

    if (!p_node) return;

    struct circular_node* p_new_node = malloc(sizeof p_new_node);

    if (!p_new_node) return;

    p_new_node->data = data;
    p_new_node->p_next = p_node;
    p_new_node->p_prev = p_node->p_prev;
    p_node->p_prev->p_next = p_new_node;
    p_node->p_prev = p_new_node;

    return;
}

void delete_node(struct circular_ll* p_self, struct circular_node** node) {
    if (!p_self->p_head) return;
    if (p_self->p_head == p_self->p_head->p_next) {
        free(p_self->p_head);
        p_self->p_head = NULL;

        return;
    }

    struct circular_node* p_tmp = *node;

    p_tmp->p_prev->p_next = p_tmp->p_next;
    p_self->p_head = p_tmp->p_next;
    p_self->p_head->p_prev = p_tmp->p_prev;
    free(p_tmp);

    return;
}

void delete_first(struct circular_ll* p_self) {
    p_self->_delete_node(p_self, &p_self->p_head);
    return;
}

void delete_last(struct circular_ll* p_self) {
    p_self->_delete_node(p_self, &p_self->p_head->p_prev);
    return;
}

void delete_after(struct circular_ll* p_self, int pos) {
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

    struct circular_node* p_node = get_node(p_self, pos);

    if (!p_node || !p_node->p_next) return;

    struct circular_node* p_tmp = p_node->p_next;

    p_node->p_next = p_tmp->p_next;
    p_tmp->p_next->p_prev = p_node;
    free(p_tmp);

    return;
}

void delete_before(struct circular_ll* p_self, int pos) {
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

    struct circular_node* p_node = p_self->get_node(p_self, pos);

    if (!p_node || !p_node->p_prev) return;

    struct circular_node* p_tmp = p_node->p_prev;

    p_node->p_prev = p_tmp->p_prev;
    p_tmp->p_prev->p_next = p_node;
    free(p_tmp);

    return;
}

void delete_at(struct circular_ll* p_self, int pos) {
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

    struct circular_node* p_tmp = p_self->get_node(p_self, pos);

    if (!p_tmp) return;
    if (p_tmp->p_prev)
        p_tmp->p_prev->p_next = p_tmp->p_next;
    if (p_tmp->p_next)
        p_tmp->p_next->p_prev = p_tmp->p_prev;

    free(p_tmp);

    return;
}

void reverse(struct circular_ll* p_self) {
    int len = p_self->length(p_self);

    if (!p_self->p_head || len == 1) return;

    struct circular_node* p_cur = p_self->p_head;
    struct circular_node* p_res = p_self->p_head->p_prev;
    struct circular_node* p_tmp = NULL;
    int count = 0;

    p_res->p_next = p_self->p_head;
    p_res->p_prev = p_cur;

    while (p_cur && count < len) {
        p_tmp = p_cur;
        p_cur = p_cur->p_next;
        p_tmp->p_next = p_res;
        p_tmp->p_prev = p_cur;
        p_res = p_tmp;
        count++;
    }

    p_self->p_head = p_res;

    return;
}

void sort(struct circular_ll* p_self) {
    int len = p_self->length(p_self);

    if (!p_self->p_head || len == 1) return;

    struct circular_node* p_cur = p_self->p_head;
    struct circular_node* p_next = NULL;
    int tmp = 0;

    do {
        p_next = p_cur->p_next;

        while (p_next && p_next != p_self->p_head) {
            if (p_cur->data > p_next->data) {
                tmp = p_cur->data;
                p_cur->data = p_next->data;
                p_next->data = tmp;
            }

            p_next = p_next->p_next;
        }

        p_cur = p_cur->p_next;
    } while (p_cur && p_cur != p_self->p_head);

    return;
}

struct circular_ll create_circular_ll() {
    struct circular_ll self;

    self.p_head = NULL;

    self.is_empty = &is_empty;

    self.count = &count;
    self.length = &length;
    self.traverse = &traverse;

    self.get_node = &get_node;
    self.search = &search;

    self._insert_node = &insert_node;
    self.insert_first = &insert_first;
    self.insert_last = &insert_last;
    self.insert_after = &insert_after;
    self.insert_before = &insert_before;
    self.insert_at = &insert_before;

    self._delete_node = &delete_node;
    self.delete_first = &delete_first;
    self.delete_last = &delete_last;
    self.delete_after = &delete_after;
    self.delete_before = &delete_before;
    self.delete_at = &delete_at;

    self.reverse = &reverse;
    self.sort = &sort;

    return self;
}

void destroy_circular_ll(struct circular_ll* p_self) {
    int len = p_self->length(p_self);
    struct circular_node* p_tmp = p_self->p_head;

    while (len) {
        p_tmp = p_self->p_head->p_next;
        free(p_self->p_head);
        p_self->p_head = p_tmp;
        len -= 1;
    }

    return;
}