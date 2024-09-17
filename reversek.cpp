#include "bits/stdc++.h"
using namespace std;
//creating linked list nodes
class node{
    public:
    int data;
    node* next;
        node(int val){
            data=val;
            next=NULL;
        }
};
//inserting element one after
// void insertatTail(node* &head,int val){
//     node* temp=head;
//     node* n=new node(val);
//     if(head==NULL)
//         {head=n;}
//     while(temp != NULL){
//         temp=temp->next;
//     }
//     temp->next=n;
// }



void insertatTail(node** head, int val)
{

    node* temp = new node(val);
 

    temp->data = val;
 

    temp->next = (head);
 

    (head) = temp;
}

//Function to reverse k nodes 


node* reverseK(node* head, int k){
    if(!head)
        return NULL;
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr=NULL;
    int count=0;
    while( currptr != NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr != NULL){
        head-> next=reverseK(nextptr,k);
    }
    return prevptr;
}
//function for displaying LL

 void display(node* head){
    // nodetemp=head;
    while(head != NULL){
        cout<<(head->data)<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node* head=NULL;
    //inserting elements
    insertatTail(&head,9);
    insertatTail(&head,8);
    insertatTail(&head,7);
    insertatTail(&head,6);
    insertatTail(&head,5);
    insertatTail(&head,4);
    insertatTail(&head,3);
    insertatTail(&head,2);
    insertatTail(&head,1);
    cout<<"Given linked list is:- ";
    display(head);


    cout<<"Linked list after reversing k nodes is:- ";
    node* krev=reverseK(head,3);
    display(krev);

    return 0;
}