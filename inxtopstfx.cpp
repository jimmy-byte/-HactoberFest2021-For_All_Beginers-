#include <iostream>
#include <stack>
using namespace std;

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

string infixToPostfix(string s){
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

    return res;
    

}

int main(){
    string str="(a-b/c)*(a/k-l)";
    cout<<infixToPostfix(str)<<endl;
    return 0;
}