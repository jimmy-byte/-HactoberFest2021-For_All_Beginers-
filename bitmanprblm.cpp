#include<iostream>
using namespace  std;
int setBit_2(int n,int pos){
    return (n &(1<<pos)!=0);
}
int unique(int a[], int n){
    int xorsm=0;
    for(int i=0;i<n;i++){
        xorsm=xorsm^a[i];
    }
    return xorsm;
}
void unique_2(int arr[],int n ){
    int xorsum = unique(arr,n);
    int tempxor=xorsum;
    int setbit=0;
    int pos=0;
    while(setbit!=1){
        setbit=xorsum & 1;
        pos++;
        xorsum=xorsum>>1;


    }//Here we found out xor of two unique no
    int newxr=0;
    for(int i=0;i<n;i++){
        if(setBit_2(arr[i],pos-1)){
            newxr=newxr^arr[i];
        }
    }//we found out a no which is one of unique
    cout<< newxr<<endl;
    cout << ((tempxor)^(newxr)) << endl;//Here we changed a bit and got desired other no
}

bool getBit_3(int n, int pos){
    return((n & (1<<pos))!=0);
}
int setBit_3(int n, int pos){
    return( n | (1<<pos));
}
int unique_3(int arr[], int n){
    int result=0;
    for(int i=0;i<64;i++){
        int sum=0;
        
        for (int j=0;j<n;j++){
            if(getBit_3(arr[j],i))
            sum++;
        }
        if((sum%3)!=0){
            result=setBit_3(result,i);
        }
    }
    return result;
}
int main (){

    /* for unique element
   // int a[]={1,2,3,4,3,2,1};//used for this types of array only in which all number are present twice except one
    //cout<<unique(a,7)<<endl;
     */
    /*For unique two elements amongst duets
    int a[]={2,2,1,3,3,4,6,6};//here 2 unique number and all others are present twice
    unique_2(a,8);*/

    //For unique element amongst triplets
    int a[]={1,2,3,1,2,3,4,1,2,3};
    cout<< unique_3(a,10) <<endl;
    return 0;
}