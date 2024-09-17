#include<iostream>
#include<climits>
using namespace std;
bool isPossible(int arr[],int n,int m,int min){
    int studentsReqied=1,sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>min){
            return false;
        }
        if(sum+arr[i]>min){
            studentsReqied++;
            sum=arr[i];
            if(studentsReqied>m){
            return false;
        }
        }
        else{
            sum+=arr[i];
        }
        
    }
    return true;
}

int allocateMinPages(int arr[],int n,int m){
    if(n<m){
        return false;
    }
    int start=0;
    int sum=0;int ans=INT_MAX;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    int end=sum;
    while(start<=end){
        int mid=(start+end)/2;
        if(isPossible(arr,n,m,mid)){
             ans=min(ans,mid);
             end=mid-1;

        }
        else{
            start=mid+1;
        }

    }
    return ans;
}
int main(){
    int arr[]={12,34,67,90};
    cout<<allocateMinPages(arr,4,2)<<endl;
    return 0;
}