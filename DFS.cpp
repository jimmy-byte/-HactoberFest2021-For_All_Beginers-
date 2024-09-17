#include"bits/stdc++.h"
using namespace std;
const int N=1e5+2;
vector<int> adj[N];
bool vis[N];

void dfs(int node){
    vis[node]=true;
    
    vector<int> :: iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++) {
        if(vis[*it]) ;
        else{
            dfs(*it);
        }
    }
    cout<<node<<" ";
}

signed main(){
    int m,n;
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        vis[i]=false;
    }
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    return 0;

}