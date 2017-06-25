#include "hash.h"
#include <stdio.h>

int hash(char *key) {
	int sum = 0;

	while (*key != '\0') {
		sum += *(key+1);
		++key;
	}

	return sum%1024;
}

void print_hash_table(char *table[]) {
	int i = 0;
	while(table[i]) {
		if (*table[i] != '\0') {
			printf("Element %d: %s", i+1, table[i]);
		}
		++i;
	}
}

int add_to_hash_table(char *table[], char *key) {
	int index = hash(key);
	if (index == 0) return 0;
	if (table[index] != key) {
		table[index] = key;
		return index;
	}

	printf("Collision alert\n");
	return 0;
}

/*

*/