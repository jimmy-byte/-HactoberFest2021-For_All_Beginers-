#include <iostream>
using namespace std;
struct Node{
int data;
 Node* left;
 Node* right;
 Node(int val){
     data=val;
     left=NULL;
     right=NULL;
 }
};
int countNode(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftcount=countNode(root->left);
    int rightcount=countNode(root->right);
    int ans=leftcount+rightcount+1;
    return ans;
}
int sumNode(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftsum=sumNode(root->left);
    int rightsum=sumNode(root->right);
    int ans=(root->data)+leftsum+rightsum;
    return ans;

}
int main(){
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(4);
    cout<<countNode(root)<<endl;
    cout<<sumNode(root)<<endl;
    return 0;
}

