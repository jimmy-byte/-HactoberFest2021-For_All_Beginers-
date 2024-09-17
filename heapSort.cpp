#include "bits/stdc++.h"
using namespace std;

void heapify(vector<int> &arr,int i,int n){
    int maxIdx=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l]>arr[maxIdx])
        maxIdx=l;

    if(r<n && arr[r]>arr[maxIdx])
        maxIdx=r;

    if(maxIdx!=i){
        swap(arr[i],arr[maxIdx]);
        heapify(arr,maxIdx,n);
    }

}

void heapsort(vector<int>&arr){
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,i,n);
    }
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,0,i);
    }

}
int main(){
    int n;cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int val;cin>>val;
        a.push_back(val);

    }
    heapsort(a);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
    return 0;
}

