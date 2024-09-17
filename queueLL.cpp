#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
class queue{
    
    node* front;
    node* back;
    public:
    queue(){
        front=NULL;
        back=NULL;
    }
    void push(int x){
       node* n=new node(x);
       if(front==NULL){
           back=n;
           front=n;
           return;
       }
       back->next=n;
       back=n;
       
    }

    void pop(){

        node* todelete=front;
        if(front==NULL){
            cout<<"No elements to delete"<<endl;
            return;
        }
        front=front->next;
        delete todelete;
    }

    int peek(){
        if(front==NULL){
            cout<<"No elements to show"<<endl;
            return -1;
        }
        return (front->data);
    }

    bool empty(){
        return (front==NULL);
    }


};

int main(){
  queue qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    cout<<qu.peek()<<endl;
    qu.pop();
    cout<<qu.peek()<<endl;

    cout<<qu.empty()<<endl;
    qu.pop();
    qu.pop();
    qu.pop();
    cout<<qu.empty()<<endl;
    qu.pop();
    cout<<qu.empty()<<endl;

return 0;
}