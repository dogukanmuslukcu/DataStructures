#include <iostream>
#include <stdlib.h>
#include "Stack_Arr.h"
using namespace std;

stack* init()
{
	stack* s = (stack*)malloc(sizeof(stack));
	s->arr = NULL;
	s->maxSize = 2;
	s->top = 0;
	return s;
}
int pop(stack* s)
{
	if (s->top <= 0 || s->arr == NULL)
	{
		cout << "Array is null" << endl;
		return -1;
	}
	if (s->top <= s->maxSize / 2)
	{
		int* tempArr = (int*)malloc(sizeof(int) * (s->maxSize / 2));
		for (int i = 0; i < s->top; i++)
		{
			tempArr[i] = s->arr[i];
		}
		free(s->arr);
		s->arr = tempArr;
		s->maxSize /= 2;
	}

	return s->arr[--s->top];

}
void push(int x, stack* s)
{
	if (s->arr == NULL)
	{
		s->arr = (int*)malloc(sizeof(int) * 2);
	}
	if (s->top >= s->maxSize - 1)
	{
		int* tempArr = (int*)malloc(sizeof(int) * s->maxSize * 2);
		for (int i = 0; i < s->top; i++)
		{
			tempArr[i] = s->arr[i];
		}
		free(s->arr);
		s->arr = tempArr;
		s->maxSize *= 2;
	}
	s->arr[s->top++] = x;

}
void readArr(stack* s)
{
	cout << "Arr's size = " << s->maxSize << endl;
	for (int i = 0; i < s->top; i++)
	{
		cout << s->arr[i] << endl;
	}
	cout << endl;
}




