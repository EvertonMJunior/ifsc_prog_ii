#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} Node;

typedef struct stack
{
    Node *top;
} Stack;

Stack *stack_create()
{
    Stack *stack = malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

Stack *stack_push(Stack *stack, int value)
{
    Node *newTop = malloc(sizeof(Node));
    newTop->value = value;
    newTop->next = stack->top;
    stack->top = newTop;

    return stack;
}

Node *stack_pop(Stack *stack){
    if(!stack->top){
        return NULL;
    }

    Node *removedNode = stack->top;
    stack->top = removedNode->next;

    return removedNode;
}

void stack_print(Stack *stack)
{
    if (!stack->top)
    {
        printf("Pilha vazia.");
    }

    Node *nextNode = stack->top;

    while (nextNode != NULL)
    {
        printf("%d\n", nextNode->value);
        nextNode = nextNode->next;
    }
}

int main()
{
    Stack *stack = stack_create();
    stack = stack_push(stack, 123);
    stack = stack_push(stack, 456);
    stack = stack_push(stack, 789);
    stack_print(stack);
    
    free(stack_pop(stack));
    free(stack_pop(stack));
    free(stack_pop(stack));
    stack_print(stack);

    return 0;
}