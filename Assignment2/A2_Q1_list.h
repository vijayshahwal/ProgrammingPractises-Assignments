#ifndef _list_h
#define _list_h

using namespace std;

struct node
{
    int data;
    struct node *next;   
};
struct node *createNewNode(int);
struct node* insert(struct node*,int);
void printCLL(struct node*);
bool search(struct node*, int);
void deletion(struct node*,int);
#endif
