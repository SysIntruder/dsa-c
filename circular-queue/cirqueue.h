#ifndef CIRQUEUE_H
#define CIRQUEUE_H

struct cir_queue {
    int _front;
    int _rear;
    int _size;
    int* p_data;

    int (*is_full)(struct cir_queue*);
    int (*is_empty)(struct cir_queue*);
    int (*length)(struct cir_queue*);

    void (*traverse)(struct cir_queue*);

    void (*enqueue)(struct cir_queue*, int);
    int (*dequeue)(struct cir_queue*);
    int (*peek)(struct cir_queue*);

    void (*reverse)(struct cir_queue*);
    void (*sort)(struct cir_queue*);
};

struct cir_queue create_queue(int);
void destroy_queue(struct cir_queue*);

#endif