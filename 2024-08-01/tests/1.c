#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

typedef struct node
{
    int value;
    struct node *left, *right;
} Node;

void check_malloc(void *pointer)
{
    if (pointer == NULL)
    {
        printf("There was an error while allocating memory. Please try again.\n");
        exit(1);
    }
}

Node *create_node(int value)
{
    // malloc returns a void, so casting is necessary
    Node *node = malloc(sizeof(Node));
    check_malloc(node);

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node *insert(Node *node, int value)
{
    if (node == NULL)
    {
        return create_node(value);
    }

    Node **queue = malloc(100 * sizeof(Node *));
    check_malloc(queue);
    int front = 0;
    int rear = 0;

    queue[rear++] = node;

    // Breadth-first search (BFS)
    while (front < rear)
    {
        Node *temp = queue[front++];
        if (temp->left != NULL)
        {
            queue[rear++] = temp->left;
        }
        else
        {
            temp->left = create_node(value);
            free(queue);
            return node;
        }

        if (temp->right != NULL)
        {
            queue[rear++] = temp->right;
        }
        else
        {
            temp->right = create_node(value);
            free(queue);
            return node;
        }
    }
}

Node *copy_tree(Node *root)
{
    if (root == NULL)
        return NULL;

    Node *new_root = create_node(root->value);
    new_root->left = copy_tree(root->left);
    new_root->right = copy_tree(root->right);

    return new_root;
}

Node *mirror_tree(Node *root)
{
    if (root == NULL)
        return NULL;

    Node *new_root = create_node(root->value);
    new_root->left = mirror_tree(root->right);
    new_root->right = mirror_tree(root->left);

    return new_root;
}

Node *biggest_value_node(Node *root)
{
    if (root == NULL)
        return NULL;

    Node *biggest = root;
    Node *left = biggest_value_node(root->left);
    Node *right = biggest_value_node(root->right);

    if (left != NULL && left->value > biggest->value)
    {
        biggest = left;
    }

    if (right != NULL && right->value > biggest->value)
    {
        biggest = right;
    }

    return biggest;
}

Node *lowest_value_node(Node *root)
{
    if (root == NULL)
        return NULL;

    Node *lowest = root;
    Node *left = lowest_value_node(root->left);
    Node *right = lowest_value_node(root->right);

    if (left != NULL && left->value < lowest->value)
    {
        lowest = left;
    }

    if (right != NULL && right->value < lowest->value)
    {
        lowest = right;
    }

    return lowest;
}

int check_trees_equality(Node *root1, Node *root2)
{
    if(root1 == NULL && root2 == NULL) {
        return 1;
    }

    if(root1 == NULL || root2 == NULL) {
        return 0;
    }

    return (root1->value == root2->value) && check_trees_equality(root1->left, root2->left) && check_trees_equality(root1->right, root2->right);
}

void remove_even_nodes(Node *root)
{
    if (root == NULL)
        return;

    if (root->left != NULL && root->left->value % 2 == 0)
    {
        root->left = NULL;
    }

    if (root->right != NULL && root->right->value % 2 == 0)
    {
        root->right = NULL;
    }

    remove_even_nodes(root->left);
    remove_even_nodes(root->right);
}


void print2DUtil(Node *root, int space)
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
    printf("%d ", root->value);
    printf("\n");

    // Process left child
    print2DUtil(root->left, space);
}

void print2D(Node *root)
{
    printf("\n------------------------------------------");
    // Pass initial space count as 0
    print2DUtil(root, 0);
    printf("\n\n------------------------------------------");
}

int main()
{
    printf("\n\n");

    Node *root = create_node(1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 6);
    insert(root, 7);
    insert(root, 8);
    insert(root, 9);
    insert(root, 10);
    insert(root, 11);
    insert(root, 12);
    insert(root, 13);
    insert(root, 14);
    insert(root, 15);

    Node *copy = copy_tree(root);
    insert(copy, 16);
    insert(copy, 17);

    Node *mirror = mirror_tree(root);

    printf("\n\nRoot tree");
    print2D(root);
    printf("\n\nCopy tree");
    print2D(copy);
    printf("\n\nMirror tree");
    print2D(mirror);

    printf("\n\nBiggest value in tree: %d\n", biggest_value_node(root)->value);
    printf("Lowest value in tree: %d\n", lowest_value_node(root)->value);

    Node *copy2 = copy_tree(root);
    printf("\n\nTrees are %s\n", check_trees_equality(root, copy2) ? "equal" : "not equal");

    remove_even_nodes(copy2);
    printf("\n\nRoot tree after removing even nodes");
    print2D(copy2);

    return 0;
}