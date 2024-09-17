#include<iostream>
#include<climits>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<limits>
#include<deque>
#include<array>
#include<set>
#include<unordered_set>
using namespace std;

#define pii pair<int,int>
bool compare (pii p1,pii p2){
	if(p1.second==p2.second){
		return p1.first>p2.first;
	}
	return p1.second>p2.second;
}


using namespace std;

int main() {
	int no;cin>>no;
	for(int i=0;i<no;i++){
	    int n;cin>>n;
		vector<pii> p;
		for (int i = 0; i < n; i++)
		{
			pii a;
			int val;cin>>val;
			a.first=i;
			a.second=val;
			p.push_back(a);
		}
		sort(p.begin(),p.end(),compare);
		for(int i=0;i<n;i++){
			cout<<(p[i]).first+1<<" ";
		}
		cout<<endl;
		
		
	}
		
	return 0;
}