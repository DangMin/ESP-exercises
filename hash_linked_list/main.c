#include <stdio.h>
#include <stdlib.h>
#include "hash_ll.h"

int main() {
	struct hash_element *table[1024];
	char s[100] = "monkey";

	for(int i = 0; i < 1024; ++i) {
		table[i] = (hash_element *)malloc(sizeof(hash_element));
		table[i]->data = NULL;
		table[i]->next = NULL;
	}


	printf("print to hash table\n");
	int num = add_to_hash_table(table, s);
	printf("%d\n", num);
	//printf("%s\n", table[num]);

	num = add_to_hash_table(table, "mnokey");
	printf("%d\n", num);

	num = add_to_hash_table(table, "mnoeyk");
	printf("%d\n", num);

	num = add_to_hash_table(table, "mkeyon");
	printf("%d\n", num);

	num = add_to_hash_table(table, "monkey");
	num = add_to_hash_table(table, "money");
	num = add_to_hash_table(table, "dedicated");
	printf("%d\n", num);

	print_hash_table(table);
}