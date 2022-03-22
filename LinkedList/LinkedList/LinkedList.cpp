#include <iostream>
#include <stdlib.h>
using namespace std;

struct n
{
    int x;
    n* next;
};
typedef n node;
int main()
{
    node * root;
    root = (node*)malloc(sizeof(node));
    root -> x = 10;
    root -> next = (node*)malloc(sizeof(node));
    root->next->x = 20;
    root->next->next = (node*)malloc(sizeof(node));
    root->next->next->x = 30;

    node* iter;
    iter = root;
    cout << iter->x<<endl;
    iter = iter->next;
    cout << iter->x << endl;

}


