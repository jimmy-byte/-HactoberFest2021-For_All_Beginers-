#include"bits/stdc++.h"
using namespace std;
bool compare(pair<int,int>p1,pair<int,int> p2){
    double vw1=(double) p1.second/p1.first;
    double vw2=(double) p2.second/p2.first;
    return vw1>vw2;
}
int main(){
    int n;cin>>n;
    vector<pair<int,int> > p(n);

    for(int i=0;i<n;i++){
        cin>>p[i].first>>p[i].second;
    }
    int w;cin>>w;
    sort(p.begin(),p.end(),compare);
    int ans=0;

    for(int i=0;i<n;i++){
        if(p[i].first<=w){
            ans+=p[i].second;
            w-=p[i].first;
            continue;
        }
        double vw=(double) p[i].second/p[i].first;
        ans+=vw*w;
        w=0;
        break;
    }
    cout<<ans<<endl;

    return 0;
}