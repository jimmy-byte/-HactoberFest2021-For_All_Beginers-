#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;

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
    int lefth=height(root->left);
    int righth=height(root->right);
    return max(lefth,righth)+1;
}
int diameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int lefth=height(root->left);
    int righth=height(root->right);
    int leftd=diameter(root->left);
    int rightd=diameter(root->right);
    int curr=lefth+righth+1;

    
    return max(curr,max(leftd,rightd)) ;

}
int optDiameter(Node* root,int *heightv){
    if(root==NULL){
        heightv=0;
        return 0;
    }
    int lh=0,rh=0;
    int leftD=optDiameter(root->left,&lh);
    int rightD=optDiameter(root->right,&rh);
    *heightv=max(lh,rh)+1;
    int curr=lh+rh+1;
    return max(curr,max(leftD,rightD));


}

int main(){
    struct Node* root=new Node(1);
    root->right=new Node(3);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->left->right=new Node(7);
    // cout<<diameter(root)<<endl;
    int heightv=0;
    cout<<optDiameter(root,&heightv);
    return 0;
}
