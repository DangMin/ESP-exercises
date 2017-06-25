#include "bd_linked_list.h"
#include <stdlib.h>
#include <stdio.h>

int add_to_list(bd_linked_list *ll, char *s) {
	int index = 0;

	if (*s != '\0' && ll->data == NULL) {
		ll->data = s;
		return ll->index;
	}

	struct bd_linked_list *item = ll;
	struct bd_linked_list *node = (bd_linked_list*)malloc(sizeof(bd_linked_list));

	if (*s == '\0' || node == NULL)
		return -1;

	while (item) {
		index = (item->index > index) ? item->index : index;
		if (!item->next) break;
		item = item->next;
	}

	node->data = s;
	node->prev = item;
	node->index = ++index;
	node->next = NULL;

	item->next = node;

	return node->index;
}

int display_item(bd_linked_list *ll) {
	if (ll) {
		printf("Item %d: %s\n", ll->index, ll->data);
		return 0;
	}

	return -1;
}

int display_list(bd_linked_list *ll) {
	int cnt = 0;
	bd_linked_list *item = ll;
	while (item) {
		printf("Index %d: %s\n", item->index, item->data);
		++cnt;
		item = item->next;
	}

	return cnt;
}

bd_linked_list * search_from_list(bd_linked_list *ll, char *s) {
	bd_linked_list *item = ll;
	while (item) {
		if (item->data == s) return item;
		item = item->next;
	}

	return NULL;
}

int delete_from_list(bd_linked_list *ll, int index) {
	bd_linked_list *item = ll, *next = (bd_linked_list *)malloc(sizeof(bd_linked_list)), *prev;
	while (item) {
		if (item->index == index) {
			prev = item->prev;
			prev->next = item->next;

			next = item->next;
			next->prev = prev;

			return display_list(ll);
		}
		item = item->next;
	}

	return -1;
}
