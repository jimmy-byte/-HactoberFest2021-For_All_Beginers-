#include"bits/stdc++.h"
using namespace std;
int maximumSubArray(int arr[],int n,int k,int X){
    int ans=0,sum=0;
    for(int i=0;i<k;i++){
         sum+=arr[i]; 
    }
    if(sum<X){
        ans=sum;
    }
    int start=0,end=start+k;
    for(int i=k;i<n;i++){
        sum=sum-arr[i-k];
        sum=sum+arr[i];
        if(sum<X){
            ans=max(ans,sum);
            cout<<sum<<" "<<i<<endl;
        }
    }


    
    return ans;
}
int main(){
    int arr[]={7,5,4,6,8,9};
    int n=6;int k=3;int X=20;
    cout<<maximumSubArray(arr,n,k,X)<<endl;
    return 0;
}