#include<iostream>
#include<vector>
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
bool getPath(node*root,int n1,vector<int> &path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==n1){
        return true;
    }
    if(getPath(root->right,n1,path)||getPath(root->left,n1,path)){
        return true;
    }
    path.pop_back();
    return false;
}

int LCA(node* root,int n1,int n2){
    vector<int> path1,path2;
    if(!getPath(root,n1,path1) || !getPath(root,n2,path2)){
        return -1;
    }
    int pc;
    for(pc=0;pc<path1.size()&&path2.size();pc++){
        if(path1[pc]!=path2[pc]){
            break;
        }
    }
    return path1[pc-1];
}
node* LCA2(node*root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1||root->data==n2){
        return root; 
    }
    node* leftLCA=LCA2(root->left,n1,n2);
    node* rightLCA=LCA2(root->right,n1,n2);  
    if(leftLCA!=NULL && rightLCA !=NULL){
        return root;
    }
    if(leftLCA !=NULL){
        return leftLCA;

    }
    return rightLCA;
} 

int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->left->left=new node(4);
    root->right=new node(3);
    root->right->left=new node(5);
    root->right->left->left=new node(7);
    root->right->right=new node(6);
    // cout<<LCA(root,7,6)<<endl;
    node* lca=LCA2(root,7,6);
    if(lca != NULL){
    cout<<lca->data<<endl;
    }else{
        cout<<"Not found"<<endl;
    }

    return 0;
}