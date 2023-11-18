#include <stdio.h>
#include <stdlib.h>
#include "dynstack.h"
#include "../color.h"

__attribute__((pure)) int is_full(struct dyn_stack* p_self) {
    return p_self->_top == p_self->_size - 1;
}

__attribute__((pure)) int is_empty(struct dyn_stack* p_self) {
    return p_self->_top == -1;
}

__attribute__((pure)) int length(struct dyn_stack* p_self) {
    return p_self->_top + 1;
}

void traverse(struct dyn_stack* p_self) {
    printf(BLU "[" RESET);

    for (int i = 0; i < p_self->_size; i++) {
        printf(" %d ", p_self->p_data[i]);

        if (i < p_self->_size - 1) printf(BLU "|" RESET);
    }

    printf(BLU "<<" RESET "\n");

    return;
}

void push(struct dyn_stack* p_self, int data) {
    if (p_self->is_full(p_self)) {
        p_self->_size <<= 1;
        p_self->p_data = realloc(p_self->p_data, sizeof p_self->p_data * p_self->_size);

        if (!p_self->p_data) return;
    }

    p_self->p_data[++p_self->_top] = data;

    return;
}

int pop(struct dyn_stack* p_self) {
    if (p_self->is_empty(p_self)) return -1;

    int res = p_self->p_data[p_self->_top];
    p_self->p_data[p_self->_top--] = 0;

    return res;
}

__attribute__((pure)) int peek(struct dyn_stack* p_self) {
    return p_self->is_empty(p_self) ? -1 : p_self->p_data[p_self->_top];
}

void reverse(struct dyn_stack* p_self) {
    if (p_self->is_empty(p_self) || p_self->length(p_self) == 1) return;

    int tmp = 0, limit = p_self->length(p_self) / 2;

    for (int i = 0; i < limit; i++) {
        tmp = p_self->p_data[p_self->_top - i];
        p_self->p_data[p_self->_top - i] = p_self->p_data[i];
        p_self->p_data[i] = tmp;
    }

    return;
}

void sort(struct dyn_stack* p_self) {
    if (p_self->is_empty(p_self) || p_self->length(p_self) == 1) return;

    int cur = 0, next = 0, tmp = 0;

    while (cur <= p_self->_top) {
        next = cur + 1;

        while (next <= p_self->_top) {
            if (p_self->p_data[cur] > p_self->p_data[next]) {
                tmp = p_self->p_data[cur];
                p_self->p_data[cur] = p_self->p_data[next];
                p_self->p_data[next] = tmp;
            }

            next++;
        }

        cur++;
    }

    return;
}

struct dyn_stack create_dyn_stack(int size) {
    struct dyn_stack self;

    self._top = -1;
    self._size = size;
    self.p_data = calloc(size, sizeof self.p_data);

    self.is_full = &is_full;
    self.is_empty = &is_empty;
    self.length = &length;

    self.traverse = &traverse;

    self.push = &push;
    self.pop = &pop;
    self.peek = &peek;

    self.reverse = &reverse;
    self.sort = &sort;

    return self;
}

void destroy_dyn_stack(struct dyn_stack* p_self) {
    free(p_self->p_data);

    return;
}