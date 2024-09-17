#include<iostream>
using namespace std;
int fib(int n){
    if(n==0 || n==1)    //Base case because we know that fibonacci of 0 and 1 are 0 nd 1 resp. 
   { return n;}

   return fib(n-1)+fib(n-2); //property of fibonacci Nos.

}
int main(){
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}