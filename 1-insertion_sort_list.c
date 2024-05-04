#include "sort.h"

/*
 * swap - swaps two nodes
 * 
 * @h: head of the list
 * @a: first node
 * @b: second node
 * Return: void
*/

void swap(listint_t **h, listint_t **a, listint_t *b)
{
    (*a)->next = b->next;
    if (b->next != NULL)
        b->next->prev = *a;
    b->prev = (*a)->prev;
    b->next = (*a);
    if ((*a)->prev != NULL)
        (*a)->prev->next = b;
    else
        *h = b;
    (*a)->prev = b;
    *a = b->prev;
}

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