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
void addNode(node* r, int x) 
{
    while (r->next != NULL) 
    {
        r = r->next;
    }
    r->next = (node*)malloc(sizeof(node));
    r->next->x = x;
    r->next->next = NULL;
    
}
int main()
{
    node * root;
    root = (node*)malloc(sizeof(node));
    root->next = NULL;
    root -> x = 100;
   
    for (int i = 1; i < 5; i++) 
    {
        addNode(root, i * 10);
    }
    readNode(root);
}  


