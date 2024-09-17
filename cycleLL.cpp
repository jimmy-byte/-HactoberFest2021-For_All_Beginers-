#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node*next;
     node(int val){
         data=val;
         next=NULL;
     }
};
void insertAtTail(node* &head,int val){
    node* temp=head;
    node* n= new node(val);
    if(head == NULL){
        head=n;
        return;
        }
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=n;


    }

void toMakeCycle(node* &head,int pos){
        node* temp = head;
    while(temp->next != NULL){
        temp=temp->next;
    }

    node* posnod=head;
    for(int i=0;i<pos;i++){
        posnod=posnod->next;
    }
    temp->next=posnod;
}
void display(node* head){
    node* temp=head;
    while(temp !=NULL){
        cout << (temp->data) << "->";
        temp=temp->next;
    }
        cout << "NULL" <<endl;
}

bool toDetectCycle(node* head){
    node* fastptr=head;
    node* slowptr=head;
    while(fastptr != NULL && fastptr->next != NULL ){
        fastptr=fastptr->next->next;
        slowptr=slowptr->next;
        if(fastptr==slowptr){
            return true;
        }
    }
    return false;
    
}
void toDeleteCycle(node* &head){
    node* fastptr=head;
    node* slowptr=head;
    while(fastptr != NULL && fastptr->next != NULL ){
        fastptr=fastptr->next->next;
        slowptr=slowptr->next;
        if(fastptr->next == slowptr-> next ){
            slowptr->next->next=NULL;
            return;
        }
    }
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtTail(head,8);
    insertAtTail(head,9);
        display(head);
    toMakeCycle(head,3);
    cout<<toDetectCycle(head)<<endl;
    toDeleteCycle(head);
   cout<<toDetectCycle(head)<<endl;
    display(head);
    return 0;
}    

