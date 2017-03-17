#define STACK_SIZE 100
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef struct Stack
{
    void *data;
    int top ;
    int elemsize;
}Stack;

Stack init(int size)
{
    Stack stack ;
    stack.top = 0;
    stack.data = (void *)malloc(size*STACK_SIZE*sizeof(void *));
    stack.elemsize = size;
    return stack;
}

void push(Stack *stack,void * newdata,int size)
{
    assert(size % stack->elemsize == 0);
    for (int i = 0 ; i < size / stack->elemsize ; i++){
        memcpy(stack->data + stack->top * stack->elemsize , newdata + i * stack->elemsize , stack->elemsize);
        stack->top ++;
    }
}

void *pop(Stack *stack)
{   
    assert(stack->top != 0);
    if (stack->top != 0)
    {
        stack->top --;
    }
    return stack->data + stack->top * stack->elemsize;
}

int getlen(Stack stack)
{
    return stack.top;
}