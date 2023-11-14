#include <stdio.h>
#include <stdlib.h>
#include "queuearr.h"
#include "../color.h"

int is_full(queue_arr_t* p_qu)
{
    return p_qu->_rear == p_qu->_size - 1;
}

int is_empty(queue_arr_t* p_qu)
{
    return p_qu->_front == -1;
}

int length(queue_arr_t* p_qu)
{
    return p_qu->is_empty(p_qu) ? 0 : p_qu->_rear - p_qu->_front + 1;
}

void traverse(queue_arr_t* p_qu)
{
    printf(BLU "[" RESET);

    int start = p_qu->is_empty(p_qu) ? 0 : p_qu->_front;

    for (int i = start; i <= p_qu->_rear; i++)
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

    printf(BLU "]" RESET "\n");

    return;
}

void enqueue(queue_arr_t* p_qu, int data)
{
    if (p_qu->is_full(p_qu)) return;

    p_qu->p_data[++p_qu->_rear] = data;

    if (p_qu->_front == -1) p_qu->_front++;

    return;
}

int dequeue(queue_arr_t* p_qu)
{
    if (p_qu->is_empty(p_qu)) return -1;

    int res = p_qu->p_data[p_qu->_front++];

    if (p_qu->_front > p_qu->_rear)
    {
        p_qu->_front = -1;
        p_qu->_rear = -1;
    }

    return res;
}

queue_arr_t create_queue_arr(int size)
{
    queue_arr_t self;

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

    return self;
}

void destroy_queue_arr(queue_arr_t* p_qu)
{
    free(p_qu->p_data);

    return;
}