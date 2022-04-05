#include <iostream>
#include <stdlib.h>
#include "BinarySearchTree.h"
using namespace std;
node* insertion(node* r, int data)//add node to the given tree
{
	if (r == NULL)
	{
		r = (node*)malloc(sizeof(node));
		r->data = data;
		r->leftChild = NULL;
		r->rightChild = NULL;
		return r;
	}
	if (data < r->data)
	{
		r->leftChild = insertion(r->leftChild, data);


	}
	if (data > r->data)
	{
		r->rightChild = insertion(r->rightChild, data);

	}
	return r;
}
int search(node* r, int data)
{
	if (r == NULL)
	{
		return -1;
	}
	if (r->data == data)
	{
		return 1;
	}
	if (search(r->rightChild, data) == 1)
	{
		return 1;
	}
	if (search(r->leftChild, data) == 1)
	{
		return 1;
	}

	return -1;

}
node* deletion(node* r, int data)
{
	if (r == NULL)// the first statu is that's the given tree is null
	{
		return NULL;
	}
	if (r->data == data)// statu is that's the root of the given tree
	{
		if (r->leftChild == NULL && r->rightChild == NULL)
		{
			return NULL;
		}
		if (r->leftChild != NULL)
		{
			r->data = max(r->leftChild);
			r->leftChild = deletion(r->leftChild, max(r->leftChild));
			return r;
		}
		r->data = min(r->rightChild);
		r->rightChild = deletion(r->rightChild, min(r->rightChild));
		return r;
	}//if data isn't root of the tree , find the data's tree which is a root of  the tree
	if (data > r->data)
	{
		r->rightChild = deletion(r->rightChild, data);
		return r;
	}
	r->leftChild = deletion(r->leftChild, data);
	return r;
}
int max(node* r)
{
	while (r->leftChild != NULL)
	{
		r = r->leftChild;
	}
	return r->data;
}
int min(node* r)
{
	while (r->rightChild != NULL)
	{
		r = r->rightChild;
	}
	return r->data;
}
void traversal_LNR(node* r)
{
	if (r == NULL)
	{
		return;
	}
	traversal_LNR(r->leftChild);
	cout << r->data << "  ";
	traversal_LNR(r->rightChild);
}
void traversal_NLR(node* r)
{
	if (r == NULL)
	{
		return;
	}

	cout << r->data << "  ";
	traversal_NLR(r->leftChild);
	traversal_NLR(r->rightChild);
}
void traversal_LRN(node* r)
{
	if (r == NULL)
	{
		return;
	}
	traversal_LRN(r->leftChild);
	traversal_LRN(r->rightChild);
	cout << r->data << "  ";
}
