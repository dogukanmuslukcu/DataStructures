#include <iostream>
#include <stdlib.h>
#include "Stack_ll.h"
using namespace std;
int pop(node* r)
{
	if (r == NULL) 
	{
		return -1;
	}
	else if (r->next == NULL) 
	{
		
		int rValue = r->x;
		
		free(r);
		return rValue;
	}
	node* iter = r;
	while (iter->next->next != NULL)
	{
		iter = iter->next;
	}
	node* temp = iter->next;
	int rValue = temp->x;
	free(temp);
	iter->next = NULL;
	return rValue;
}
node* push(node* r, int x)
{

	if (r == NULL)
	{
		r = (node*)malloc(sizeof(node));
		r->next = NULL;
		r->x = x;
		return r;
	}
	node* iter = r;
	while (iter->next != NULL)
	{
		iter = iter->next;
	}
	iter->next = (node*)malloc(sizeof(node));
	iter->next->x = x;
	iter->next->next = NULL;
	return r;

}
void readStack(node *r)
{
	if (r == NULL)
	{
		cout << "Stack is null" << endl;
	}
	while (r != NULL)
	{
		cout <<  " -> " << r->x << endl;
		r = r->next;
	}
	cout << endl;
}


