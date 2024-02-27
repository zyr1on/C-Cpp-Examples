#include <stdio.h>
int _strlen(char *str) { // _strlen(string) returns length of string
	int count = 0;
	while(str[count] != '\0') // \0 NULL terminator, refers to nothing
		count++;
	return count;
}
int _strcmp(char *_source,char *_target) { // if(_strcmp(string,string)) If the same, the 'if' block returns true(1) if not, returns false(0)
	if(_strlen(_source) != _strlen(_target))
		return 0;
	else {
		int i = 0;
		while(i < _strlen(_source))
			if(_source[i] == _target[i])
				i++;
		if(i == _strlen(_source))
			return 1;
		else
			return 0;
	}
}
// The scanf function is actually unsafe, but that's beside the point.

void readInt(int *val) {
	scanf("%d",val);
}
void readChar(char *c) {
	scanf("%c",c);
}
void readStr(char * str) {
	fgets(str,sizeof(str),stdin);
	// If you declare the string as 'char *' it probably won't work (cause:size of string)
}
