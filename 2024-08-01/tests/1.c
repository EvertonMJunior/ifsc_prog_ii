#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

typedef struct node
{
    char value;
    struct node *left, *right;
} Node;

void check_malloc(void* pointer){
    if(pointer == NULL){
        printf("There was an error while allocating memory. Please try again.\n");
        exit(1);
    }
}

Node* create_node(char value) {
    // malloc returns a void, so casting is necessary
    Node* node = malloc(sizeof(Node));
    check_malloc(node);

    node->value=value;
    node->left=NULL;
    node->right=NULL;

    return node;
}

Node* insert(Node *node, char value) {
    if(node == NULL) {
        return create_node(value);
    }

    Node** queue = malloc(100*sizeof(Node*));
    check_malloc(queue);
    int front = 0;
    int rear = 0;

    queue[rear++] = node;

    // Breadth-first search (BFS)
    while(front < rear) {
        Node* temp = queue[front++];
        if(temp->left != NULL) {
            queue[rear++] = temp->left;
        } else {
            temp->left = create_node(value);
            free(queue);
            return node;
        }

        if(temp->right != NULL) {
            queue[rear++] = temp->right;
        } else {
            temp->right = create_node(value);
            free(queue);
            return node;
        }
    }
}

void print2DUtil(Node* root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%c ", root->value);
    printf("\n");
 
    // Process left child
    print2DUtil(root->left, space);
}
 
void print2D(Node* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

int main(){
    printf("\n\n");

    Node* root = create_node('a');
    insert(root, 'b');
    insert(root, 'c');
    insert(root, 'd');
    insert(root, 'e');
    insert(root, 'f');
    insert(root, 'g');
    insert(root, 'h');
    insert(root, 'i');
    insert(root, 'j');
    insert(root, 'k');
    insert(root, 'l');
    insert(root, 'm');
    insert(root, 'n');
    insert(root, 'o');
    print2D(root);

    printf("\n\n");

    return 0;
}