#include "linked_list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int add_to_list(linked_list *ll, char *s) {
	struct linked_list *list = ll;

	if (*s == '\0') return -1;

	// If head data is NULL, set the input as head of linked list
	if (list->data == NULL) {
		list->data = s;
		return 0;
	}
	
	struct linked_list * item = (linked_list*)malloc(sizeof(linked_list));
	int index = 0;

	if (!item) {
		return -1;
	}

	item->data = s;
	item->next = NULL;

	while(list) {
		if (list->index > index) index = list->index;
		if (!list->next) break;

		list = list->next;
	}

	item->index = ++index;
	list->next = item;
	return item->index;
}

int display_list(linked_list *ll) {
	struct linked_list *list = ll;
	int cnt = 0;

	printf("Linked List:\n");

	if(!list) return 0;

	while(list) {
		printf("\tIndex %d: %s\n", list->index, list->data);
		++cnt;
		list = list->next;
	}

	return cnt;
}

int display_item(linked_list *ll) {
	if (ll) {
		printf("\tIndex %d: %s\n", ll->index, ll->data);
		return 1;
	}

	return 0;
}

linked_list * search_from_list(linked_list *ll, char *s) {
	struct linked_list *list = ll;
	while (list) {
		if (list->data == s) {
			return list;
		}

		list = list->next;
	}

	return NULL;
}

int delete_from_list(linked_list *ll, int index) {
	struct linked_list *list = ll, *prev = ll;
	while (list) {
		if (list->index == index) {
			prev->next = list->next;
			return display_list(ll);
		}
		prev = list;
		list = list->next;
	}

	return -1;
}
