#include <iostream>
#include "A2_Q1_list.h"
using namespace std;
struct node *header_node = new node();
int main(){
    //node *head_pointer;
    header_node->next=NULL;
    header_node->next = insert(header_node->next,10);
    header_node->next = insert(header_node->next,20);
    header_node->next = insert(header_node->next,30);
    header_node->next = insert(header_node->next,40);
    header_node->next = insert(header_node->next,50);
    printCLL(header_node->next);
    cout<<endl;
    cout<<search(header_node->next,50)<<endl;
    deletion(header_node->next,40);
    printCLL(header_node->next);
    return 0;
}
