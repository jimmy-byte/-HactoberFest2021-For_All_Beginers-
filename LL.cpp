#include<iostream>
using namespace std;
//as linked list is not default, we have to define it 

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next= NULL;

    }
};
void insertAtTail(node* &head, int val){

    node* n = new node(val);
    if(head==NULL)
        head=n;
    node* temp=head;
    while(temp->next!= NULL){
        temp= temp->next;
    }
    temp -> next =n;

}

display(node* head){
    node* temp=head;
    while(temp !=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
