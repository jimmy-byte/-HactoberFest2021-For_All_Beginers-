#include"bits/stdc++.h"
using namespace std;
signed main(){
    int n;cin>>n;
    vector<int> v={2000,500,200,100,50,20,10,5,2,1};
    int cnt=0;

   
        for(int i=0;i<v.size();i++){

            if(n>=v[i]){
                cnt+= n/v[i];
                n = n - ((cnt)*(v[i]));
            }

        }
   
    cout<<cnt<<endl;
    
}