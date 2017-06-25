#include "string.h"
#include <stdlib.h>

int my_strlen(char *c) {
	int len = 0;

	while (*c != '\0') {
		++len;
		++c;
	}

	return len;
}

void mystrcpy(char *s, char *d) {
	while(*s) {
		*d = *s;
		++s; ++d;
	}
	*d = '\0';

	return;
}

int mystrcmp(char *s, char *d) {
	int cnt = 0;
	while(*s == *d && (*s || *d)) {
		++cnt;
		++s; ++d; 
	}

	if (*s == *d) return 0;

	return *s < *d ? cnt : -cnt;
}

int str2upper(char *s) {
	int cnt = 0;
	while (*s) {
		if (*s >= 97 && *s <= 122) {
			*s = *s - 32;
			++cnt;
		}
		++s;
	}

	return cnt;
}

int str2lower(char *s) {
	int cnt = 0;
	while (*s) {
		if (*s >= 65 && *s <= 90) {
			*s = *s + 32;
			++cnt;
		}

		++s;
	}

	return cnt;
}

int str_strip_numbers(unsigned char *s) {
	int i = 0;
	unsigned char *temp = s;
	while (*temp) {
		if (*temp >= 48 && *temp <= 57) {
			while (*(temp+i)) {
				*(temp+i) = (temp+i+1) ? *(temp+i+1) : '\0';
				++i;
			}
			i = 0;
		}else
			++temp;
	}

	return my_strlen((char*)s);
}

char * strdupl(char *s) {
	char *d = (char *)malloc(sizeof(char)*(my_strlen(s)+1));
	char *temp = d;
	while (*s) {
		*temp = *s;
		++s; ++temp;
	}
	*temp = '\0';

	return d;
}
