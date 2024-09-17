#include <iostream>
#include <stack>
using namespace std;
class queue{
    stack <int> s;
    public:
    void push(int x){
        s.push(x);
        return;
    }

    int pop(){
        if(s.empty()){
            cout<<"No elements to delete ";
            return -1;
        }
        int x=s.top();
        s.pop();
        if(s.empty()){
            return x;
        }
        int item=pop();
        s.push(x);
        return item;

        


    }
    bool empty(){
        return s.empty();
    }


};
int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.empty()<<endl;
    return 0;
}