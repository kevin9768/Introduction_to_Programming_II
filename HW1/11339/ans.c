#include <stdio.h>
#include <stdlib.h>
#include "function.h"


void do_I(Node **head, size_t pos, unsigned short val){
	Node *temp;
	Node *a;
	int i;
	a = (Node*)malloc(sizeof(Node));
	if(!(*head)){
		*head = a;
		a->val=val;
		a->next=NULL;
		return;
	}
	temp=*head;
	if(pos==0){
		a->next=*head;
		a->val=val;
		*head=a;
		return;
	}
	for(i=0; i<pos-1; i++){
		if(temp->next == NULL){
				temp->next=a;
				temp=temp->next;
				temp->val=val;
				temp->next=NULL;
				return;
		}else{
			temp=temp->next;
		}
	}
	a->next=temp->next;
	temp->next=a;
	a->val=val;
	return;
}
/*void do_E(Node **head, size_t begin_pos, size_t end_pos)
{
	size_t i;
	Node *pre, *cur, *t;
	cur = *head;
	//Find the node [begin_pos].
	for (i = 0; i < begin_pos; i++)
	{
		if (cur == NULL)
			return;
		pre = cur;
		cur = cur->next;
	}
	//cur is the node [begin_pos].
	//Erase region.
	for (i = begin_pos; i < end_pos; i++)
	{
		if (cur == NULL)
			return;
		t = cur;
		cur = cur->next;
		if (begin_pos != 0)
			pre->next = cur;
		else
			*head = cur;
		free(t);
	}
}*/
void do_E(Node **head, size_t begin_pos, size_t end_pos)
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
}
void do_P(Node  *head, size_t pos){
	Node *temp=head;
	int i;
	if(head==NULL)
		return;
	for(i=0; i<=pos; i++){
		if(i==pos){
			printf("%hd ", temp->val);
			break;
		}
		if(temp->next != NULL)
			temp=temp->next;
		else {
			printf("%hd ", temp->val);
			return;
		}
	}
}
/*void do_R(Node **head, unsigned short val){
	Node *pre = NULL, *t, *cur;
	cur = *head;
	while (cur != NULL)
	{
		if (cur->val == val)
		{
			t = cur;
			cur = cur->next;
			if (pre != NULL)
				pre->next = cur;
			else
				*head = cur;
			free(t);
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
}*/
void do_R(Node **head, unsigned short val){
	int i;
	Node *temp, *p;
	temp=*head;
	if (*head == NULL)
		return;
	while((*head)->val==val){
		(*head)=temp->next;
		temp=temp->next;
		if (*head == NULL)
			return;
	}
	while(temp->next!=NULL){
		if(temp->next->val == val){
			if(temp->next->next==NULL){
				temp->next=NULL;
			}else{
				temp->next=temp->next->next;
			}
		}else{
			temp=temp->next;
		}
	}
	return;
}
void do_S(Node  *head){
	Node *temp = head;
	while(temp != NULL){
		printf("%hd ", temp->val);
		temp=temp->next;
		
	}
	return;
}