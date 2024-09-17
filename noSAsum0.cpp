#include "bits/stdc++.h"
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int pref=0;
    map<int,int> m;
    for(int i=0;i<n;i++){
         pref+=v[i];
         m[pref]++;
    }
    int ans=0;
    map<int,int> :: iterator it;
    for(it=m.begin();it!=m.end();it++){
        int s=it->second;
        ans+= (s*(s-1))/2;
        if(it->first==0){
            ans+= it->second;
        }

    }
    cout<< ans <<endl;
    
    

}