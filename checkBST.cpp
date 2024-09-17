#include"bits/stdc++.h"
using namespace std;
struct node{
    int data;
    node *left,*right;
    node(int val){
        data=val;
        right=nullptr;
        left=nullptr;
    } 
};

bool isBST(node* root,node* min=nullptr,node* max=nullptr){

    if(root==nullptr){
        return true;
    }
    if(min!=nullptr &&  (root->data) < (min->data)){
        return false;

    }
    if(max!=nullptr &&  (root->data) > (max->data)){
        return false;
    }
    bool leftst=isBST(root->left,min,root);
    bool rightst=isBST(root->right,root,max);
    return (leftst&&rightst);


}
int main(){

    node* root=new node(3);
    root->right=new node(5);
    root->right->right=new node(2);
    root->left=new node(1); 
    cout<<isBST(root,nullptr,nullptr)<<endl;

    return 0;
}