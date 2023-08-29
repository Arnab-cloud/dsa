#include <stdio.h>
#include <stdlib.h>

struct node
{
	int val;
	struct node* next;
}typedef node;

void printList(node** head)
{
	node* temp = *head;
	while(temp)
	{
		printf("%d--> ", temp->val);
		temp = temp->next;
	}
	printf("NULL\n");
}


node* createNode(int val)
{
	node* new = (node*)malloc(sizeof(node));
	new->val = val;
	new->next = NULL;
	return new;
}

void insertEnd(node** head, int val)
{
	if(!(*head))
	{
		*head = createNode(val);
		return;
	}
	node* temp = *head;
	while(temp->next)
		temp = temp->next;
	temp->next = createNode(val);
}

void reverseNode(node** head)
{
	node* pre = NULL, *temp = *head, *next;
	while(temp->next)
	{
		next = temp->next;
		temp->next = pre;
		pre = temp;
		temp = next;
	}
	temp->next = pre;
	*head = temp;
}

void deleteList(node* head)
{
	if(!head)
		return;
	else
		deleteList(head->next);
		free(head);
}

int main()
{
	node* head = createNode(1);
	for(int i=0; i<9; i++)
		insertEnd(&head,i+2);
	printf("Before reversing: \n");
	printList(&head);
	
	//printList(&head);
	reverseNode(&head);
	
	printf("After reversing: \n");
	printList(&head);
	deleteList(head);
	return 0;	
}
