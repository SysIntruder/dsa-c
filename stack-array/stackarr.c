#include <stdio.h>
#include <stdlib.h>
#include "stackarr.h"
#include "../color.h"

void help();
void demo();
void stack_arr();

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
        stack_arr();
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
    printf("Stack\n");

    stack_arr_t st = create_stack_arr(3);
    st.traverse(&st);
    printf("Length: %d\n", st.length(&st));
    printf("\n");

    printf("Push: 1\n");
    st.push(&st, 1);
    st.traverse(&st);
    printf("Length: %d\n", st.length(&st));
    printf("\n");

    printf("Push: 2\n");
    st.push(&st, 2);
    st.traverse(&st);
    printf("Length: %d\n", st.length(&st));
    printf("\n");

    printf("Push: 3\n");
    st.push(&st, 3);
    st.traverse(&st);
    printf("Length: %d\n", st.length(&st));
    printf("Check Full: %d\n", st.is_full(&st));
    printf("\n");

    printf("Reverse\n");
    st.reverse(&st);
    st.traverse(&st);
    printf("\n");

    printf("Sort\n");
    st.sort(&st);
    st.traverse(&st);
    printf("\n");

    printf("Peek: %d\n", st.peek(&st));
    printf("\n");

    printf("Pop\n");
    st.pop(&st);
    st.traverse(&st);
    printf("Length: %d\n", st.length(&st));
    printf("\n");

    printf("Pop\n");
    st.pop(&st);
    st.traverse(&st);
    printf("Length: %d\n", st.length(&st));
    printf("\n");

    printf("Pop\n");
    st.pop(&st);
    st.traverse(&st);
    printf("Length: %d\n", st.length(&st));
    printf("Check Empty: %d\n", st.is_empty(&st));
    printf("\n");

    destroy_stack_arr(&st);
}

void stack_arr()
{
    int size = 0;
    printf("input stack size --THIS CAN'T BE CHANGED LATER--\n");
    scanf("%d", &size);

    system("clear");

    int choice = 0, data = 0;
    stack_arr_t st = create_stack_arr(size);

    printf("Interactive Stack Array\n");
    printf("choose operation:\n\n");
    printf("0)\tShow Operation\n");
    printf("1)\tDisplay Status\n");
    printf("2)\tPush\n");
    printf("3)\tPop\n");
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
            printf("2)\tPush\n");
            printf("3)\tPop\n");
            printf("4)\tPeek\n");
            printf("5)\tReverse\n");
            printf("6)\tSort\n");
            printf("7)\tClear Screen\n");
            printf("8)\tReset\n");
            printf("9)\tExit\n");

            break;
        case 1:
            printf(GRN "== Information ==\n\n" RESET);
            printf("Top Index: %d\n", st._top);
            printf("Stack Size: %d\n", st._size);
            printf("Current Length: %d\n", st.length(&st));
            st.traverse(&st);

            break;
        case 2:
            printf(GRN "== Push ==\n\n" RESET);
            printf("Input Data:\n");
            scanf("%d", &data);
            st.push(&st, data);
            printf("Data Pushed\n");
            st.traverse(&st);

            break;
        case 3:
            printf(GRN "== Pop ==\n\n" RESET);
            st.pop(&st);
            printf("Data Popped\n");
            st.traverse(&st);

            break;
        case 4:
            printf(GRN "== Peek ==\n\n" RESET);
            printf("Top Data: %d\n", st.peek(&st));

            break;
        case 5:
            printf(GRN "== Reverse ==\n\n" RESET);
            st.reverse(&st);
            printf("Data Reversed\n");
            st.traverse(&st);

            break;
        case 6:
            printf(GRN "== Sort ==\n\n" RESET);
            st.sort(&st);
            printf("Data Sorted\n");
            st.traverse(&st);

            break;
        case 7:
            system("clear");

            break;
        case 8:
            data = 0;
            destroy_stack_arr(&st);
            printf("input stack size --THIS CAN'T BE CHANGED LATER--\n");
            scanf("%d", &size);
            st = create_stack_arr(size);
            system("clear");

            break;
        case 9:
            printf(GRN "== Exiting ==\n");
            destroy_stack_arr(&st);
            exit(0);
        default:
            printf("\nInvalid Choice\n");

            break;
        }
    }

    return;
}
