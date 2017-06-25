#include <stdio.h>

int main () {
	char s[3][10] = {"akfs", "fskdf", "saklf"};

	for(int i = 0; i < 3; ++i) {
		printf("%s\n", s[i]);
	}
}