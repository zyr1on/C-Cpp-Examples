	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	typedef struct {
		char *chars; //unknown length of string, need to allocate that;
		int(*length)(struct String* string);
	}String;

	int length(String* string) {
		return strlen(string->chars);
	}
	String *initialize(int n) {
		String* str = malloc(sizeof(str));
		str->chars = malloc(sizeof(char) * n);
		str->length = length;
		str->chars[0] = '\0';
		return str;
	}
	int main(int argc, char const *argv[]) {
		String* str = initialize(10);
		strcpy(str->chars,"hello");
		printf("%d\n",str->length(str));
		free(str);
		return 0;
	}

