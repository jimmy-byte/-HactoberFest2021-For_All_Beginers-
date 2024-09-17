#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
                cout<<"  ";


        }
        for(int m=i;m>1;m--)
        {
            cout<<m<<" ";
        }
        for(int k=1;k<=i;k++){
            cout<<k<<" ";
        }
        for(int l=1;l<=n-i;l++){
                cout<<"  ";
        }
        cout<<endl;
    }


    return 0;
}