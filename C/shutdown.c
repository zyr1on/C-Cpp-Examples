#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    char time[5]; printf("Seconds to shutdown: ");scanf("%s",time);
    printf("%d Minutes to shutdown \n",(atoi(time) / 60));
    char shutDownStr[] = "shutdown -s -f -t ";
    strcat(shutDownStr,time);
    system(shutDownStr);
    getchar();

    return 0;
}
