#include "bits/stdc++.h"
using namespace std;
int main(){
    priority_queue<int,vector<int> > hmx;
    hmx.push(1);
    hmx.push(2);
    hmx.push(3);
    cout<<"Max Heap: "<<endl;
    cout<<hmx.top()<<endl;
    hmx.pop();
    cout<<hmx.top()<<endl;
    cout<<endl;
    cout<<"Min Heap: "<<endl;

    priority_queue<int , vector <int>,greater<int> > hmn;
    hmn.push(1);
    hmn.push(2);
    hmn.push(3);
    cout<<hmn.top()<<endl;
    hmn.pop();
    cout<<hmn.top()<<endl;



}