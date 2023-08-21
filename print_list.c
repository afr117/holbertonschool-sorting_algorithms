#include "sort.h"
#include <stdio.h>

void print_list(const listint_t *list)
{
    while (list)
    {
        printf("%d", list->n);
        list = list->next;
        if (list)
            printf(", ");
    }
    printf("\n");
}

