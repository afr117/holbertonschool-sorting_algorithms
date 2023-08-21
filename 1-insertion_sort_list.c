#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the insertion sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 * Return: A pointer to the sorted list.
 */
listint_t *insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return (*list);

    listint_t *current, *next_node, *temp, *prev;

    current = (*list)->next;

    while (current != NULL)
    {
        temp = current;
        prev = current->prev;
        next_node = current->next;

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

            print_list(*list);
            prev = temp->prev;
        }

        current = next_node;
    }

    return (*list);
}

