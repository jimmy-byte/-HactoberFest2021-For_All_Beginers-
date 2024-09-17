#include"bits/stdc++.h"
using namespace std;
bool isPerfect(int n){
    int sum=1;
    for(int i=2;i<sqrt(n);i++){
        if(n%i==0){
            if(i==n/i){
                sum+=i;

            }else{
                sum+= i+(n/i);
            }
              
        }

    }
    if(sum==n and n!=1){
        return true;
    }
    return false;
}

int maxSum (int arr[],int n,int k){
    if(n<k){
        return -1;
    }
    int result=0;
    for (size_t i = 0; i < k; i++)
    {
        result+=arr[i];
    }
    int sum=result;
    for(int i=k;i<n;i++){
        sum=sum+arr[i]-arr[i-k];
        result=max(result,sum);
    }
    return result;
    
}
int maxNoofPrefects(int arr[],int n,int  k){
    for (size_t i = 0; i<n; i++)
    {
        if(isPerfect(arr[i])){
            arr[i]=1;
        }
        else{
            arr[i]=0;
        }
    }
    return maxSum(arr,n,k);

    
}
int main(){
    int arr[]={28,2,3,6,496,99,8128,24};
    int n=8,k=4;
     cout<<maxNoofPrefects(arr,n,k)<<endl;
    return 0;
}