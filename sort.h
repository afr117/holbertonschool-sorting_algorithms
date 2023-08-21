#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node structure
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;


/* External declarations for variables */
extern listint_t *current;
extern listint_t *next_node;
extern listint_t *temp;
extern listint_t *prev;

/* Function prototypes */
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);

listint_t *add_nodeint(listint_t **head, int n);

#endif /* SORT_H */

