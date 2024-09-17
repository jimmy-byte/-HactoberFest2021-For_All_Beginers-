#include "bits/stdc++.h"
using namespace std;
int main(){
    int n;cin>>n;
    vector <int> a(n);
    for(int i=0;i<n ; i++)
        cin >> a[i];
    sort(a.begin(),a.end());
    long long maxd=0;
    long long mind=0;

    for(int i=0;i<n/2;i++){
        maxd+=a[i+(n/2)];
        maxd-=a[i];
        mind+=a[2*i+1];
        mind-=a[2*i];
    }

    cout<<maxd<<" "<<mind<<endl;
    return 0;



     

}