#include <stdio.h>
#include <stdlib.h>
#include "sort.h" // Include your header file

listint_t *add_nodeint(listint_t **head, int n);

int main(void)
{
    listint_t *list = NULL;
    listint_t *sorted = NULL;

    // Add test elements to the list using add_nodeint function
    add_nodeint(&list, 30);
    add_nodeint(&list, 20);
    add_nodeint(&list, 10);
    // ...

    // Print the original list
    printf("Original list: ");
    print_list(list);

    // Call the insertion_sort_list function
    sorted = insertion_sort_list(&list);

    // Print the sorted list
    printf("Sorted list: ");
    print_list(sorted);

    return 0;
}

