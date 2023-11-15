#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue queue_t;
struct queue
{
    int _front;
    int _rear;
    int _size;
    int* p_data;

    int (*is_full)(queue_t*);
    int (*is_empty)(queue_t*);
    int (*length)(queue_t*);

    void (*traverse)(queue_t*);

    void (*enqueue)(queue_t*, int);
    int (*dequeue)(queue_t*);
    int (*peek)(queue_t*);

    void (*reverse)(queue_t*);
    void (*sort)(queue_t*);
};

queue_t create_queue(int);
void destroy_queue(queue_t*);

#endif