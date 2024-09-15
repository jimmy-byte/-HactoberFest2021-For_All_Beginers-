/*CODE FOR POWER OF NUMBERS USING MODULO OPERATOR*/
#include<bits/stdc++.h>
using namespace std;
long long int power(long long int n,long long int r){
if(r==1)return n;
int x=power(n,r/2),m=1000000007;
if(r%2==0){
return ((x%m*x)%m)%m;}
else
return ((x%m * n)%m*x)%m;}

int main(){
long long int n;
long long int r;
cin>>n;
cin>>r;
long long int c=power(n,r);
cout<<c<<endl;
return 0;}

