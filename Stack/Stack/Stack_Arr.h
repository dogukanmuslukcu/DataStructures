#ifndef  Stack_Arr
#define Stack_Arr
struct s
{
	int maxSize;
	int top;
	int* arr;
};
typedef s stack;
stack * init();
int pop(stack* s);
void push(int x, stack* s);
void readArr(stack* s);
#endif 
