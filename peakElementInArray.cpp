#include "bits/stdc++.h"
using namespace std;

int findPeakElement(int arr[],int low,int high,int n){
    int mid=low+(high-low)/2;
    if((mid==0||arr[mid-1]<arr[mid]) && (mid==n||arr[mid]>arr[mid+1])){
        return mid;
    }
    if(mid>0 && arr[mid-1]>arr[mid]){
        return findPeakElement(arr,low,mid-1,n);
    }
    if(mid>0&& arr[mid+1]>arr[mid]){
        return findPeakElement(arr,mid+1,high,n);
    }
    return -1; 
}
int main(){
    int arr[]={2,5,3,6,8,10,4};
    int n=7;
    cout<<findPeakElement(arr,0,n-1,n)<<endl ;
    return 0;
}