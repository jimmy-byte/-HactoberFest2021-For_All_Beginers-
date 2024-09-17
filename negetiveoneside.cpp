#include<vector>
#include <bits/stdc++.h>
using namespace std;
int main(){

  /*   //firstwe will define numeric string;
     string str; 
     //input the string with space..
     getline(cin,str);
sort(str.begin(),str.end());
  cout<< str <<endl;
// for printing with space
for (int i=0;i<str.length();i++){
    cout<<str[i]<<" ";

}
cout<<endl;


    return 0;*/
    
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        v.push_back(val);
    }
    vector<int>::iterator it;
    for(int i=0;i<v.size();i++){
        int temp = v[i];
        if(temp<0){
             v.insert(v.begin(), temp);
        }
    }
vector<int>::iterator pt;//it is like pointer over here
    for(pt=v.begin();pt !=v.end();pt++){
        cout<<*pt<<" ";
    }cout<<endl;

    return 0;
}