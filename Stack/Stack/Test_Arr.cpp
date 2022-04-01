#include <iostream>
#include <stdlib.h>
#include "Stack_Arr.h"
using namespace std;
int main()
{
	stack* stack1 = init();
	stack* stack2 = init();
	for (int i = 0; i < 10; i++)
	{
		push(i * 10, stack1);
	}
	readArr(stack1);
	for (int i = 0; i < 10; i++)
	{
			push(pop(stack1), stack2);
		
	}
	readArr(stack2);
	readArr(stack1);
}