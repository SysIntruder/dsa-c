#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "../color.h"

__attribute__((pure)) int is_full(struct queue* p_self) {
    return p_self->_rear == p_self->_size - 1;
}

__attribute__((pure)) int is_empty(struct queue* p_self) {
    return p_self->_front == -1 || p_self->_rear == -1;
}

__attribute__((pure)) int length(struct queue* p_self) {
    return p_self->is_empty(p_self) ? 0 : p_self->_rear - p_self->_front + 1;
}

void traverse(struct queue* p_self) {
    printf(BLU "<<" RESET);

    if (p_self->is_empty(p_self)) goto finish;

    for (int i = p_self->_front; i <= p_self->_rear; i++) {
        printf(" %d " RESET, p_self->p_data[i]);

        if (i < p_self->_rear) printf(BLU "|" RESET);
    }

finish:
    printf(BLU "<<" RESET "\n");

    return;
}

void enqueue(struct queue* p_self, int data) {
    if (p_self->is_full(p_self)) return;

    p_self->p_data[++p_self->_rear] = data;

    if (p_self->_front == -1) p_self->_front++;

    return;
}

int dequeue(struct queue* p_self) {
    if (p_self->is_empty(p_self)) return -1;

    int res = p_self->p_data[p_self->_front];
    p_self->p_data[p_self->_front] = 0;
    p_self->_front++;

    if (p_self->_front > p_self->_rear) {
        p_self->_front = -1;
        p_self->_rear = -1;
    }

    return res;
}

__attribute__((pure)) int peek(struct queue* p_self) {
    return p_self->is_empty(p_self) ? -1 : p_self->p_data[p_self->_front];
}

void reverse(struct queue* p_self) {
    if (p_self->is_empty(p_self) || p_self->length(p_self) == 1) return;

    int tmp = 0, limit = p_self->length(p_self) / 2;

    for (int i = 0; i < limit; i++) {
        tmp = p_self->p_data[p_self->_rear - i];
        p_self->p_data[p_self->_rear - i] = p_self->p_data[p_self->_front + i];
        p_self->p_data[p_self->_front + i] = tmp;
    }

    return;
}

void sort(struct queue* p_self) {
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

struct queue create_queue(int size) {
    struct queue self;

    self._front = -1;
    self._rear = -1;
    self._size = size;
    self.p_data = (int*)malloc(size * sizeof(int));

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

void destroy_queue(struct queue* p_self) {
    free(p_self->p_data);

    return;
}