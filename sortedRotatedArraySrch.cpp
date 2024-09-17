#include"bits/stdc++.h"
using namespace std;
int searchInRotatedArray(int arr[],int key,int left,int right){
    if(left>right){
        return -1;
    }
    int mid=(left+right)/2;
    if(arr[mid]==key){
        return mid;
    }
    if(arr[left] < arr[mid]){
        if(key<arr[mid]&&key>arr[left]){
            return searchInRotatedArray(arr,key,left,mid-1);
        }
        return searchInRotatedArray(arr,key,mid+1,right);
    }
    if(key<arr[right] && key>arr[mid]){
        return searchInRotatedArray(arr,key,mid+1,right);
    }
    return searchInRotatedArray(arr,key,left,mid-1);

}
int main(){
    int arr[]={30,40,50,5,10,20};
    int key=10;
    cout<<searchInRotatedArray(arr,key,0,5)<<endl;
    return 0;


}