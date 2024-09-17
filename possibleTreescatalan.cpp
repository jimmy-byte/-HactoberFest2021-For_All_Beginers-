#include"bits/stdc++.h"
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

vector<node*> possibleBST(int start,int end){
    vector<node*> trees;
    if(start>end){
        trees.push_back(nullptr);
        return trees;
    }
    for(int i=start;i<=end;i++){
        vector<node*> leftTrees=possibleBST(start,i-1);
        vector<node*> rightTrees=possibleBST(i+1,end);

        for(int j=0;j<leftTrees.size();j++){
            node* lefte=leftTrees[j];
            for(int k=0;k<rightTrees.size();k++){
                node* righte=rightTrees[k];
                node* n=new node(i);
                n->left=lefte;
                n->right=righte;
                trees.push_back(n);    
            }
            
        }

    }
    return trees; 

}
void preorder(node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
     preorder(root->left);
     preorder(root->right);

}
int main(){
     vector<node*> totalTrees=possibleBST(1,3);
      for(int i=0;i<totalTrees.size();i++){
          cout<< i+1 <<" : ";
          preorder(totalTrees[i]);
          cout<<endl;
      }
      return 0; 
}