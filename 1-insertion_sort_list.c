#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    listint_t *current, *next_node, *temp, *prev;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;

    while (current != NULL)
    {
        next_node = current->next;
        temp = current;
        prev = temp->prev;

        while (prev != NULL && prev->n > temp->n)
        {
            prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = prev;

            temp->next = prev;
            temp->prev = prev->prev;

            if (prev->prev != NULL)
                prev->prev->next = temp;
            else
                *list = temp;

            prev->prev = temp;

            prev = temp->prev;
        }

        current = next_node;
    }
}

