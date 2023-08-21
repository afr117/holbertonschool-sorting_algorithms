#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Insertion sort algorithm.
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

    listint_t *current = (*list)->next;

    while (current != NULL)
    {
        listint_t *next_node = current->next;

        if (current->prev != NULL && current->prev->n > current->n)
        {
            listint_t *temp = current;

            while (temp->prev != NULL && temp->prev->n > temp->n)
            {
                listint_t *prev = temp->prev;

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
            }
        }
        current = next_node;
    }
}

