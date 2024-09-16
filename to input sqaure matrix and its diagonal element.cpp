#include <iostream>

using namespace std;

int main() {
    
int n;
cin>>n;
int arr[n][n];
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++)
       cin>>arr[i][j];
        
    }
    cout<<"Matrix is:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
         cout<<arr[i][j]<<" ";
        
        cout<<"\n";
        
    }
    //for diagonal element//
    cout<<" right Diagonal element are:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            if(i==j){
                cout<<arr[i][j]<<" ";
                cout<<"\n";
            }
    }
    cout<<"left diagonal element:\n";
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            if(i+j==n-1){
                cout<<arr[i][j]<<" ";
                cout<<"\n";
            }
     }
    
    return 0;
}
