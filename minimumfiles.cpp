#include"bits/stdc++.h"

using namespace std;
int main(){
    int n;cin>>n;
    vector<int> v(n);
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    priority_queue<int,vector<int>,greater <int> > p;
    for(int i=0;i<n;i++){
        p.push(v[i]);

    }
    int ans=0;
    while(p.size()>1){
        int p1=p.top();p.pop();
        int p2=p.top();p.pop();
        int q=p1+p2;
        ans+=q;
        p.push(q);
    }
    return 0;
    cout<<ans<<endl; 
    
}