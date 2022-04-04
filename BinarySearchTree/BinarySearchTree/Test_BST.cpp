#include <iostream>
#include <stdlib.h>
#include "BinarySearchTree.h"
using namespace std;
int main()
{
	node* root = NULL;
	root = insertion(root, 200);
	root = insertion(root, 213);
	root = insertion(root, 190);
	root = insertion(root, 56);
	root = insertion(root, 28);
	root = insertion(root, 27);
	root = insertion(root, 12);
	root = insertion(root, 18);
	root = insertion(root, 26);
	root = insertion(root, 24);
	traversal_LNR(root);
	cout<<endl;
	cout<< findNode(root, 213) << endl;;
	cout << findNode(root, 200) << endl;;
	cout << findNode(root, 2115) << endl;;
	cout << findNode(root, 18) << endl;;
	cout << findNode(root, 12) << endl;;
	cout << findNode(root, 23) << endl;;
	cout << findNode(root, 28) << endl;;
	
}



