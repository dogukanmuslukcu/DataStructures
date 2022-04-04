#include <iostream>
#include <stdlib.h>
#include "BinarySearchTree.h"
using namespace std;
node* insertion(node* r, int data)
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
int findNode(node* r, int data) 
{   if (r == NULL) 
	 {
		 return -1;
	 }
	if (r->data == data) 
	{
		return 1;
	}
	if (findNode(r->rightChild, data) == 1) 
	{
		return 1;
	}
	if (findNode(r->leftChild, data) == 1)
	{
		return 1;
	}
	 
	 return -1;
		 
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