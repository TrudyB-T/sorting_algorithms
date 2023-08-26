#include "deck.h"

/**
 *exchange - exchanges two nodes in a doubly-linked list
 *@a: pointer to first node
 *@b: pointer to second node
*/

void exchange(deck_node_t *a, deck_node_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}


/**
 * insertion_sort_list - insertion sorts a doubly-linked list
 * @list: pointer to head node
 *
 */

void insertion_sort_list(deck_node_t **list)
{
	deck_node_t *k, *l;

	if (list == NULL || !*list || !(*list)->next)
		return;
	k = (*list)->next;
	while (k)
	{
		l = k;
		k = k->next;
		while (l && l->prev)
		{
			if (compare_cards(l->prev->card, l->card))
			{
				exchange(l->prev, l);
				if (!l->prev)
					*list = l;
			}
			else
				l = l->prev;
		}

	}
}


/**
* sort_deck - sorts the deck by a given sort function
* @deck: pointer to the deck node head
*/

void sort_deck(deck_node_t **deck)
{
	insertion_sort_list(deck);
}


/**
* compare_cards - compares two cards and returns the correct order
* @a: pointer to first card
* @b: pointer to second card
*
* Return: true if a > b
*/

int compare_cards(const card_t *a, const card_t *b)
{
	char *s1, *s2, *values[] = {"King", "Queen", "Jack", "10", "9", "8",
		"7", "6", "5", "4", "3", "2", "Ace"};
	int val_a = 0, val_b = 0, i = 0;

	for (i = 0; i < 13; i++)
	{
		for (s1 = (char *)a->value, s2 = values[i]; *s1 && *s1 == *s2; ++s1, ++s2)
			;
		if (*s1 == 0 && *s2 == 0)
		{
			val_a = i;
			break;
		}
	}
	for (i = 0; i < 13; i++)
	{
		for (s1 = (char *)b->value, s2 = values[i]; *s1 && *s1 == *s2; ++s1, ++s2)
			;
		if (*s1 == 0 && *s2 == 0)
		{
			val_b = i;
			break;
		}
	}
	if (a->kind == b->kind)
		return (val_a < val_b);
	return (a->kind > b->kind);

}
