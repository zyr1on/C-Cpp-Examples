#include <stdio.h>
int _strlen(char *str) { // _strlen(string) returns length of string
	int count = 0;
	while(str[count] != '\0')
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