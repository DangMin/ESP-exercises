#include <gtest/gtest.h>
#include "bd_linked_list.h"
#include <stdlib.h>

TEST(AddToLinkedList, Add_none_to_list) {
	struct bd_linked_list *head = (bd_linked_list*)malloc(sizeof(bd_linked_list));
	head->data = NULL;
	head->index = 0;
	head->next = NULL;

	char f[10] = "\0";
	int num = add_to_list(head, f);
	ASSERT_EQ(-1, num);
}

TEST(AddToLinkedList, Add_3_to_list) {
	struct bd_linked_list *head = (bd_linked_list*)malloc(sizeof(bd_linked_list));
	head->data = NULL;
	head->index = 0;
	head->next = NULL;

	char f[100] = "first", s[100] = "second", t[100] = "third";
	int num = add_to_list(head, f);
	ASSERT_EQ(0, num);
	ASSERT_STREQ("first", head->data);

	num = add_to_list(head, s);
	ASSERT_EQ(1, num);
	ASSERT_STREQ("second", head->next->data);
	ASSERT_EQ(head, head->next->prev);

	num = add_to_list(head, t);
	ASSERT_EQ(2, num);
	ASSERT_STREQ("third", head->next->next->data);
	ASSERT_EQ(head->next, head->next->next->prev);
}

TEST(DisplayList, Display_empty) {
	struct bd_linked_list *head = (bd_linked_list*)malloc(sizeof(bd_linked_list));
	head->data = NULL;
	head->index = 0;
	head->next = 0;

	ASSERT_EQ(1, display_list(head));
}

TEST(DisplayList, Display_non_empty_list) {
	struct bd_linked_list *head = (bd_linked_list*)malloc(sizeof(bd_linked_list));
	head->data = NULL;
	head->index = 0;
	head->next = NULL;

	char f[100] = "first", s[100] = "second", t[100] = "third";
	int num = add_to_list(head, f);
	num = add_to_list(head, s);
	num = add_to_list(head, t);

	ASSERT_EQ(3, display_list(head));
	ASSERT_STREQ("first", head->data);
	ASSERT_STREQ("second", head->next->data);
	ASSERT_STREQ("third", head->next->next->data);
}

/*TEST(DisplayItem, Display_non_exists) {
	struct bd_linked_list *head = (bd_linked_list*)malloc(sizeof(bd_linked_list));
	head->data = NULL;
	head->index = 0;
	head->next = NULL;

	ASSERT_EQ(-1, display_item(head->next));
	ASSERT_EQ(-1, display_item(head->next->next));
}*/

TEST(DisplayItem, Display_exist) {
	struct bd_linked_list *head = (bd_linked_list*)malloc(sizeof(bd_linked_list));
	head->data = NULL;
	head->index = 0;
	head->next = NULL;

	char f[100] = "first", s[100] = "second", t[100] = "third";
	int num = add_to_list(head, f);
	num = add_to_list(head, s);
	num = add_to_list(head, t);

	ASSERT_EQ(0, display_item(head));
	ASSERT_EQ(0, display_item(head->next->next));
	ASSERT_STREQ("first", head->data);
	ASSERT_STREQ("second", head->next->data);
	ASSERT_STREQ("third", head->next->next->data);
}

TEST(SearchFromList, NonExist) {
	struct bd_linked_list *head = (bd_linked_list*)malloc(sizeof(bd_linked_list));
	head->data = NULL;
	head->index = 0;
	head->next = NULL;
	struct bd_linked_list *target;

	char f[100] = "first", s[100] = "second", t[100] = "third";
	int num = add_to_list(head, f);
	num = add_to_list(head, s);


	target = search_from_list(head, t);
	ASSERT_EQ(NULL, target);
}

TEST(SearchFromList, Exist) {
	struct bd_linked_list *head = (bd_linked_list*)malloc(sizeof(bd_linked_list)), *target;
	head->data = NULL;
	head->index = 0;
	head->next = NULL;

	char f[100] = "first", s[100] = "second", t[100] = "third";
	int num = add_to_list(head, f);
	num = add_to_list(head, s);
	num = add_to_list(head, t);

	target = search_from_list(head, s);
	ASSERT_EQ(head->next, target);
	ASSERT_EQ(head, target->prev);
	ASSERT_EQ(head->next->next, target->next);
	ASSERT_STREQ(s, target->data);
}

TEST(DeleteFromList, Non_exist) {
	struct bd_linked_list *head = (bd_linked_list*)malloc(sizeof(bd_linked_list)), *target;
	head->data = NULL;
	head->index = 0;
	head->next = NULL;

	char f[100] = "first", s[100] = "second", t[100] = "third";
	int num = add_to_list(head, f);
	num = add_to_list(head, s);
	num = add_to_list(head, t);

	num = delete_from_list(head, 5);
	ASSERT_EQ(-1, num);
}

TEST(DeleteFromList, Exist) {
	struct bd_linked_list *head = (bd_linked_list*)malloc(sizeof(bd_linked_list)), *target;
	head->data = NULL;
	head->index = 0;
	head->next = NULL;

	char f[100] = "first", s[100] = "second", t[100] = "third";
	int num = add_to_list(head, f);
	num = add_to_list(head, s);
	num = add_to_list(head, t);

	num = delete_from_list(head, 2);
	ASSERT_EQ(2, num);
	ASSERT_EQ(1, head->next->index);
}