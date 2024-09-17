//Author: AnubhavChakrabortyNits
//Q: Linear Search using Arrays

#include<iostream>


using namespace std;


int linearSearch(int arr[],int target,int length){
    for(int i=0;i<length;i++){
        if(arr[i]==target){
            return i;                        //Time Complexity: O(n)
                 }                           //Space Complexity O(1)
    }
    return -1;
}

int main(){


int arr[]={1,2,5,7,9,10}; // initialise array


int index=linearSearch(arr,7,sizeof(arr)/sizeof(int)); //Calling the linearSearch function


if(index!=-1){           
    cout<<"Element Fount at index "<<index; //if element is found then index of the element is returned
}
else{
    cout<<"Element Does Not Exist in the Array";   //if element is not found -1 is returned
}


    return 0;
}