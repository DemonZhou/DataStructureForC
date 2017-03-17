#include<stdio.h>
#include<stdlib.h>
#include "bag.h"

int main()
{
    Bag bag = init(sizeof(int));
    int t = 4;
    add(&bag,&t,sizeof(t));
    printf("%d\n",bag.size);
    printf("%d\n",*(int *)bag.data);
    t = 6;
    add(&bag,&t,sizeof(t));
    printf("%d\n",bag.size);
    printf("%d\n",*(int *)bag.data);
    printf("%d\n",*(int *)(bag.data + bag.elemsize));
    return 0;
}