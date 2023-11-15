#include <stdio.h>
#include <stdlib.h>
#include "dynstack.h"
#include "../color.h"

int is_full(dyn_stack_t* p_st)
{
    return p_st->_top == p_st->_size - 1;
}

int is_empty(dyn_stack_t* p_st)
{
    return p_st->_top == -1;
}

int length(dyn_stack_t* p_st)
{
    return p_st->_top + 1;
}

void traverse(dyn_stack_t* p_st)
{
    printf(BLU "[" RESET);

    for (int i = 0; i < p_st->length(p_st); i++)
    {
        if (i == p_st->_top) printf(YEL);

        printf(" %d ", p_st->p_data[i]);
    }

    printf(BLU "<=>" RESET "\n");

    return;
}

void push(dyn_stack_t* p_st, int data)
{
    if (p_st->is_full(p_st))
    {
        p_st->_size += p_st->_size / 2;
        p_st->p_data = (int*)realloc(p_st->p_data, p_st->_size * sizeof(int));

        if (!p_st->p_data) return;
    }

    p_st->p_data[++p_st->_top] = data;

    return;
}

int pop(dyn_stack_t* p_st)
{
    if (p_st->is_empty(p_st)) return -1;

    int res = p_st->p_data[p_st->_top];
    p_st->p_data[p_st->_top--] = 0;

    return res;
}

int peek(dyn_stack_t* p_st)
{
    return p_st->is_empty(p_st) ? -1 : p_st->p_data[p_st->_top];
}

void reverse(dyn_stack_t* p_st)
{
    if (p_st->is_empty(p_st) || p_st->length(p_st) == 1) return;

    int tmp = 0, limit = p_st->length(p_st) / 2;

    for (int i = 0; i < limit; i++)
    {
        tmp = p_st->p_data[p_st->_top - i];
        p_st->p_data[p_st->_top - i] = p_st->p_data[i];
        p_st->p_data[i] = tmp;
    }

    return;
}

void sort(dyn_stack_t* p_st)
{
    if (p_st->is_empty(p_st) || p_st->length(p_st) == 1) return;

    int cur = 0, next = 0, tmp = 0;

    while (cur <= p_st->_top)
    {
        next = cur + 1;

        while (next <= p_st->_top)
        {
            if (p_st->p_data[cur] > p_st->p_data[next])
            {
                tmp = p_st->p_data[cur];
                p_st->p_data[cur] = p_st->p_data[next];
                p_st->p_data[next] = tmp;
            }

            next++;
        }

        cur++;
    }

    return;
}

dyn_stack_t create_dyn_stack(int size)
{
    dyn_stack_t self;

    self._top = -1;
    self._size = size;
    self.p_data = (int*)calloc(size, sizeof(int));

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

void destroy_dyn_stack(dyn_stack_t* p_st)
{
    free(p_st->p_data);

    return;
}