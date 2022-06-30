#include <iostream>
#include "A2_Q1_list.h"
using namespace std;
struct node *createNewNode(int data){
    struct node *temp = new node();
    temp->data = data;
    temp->next=temp;
    return temp;

}
struct node* insert(struct node *head,int data){
    struct node *head_pointer = head;
    if(head_pointer==NULL){
        head_pointer= createNewNode(data);
        return head_pointer;
    }
        struct node *temp=head_pointer->next;
        while(temp->next!=head->next) temp=temp->next;
        struct node *newnode = createNewNode(data);
        temp->next = newnode;
        newnode->next = head_pointer->next;
        return head_pointer;
}
void printCLL(struct node* head){
    struct node *temp = head->next;
    cout<<head->data<<" ";
    do{
        	cout<<temp->data<<" ";
        	temp=temp->next;
    }while(temp!=head->next);
    
}
bool search(node *head_pointer,int data){
	struct node *head = head_pointer->next;
	if(head_pointer->data == data) return true;
	do{
        	if(head->data == data) return true;
        	head=head->next;
    }while(head!=head_pointer->next);
	return false;
}
void deletion(struct node *head,int val){
    if(search(head,val)==0){
        cout<<"Value to be deleted is not present in CLL"<<endl;
        return;
    }
    else
    {
        struct node *temp1 =head,*temp2;
        if(temp1->data==val){
            int x=temp1->data;
            temp2=temp1->next;
            temp1->data = temp2->data;
            temp2->data = x;
        }
        temp1=head;
        while(temp1->data!=val){
            temp2=temp1;
            temp1=temp1->next;
        }
        temp2->next = temp1->next;
        free(temp1);
        temp1=NULL;
    }
}
