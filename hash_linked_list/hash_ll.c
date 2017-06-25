#include <stdlib.h>
#include <stdio.h>
#include "hash_ll.h"
#include <string.h>

int hash(char *key) {
	int sum = 0;
	char *c = key;

	while (*c != '\0') {
		sum += *(c+1);
		++c;
	}

	return sum%1024;
}

void print_hash_table(hash_element *table[]) {
	for (int i = 0; i < 1024; ++i) {
		if (table[i]->data != NULL) {
			struct hash_element *head = table[i];
			while(head) {
				printf("Element number %d: %s\n", i, head->data);
				head = head->next;
			}
		}
	}

}

int add_to_hash_table(hash_element *table[], char *key) {
	int index = hash(key);
	struct hash_element *list = table[index];
	struct hash_element *node = (hash_element *)malloc(sizeof(hash_element));

	if (*key == '\0')
		return -1;

	if (list->data == NULL) {
		list->data = key;
		return 0;
	}

	while (list) {
		if (strcmp(list->data, key) == 0){
			list->repeat += 1;
			return -1;
		}
		if (!list->next) break;
		list = list->next;
	}

	if (node == NULL)
		return -1;

	node->data = key;
	node->repeat = 0;
	node->next = NULL;

	list->next = node;

	return index;
}