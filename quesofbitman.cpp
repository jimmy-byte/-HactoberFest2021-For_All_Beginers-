#include<iostream>
using namespace std;
bool powerof_2(int n){
    if(!(n&&(n&(n-1))))
        return true;
        else return false;

}
int noof_ones(int n){
    int ctr=0;
    while(n>0){
        n=(n&(n-1));
        ctr++;


    } 
    return ctr;
}
int main(){
        int n;
        cin>>n;
        //For power of 2;
        //bool i= powerof_2(n);
        //if(i)
        //cout<<"Power of 2"<<endl;
        //else
        //cout<<"Not power of 2"<<endl;
        //To fone number of ones in binary representation
        int j=noof_ones(n);
        cout<<j<<endl;



    return 0;
}