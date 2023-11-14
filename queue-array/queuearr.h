#ifndef QUEUEARR_H
#define QUEUEARR_H

typedef struct queue_arr queue_arr_t;
struct queue_arr
{
    int _front;
    int _rear;
    int _size;
    int* p_data;

    int (*is_full)(queue_arr_t*);
    int (*is_empty)(queue_arr_t*);
    int (*length)(queue_arr_t*);

    void (*traverse)(queue_arr_t*);

    void (*enqueue)(queue_arr_t*, int);
    int (*dequeue)(queue_arr_t*);
};

queue_arr_t create_queue_arr(int);
void destroy_queue_arr(queue_arr_t*);

#endif