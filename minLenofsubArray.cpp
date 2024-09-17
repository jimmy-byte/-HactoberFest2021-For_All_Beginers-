#include"bits/stdc++.h"
using namespace std;

int minimumLenghtOfSubArray(int arr[],int n,int X){
    int end=0,start=0,minLen=n+1,sum=0;
    while(end<n){
        while(sum<=X && end<n){
            sum+=arr[end++];
        }
        
        while(sum>X && start<end){
            minLen=min(end-start,minLen);
            sum-=arr[start++];

        }
    }
    return minLen;
}
int main(){
    int arr[]={1,4,45,6,10,19};
    int n=6,x=200;
    if(minimumLenghtOfSubArray(arr,n,x)==n+1){
        cout<<"do not exist"<<endl;
        return 0;
    }
    cout<<minimumLenghtOfSubArray(arr,n,x)<<endl;
    return 0;
}