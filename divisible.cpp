#include<iostream>
using namespace std;
int main()
{
    int n,d;
     cout<<"Enter the number till you want to print\n";
    cin>>n;
    cout<<"Enter the number with you want to divide\n ";
    cin>>d;
    for(int i=0;i<n;i++){
        if(i%d==0){
            continue;
        }
        else{cout<<i<<endl;}
    }


    return 0;
}