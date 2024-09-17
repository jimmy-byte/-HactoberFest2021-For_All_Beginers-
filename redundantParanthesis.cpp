#include <iostream>
#include <stack>
using namespace std;
bool redundantParanthesis(string s){
    stack<char> st;
    int n=s.size();
    for (int i=0;i<n;i++){
        if(s[i]=='('|| s[i]=='+'|| s[i]=='-' || s[i]=='*'|| s[i]=='/'){
                st.push(s[i]);
        }
        else if(!st.empty() && s[i]==')'){
            if(st.top()=='('){
                return true;
            }
            while(!st.empty() && st.top() !='('){
                st.pop();
            }
            st.pop();

        }

    }
    return false;
}
int main(){
    string str;
    str="(((a+b)+c))";
    cout<<redundantParanthesis(str)<<endl;
    return 0;


}