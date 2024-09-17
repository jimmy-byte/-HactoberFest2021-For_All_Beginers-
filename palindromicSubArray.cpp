#include "bits/stdc++.h"
//Use C++11
using namespace std;
bool isPalindrom(int num){
        string str=to_string(num);
        int n=str.size();
        for(int i=0;i<n/2;i++){
            if(str[i]!=str[n-i-1]){
                return false;
            }
        }
        return true;
}/*
another approch for  isPalindrom--> Reverse the num
using following program
bool isPalindeomic(int n){
    int num1=n,num2=0;
while(num1>0){
    num2=num2*10+num1%2;
    num1/=10;

}
if(num2==n){
    return true;
}
return false;
}
*/

int palindromicSubArray(vector <int> arr,int k){
    int num=0;
    for(int i=0;i<k;i++){
        num=(num*10)+arr[i];
    }
    if(isPalindrom(num)){
        return 0;
    }
    for(int j=k;j<arr.size();j++){
        num=(num%(int)(pow(10,k-1)))*10+arr[j];
        if(isPalindrom(num)){
            return j-k+1;
        }

    }
    return -1;
}
int main(){
    vector <int> a={2,3,5,1,1};
    int k=4;

    int idx=palindromicSubArray(a,k);
    if(idx==-1){
        cout<<"no palindromic subarray possible"<<endl;
    } 
    else{
        for(int i=idx;i<idx+k;i++){
            cout<<a[i]<<" "; 
        }
        cout<<endl;
        
    }
    return 0;
}
