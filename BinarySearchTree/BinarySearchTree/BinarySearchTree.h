#ifndef BinarySearchTree
#define BinarySearchTree
struct n 
{
	int data;
	n* leftChild;
	n* rightChild;
};
typedef n node;
node* insertion(node* r, int data);
void traversal_LNR(node* r);
void traversal_NLR(node* r);
void traversal_LRN(node* r);
int findNode(node* r, int data);
#endif 
