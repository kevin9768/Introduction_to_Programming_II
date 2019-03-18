#include "function.h"
#include <stdio.h>
#include <stdlib.h>

void do_I(Node **head,size_t pos,unsigned short val){
    Node *in, *temp;
    int i;
    
    in = (Node*)malloc(sizeof(Node));
    in->val = val;
    in->next = NULL;
    
    if((*head)==NULL){
        *head = in;
        return;
    }
    if(pos==0){
        in->next = *head;
        *head = in;
        return;
    }

    temp = *head;
    for(i=0; i<pos-1; i++){
        if(temp->next==NULL){
            temp->next = in;
            return;
        }
        temp = temp->next;
    }
    in->next = temp->next;
    temp->next = in;
    return;
}
void do_E(Node **head, size_t begin_pos, size_t end_pos){
    if((*head)==NULL||begin_pos==end_pos)   return;

    int i;
    if(begin_pos==0){
        for(i=0; i<end_pos; i++){
            if((*head)==NULL)   return;
            *head = (*head)->next;
        }
        return;
    }

    Node *temp = *head;
    for(i=0; i<begin_pos; i++){
        if(temp->next==NULL)    return;
        temp = temp->next;
    }
    for(i=begin_pos; i<end_pos; i++){
        if(temp==NULL)  return;
    }
}

/*void do_E(Node **head, size_t begin_pos, size_t end_pos)
{
	int i, j;
	Node *temp1, *temp2, *p;
	temp1 = *head;
	if(*head == NULL)
		return;
	if(begin_pos == end_pos)
		return;
	if(begin_pos==0){
		p=*head;
		for(i=0; i<end_pos; i++){
			if(*head==NULL)
				return;
			temp2=p->next;
			*head=temp2;
			//free(p);
			p=temp2;
		}
		return;
	}
	for(i=0; i<begin_pos-1; i++){
		if(temp1->next==NULL)
			return;
		temp1=temp1->next;
	}
	p=temp1->next;
	for(j=begin_pos; j<end_pos; j++){
		if(p == NULL)
			return;
		temp2=p->next;
		free(p);
		temp1->next=temp2;
		p=temp2;
	}
	return;
}*/

void do_P(Node  *head,size_t pos){
    Node *temp = head;
    if(head==NULL)  return;
    int i;
    for(i=0; i<=pos; i++){
        if(i==pos){
            printf("%hd ", temp->val);
            break;
        }
        if(temp->next != NULL)
            temp = temp->next;
        else{
            printf("%hd ", temp->val);
            return;
        }
    }
    return;
}
void do_R(Node **head,unsigned short val){
    if(*head==NULL) return;

    while((*head)->val == val){
        *head = (*head)->next;
        if((*head)==NULL)   return;
    }

    Node *temp = *head;

    while(temp->next != NULL){
        if(temp->next->val == val){
            if(temp->next->next == NULL)
                temp->next = NULL;
            else
                temp->next = temp->next->next;
        }
        else
            temp = temp->next;
    }
    return;
}

void do_S(Node  *head){
    Node *temp = head;
    while(temp!=NULL){
        printf("%hd ", temp->val);
        temp = temp->next;
    }
    return;
}