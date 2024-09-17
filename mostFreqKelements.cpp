#include "bits/stdc++.h"
using namespace std;
signed main(){
    int n;cin>>n;
    int k;cin>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int,int>f;
    for(int i=0;i<n;i++){
        int prSize=f.size();
         if(f[a[i]]==0 && prSize==k){
            break;
        }
        f[a[i]]++;
       

    }
    map <int,int> :: iterator it;

    vector<pair<int,int>  > v;
    for(it=f.begin();it!=f.end(); it++){
        if(it->second!=0 ){
            pair<int,int> p;
            p.first=it->second;
            p.second=it->first;
            v.push_back(p);  
        }
    }

     sort(v.begin(),v.end(),greater< pair <int,int> >() );
     vector<pair<int,int> >:: iterator it1;
     for(it1=v.begin();it1!=v.end();it1++){
         cout<<it1->first<<" "<<it1->second<<endl;
     }

 


    return 0;
}