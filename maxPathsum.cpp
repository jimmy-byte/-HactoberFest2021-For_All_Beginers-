#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
        }
};
int maxPathSumUtil(node* root,int &ans){
    if(root==NULL){
        return 0;
    }
    int left=maxPathSumUtil(root->left,ans);
    int right=maxPathSumUtil(root->right,ans);
     ans=max(max(root->data,root->data+left+right)
                    ,max(root->data+left,root->data+right));
    int singlesum=max(root->data,max(root->data+left,root->data+right));
    return singlesum;
}

int maxPathSum(node* root){
    int ans=INT_MIN;
   int x= maxPathSumUtil(root,ans);
   return ans;
}
int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->right=new node(5);
    cout<<maxPathSum(root)<<endl;
    return 0;
}