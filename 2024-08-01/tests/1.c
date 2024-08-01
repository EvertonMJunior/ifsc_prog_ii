#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

typedef struct node
{
    char value;
    struct node *left, *right;
} Node;

Node* create_node(char value) {
    Node* node = malloc(sizeof(Node));
    node->value=value;
    return node;
}

// Node* next_free_node(Node *node) {
//     if(node->left == NULL) return node->left;
//     if(node->right == NULL) return node->right;

//     return NULL;
// }

Node* insert(Node *node, char value) {
    if(node == NULL) {
        return create_node(value);
    }

    if(node->left == NULL){
        node->left = insert(node->left, value);
    } else if(node->right == NULL){
        node->right = insert(node->right, value);
    } else {
        insert(node->left, value);
    }

    return node;
}

void print_tree(Node *root) {
    if (root == NULL) return;
    
    print_tree(root->left);
    printf("%c ", root->value);
    print_tree(root->right);
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
 
// Wrapper over print2DUtil()
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
    print2D(root);

    printf("\n\n");

    return 0;
}