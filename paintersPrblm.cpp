#include"bits/stdc++.h"
using namespace std;
int findPainters(int boards[],int n,int limit){
    int sum=0;int num=1;
    for(int i=0;i<n;i++){
        sum+=boards[i];
        if(sum > limit){
            num++;
            sum=boards[i];
        }
    }
    return num;
}
int paintersPartition(int boards[],int n,int m){
    int totalLenght=0;int k=0;
    for(int i=0;i<n;i++){
        k=max(k,boards[i]);
        totalLenght = totalLenght + boards[i];
    }

    int low=k;int high=totalLenght;
    while(low<high){
        int mid=(low+high)/2; 
        int painters=findPainters(boards,n,mid);
        if(painters <= m){
            high=mid;
        }
        else{  
            low=mid+1;
        }
    }
    return low;

}
int main(){
    int boards[]={10,20,30,40};
    int n=4;int m=2;
    cout<<paintersPartition(boards,n,m)<<endl;
    return 0;
}