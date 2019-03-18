#include<stdio.h>
#include<stdlib.h>
#include"function.h"


void create_tree(Node **root, int n){
    int i;
    for( i=0; i<n; i++){
        Node *add;
        add = (Node*)malloc(sizeof(Node));
        add->left=NULL;
        add->right=NULL;
        scanf("%d", &add->data);
        
        if((*root)==NULL){
            (*root) = add;
        }
        else{
            Node *temp = *root;
            while(1){
                if(add->data<temp->data){
                    if(temp->left==NULL){
                        temp->left = add;
                        break;
                    }
                    else
                        temp = temp->left;
                }
                else if(add->data>temp->data){
                    if(temp->right==NULL){
                        temp->right = add;
                        break;
                    }
                    else
                        temp = temp->right;
                }
                else
                    break;
            }
        }
        
    }
    return;
}

void print_tree(Node *root){
    printf("preorder:");
    preorder(root);
    printf("\n");

    printf("inorder:");
    inorder(root);
    printf("\n");

    printf("postorder:");
    postorder(root);
    printf("\n");
}

void preorder(Node *root){
    if(root!=NULL){
        printf(" %d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        printf(" %d", root->data);
        inorder(root->right);
    }
}
void postorder(Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf(" %d", root->data);
    }
}