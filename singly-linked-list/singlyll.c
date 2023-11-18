#include <stdio.h>
#include <stdlib.h>
#include "singlyll.h"
#include "../color.h"

void help();
void demo();
void singly_ll();

int main(int argc, char* argv[]) {
    if (argc < 2) {
        help();

        return 0;
    }

    char* args = argv[1];

    switch (*args) {
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

void help() {
    printf("Use one of following arguments:\n");
    printf("h\tShow this help\n");
    printf("d\tDemo\n");
    printf("i\tInteractive\n");

    return;
}

void demo() {
    system("clear");
    printf("Singly Linked List\n");

    struct singly_ll ll = create_singly_ll();
    ll.traverse(&ll);
    printf("Length: %d\n", ll.length(&ll));
    printf("Check Empty: %d\n", ll.is_empty(&ll));
    printf("\n");

    printf("Insert First: 1\n");
    ll.insert_first(&ll, 1);
    ll.traverse(&ll);
    printf("Length: %d\n", ll.length(&ll));
    printf("\n");

    printf("Insert First: 2\n");
    ll.insert_first(&ll, 2);
    ll.traverse(&ll);
    printf("Length: %d\n", ll.length(&ll));
    printf("\n");

    printf("Insert Last: 3\n");
    ll.insert_last(&ll, 3);
    ll.traverse(&ll);
    printf("Length: %d\n", ll.length(&ll));
    printf("\n");

    printf("Insert Last: 4\n");
    ll.insert_last(&ll, 4);
    ll.traverse(&ll);
    printf("Length: %d\n", ll.length(&ll));
    printf("\n");

    int pos = 3;
    printf("Get Node at Position: %d\n", pos);
    struct singly_node* p_node = ll.get_node(&ll, pos);
    printf("Node at Position %d: %d\n", pos, p_node->data);
    printf("\n");

    printf("Insert After Position %d: 5\n", pos);
    ll.insert_after(&ll, pos, 5);
    ll.traverse(&ll);
    printf("Length: %d\n", ll.length(&ll));
    printf("\n");

    printf("Insert After Position %d: 6\n", p_node->data);
    ll.insert_after(&ll, pos, 6);
    ll.traverse(&ll);
    printf("Length: %d\n", ll.length(&ll));
    printf("\n");

    printf("Insert Before Position %d: 7\n", pos);
    ll.insert_before(&ll, pos, 7);
    ll.traverse(&ll);
    printf("Length: %d\n", ll.length(&ll));
    printf("\n");

    printf("Insert Before Position %d: 8\n", pos);
    ll.insert_before(&ll, pos, 8);
    ll.traverse(&ll);
    printf("Length: %d\n", ll.length(&ll));
    printf("\n");

    printf("Insert At Position %d: 9\n", pos);
    ll.insert_at(&ll, pos, 9);
    ll.traverse(&ll);
    printf("Length: %d\n", ll.length(&ll));
    printf("\n");

    printf("Insert At Position %d: 10\n", pos);
    ll.insert_at(&ll, pos, 10);
    ll.traverse(&ll);
    printf("Length: %d\n", ll.length(&ll));
    printf("\n");

    printf("Delete First\n");
    ll.delete_first(&ll);
    ll.traverse(&ll);
    printf("Length: %d\n", ll.length(&ll));
    printf("\n");

    printf("Delete Last\n");
    ll.delete_last(&ll);
    ll.traverse(&ll);
    printf("Length: %d\n", ll.length(&ll));
    printf("\n");

    int data = 8;
    printf("Search Node: %d\n", data);
    pos = ll.search(&ll, data);
    printf("Node found at Position: %d\n", pos);
    printf("\n");

    printf("Delete After Position %d\n", pos);
    ll.delete_after(&ll, pos);
    ll.traverse(&ll);
    printf("Length: %d\n", ll.length(&ll));
    printf("\n");

    printf("Delete Before Position %d\n", pos);
    ll.delete_before(&ll, pos);
    ll.traverse(&ll);
    printf("Length: %d\n", ll.length(&ll));
    printf("\n");

    printf("Delete At Position %d\n", pos);
    ll.delete_at(&ll, pos);
    ll.traverse(&ll);
    printf("Length: %d\n", ll.length(&ll));
    printf("\n");

    printf("Reverse:\n");
    ll.reverse(&ll);
    ll.traverse(&ll);
    printf("Length: %d\n", ll.length(&ll));
    printf("\n");

    printf("Sort:\n");
    ll.sort(&ll);
    ll.traverse(&ll);
    printf("Length: %d\n", ll.length(&ll));
    printf("\n");

    destroy_singly_ll(&ll);

    return;
}

void singly_ll() {
    system("clear");

    int choice = 0, pos = 0, data = 0, search = 0;
    struct singly_ll ll = create_singly_ll();
    struct singly_node* p_node = NULL;

    printf("Interactive Singly Linked List\n");
    printf("choose operation:\n\n");
    printf("0)\tShow Operation\n");
    printf("1)\tDisplay Status\n");
    printf("2)\tInsert First\n");
    printf("3)\tInsert Last\n");
    printf("4)\tInsert After Position\n");
    printf("5)\tInsert Before Position\n");
    printf("6)\tInsert At Position\n");
    printf("7)\tDelete First\n");
    printf("8)\tDelete Last\n");
    printf("9)\tDelete After Position\n");
    printf("10)\tDelete Before Position\n");
    printf("11)\tDelete At Position\n");
    printf("12)\tReverse\n");
    printf("13)\tSort\n");
    printf("14)\tSearch Node\n");
    printf("15)\tClear Screen\n");
    printf("16)\tReset\n");
    printf("17)\tExit\n");

    while (1) {
        printf("\n> ");
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            printf("0)\tShow Operation\n");
            printf("1)\tDisplay Status\n");
            printf("2)\tInsert First\n");
            printf("3)\tInsert Last\n");
            printf("4)\tInsert After Position\n");
            printf("5)\tInsert Before Position\n");
            printf("6)\tInsert At Position\n");
            printf("7)\tDelete First\n");
            printf("8)\tDelete Last\n");
            printf("9)\tDelete After Position\n");
            printf("10)\tDelete Before Position\n");
            printf("11)\tDelete At Position\n");
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
            printf("Current Length: %d\n", ll.length(&ll));
            ll.traverse(&ll);

            break;
        case 2:
            printf(GRN "== Insert First ==\n\n" RESET);
            printf("Input Data:\n");
            scanf("%d", &data);
            ll.insert_first(&ll, data);
            printf("Data Pushed\n");
            ll.traverse(&ll);

            break;
        case 3:
            printf(GRN "== Insert Last ==\n\n" RESET);
            printf("Input Data:\n");
            scanf("%d", &data);
            ll.insert_last(&ll, data);
            printf("Data Pushed\n");
            ll.traverse(&ll);

            break;
        case 4:
            printf(GRN "== Insert After ==\n\n" RESET);
            printf("Choose Node Position:\n");
            scanf("%d", &pos);
            printf("Input Data:\n");
            scanf("%d", &data);
            ll.insert_after(&ll, pos, data);
            printf("Data Pushed\n");
            ll.traverse(&ll);

            break;
        case 5:
            printf(GRN "== Insert Before ==\n\n" RESET);
            printf("Choose Node Position:\n");
            scanf("%d", &pos);
            printf("Input Data:\n");
            scanf("%d", &data);
            ll.insert_before(&ll, pos, data);
            printf("Data Pushed\n");
            ll.traverse(&ll);

            break;
        case 6:
            printf(GRN "== Insert At ==\n\n" RESET);
            printf("Choose Node Position:\n");
            scanf("%d", &pos);
            printf("Input Data:\n");
            scanf("%d", &data);
            ll.insert_at(&ll, pos, data);
            printf("Data Pushed\n");
            ll.traverse(&ll);

            break;
        case 7:
            printf(GRN "== Delete First ==\n\n" RESET);
            ll.delete_first(&ll);
            printf("Data Popped\n");
            ll.traverse(&ll);

            break;
        case 8:
            printf(GRN "== Delete Last ==\n\n" RESET);
            ll.delete_last(&ll);
            printf("Data Popped\n");
            ll.traverse(&ll);

            break;
        case 9:
            printf(GRN "== Delete After ==\n\n" RESET);
            printf("Choose Node Position:\n");
            scanf("%d", &pos);
            ll.delete_after(&ll, pos);
            printf("Data Popped\n");
            ll.traverse(&ll);

            break;
        case 10:
            printf(GRN "== Delete Before ==\n\n" RESET);
            printf("Choose Node Position:\n");
            scanf("%d", &pos);
            ll.delete_before(&ll, pos);
            printf("Data Popped\n");
            ll.traverse(&ll);

            break;
        case 11:
            printf(GRN "== Delete At ==\n\n" RESET);
            printf("Choose Node Position:\n");
            scanf("%d", &pos);
            ll.delete_at(&ll, pos);
            printf("Data Popped\n");
            ll.traverse(&ll);

            break;
        case 12:
            printf(GRN "== Reverse ==\n\n" RESET);
            ll.reverse(&ll);
            printf("Data Reversed\n");
            ll.traverse(&ll);

            break;
        case 13:
            printf(GRN "== Sort ==\n\n" RESET);
            ll.sort(&ll);
            printf("Data Sorted\n");
            ll.traverse(&ll);

            break;
        case 14:
            printf(GRN "== Search Data ==\n\n" RESET);
            printf("Input Search Data\n");
            scanf("%d", &search);
            pos = ll.search(&ll, search);

            if (pos) {
                printf("Node Found at Position: %d\n", pos);
            }
            else {
                printf("Node Not Found\n");
            }
            ll.traverse(&ll);

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
            destroy_singly_ll(&ll);
            ll = create_singly_ll();
            system("clear");

            break;
        case 17:
            printf(GRN "== Exiting ==\n");
            destroy_singly_ll(&ll);
            exit(0);
        default:
            printf("\nInvalid Choice\n");

            break;
        }
    }

    return;
}