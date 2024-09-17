#include "bits/stdc++.h"
using namespace std;
int main(){
    int k;
    cin>>k;
    vector<vector<int> > a(k);
    for(int i=0;i<k;i++){
        int size;cin>>size;
        a[i]=vector<int> (size);
        for(int j=0;j<size;j++){
            cin>>a[i][j];
        }

    }
    vector<int> idx(k,0);
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater <pair<int,int> > > minh;
    for(int i=0;i<k;i++){
        pair<int,int>p;
        p.first=a[i][0];
        p.second=i;
        minh.push(p);
    }
    vector<int> ans; 
    while(!minh.empty()){
        pair<int, int> el=minh.top();
        minh.pop();
        ans.push_back(el.first);
        
        if(idx[el.second]+1<a[el.second].size()){
            pair<int,int> x;
            x.first=a[el.second][idx[el.second]+1];
            x.second=el.second;
            minh.push(x);
             
        }
        idx[el.second]+=1;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";

    }
    cout<<endl;


    return 0;

}