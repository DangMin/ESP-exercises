#include "linked_list.h"
#include <stdlib.h>

int main() {
	struct linked_list *head = (linked_list*)malloc(sizeof(linked_list)), *target;
	head->data = NULL;
	head->index = 0;
	head->next = NULL;

	char f[100] = "first", s[100] = "second", t[100] = "third";
	int num = add_to_list(head, f);
	num = add_to_list(head, s);
	num = add_to_list(head, t);

	num = display_list(head);

	num = display_item(head->next->next);

	target = search_from_list(head, t);

	num = delete_from_list(head, 2);

	return 0;
}