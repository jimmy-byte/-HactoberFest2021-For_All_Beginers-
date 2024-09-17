#include<iostream>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
    #endif
    int a,b,c;
    cin>>a>>b>>c;

    if(a>b){
                if(a>c)
                        {
                            cout<<"a is highest\n";
                        }
                else
                        {
                            cout<<"c is highest\n";
                        }
            }
    else
    {
        
                if(b>c)
                    {
                      cout<<"b is highest\n";
                    }
        
                else
                    {
                     cout<<"c is highest";
                }        
        
        
    }
}