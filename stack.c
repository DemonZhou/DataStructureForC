#include "stack.h"
#include <stdio.h>
#include <string.h>

int main()
{
    Stack stack = init(sizeof(char));
    char c = 'c';
    char str[10] = "hello";
    push(&stack,str,strlen(str));
    printf("%d\n",stack.top);
    int len = getlen(stack);
    for(int i = 0;i < len;i++)
    {
        printf("%c",*(char *)pop(&stack));
    }
    printf("\n");
    return 0;
}