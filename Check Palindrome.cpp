#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    string rev_str;
    for (int i = str.size() - 1 ; i>=0; --i)
    {
        rev_str.push_back(str[i]);
    }
    if(str == rev_str)
    {
        cout<<"Yes,it is palindrome"<<endl;
    }
    else 
    {
        cout<<"No,it is not a palindrome"<<endl;
    }
}