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

bool isIdentical(node* root1,node* root2){
    if(root1==nullptr && root2==nullptr){
        return true;
    }
    else if(root1==nullptr||root2==nullptr){
        return false;
    }
    else{
        bool c1= root1->data==root2->data;
        bool c2=isIdentical(root1->left,root2->left);
        bool c3=isIdentical(root1->right,root2->right);

        return c1&&c2&&c3;
    }
    return false;
}

int main(){
    node* root=new node(2);
    root->left=new node(1);
    root->right=new node(3);
      node* root2=new node(2);
    root2->left=new node(1);
    root2->right=new node(4);
    cout<<isIdentical(root,root2)<<endl;
    return 0;
}