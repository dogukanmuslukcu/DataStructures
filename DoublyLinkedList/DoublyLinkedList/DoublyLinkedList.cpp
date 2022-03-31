#include <iostream>
#include <stdlib.h>
using namespace std;
struct n
{
	int x;
	n* next;
	n* prev;
};
typedef n node;
node* readForwardNode(node* r)
{
	int i = 1;
	while (r->next != NULL)
	{
		cout << i << ". node's value : " << r->x << endl;
		i++;
		r = r->next;
	}
	cout << i << ". node's value : " << r->x << endl;
	i++;
	return r;
	cout << endl;
}
node* readBackwardsNode(node* r)
{
	int i = 1;
	while (r->prev != NULL)
	{
		cout << i << ". node's value : " << r->x << endl;
		i++;
		r = r->prev;
	}
	cout << i << ". node's value : " << r->x << endl;
	i++;
	return r;
	cout << endl;
}
node* sequentiallyAddNode(node* r, int x)
{
	if (r == NULL)
	{
		r = (node*)malloc(sizeof(node));
		r->next = NULL;
		r->prev = NULL;
		r->x = x;
		return r;
	}
	else if (x < r->x)
	{
		node* temp = (node*)malloc(sizeof(node));
		temp->x = x;
		temp->prev = NULL;
		temp->next = r;
		temp->next->prev = temp;
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
	temp->prev = iter;
	if (temp->next != NULL)
	{
		temp->next->prev = temp;
	}
	temp->x = x;
	return r;


}
node* removeNode(node * r, int x)
{
	node* iter = r;
	node* temp;
	if (r->x == x)
	{
		temp = r;
		r = r->next;
		free(temp);
		r->prev = NULL;
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
	if (temp->next != NULL) 
	{
		iter->next->prev = iter;
	}
	free(temp);
	return r;

}

int main()
{
	node* root;
	root = NULL;
	root = sequentiallyAddNode(root, 400);
	root = sequentiallyAddNode(root, 4);
	root = sequentiallyAddNode(root, 45);
	root = sequentiallyAddNode(root, 40);
	root = sequentiallyAddNode(root, 20);
	root = sequentiallyAddNode(root, 410);

	root = removeNode(root, 4);
	root = removeNode(root, 400);
	root = removeNode(root, 410);
	root = readForwardNode(root);
	cout << "-----------------" << endl;
	root = readBackwardsNode(root);
	cout << "-----------------" << endl;
	root = readForwardNode(root);

}

