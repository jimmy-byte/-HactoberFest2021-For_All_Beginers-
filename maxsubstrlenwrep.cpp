#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string str;
    cin>>str;
    int maxLen=0,start=-1;
    vector<int> dict(256,-1);
    for(int i=0;i<str.length();i++){
        if(dict[str[i]] > start){
            start=dict[str[i]];
        }
        dict[str[i]]=i;
        maxLen=max(maxLen,i-start);
    }
    cout<<maxLen<<endl;
    return 0;
}