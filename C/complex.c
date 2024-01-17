#include <stdio.h>
#include <string.h>


typedef struct {
	float real;
	float im;
} complex;

complex operation(char type[],complex c1,complex c2) { 
    complex result = {0,0};
	if(strcmp("+",type) == 0 ||strcmp("sum",type) == 0) {
		result.real = c1.real + c2.real;
		result.im = c1.im + c2.im;
	}
	else if(strcmp("-",type) == 0 ||strcmp("sub",type) == 0) {
		result.real = c1.real - c2.real;
		result.im = c1.im - c2.im;
	}
	else if(strcmp("/",type) == 0 ||strcmp("divide",type) == 0) {
		result.real = (c1.real*c2.real + c1.im *c2.im) / (c2.real*c2.real + c2.im * c2.im);
		result.im = (c1.im * c2.real - c1.real*c2.im) / (c2.real*c2.real + c2.im * c2.im);
	}
	else if(strcmp("multiply",type) == 0 ||strcmp("*",type) == 0) {
		result.real = c1.real*c2.real - c1.im *c2.im;
		result.im = c1.real*c2.im + c1.im * c2.real;
	}
	else
		printf("Operations are sum,+ | sub,- | div,/ | multi,* \n");
	return result;
}
main() {
	complex c1 = {3,-1};
	complex c2 = {2,-2};
	complex example = operation("*",c1,c2);
	printf("%.1fi + %.1fj\n",example.real,example.im);
	return 0;
}
