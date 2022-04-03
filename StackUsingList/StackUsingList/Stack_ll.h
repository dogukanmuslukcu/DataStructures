#ifndef Stack_ll
#define Stack_ll
struct n 
{
	int x;
	n* next;
};
typedef n node;
int pop(node*);
node* push(node*, int);
void readStack(node*);
#endif

