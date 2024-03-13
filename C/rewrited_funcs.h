#include <stdio.h>

size_t _strlen(char *str) { // _strlen(string) returns length of string
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
char* toUpperCase(char* dst) { // char str[];
	if (dst == NULL) return NULL;
	while (*dst != '\0')
		if(*dst >= 'a' && *dst <= 'z')
			*dst++ = *dst - 32; //*dst++;
	return dst;
}
char* toLowerCase(char* dst) { // char str[];
	if(dst == NULL) return NULL;
	while (*dst != '\0')
		if(*dst >= 'A' && *dst <= 'Z')
			*dst++ = *dst + 32; //*dst++;
	return dst;
}
char* _strcpy(char* dst,const char* source) { // char str[];
	if(dst == NULL) return NULL;
	while(*source != '\0')
		*dst++ = *source++;
	*dst = '\0';
	return dst;
}
void* _memset(void *dst,int c, size_t len) {
	unsigned char* char_dst = dst;
	while (len--)
		*char_dst++ = c;
	return dst;
}
void* _memcpy(void *dst,void *src,size_t byte) { // copys src  to dst (byte one byte);
    if(dst == NULL) return NULL;
    unsigned char* buf1 = (char*) dst;
    unsigned char* buf2 = (char*) src;
    while(byte--)
        *buf1++ = *buf2++;
    return dst;
	// _memcpy(&struct,&struct1,sizeof(struct1));
	// _memcpy(array,array1,sizeof(array1));
	// _memcpy(string,string1,x);
}

char* _fgets(char* _string,size_t _bytes, FILE* _stream) {
    int c,i = 0;
    if(_bytes <= 0)
        return _string;
    
    while(i < _bytes -1 && ((c = getc(_stream)) != EOF)) {
        _string[i++] = c;
        if(c == '\n')
            break;
    }
    _string[i] = '\0';
    if(i > 0)
        return _string;
    else
        return NULL;
}
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
