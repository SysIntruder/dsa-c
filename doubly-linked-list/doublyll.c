#include <stdio.h>
#include <stdlib.h>
#include "doublyll.h"
#include "../color.h"

void help();
void demo();
void doubly_ll();

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        help();

        return 0;
    }
    
    char* args = argv[1];

    switch (*args)
    {
    case 'd':
        demo();
        break;
    case 'i':
        doubly_ll();
        break;
    case 'h':
        help();
        break;
    default:
        help();
        break;
    }

    return 0;
}

void help()
{
    printf("Use one of following arguments:\n");
    printf("h\tShow this help\n");
    printf("d\tDemo\n");
    printf("i\tInteractive\n");

    return;
}

void demo()
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

    int pos = 3;
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

    printf("Push At Position %d: 9\n", pos);
    p_ll->push_at(&p_ll, pos, 9);
    p_ll->traverse(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    printf("Push At Position %d: 10\n", pos);
    p_ll->push_at(&p_ll, pos, 10);
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

    int data = 8;
    printf("Search Node: %d\n", data);
    pos = p_ll->search(p_ll, data);
    printf("Node found at Position: %d\n", pos);
    printf("\n");

    printf("Pop After Position %d\n", pos);
    p_ll->pop_after(&p_ll, pos);
    p_ll->traverse(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    printf("Pop Before Position %d\n", pos);
    p_ll->pop_before(&p_ll, pos);
    p_ll->traverse(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    printf("Pop At Position %d\n", pos);
    p_ll->pop_at(&p_ll, pos);
    p_ll->traverse(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    printf("Reverse\n");
    p_ll->reverse(&p_ll);
    p_ll->traverse(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    printf("Sort\n");
    p_ll->sort(&p_ll);
    p_ll->traverse(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    destroy_doubly_ll(p_ll);
}

void doubly_ll()
{
    system("clear");

    int choice = 0, pos = 0, data = 0, search = 0;
    doubly_ll_t* p_ll = create_doubly_ll();
    doubly_node_t* p_node = NULL;

    printf("Interactive Doubly Linked List\n");
    printf("choose operation:\n\n");
    printf("0)\tShow Operation\n");
    printf("1)\tDisplay Status\n");
    printf("2)\tPush Front\n");
    printf("3)\tPush Back\n");
    printf("4)\tPush After Position\n");
    printf("5)\tPush Before Position\n");
    printf("6)\tPush At Position\n");
    printf("7)\tPop Front\n");
    printf("8)\tPop Back\n");
    printf("9)\tPop After Position\n");
    printf("10)\tPop Before Position\n");
    printf("11)\tPop At Position\n");
    printf("12)\tReverse\n");
    printf("13)\tSort\n");
    printf("14)\tSearch Node\n");
    printf("15)\tClear Screen\n");
    printf("16)\tReset\n");
    printf("17)\tExit\n");

    while (1)
    {
        printf("\n> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("0)\tShow Operation\n");
            printf("1)\tDisplay Status\n");
            printf("2)\tPush Front\n");
            printf("3)\tPush Back\n");
            printf("4)\tPush After Position\n");
            printf("5)\tPush Before Position\n");
            printf("6)\tPush At Position\n");
            printf("7)\tPop Front\n");
            printf("8)\tPop Back\n");
            printf("9)\tPop After Position\n");
            printf("10)\tPop Before Position\n");
            printf("11)\tPop At Position\n");
            printf("12)\tReverse\n");
            printf("13)\tSort\n");
            printf("14)\tSearch Node\n");
            printf("15)\tClear Screen\n");
            printf("16)\tReset\n");
            printf("17)\tExit\n");

            break;
        case 1:
            printf(GRN "== Information ==\n\n" RESET);
            printf("Current Position: %d\n", pos);
            printf("Current Node: %d\n", p_node ? p_node->data : 0);
            printf("Current Length: %d\n", p_ll->get_length(p_ll));
            p_ll->traverse(p_ll);

            break;
        case 2:
            printf(GRN "== Push Front ==\n\n" RESET);
            printf("Input Data:\n");
            scanf("%d", &data);
            p_ll->push_front(&p_ll, data);
            printf("Data Pushed\n");
            p_ll->traverse(p_ll);

            break;
        case 3:
            printf(GRN "== Push Back ==\n\n" RESET);
            printf("Input Data:\n");
            scanf("%d", &data);
            p_ll->push_back(&p_ll, data);
            printf("Data Pushed\n");
            p_ll->traverse(p_ll);

            break;
        case 4:
            printf(GRN "== Push After ==\n\n" RESET);
            printf("Choose Node Position:\n");
            scanf("%d", &pos);
            printf("Input Data:\n");
            scanf("%d", &data);
            p_ll->push_after(&p_ll, pos, data);
            printf("Data Pushed\n");
            p_ll->traverse(p_ll);

            break;
        case 5:
            printf(GRN "== Push Before ==\n\n" RESET);
            printf("Choose Node Position:\n");
            scanf("%d", &pos);
            printf("Input Data:\n");
            scanf("%d", &data);
            p_ll->push_before(&p_ll, pos, data);
            printf("Data Pushed\n");
            p_ll->traverse(p_ll);

            break;
        case 6:
            printf(GRN "== Push At ==\n\n" RESET);
            printf("Choose Node Position:\n");
            scanf("%d", &pos);
            printf("Input Data:\n");
            scanf("%d", &data);
            p_ll->push_at(&p_ll, pos, data);
            printf("Data Pushed\n");
            p_ll->traverse(p_ll);

            break;
        case 7:
            printf(GRN "== Pop Front ==\n\n" RESET);
            p_ll->pop_front(&p_ll);
            printf("Data Popped\n");
            p_ll->traverse(p_ll);

            break;
        case 8:
            printf(GRN "== Pop Back ==\n\n" RESET);
            p_ll->pop_back(&p_ll);
            printf("Data Popped\n");
            p_ll->traverse(p_ll);

            break;
        case 9:
            printf(GRN "== Pop After ==\n\n" RESET);
            printf("Choose Node Position:\n");
            scanf("%d", &pos);
            p_ll->pop_after(&p_ll, pos);
            printf("Data Popped\n");
            p_ll->traverse(p_ll);

            break;
        case 10:
            printf(GRN "== Pop Before ==\n\n" RESET);
            printf("Choose Node Position:\n");
            scanf("%d", &pos);
            p_ll->pop_before(&p_ll, pos);
            printf("Data Popped\n");
            p_ll->traverse(p_ll);

            break;
        case 11:
            printf(GRN "== Pop At ==\n\n" RESET);
            printf("Choose Node Position:\n");
            scanf("%d", &pos);
            p_ll->pop_at(&p_ll, pos);
            printf("Data Popped\n");
            p_ll->traverse(p_ll);

            break;
        case 12:
            printf(GRN "== Reverse ==\n\n" RESET);
            p_ll->reverse(&p_ll);
            printf("Data Reversed\n");
            p_ll->traverse(p_ll);

            break;
        case 13:
            printf(GRN "== Sort ==\n\n" RESET);
            p_ll->sort(&p_ll);
            printf("Data Sorted\n");
            p_ll->traverse(p_ll);

            break;
        case 14:
            printf(GRN "== Search Data ==\n\n" RESET);
            printf("Input Search Data\n");
            scanf("%d", &search);
            pos = p_ll->search(p_ll, search);

            if (pos)
            {
                printf("Node Found at Position: %d\n", pos);
            }
            else
            {
                printf("Node Not Found\n");
            }
            p_ll->traverse(p_ll);

            break;
        case 15:
            system("clear");

            break;
        case 16:
            pos = 0;
            data = 0;
            search = 0;
            free(p_node);
            p_node = NULL;
            destroy_doubly_ll(p_ll);
            p_ll = create_doubly_ll();
            system("clear");

            break;
        case 17:
            printf(GRN "== Exiting ==\n");
            destroy_doubly_ll(p_ll);
            exit(0);
        default:
            printf("\nInvalid Choice\n");

            break;
        }
    }
    
    return;
}
