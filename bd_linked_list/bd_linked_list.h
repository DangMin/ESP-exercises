typedef struct bd_linked_list bd_linked_list;

struct bd_linked_list {
	char *data;
	int index;
	struct bd_linked_list *next;
	struct bd_linked_list *prev;
};

int add_to_list(bd_linked_list *ll, char *s);

int display_item(bd_linked_list *ll);

int display_list(bd_linked_list *ll);

bd_linked_list * search_from_list(bd_linked_list *ll, char *s);

int delete_from_list(bd_linked_list *ll, int index);

// Additional
int empty_list(bd_linked_list *ll);

bd_linked_list * swap_items(bd_linked_list *f, bd_linked_list *s);

int sort_list(bd_linked_list *ll);