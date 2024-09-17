#include "bits/stdc++.h"
using namespace std;
class node{
     public:
    int data;
    node *left;
    node* right;
    node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }

};
struct info
{
    int size;
    int min;
    int max;
    int ans;
    bool isBST;
};

info largestBSTinBT(node*root){
    if(root==nullptr){
        return {0,INT_MIN,INT_MAX,0,true};
    }
    if(root->left==nullptr && root->right==nullptr){
        return {1,root->data,root->data,1,true};
    } 
    info lefti=largestBSTinBT(root->left);
    info righti=largestBSTinBT(root->right);
    info curr;
    curr.size=(1 + lefti.size + righti.size);
    if((lefti.isBST) && (righti.isBST) && (root->data > lefti.max) && (root->data < righti.min)){
        curr.min=min(lefti.min,min(righti.min,root->data));
        curr.max=max(righti.max,max(lefti.max,root ->data));
        curr.ans=curr.size;
        curr.isBST=true;
        return curr;
    }

    curr.ans=max(lefti.ans,righti.ans);
    curr.isBST=false;
    return curr;


}
 int main(){
     /*
              15
             /  \
            20  30
           /
          5    
     */
    
     node*root=new node(15);
     root->right=new node(30);
     root->left=new node(20);
     root->left->left=new node(5);
     info rooti=largestBSTinBT(root);
     cout<<rooti.ans<<endl;
     return 0;
    
}