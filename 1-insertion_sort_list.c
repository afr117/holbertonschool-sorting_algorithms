#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the insertion sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 *
 * Description: This function implements the insertion sort algorithm
 *              on a doubly linked list. It rearranges the nodes in the
 *              list to sort them in ascending order.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current;
    listint_t *next_node;
    listint_t *temp;
    listint_t *prev;

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

            print_list(*list);
            prev = temp->prev;
        }

        current = next_node;
    }
}

