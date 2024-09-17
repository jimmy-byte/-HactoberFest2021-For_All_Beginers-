#include<iostream>
#include <stack>
#include<vector>
using namespace std;
int rainWater(vector <int> a){
    int n=a.size();
    stack<int> st;
    int res=0;
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]<a[i]){
            int cur=a[st.top()];
            st.pop();
            if(st.empty()){
                break;
            }
            int diff=i-1-st.top();
             res+= (min(a[st.top()],a[i])-a[cur])*diff;





        }

        st.push(i);
    }
    return res;
}


int32_t main(){
    
        int arr[]={0,1,0,2,1,0,1,3,2,1,2,1};


    vector <int> a;

    for(int i=0;i<12;i++){
        a.push_back(arr[i]);
    }
    cout<<rainWater(a)<<endl;

    return 0;




}