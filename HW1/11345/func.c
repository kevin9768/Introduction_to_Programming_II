#include <stdio.h>
#include <stdlib.h>
#include "function.h"


void delete_node(man* man){
    man->prev->next = man->next;
    man->next->prev = man->prev;
    free(man);
    return;
}

man* createList(int n){
    
    int i;
    man* curr;
    head = (man*)malloc(sizeof(man));
    curr = head;
    curr->id = 1;
    for(i=2; i<=n; i++){
        curr->next = (man*)malloc(sizeof(man));
        curr->next->prev = curr;
        curr = curr->next;
        curr->id = i;
    }
    curr->next = head;
    head->prev = curr;

    return head;
}


int solveJosephus(int step){
    man *cur = head;
    while(cur->next!=cur){
        int i;
        for(i=0; i<step-1; i++)
            cur = cur->next;
        cur = cur->prev;
        delete_node(cur->next);
        if(cur->next==cur)  break;
        for(i=0; i<step-1; i++)
            cur = cur->prev;
        cur = cur->next;
        delete_node(cur->prev);
    }
    return cur->id;
}