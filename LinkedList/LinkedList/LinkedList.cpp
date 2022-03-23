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
    int i = 0;
    while (r!=NULL)
    {
        cout << i << ".nci :" << r->x << endl;
       i++; 
       r=r->next;
        
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
    cout << "----" << endl;

    node* iter;
    iter = root;
    node* temp;
    temp  = (node*)malloc(sizeof(node));
    
    for (int i = 0; i < 3; i++)
    {
        iter = iter->next;
    }
     
    temp->next = iter->next;
    iter->next = temp;
    temp->x = 25;
    
    readNode(root);


   
}  


