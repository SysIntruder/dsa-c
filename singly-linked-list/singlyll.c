#include <stdio.h>
#include <stdlib.h>
#include "singlyll.h"

void help();
void demo();
void singly_ll();

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
        singly_ll();
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
    printf("Singly Linked List\n");

    singly_ll_t* p_ll = create_singly_ll();
    p_ll->display(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("Check Empty: %d\n", p_ll->check_empty(p_ll));
    printf("\n");

    printf("Push Front: 1\n");
    p_ll->push_front(&p_ll, 1);
    p_ll->display(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    printf("Push Front: 2\n");
    p_ll->push_front(&p_ll, 2);
    p_ll->display(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    printf("Push Back: 3\n");
    p_ll->push_back(&p_ll, 3);
    p_ll->display(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    printf("Push Back: 4\n");
    p_ll->push_back(&p_ll, 4);
    p_ll->display(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    int pos = 2;
    printf("Get Node at Position: %d\n", pos);
    singly_node_t* p_node = p_ll->get_node(p_ll, pos);
    printf("Node at Position %d: %d\n", pos, p_node->data);
    printf("\n");

    printf("Push After Position %d: 5\n", pos);
    p_ll->push_after(&p_ll, pos, 5);
    p_ll->display(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    printf("Push After Position %d: 6\n", p_node->data);
    p_ll->push_after(&p_ll, pos, 6);
    p_ll->display(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    printf("Check Empty: %d\n", p_ll->check_empty(p_ll));
    printf("Count Length: %d\n", p_ll->count(p_ll->head));
    printf("\n");

    printf("Reverse:\n");
    p_ll->reverse(&p_ll);
    p_ll->display(p_ll);
    printf("\n");

    printf("Sort:\n");
    p_ll->sort(&p_ll);
    p_ll->display(p_ll);
    printf("\n");

    printf("Pop Front\n");
    p_ll->pop_front(&p_ll);
    p_ll->display(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    printf("Pop Back\n");
    p_ll->pop_back(&p_ll);
    p_ll->display(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    int data = 3;
    printf("Search Data: %d\n", data);
    p_node = p_ll->search_node(p_ll, data, &pos);
    if (pos)
    {
        printf("Data Found at Position: %d\n", pos);
    }
    else
    {
        printf("Data Not Found\n");
    }
    printf("\n");

    printf("Pop After Position %d\n", pos);
    p_ll->pop_after(&p_ll, pos);
    p_ll->display(p_ll);
    printf("Length: %d\n", p_ll->get_length(p_ll));
    printf("\n");

    destroy_singly_ll(p_ll);
}

void singly_ll()
{
    system("clear");

    int choice = 0, pos = 0, data = 0, search = 0;
    singly_ll_t* p_ll = create_singly_ll();
    singly_node_t* p_node = NULL;

    printf("Interactive Singly Linked List\n");
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
    printf("9)\tPop After Node\n");
    printf("10)\tReverse\n");
    printf("11)\tSort\n");
    printf("12)\tSearch Node\n");
    printf("13)\tExit\n");

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
            printf("9)\tPop After Node\n");
            printf("10)\tReverse\n");
            printf("11)\tSort\n");
            printf("12)\tSearch Node\n");
            printf("13)\tExit\n");

            break;
        case 1:
            printf("Current Position: %d\n", pos);
            printf("Current Node: %d\n", p_node ? p_node->data : 0);
            printf("Current Length: %d\n", p_ll->get_length(p_ll));
            p_ll->display(p_ll);

            break;
        case 2:
            printf("Push Front\n\n");
            printf("Input Data:\n");
            scanf("%d", &data);
            p_ll->push_front(&p_ll, data);
            printf("Data Pushed\n");
            p_ll->display(p_ll);

            break;
        case 3:
            printf("Push Back\n\n");
            printf("Input Data:\n");
            scanf("%d", &data);
            p_ll->push_back(&p_ll, data);
            printf("Data Pushed\n");
            p_ll->display(p_ll);

            break;
        case 4:
            printf("Push After\n\n");
            printf("Choose Node Position:\n");
            scanf("%d", &pos);
            printf("Input Data:\n");
            scanf("%d", &data);
            p_ll->push_after(&p_ll, pos, data);
            printf("Data Pushed\n");
            p_ll->display(p_ll);

            break;
        case 5:
            printf("Push Before\n\n");
            printf("Choose Node Position:\n");
            scanf("%d", &pos);
            printf("Input Data:\n");
            scanf("%d", &data);
            p_ll->push_before(&p_ll, pos, data);
            printf("Data Pushed\n");
            p_ll->display(p_ll);

            break;
        case 6:
            printf("Push At\n\n");
            printf("Choose Node Position:\n");
            scanf("%d", &pos);
            printf("Input Data:\n");
            scanf("%d", &data);
            p_ll->push_at(&p_ll, pos, data);
            printf("Data Pushed\n");
            p_ll->display(p_ll);

            break;
        case 7:
            printf("Pop Front\n\n");
            p_ll->pop_front(&p_ll);
            printf("Data Popped\n");
            p_ll->display(p_ll);

            break;
        case 8:
            printf("Pop Back\n\n");
            p_ll->pop_back(&p_ll);
            printf("Data Popped\n");
            p_ll->display(p_ll);

            break;
        case 9:
            printf("Pop After\n\n");
            printf("Choose Node Position:\n");
            scanf("%d", &pos);
            p_ll->pop_after(&p_ll, pos);
            printf("Data Popped\n");
            p_ll->display(p_ll);

            break;
        case 10:
            printf("Reverse\n\n");
            p_ll->reverse(&p_ll);
            printf("Data Reversed\n");
            p_ll->display(p_ll);

            break;
        case 11:
            printf("Sort\n\n");
            p_ll->sort(&p_ll);
            printf("Data Sorted\n");
            p_ll->display(p_ll);

            break;
        case 12:
            printf("Search Data\n\n");
            printf("Input Search Data\n");
            scanf("%d", &search);
            p_ll->search_node(p_ll, search, &pos);

            if (pos)
            {
                printf("Node Found at Position: %d\n", pos);
            }
            else
            {
                printf("Node Not Found\n");
            }
            p_ll->display(p_ll);

            break;
        case 13:
            printf("Exiting\n");
            destroy_singly_ll(p_ll);
            exit(0);
        default:
            printf("\nInvalid Choice\n");

            break;
        }
    }
    
    return;
}