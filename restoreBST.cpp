#include "bits/stdc++.h"
using namespace std;

void calcPtrs(Node*root,Node**first,Node**mid,Node**last,Node**prev){
    if(root==NULL){
        return;
    }
    calcPtrs(root->left,first,mid,last,prev);
    if(*prev&&root->data<(*prev)->data){ //condition for if it violates Property
        if(!*first){//condition if it is first time
            *first=*prev; 
            *mid=root;
        }
        else{//if second time there is violation
            *last=root;
        }
    }
    *prev=root;

    calcPtrs(root->right,first,mid,last,prev);
}

void swap(int* a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp; 

}

void restoreBST(Node*root){
    Node *first=NULL,*last=NULL,*mid=NULL,*prev=NULL;
    calcPtrs(root,&first,&mid,&last,&prev);
    if(first && last){
        swap(&(first->data),&(last->data));
    }
    else if(first && mid){
        swap(&(first->data),&mid->data); 
    }
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){

    Node* root=new Node(6);
    root->left=new Node(9);
    root->left->left=new Node(1);
    root->left->right=new Node(4);
    root->right=new Node(3);
    root->right->right=new Node(13); 
    inorder(root);cout<<endl;
    restoreBST(root);
    inorder(root);cout<<endl;

    return 0;
}