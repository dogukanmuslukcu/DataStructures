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
}
void addNode(node* r, int x)
{
	while (r->next != NULL)
	{
		r = r->next;
	}
	r->next = (node*)malloc(sizeof(node));
	r->next->x = x;
	r->next->next = NULL;

}
node* sequentiallyAddNode(node* r, int x)
{
	if (r == NULL)
	{
		r = (node*)malloc(sizeof(node*));
		r->next = NULL;
		r->x = x;
		return r;
	}
	else if (r->x > x)
	{
		node* temp = (node*)malloc(sizeof(node*));
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
	root = sequentiallyAddNode(root, 150);
	root = sequentiallyAddNode(root, 5);
	root = sequentiallyAddNode(root, 3);
	root = sequentiallyAddNode(root, 1150);
	root = sequentiallyAddNode(root, 4);
	root = sequentiallyAddNode(root, 250);
	root = sequentiallyAddNode(root, 10);
    readNode(root);


}


