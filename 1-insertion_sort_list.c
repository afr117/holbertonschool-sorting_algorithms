#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next;

    while (current != NULL)
    {
        listint_t *next_node = current->next;
        listint_t *temp = current;
        listint_t *prev = temp->prev;

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

