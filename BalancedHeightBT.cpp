#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
}

bool isBalanced(Node* root){
    if(root==NULL){
        return true;
    }
    if(isBalanced(root->left)==false){
        return false;
    }
       if(isBalanced(root->right)==false){
        return false;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    if(abs(lh-rh)<=1){
        return true;
    }
    else{
    return false;
    }

}
bool isBalancedopt(Node* root,int* heightv){
    if(root==NULL){
        return true;
    }
    int lh=0,rh=0;
    if(isBalancedopt(root->left,&lh)==false){
        return false;
    }
    if(isBalancedopt(root->right,&rh)==false){
        return false;
    }

    *heightv=max(lh,rh)+1;

    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }


}
int main(){
    Node* root = new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    // root->left=new Node(2);
    // root->left->left=new Node(3);
    //  cout<<isBalanced(root)<<endl;
    int heightv=0;
    cout<<isBalancedopt(root,&heightv)<<endl;
    return 0;
}