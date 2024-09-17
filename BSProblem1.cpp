#include "bits/stdc++.h"
using namespace std;

bool isFeasible(int arr[],int n,int k,int mid){
    int element=0;int pos=arr[0];
    for(int  i=0;i<n;i++){
        if(arr[i]-pos>=mid){
            pos=arr[i];
            element++;
        }
        if(element==k){
            return true;
        }
    }
    return false;
}

int largestMinDistance(int arr[],int n,int k){
    int result=-1;
    sort(arr,arr+n);
    int left=arr[0];int right=arr[n-1];
    while(left<right){
        int mid=(left+right)/2;
        if(isFeasible(arr,n,k,mid)){
            result=max(result,mid);
            left=mid+1;
        }
        else{
            right=mid;
        }
    }
    return result;
}
int main(){
    int arr[]={1,2,8,4,9};
    int n=5,k=2;
    cout<<largestMinDistance(arr,n,k)<<endl;
    return 0;


}