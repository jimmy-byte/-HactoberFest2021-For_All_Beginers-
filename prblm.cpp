#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
int ToFind(int tofind , vector <int> Y, int n ){
    int x= tofind;
    for(int j=0;j<n;j++){
        if(tofind==Y[j]){
            return j+1;
        }         
    }
    return 0;
}
int  notFounded(int Tofind, vector<int> Y,int n){
    Tofind++;
    if(ToFind(Tofind,Y,n)){
        return ToFind(Tofind,Y,n);
    }
    else{
       return  notFounded(Tofind,  Y, n);
    }

}


int main() {
    vector<int> y;
    vector <int> Q;
     int n,Qno;
     cin>>n;
     for(int i=0;i<n;i++){
         int val;
         cin>>val;
         y.push_back(val);
     }
     cin>> Qno;
     for(int i=0;i<Qno;i++){
         int Qval;
         cin>>Qval;
         Q.push_back(Qval);
         
     }

     for(int i=0;i<Qno;i++){
         int tofind=Q[i];
         
          if(ToFind(tofind, y,n)){
              cout<<"Yes "<<ToFind(tofind, y,n)<<endl;
          }
          else{
              

              cout<<"No "<<notFounded(tofind, y,n)<<endl;
          }
     }
     
    return 0;
}
