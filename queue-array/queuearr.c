#include <stdio.h>
#include <stdlib.h>
#include "queuearr.h"
#include "../color.h"

void help();
void demo();
void queue_arr();

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
        queue_arr();
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
    printf("Queue\n");

    queue_arr_t qu = create_queue_arr(3);
    qu.traverse(&qu);
    printf("Length: %d\n", qu.length(&qu));
    printf("\n");

    printf("Enqueue: 1\n");
    qu.enqueue(&qu, 1);
    qu.traverse(&qu);
    printf("Length: %d\n", qu.length(&qu));
    printf("\n");

    printf("Enqueue: 2\n");
    qu.enqueue(&qu, 2);
    qu.traverse(&qu);
    printf("Length: %d\n", qu.length(&qu));
    printf("\n");

    printf("Enqueue: 3\n");
    qu.enqueue(&qu, 3);
    qu.traverse(&qu);
    printf("Length: %d\n", qu.length(&qu));
    printf("Check Full: %d\n", qu.is_full(&qu));
    printf("\n");

    printf("Reverse\n");
    qu.reverse(&qu);
    qu.traverse(&qu);
    printf("\n");

    printf("Sort\n");
    qu.sort(&qu);
    qu.traverse(&qu);
    printf("\n");

    printf("Peek: %d\n", qu.peek(&qu));
    printf("\n");

    printf("Dequeue\n");
    qu.dequeue(&qu);
    qu.traverse(&qu);
    printf("Length: %d\n", qu.length(&qu));
    printf("\n");

    printf("Dequeue\n");
    qu.dequeue(&qu);
    qu.traverse(&qu);
    printf("Length: %d\n", qu.length(&qu));
    printf("\n");

    printf("Dequeue\n");
    qu.dequeue(&qu);
    qu.traverse(&qu);
    printf("Length: %d\n", qu.length(&qu));
    printf("Check Empty: %d\n", qu.is_empty(&qu));
    printf("\n");

    destroy_queue_arr(&qu);
}

void queue_arr()
{
    int size = 0;
    printf("input queue size --THIS CAN'T BE CHANGED LATER--\n");
    scanf("%d", &size);

    system("clear");

    int choice = 0, data = 0;
    queue_arr_t qu = create_queue_arr(size);

    printf("Interactive Queue Array\n");
    printf("choose operation:\n\n");
    printf("0)\tShow Operation\n");
    printf("1)\tDisplay Status\n");
    printf("2)\tEnqueue\n");
    printf("3)\tDequeue\n");
    printf("4)\tPeek\n");
    printf("5)\tReverse\n");
    printf("6)\tSort\n");
    printf("7)\tClear Screen\n");
    printf("8)\tReset\n");
    printf("9)\tExit\n");

    while (1)
    {
        printf("\n> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("0)\tShow Operation\n");
            printf("1)\tDisplay Status\n");
            printf("2)\tEnqueue\n");
            printf("3)\tDequeue\n");
            printf("4)\tPeek\n");
            printf("5)\tReverse\n");
            printf("6)\tSort\n");
            printf("7)\tClear Screen\n");
            printf("8)\tReset\n");
            printf("9)\tExit\n");

            break;
        case 1:
            printf(GRN "== Information ==\n\n" RESET);
            printf("Queue Size: %d\n", qu._size);
            printf("Current Length: %d\n", qu.length(&qu));
            qu.traverse(&qu);

            break;
        case 2:
            printf(GRN "== Enqueue ==\n\n" RESET);
            printf("Input Data:\n");
            scanf("%d", &data);
            qu.enqueue(&qu, data);
            printf("Data Enqueued\n");
            qu.traverse(&qu);

            break;
        case 3:
            printf(GRN "== Dequeue ==\n\n" RESET);
            qu.dequeue(&qu);
            printf("Data Dequeued\n");
            qu.traverse(&qu);

            break;
        case 4:
            printf(GRN "== Peek ==\n\n" RESET);
            printf("Top Data: %d\n", qu.peek(&qu));

            break;
        case 5:
            printf(GRN "== Reverse ==\n\n" RESET);
            qu.reverse(&qu);
            printf("Data Reversed\n");
            qu.traverse(&qu);

            break;
        case 6:
            printf(GRN "== Sort ==\n\n" RESET);
            qu.sort(&qu);
            printf("Data Sorted\n");
            qu.traverse(&qu);

            break;
        case 7:
            system("clear");

            break;
        case 8:
            data = 0;
            destroy_queue_arr(&qu);
            printf("input queue size --THIS CAN'T BE CHANGED LATER--\n");
            scanf("%d", &size);
            qu = create_queue_arr(size);
            system("clear");

            break;
        case 9:
            printf(GRN "== Exiting ==\n");
            destroy_queue_arr(&qu);
            exit(0);
        default:
            printf("\nInvalid Choice\n");

            break;
        }
    }

    return;
}