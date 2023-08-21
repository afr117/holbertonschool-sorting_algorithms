#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current;
    listint_t *next_node;

    current = (*list)->next;

    while (current != NULL)
    {
        next_node = current->next;

        while (current->prev != NULL && current->n < current->prev->n)
        {
            listint_t *prev = current->prev;

            prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = prev;

            current->next = prev;
            current->prev = prev->prev;

            if (prev->prev != NULL)
                prev->prev->next = current;
            else
                *list = current;

            prev->prev = current;
        }

        current = next_node;
    }
}

