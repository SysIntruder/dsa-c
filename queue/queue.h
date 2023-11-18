#ifndef QUEUE_H
#define QUEUE_H

struct queue {
    int _front;
    int _rear;
    int _size;
    int* p_data;

    int (*is_full)(struct queue*);
    int (*is_empty)(struct queue*);
    int (*length)(struct queue*);

    void (*traverse)(struct queue*);

    void (*enqueue)(struct queue*, int);
    int (*dequeue)(struct queue*);
    int (*peek)(struct queue*);

    void (*reverse)(struct queue*);
    void (*sort)(struct queue*);
};

struct queue create_queue(int);
void destroy_queue(struct queue*);

#endif