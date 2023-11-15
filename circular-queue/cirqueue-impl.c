#include <stdio.h>
#include <stdlib.h>
#include "cirqueue.h"
#include "../color.h"

int is_full(cir_queue_t* p_qu)
{
    return (p_qu->_rear + 1) % p_qu->_size == p_qu->_front;
}

int is_empty(cir_queue_t* p_qu)
{
    return p_qu->_front == -1 || p_qu->_rear == -1;
}

int length(cir_queue_t* p_qu)
{
    if (p_qu->is_empty(p_qu)) return 0;
    else if (p_qu->is_full(p_qu)) return p_qu->_size;
    else if (p_qu->_rear + p_qu->_front + 1 == p_qu->_size) return 2;
    else return p_qu->_rear - p_qu->_front + 1;
}

void traverse(cir_queue_t* p_qu)
{
    printf(BLU "<<" RESET);

    for (int i = 0; i <= p_qu->_size - 1; i++)
    {
        if (i == p_qu->_front)
        {
            printf(YEL " %d " RESET, p_qu->p_data[i]);
        }
        else if (i == p_qu->_rear)
        {
            printf(GRN " %d " RESET, p_qu->p_data[i]);
        }
        else
        {
            printf(" %d " RESET, p_qu->p_data[i]);
        }
    }

    printf(BLU "<<" RESET "\n");

    return;
}

void enqueue(cir_queue_t* p_qu, int data)
{
    if (p_qu->is_full(p_qu)) return;

    if (p_qu->_rear + 1 == p_qu->_size && p_qu->_front > 0)
    {
        p_qu->_rear = (p_qu->_rear + 1) % p_qu->_size;
    }
    else
    {
        p_qu->_rear++;
    }

    p_qu->p_data[p_qu->_rear] = data;

    if (p_qu->_front == -1) p_qu->_front++;

    return;
}

int dequeue(cir_queue_t* p_qu)
{
    if (p_qu->is_empty(p_qu)) return -1;

    int res = p_qu->p_data[p_qu->_front];
    p_qu->p_data[p_qu->_front] = 0;
    p_qu->_front++;

    if (p_qu->_front == p_qu->_size)
    {
        p_qu->_front = p_qu->_front %= p_qu->_size;

        goto finish;
    }

    if (p_qu->_front - p_qu->_rear == 1)
    {
        p_qu->_front = -1;
        p_qu->_rear = -1;

        goto finish;
    }

finish:
    return res;
}

int peek(cir_queue_t* p_qu)
{
    return p_qu->is_empty(p_qu) ? -1 : p_qu->p_data[p_qu->_front];
}

void reverse(cir_queue_t* p_qu)
{
    if (p_qu->is_empty(p_qu) || p_qu->length(p_qu) == 1) return;

    int tmp = 0, limit = p_qu->length(p_qu) / 2;

    for (int i = 0; i < limit; i++)
    {
        tmp = p_qu->p_data[p_qu->_rear - i];
        p_qu->p_data[p_qu->_rear - i] = p_qu->p_data[p_qu->_front + i];
        p_qu->p_data[p_qu->_front + i] = tmp;
    }

    return;
}

void sort(cir_queue_t* p_qu)
{
    if (p_qu->is_empty(p_qu) || p_qu->length(p_qu) == 1) return;

    int cur = p_qu->_front, next = 0, tmp = 0;

    while (cur <= p_qu->_rear)
    {
        next = cur + 1;

        while (next <= p_qu->_rear)
        {
            if (p_qu->p_data[cur] > p_qu->p_data[next])
            {
                tmp = p_qu->p_data[cur];
                p_qu->p_data[cur] = p_qu->p_data[next];
                p_qu->p_data[next] = tmp;
            }

            next++;
        }

        cur++;
    }

    return;
}

cir_queue_t create_queue(int size)
{
    cir_queue_t self;

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

void destroy_queue(cir_queue_t* p_qu)
{
    free(p_qu->p_data);

    return;
}