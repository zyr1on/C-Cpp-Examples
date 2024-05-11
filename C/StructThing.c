#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char* data; //unknown length of string, need to allocate that;
	int length;
}String;

String* init(char* source) {
	String* str = malloc(sizeof(String));
	str->length = strlen(source);
	str->data = malloc(sizeof(char) * str->length);
	strcpy(str->data,source);
	return str;
}
typedef String* string;
int main(int argc, char const *argv[]) {
	string str = init("hello world");
	printf("%s\n",str->data);
	free(str);
}

