#include "hash_ll.h"
#include <gtest/gtest.h>

TEST(AddToHashTableWithLinkedList, Empty) {
	char s[] = "sdkfj", d[] = "skdfjl", k[] = "adkfaj";
	struct hash_element *table[1024];
	int num;

	num = add_to_hash_table(table, s);
	ASSERT_STREQ(s, table[num]);
}