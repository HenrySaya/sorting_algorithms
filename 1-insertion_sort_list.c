#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending order
 * 
 * @list: list to be printed
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *current, *new, *tmp;

    if (!list || !*list || !(*list)->next)
        return;
    
    for (current = (*list)->next; current; current = tmp)
    {
        tmp = current->next;
        new = current->prev;
        while (new && current->n < new->n)
        {
            swap(list, &new, current);
            print_list(*list);
        }
    }
}
