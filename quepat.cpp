#include<iostream>
using namespace std;
int main(){
        int n,j;
        cin>>n;
        for( int i=0;i<n;i++){
            
            for( j=0;j<=i;j++){
                cout<<n-min(i,j)<<" ";
            }
            cout<<n-min(i,j)<<endl;
            for( int j=n;j>i;j--){
                cout<<n-min(i,j)<<" ";
            }cout<<endl;

        }
        for( int i=n;i>0;i--){
            for( int j=0;j<i;j++){
                cout<<n-min(i,j)<<" ";
            }
            cout<<n-min(i,j)<<endl;
            for( int j=n;j>i;j--){
                cout<<n-min(i,j)<<" ";
            }cout<<endl;

        }


    return 0;
}