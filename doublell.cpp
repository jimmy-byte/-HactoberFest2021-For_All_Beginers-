#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* prev;
    node* next;

        node(int num){
            prev=NULL;
            data=num;
            next=NULL;
        }

};
void insertAtHead(node* &head, int val){
    node* n=new node(val);
    n->next=head;
    if(head != NULL){
    head->prev=n;
    }
    head=n;
}
void insertAtTail(node* &head,int val){
    node* temp = head;
    node* n= new node(val);
    if(head==NULL){
        insertAtHead(head,val);
        return ;
    }
    else{
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=n;
        n->prev=temp;
        
        
    }
    
}
void display(node* head){
    node* temp=head;
    while(temp != NULL){
        cout<<(temp->data)<<"<->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtTail(head,8);
    insertAtTail(head,9);
    display(head);
    insertAtHead(head,10);
    display(head);

    return 0;
}