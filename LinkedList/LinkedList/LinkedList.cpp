#include <iostream>
#include <stdlib.h>
using namespace std;

struct n
{
    int x;
    n* next;
};
typedef n node;

void readNode(node * r) 
{
    while (r!=NULL)
    {
        int i = 1;
        cout << i << ".nci :" << r->x << endl;
        r=r->next;
        i++;
    }
}
int main()
{
    node * root;
    root = (node*)malloc(sizeof(node));
    root -> x = 10;
    root -> next = (node*)malloc(sizeof(node));
    root->next->x = 20;
    root->next->next = (node*)malloc(sizeof(node));
    root->next->next->x = 30;
    root->next->next->next = NULL;

    node* iter;
    iter = root;
    while (iter->next != NULL) 
    {
        cout << iter->x << endl;
        iter = iter->next;
    }

    for (int i = 1; i < 5; i++) 
    {
        iter->next = (node*)malloc(sizeof(node));
        iter = iter->next;
        iter->x = i * 10;
        iter->next = NULL;
    }
    readNode(root);
}  


