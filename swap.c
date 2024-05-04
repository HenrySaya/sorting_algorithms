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