#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end){
    static int pre=0;
    
    if(inorder_start>inorder_end)   return NULL;

    Node *root = (Node*)malloc(sizeof(Node));
    root->data = preorder[pre++];
    root->left = NULL;
    root->right = NULL;

    if(inorder_start==inorder_end)  return root;

    int idx;
    for(idx=inorder_start; idx<=inorder_end; idx++)
        if(root->data==inorder[idx])    break;
    
    root->left = buildTree(inorder, preorder, inorder_start, idx-1);
    root->right = buildTree(inorder, preorder, idx+1, inorder_end);
    return root;
}
void showPostorder(Node* root){
    if(root!=NULL){
        showPostorder(root->left);
        showPostorder(root->right);
        printf("%d ", root->data);
    }
}

