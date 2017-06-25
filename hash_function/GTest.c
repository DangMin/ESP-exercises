#include <gtest/gtest.h>
#include "hash.h"
#include <stdlib.h>

TEST(GetHash, EmptyString) {
	char s[10] = "";
	int hash_key = hash(s);

	ASSERT_EQ(0, hash_key);
}

TEST(GetHash, String) {
	char s[100] = "monkey";
	ASSERT_EQ(550, hash(s));
}

TEST(AddToHashTable, Empty) {
	char s[100] = "";
	char *table[1024];

	int num = add_to_hash_table(table, s);
	ASSERT_EQ(0, num);
}

TEST(AddToHashTable, String) {
	char s[100] = "monkey";
	char *table[1024];

	int num = add_to_hash_table(table, s);
	ASSERT_EQ(550, num);
	ASSERT_STREQ("monkey", table[num]);	
}

TEST(AddToHashTable, DuplicateString) {
	char d[100] = "holla";
	char *tab[1024];

	int num = add_to_hash_table(tab, d);
	//ASSERT_EQ(550, num);
	ASSERT_STREQ("holla", tab[num]);

	num = add_to_hash_table(tab, d);
	ASSERT_EQ(0, num);
}