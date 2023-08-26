#include "sort.h"

/**
 * exchange  - exchanges the index of integer
 * @a : pointer to a list of integers
 * @head: list head
 * @a: The node
 * @b: The node
*Return: no return
*/

void exchange(listint_t *a, listint_t *b, listint_t **head)
{
	listint_t *xmp1 = NULL, *xmp2 = NULL;

	if (a == NULL || b == NULL)
		return;
	xmp1 = a->prev;
	xmp2 = b->next;
	/* if nodes are adjacent*/
	if (xmp1)
		xmp1->next = b;
	if (xmp2)
		xmp2->prev = a;
	a->next = xmp2;
	a->prev = b;
	b->next = a;
	b->prev = xmp1;
	if (xmp1 == NULL)
		*head = b;
}
/**
 * insertion_sort_list  - insertion_sort_list
 * @list: doubly liked list
 *
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *prev;
	int value;

	if (list == NULL || (*list)->next == NULL || (*list) == NULL)
	{
		return;
	}
	head = *list;
	while (head)
	{
		prev = head->prev;
				value = head->n;

		while (prev && prev->n > value)
		{
			exchange(prev, head, list);
			print_list(*list);
			prev = head->prev;
		}
		head = head->next;
	}
}
