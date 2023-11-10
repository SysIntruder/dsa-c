#include <stdio.h>
#include <stdlib.h>
#include "doublyll.h"

int main(int argc, char *argv[])
{
    system("clear");
    printf("Doubly Linked List\n");

    doubly_ll_t* p_ll = create_doubly_ll();
    p_ll->traverse(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("Check Empty: %d\n", p_ll->check_empty(p_ll));
    printf("\n");

    printf("Push Front: 1\n");
    p_ll->push_front(&p_ll, 1);
    p_ll->traverse(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    printf("Push Front: 2\n");
    p_ll->push_front(&p_ll, 2);
    p_ll->traverse(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    printf("Push Back: 3\n");
    p_ll->push_back(&p_ll, 3);
    p_ll->traverse(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    printf("Push Back: 4\n");
    p_ll->push_back(&p_ll, 4);
    p_ll->traverse(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    int pos = 2;
    printf("Get Node at Position: %d\n", pos);
    doubly_node_t* p_node = p_ll->get_node(p_ll, pos);
    printf("Node at Position %d: %d\n", pos, p_node->data);
    printf("\n");

    printf("Push After Position %d: 5\n", pos);
    p_ll->push_after(&p_ll, pos, 5);
    p_ll->traverse(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    printf("Push After Position %d: 6\n", p_node->data);
    p_ll->push_after(&p_ll, pos, 6);
    p_ll->traverse(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    printf("Push Before Position %d: 7\n", pos);
    p_ll->push_before(&p_ll, pos, 7);
    p_ll->traverse(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    printf("Push Before Position %d: 8\n", pos);
    p_ll->push_before(&p_ll, pos, 8);
    p_ll->traverse(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    printf("Pop Front\n");
    p_ll->pop_front(&p_ll);
    p_ll->traverse(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    printf("Pop Back\n");
    p_ll->pop_back(&p_ll);
    p_ll->traverse(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    return 0;
}
