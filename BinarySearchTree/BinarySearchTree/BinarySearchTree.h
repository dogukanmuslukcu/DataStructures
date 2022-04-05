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
node* deletion(node*, int);
int search(node*, int);
void traversal_LNR(node*);
void traversal_NLR(node*);
void traversal_LRN(node*);
int min(node*);
int max(node*);

#endif 
