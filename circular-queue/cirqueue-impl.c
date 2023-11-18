#include <stdio.h>
#include <stdlib.h>
#include "cirqueue.h"
#include "../color.h"

__attribute__((pure)) int is_full(struct cir_queue* p_self) {
    return (p_self->_rear + 1) % p_self->_size == p_self->_front;
}

__attribute__((pure)) int is_empty(struct cir_queue* p_self) {
    return p_self->_front == -1 || p_self->_rear == -1;
}

__attribute__((pure)) int length(struct cir_queue* p_self) {
    if (p_self->is_empty(p_self)) return 0;
    if (p_self->is_full(p_self)) return p_self->_size;

    int next_size = (p_self->_size + 1);

    return p_self->_rear < p_self->_front
        ? (p_self->_rear - p_self->_front + next_size) % next_size
        : p_self->_rear - p_self->_front + 1;
}

void traverse(struct cir_queue* p_self) {
    int limit = p_self->_front + p_self->_size - 1;

    printf(BLU "<<" RESET);

    for (int i = p_self->_front; i <= limit; i++) {
        printf(" %d " RESET, p_self->p_data[i % p_self->_size]);

        if (i < limit) printf(BLU "|" RESET);
    }

    printf(BLU "<<" RESET "\n");

    return;
}

void enqueue(struct cir_queue* p_self, int data) {
    if (p_self->is_full(p_self)) return;

    p_self->_rear + 1 == p_self->_size && p_self->_front > 0
        ? p_self->_rear = ++p_self->_rear % p_self->_size
        : p_self->_rear++;

    p_self->p_data[p_self->_rear] = data;

    if (p_self->_front == -1) p_self->_front++;

    return;
}

int dequeue(struct cir_queue* p_self) {
    if (p_self->is_empty(p_self)) return -1;

    int res = p_self->p_data[p_self->_front];
    p_self->p_data[p_self->_front] = 0;
    p_self->_front++;

    if (p_self->_front == p_self->_size) {
        p_self->_front %= p_self->_size;

        goto finish;
    }

    if (p_self->_front - p_self->_rear == 1) {
        p_self->_front = -1;
        p_self->_rear = -1;
    }

finish:
    return res;
}

__attribute__((pure)) int peek(struct cir_queue* p_self) {
    return p_self->is_empty(p_self) ? -1 : p_self->p_data[p_self->_front];
}

void reverse(struct cir_queue* p_self) {
    if (p_self->is_empty(p_self) || p_self->length(p_self) == 1) return;

    int tmp = 0, limit = p_self->length(p_self) / 2;

    for (int i = 0; i < limit; i++) {
        tmp = p_self->p_data[p_self->_rear - i];
        p_self->p_data[p_self->_rear - i] = p_self->p_data[p_self->_front + i];
        p_self->p_data[p_self->_front + i] = tmp;
    }

    return;
}

void sort(struct cir_queue* p_self) {
    if (p_self->is_empty(p_self) || p_self->length(p_self) == 1) return;

    int cur = p_self->_front, next = 0, tmp = 0;

    while (cur <= p_self->_rear) {
        next = cur + 1;

        while (next <= p_self->_rear) {
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

struct cir_queue create_queue(int size) {
    struct cir_queue self;

    self._front = -1;
    self._rear = -1;
    self._size = size;
    self.p_data = (int*)calloc(size, sizeof(int));

    self.is_full = &is_full;
    self.is_empty = &is_empty;
    self.length = &length;

    self.traverse = &traverse;

    self.enqueue = &enqueue;
    self.dequeue = &dequeue;
    self.peek = &peek;

    self.reverse = &reverse;
    self.sort = &sort;

    return self;
}

void destroy_queue(struct cir_queue* p_self) {
    free(p_self->p_data);

    return;
}