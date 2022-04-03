#include <iostream>
#include <stdlib.h>
#include "Stack_ll.h"
using namespace std;

int main()
{
	node* root = NULL;

	root = push(root, 10);
	root = push(root, 20);
	root = push(root, 30);
	root = push(root, 40);
	cout << pop(root)<<endl;
	cout << pop(root)<< endl;
	cout << pop(root)<< endl;
	
	root = push(root, 40);
	readStack(root);


}