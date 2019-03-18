#ifndef __FUNCTION_H__
#define __FUNCTION_H__

typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

void create_tree(Node **root, int n);
void print_tree(Node *root);
void destroyTree(Node *root);
void preorder(Node *root);
void inorder(Node *root);
void postorder(Node *root);
#endif