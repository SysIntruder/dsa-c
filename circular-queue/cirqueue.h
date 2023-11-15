#ifndef CIRQUEUE_H
#define CIRQUEUE_H

typedef struct cir_queue cir_queue_t;
struct cir_queue
{
    int _front;
    int _rear;
    int _size;
    int* p_data;

    int (*is_full)(cir_queue_t*);
    int (*is_empty)(cir_queue_t*);
    int (*length)(cir_queue_t*);

    void (*traverse)(cir_queue_t*);

    void (*enqueue)(cir_queue_t*, int);
    int (*dequeue)(cir_queue_t*);
    int (*peek)(cir_queue_t*);

    void (*reverse)(cir_queue_t*);
    void (*sort)(cir_queue_t*);
};

cir_queue_t create_queue(int);
void destroy_queue(cir_queue_t*);

#endif