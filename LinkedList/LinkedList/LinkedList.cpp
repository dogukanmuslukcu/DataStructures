#include <iostream>
#include <stdlib.h>
using namespace std;

struct n
{
	int x;
	n* next;
};
typedef n node;
void readNode(node* r)
{
	int i = 1;
	while (r != NULL)
	{
		cout << i << ". node's value : " << r->x << endl;
		i++;
		r = r->next;
	}
	cout << endl;
}
void addNode(node* r, int x)
{
	if (r == NULL) 
	{
		r = (node*)malloc(sizeof(node));
		r->next = NULL;
		r->x = x;
	}
	while (r->next!=NULL)
	{
		r = r->next;
	}
	r->next = (node*)malloc(sizeof(node));
	r->next->next = NULL;
	r->next->x = x;
}
node* removeNode(node* r, int x)
{
	node* iter = r;
	node* temp;
	if (r->x == x)
	{
		temp = r;
	    r = r->next;	
		free(temp);
		return r;
	}
	while (iter->next != NULL && iter->next->x != x)
	{
		iter = iter->next;
	}
	if (iter->next == NULL)
	{
		cout << "value not found in list" << endl;
		return r;
	}
	temp = iter->next;
	iter->next = iter->next->next;
	free(temp);
	return r;

}
node* sequentiallyAddNode(node* r, int x)
{
	if (r == NULL)
	{
		r = (node*)malloc(sizeof(node));
		r->next = NULL;
		r->x = x;
		return r;
	}
	else if (r->x > x)
	{
		node* temp = (node*)malloc(sizeof(node));
		temp->x = x;
		temp->next = r;
		r = temp;
		return temp;
	}
	node* iter = r;
	while (iter->next != NULL && iter->next->x < x)
	{
		iter = iter->next;
	}
	node* temp = (node*)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->x = x;
	return r;


}
int main()
{

	node* root;
	root = NULL;
	root = sequentiallyAddNode(root, 400);
	root = sequentiallyAddNode(root, 40);
	root = sequentiallyAddNode(root, 4);
	root = sequentiallyAddNode(root, 450);
	root = sequentiallyAddNode(root, 50);
	readNode(root);
	root = removeNode(root, 50);
	readNode(root);
	root = removeNode(root, 999);
	readNode(root);
	root = removeNode(root, 4);
	readNode(root);
	root = removeNode(root, 450);
	readNode(root);


}


