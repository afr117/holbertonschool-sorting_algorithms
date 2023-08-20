#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                       using the Insertion sort algorithm.
 *
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *curr, *temp;

    if (!list || !(*list) || !(*list)->next)
        return;

    curr = (*list)->next;
    while (curr)
    {
        temp = curr->next;
        while (curr->prev && curr->n < curr->prev->n)
        {
            curr->prev->next = curr->next;
            if (curr->next)
                curr->next->prev = curr->prev;
            curr->next = curr->prev;
            curr->prev = curr->next->prev;
            if (curr->prev)
                curr->prev->next = curr;
            else
                (*list) = curr;
            curr->next->prev = curr;
            print_list(*list);
        }
        curr = temp;
    }
}

