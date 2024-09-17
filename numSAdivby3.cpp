#include "bits/stdc++.h"
using namespace std;

void numberfromSubarray(vector <int> a,int k){
    pair<int ,int > ans;
    int sum=0;bool isit=false;
    for(int i=0;i<k;i++){
        sum+=a[i];
    }
    if (sum%3==0)
    {
        ans=make_pair(0,k-1);
        isit=true;
        }
    for(int j=k;j<a.size();j++){
        if(isit){
            break;
        }
        sum=sum+a[j]-a[j-k];
        if(sum%3==0){
            isit=true;
            ans=make_pair(j-k+1,j);
        }
    }
    if(!isit){
        cout<<"No such element exist"<<endl;
    }
    for(int i=ans.first;i<=ans.second;i++){
        cout<<a[i];
        }
}
int main(){
    vector <int >a = { 84,23,45,12,56,82 };
    int k=3;
    numberfromSubarray(a,k);
    return 0;

}