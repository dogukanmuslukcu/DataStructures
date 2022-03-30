#include <iostream>
#include <stdlib.h>
using namespace std;
struct n
{
    int x;
    n* next;
};
typedef n node;

void readNode(node *r)
{
    int i = 1;
    node* iter = r;
    cout << i << " Node's value : " << iter->x << endl;
    i++;
    iter = iter->next;

    while (iter->next !=r->next)
    {
        cout << i << " Node's value : " << iter->x << endl;
        i++;
        iter = iter->next;
    }
}
void addNode(node * r , int x)
{
    node* iter = r;
    while (iter ->next !=r)
    {
        iter = iter->next;
    }
    iter->next = (node*)malloc(sizeof(node));
    iter->next->next = r;
    iter->next->x = x;

}
node* sequentiallyAddNode(node* r, int x)
{
    if (r == NULL) 
    {
        r = (node*)malloc(sizeof(node));
        r->next = r;
        r->x = x;
        return r;
    }
    else if (r->x > x) 
    {
        node* temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = r;
        node* iter = r;
        while(iter->next!=r)
        {
            iter = iter->next;
        }
        iter->next = temp;
        return temp;
    }
    node* iter = r;
    while (iter->next != r && iter->next->x < x)
    {
        iter = iter->next;
    }
    node* temp = (node*)malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp->x = x;
    return r;
}
node* removeNode(node* r,int x)
{
    node* temp;
    node* iter = r;
    if (r->x == x) {
        while (iter->next != r) {
            iter = iter->next;
        }
        iter->next = r->next;
        free(r);
        return iter->next;
    }

    while (iter->next != r && iter->next->x != x) {
        iter = iter->next;
    }
    if (iter->next == r) {
        cout<<"Sayi bulunamadi!"<<endl;
        return r;
    }
    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    return r;
}


int main()
{
    node* root;
    root = NULL;
    root = sequentiallyAddNode(root, 400); 
    root = sequentiallyAddNode(root, 40);
    root = sequentiallyAddNode(root, 4);
    root = sequentiallyAddNode(root, 450);
    root = sequentiallyAddNode(root, 50);
    readNode(root);
    root = removeNode(root, 50);
    readNode(root);
    root = removeNode(root, 999);
    readNode(root);
    root = removeNode(root, 4);
    readNode(root);
    root = removeNode(root, 450);
    readNode(root);

}

