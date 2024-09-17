#include"bits/stdc++.h"
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    map<int,int> f;
    for(int i=0;i<n;i++){
        f[v[i]]++;
    }
    map<int,int> ::  iterator it;
    for(it=f.begin();it!=f.end();it++){
        cout<< it->first <<" "<<it->second<<endl;
    }
    return 0;

}