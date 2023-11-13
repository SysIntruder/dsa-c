#include <stdio.h>
#include <stdlib.h>
#include "stackarr.h"
#include "../color.h"

int is_full(stack_arr_t* p_st)
{
    return p_st->top == p_st->size - 1;
}

int is_empty(stack_arr_t* p_st)
{
    return p_st->top == -1;
}

int length(stack_arr_t* p_st)
{
    return p_st->top + 1;
}

void traverse(stack_arr_t* p_st)
{
    printf(BLU "[" RESET);

    int len = p_st->length(p_st);

    for (int i = p_st->top; i > -1; i--)
    {
        printf(" %d ", p_st->p_data[i]);
    }

    printf(BLU "]" RESET "\n");

    return;
}

void push(stack_arr_t* p_st, int data)
{
    if (p_st->is_full(p_st)) return;

    p_st->p_data[++p_st->top] = data;

    return;
}

int pop(stack_arr_t* p_st)
{
    if (p_st->is_empty(p_st)) return -1;

    return p_st->p_data[p_st->top--];
}

int peek(stack_arr_t* p_st)
{
    if (p_st->is_empty(p_st)) return -1;

    return p_st->p_data[p_st->top];
}

stack_arr_t create_stack_arr(int size)
{
    stack_arr_t self;

    self.top = -1;
    self.size = size;
    self.p_data = (int*)malloc(size * sizeof(int));

    self.is_full = &is_full;
    self.is_empty = &is_empty;
    self.length = &length;

    self.traverse = &traverse;

    self.push = &push;
    self.pop = &pop;
    self.peek = &peek;

    return self;
}

void destroy_stack_arr(stack_arr_t* p_st)
{
    free(p_st->p_data);

    return;
}