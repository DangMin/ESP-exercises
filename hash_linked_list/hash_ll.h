typedef struct hash_element hash_element;

struct hash_element {
	char *data;
    int repeat;
    hash_element *next;
};

int hash(char *key);

void print_hash_table(hash_element *table[]);

int add_to_hash_table(hash_element *hash_table[], char *key);