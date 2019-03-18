#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node* createList(){
    int n;
    scanf("%d", &n);
    if(n==-1)   return NULL;

    Node* head = (Node*)malloc(sizeof(Node));
    head->data = n;
    head->next = NULL;

    Node* cur = head;

    Node* temp;
    while(1){
        temp = (Node*)malloc(sizeof(Node));
        scanf("%d", &n);
        if(n==-1)   break;
        temp->data = n;
        temp->next = NULL;
        cur->next = temp;
        cur = cur->next;        
    }
    return head;
}

Node* reverse(Node *head){
    if(head->next==NULL)    return head;
    Node *prev, *cur, *next;
    prev = NULL;
    cur = head;
    next = head->next;

    while(next != NULL){
        cur->next = prev;
        prev = cur;
        cur = next;
        next = next->next;
    }
    cur->next = prev;

    return cur;
}