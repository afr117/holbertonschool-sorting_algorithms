#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    listint_t *current, *insertion_point;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;

    while (current != NULL)
    {
        insertion_point = current->prev;

        while (insertion_point != NULL && insertion_point->n > current->n)
        {
            insertion_point->next = current->next;
            if (current->next != NULL)
                current->next->prev = insertion_point;

            current->next = insertion_point;
            current->prev = insertion_point->prev;

            if (insertion_point->prev != NULL)
                insertion_point->prev->next = current;
            else
                *list = current;

            insertion_point->prev = current;

            insertion_point = current->prev;
        }

        current = current->next;
    }
}

