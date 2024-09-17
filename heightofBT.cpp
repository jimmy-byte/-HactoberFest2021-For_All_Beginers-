#include<bits/stdc++.h>
using namespace std;
struct Node
{
   int data;
   Node* left;
   Node* right;
   Node(int val){
       data=val;
       right=NULL;
       left=NULL;
   }
};
int heightBT(Node* root){
    if(root==NULL){
        return 0;
    }
    int lefth=heightBT(root->left);
    int righth=heightBT(root->right);
    int ans=max(lefth,righth)+1;
    return ans;
}


int main(){
    struct Node* root=new Node(1);
    root->right=new Node(3);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->left->right=new Node(7);
    cout<<heightBT(root)<<endl;
    return 0;
}
