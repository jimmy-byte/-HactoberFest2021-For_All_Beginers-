#include<iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL; 
    }
};
node* insertBST(node*root,int val){
    if(root==NULL){
        node* rnode=new node(val);
        return rnode;
    }
    if((root->data) > val){
       root->left=  insertBST(root->left,val);
    }
    else{
        root->right=insertBST(root->right,val);
    }

    return root;
}
void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data  <<" ";
    inorder(root->right);

}

int main(){
        node*root=NULL;
        root=insertBST(root,5);
        insertBST(root,1);
        insertBST(root,3);
        insertBST(root,4);
        insertBST(root,2);
        insertBST(root,7);

        inorder(root);

    return 0;
    
}