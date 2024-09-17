#include<iostream>
#include<stdio.h>
#include <stack>
using namespace std;

string reverseString(string s){
    string res;
    for(int i=(s.length()-1);i>=0;i--){
        if(s[i]==')'){
            res+='(';
        }
        else if(s[i]=='('){
            res+=')';
        }
        else{
            res+=s[i];
        }
    }
    return res;
}
int precdense(char c){
    if(c=='^'){
        return 3;
    }
    if(c=='*' || c=='/'){
        return 2;
    }
    if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
string infixToPrefix(string s){
    s=reverseString(s);
    stack<char> st;
    string res;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a'&& s[i]<='z') || (s[i]>='A'&&s[i]<='Z')){
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]); 
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if((!st.empty()) && (precdense(st.top())>precdense(s[i]))){
                res+=st.top();
                st.pop();

            }
            st.push(s[i]);
        }

    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    
    return reverseString(res);
    

}
int main(){
    string str="(a-b/c)*(a/k-l)";
    cout<<infixToPrefix(str)<<endl;
    return 0;
}