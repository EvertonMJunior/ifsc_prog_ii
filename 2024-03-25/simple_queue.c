#include <stdio.h>
#include <stdlib.h>

// a queue is a FIFO data structure

typedef struct node
{
    int value;
    struct node *next;
} Node;

void queue_insert(Node **queue, int value)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Erro ao alocar memória");
        return;
    }
    newNode->value = value;
    newNode->next = NULL;

    if (*queue == NULL)
    {
        *queue = newNode;
    }
    else
    {
        Node *aux = *queue;

        while (aux->next)
        {
            aux = aux->next;
        }
        aux->next = newNode;
    }
}

int queue_remove(Node **queue)
{
    Node *nodeToRemove = NULL;
    int removedValue = NULL;

    if (!*queue)
    {
        printf("Fila vazia\n");
        return removedValue;
    }
    nodeToRemove = *queue;
    *queue = nodeToRemove->next;
    removedValue = nodeToRemove->value;

    free(nodeToRemove);

    return removedValue;
}

void queue_print(Node *queue)
{
    printf("QUEUE: ");
    while (queue)
    {
        printf("%d ", queue->value);
        queue = queue->next;
    }
    printf("\n");
}

int main()
{
    Node *queue = NULL;
    int removedValue = NULL;

    removedValue = queue_remove(&queue);
    if (removedValue)
    {
        printf("Removido: %d\n", removedValue);
    }

    queue_insert(&queue, 1);
    queue_insert(&queue, 2);
    queue_insert(&queue, 3);
    queue_insert(&queue, 4);
    queue_insert(&queue, 5);

    queue_print(queue);

    removedValue = queue_remove(&queue);
    if (removedValue)
    {
        printf("Removido: %d\n", removedValue);
    }
    queue_print(queue);

    queue_insert(&queue, 1);
    queue_print(queue);

    return 0;
}