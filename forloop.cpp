#include<iostream>
using namespace std;
int main(){
     int sum=0;
     int n,d;
     cout<<"Enter last term and diffrence in order\n";
     cin>>n>>d;
     for(int ctr=1;ctr<=n;ctr=ctr+d){
         sum=sum+ctr;
     }
     cout<<sum<<endl;
      
    return 0;
}