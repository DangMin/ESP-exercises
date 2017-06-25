#include <stdio.h>
#include "hash.h"

int main() {
	char s[100] = "monkey";
	char *table[1024];

	int num = add_to_hash_table(table, s);
}