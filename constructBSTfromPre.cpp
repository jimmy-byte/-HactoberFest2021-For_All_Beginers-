#include "bits/stdc++.h"
using namespace std;
 struct node{
     int data;
     node *right,*left;
    node(int val){
        data=val;
        right=nullptr;
        left=nullptr;

    }

 };

 node* constructBSTPreOrder(int preorder[],int key,int* preorderIdx, int min, int max,int n ){
     if(*preorderIdx>=n){
         return nullptr;
     }
     node* root=nullptr;
    if(key>min && key<max){
        root=new node(key);
        *preorderIdx= *preorderIdx+1;
        if(*preorderIdx<n){
            root->left=constructBSTPreOrder(preorder,preorder[*preorderIdx],preorderIdx, min,key,n);
        }
          if(*preorderIdx<n){
            root->right=constructBSTPreOrder(preorder,preorder[*preorderIdx],preorderIdx, key,max,n);
        }

    }
    return root;

 }
 void preOrder(node* root){
     if(root==nullptr){
         return ;
     }
     cout<<root->data<<" ";
     preOrder(root->left);
     preOrder(root->right);
 }
 int main(){
     int preorder[]= {10,2,1,13,11};int n=5;int preorderIdx=0; 
    node* root=constructBSTPreOrder(preorder,preorder[0],&preorderIdx, INT_MIN,INT_MAX,n );
    preOrder(root); 
    // return 0; 
 }