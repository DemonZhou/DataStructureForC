#include<stdlib.h>
#include<string.h>
#include<assert.h>
#define BAG_SIZE 10000

typedef struct Bag
{
    void * data;
    int size;
    int elemsize;
}Bag;

Bag init(int size)
{
    Bag bag;
    bag.size = 0;
    bag.elemsize = size;
    bag.data = (void *)malloc(BAG_SIZE * size * sizeof(char));
    return bag;
}

void add(Bag* bag,void * newdata,int size)
{
    assert(size % bag->elemsize == 0);
    for(int i = 0;i < size / bag->elemsize;i++)
    {
        memcpy(bag->data + bag->size * bag->elemsize , newdata + i * bag->elemsize , bag->elemsize);
        bag->size ++;
    }
}

int isempty(Bag *bag)
{
    return bag->size > 0;
}

int getlen(Bag * bag)
{
    return bag->size;
}