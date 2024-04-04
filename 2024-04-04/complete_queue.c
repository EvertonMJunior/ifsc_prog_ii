#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} Node;

typedef struct queue
{
    Node *first;
    Node *last;
} Queue;

Queue *queue_create()
{
    Queue *queue = malloc(sizeof(Queue));
    if (queue == NULL)
    {
        return NULL;
    }
    queue->first = NULL;
    queue->last = NULL;
}

void queue_insert(Queue *queue, int value)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Erro ao alocar memória");
        return;
    }
    newNode->value = value;
    newNode->next = NULL;

    if (queue->first == NULL)
    {
        queue->first = newNode;
        queue->last = newNode;
    }
    else
    {
        queue->last->next = newNode;
        queue->last = newNode;
    }
}

int queue_remove(Queue *queue)
{
    Node *nodeToRemove = NULL;
    int removedValue = NULL;

    if (!queue->first)
    {
        printf("Fila vazia\n");
        return removedValue;
    }
    nodeToRemove = queue->first;
    queue->first = nodeToRemove->next;
    removedValue = nodeToRemove->value;

    free(nodeToRemove);

    return removedValue;
}

void queue_print(Queue *queue)
{
    Node *aux = queue->first;
    printf("QUEUE: ");
    while (aux)
    {
        printf("%d ", aux->value);
        aux = aux->next;
    }
    printf("\n");
}

int main()
{
    Queue *queue = queue_create();
    int removedValue;

    queue_insert(queue, 1);
    queue_insert(queue, 2);
    queue_insert(queue, 3);
    queue_insert(queue, 4);
    queue_insert(queue, 5);

    queue_print(queue);

    removedValue = queue_remove(queue);
    if (removedValue)
    {
        printf("Removido: %d\n", removedValue);
    }
    queue_print(queue);

    queue_insert(queue, 1);
    queue_print(queue);

    return 0;
}