#include <iostream>
using namespace std;

int main(){
    int a = 11;
    int* aptr =&a;
    cout<<*aptr<<endl;
    cout<<aptr<<endl;
    return 0;
}