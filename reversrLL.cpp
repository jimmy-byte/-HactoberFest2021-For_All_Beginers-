#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next=NULL;

  node(int val){
        data = val;
        next= NULL;

    }
};

void insertAtTail(node* &head,int val){
    node* n= new node(val);
    if(head==NULL){
        head=n;
        return;
        
    }
    node*temp = head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=n;

}
node* reverseAll(node* &head){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    while(currptr != NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}

node* reverseK(node* &head,int k ){

    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr=NULL;
    int count=0;
    while(count < k && currptr != NULL){
        
      
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;


        count++;
    }    

    while(nextptr != NULL){
        nextptr=head->next;
        head->next= reverseK(nextptr , k);
    }
    
    return prevptr;
   

}

void display(node* head){
    node* temp=head;
    while(temp !=NULL){
        cout << (temp->data) << "->";
        temp=temp->next;
    }
        cout << "NULL" <<endl;
}


int main(){
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);

    display(head);
    node* reversedall= reverseAll(head);
    display(reversedall);

    node* reversek= reverseK(head,2);
    display(reversek);
    return 0;
}