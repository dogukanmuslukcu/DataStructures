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
	root = insertion(root, 1);
	root = insertion(root, -1);
	traversal_LNR(root);
	cout << endl;
	/*cout << search(root, 213) << endl;
	cout << search(root, 200) << endl;
	cout << search(root, 2115)<< endl;
	cout << search(root, 18)  << endl;
	cout << search(root, 12)  << endl;
	cout << search(root, 23)  << endl;
	cout << search(root, 28)  << endl;
	cout << min(root) << endl;
	cout << max(root) << endl;*/
	root = deletion(root, 200);
	root = deletion(root, 213);
	traversal_LNR(root);
	

	
}



