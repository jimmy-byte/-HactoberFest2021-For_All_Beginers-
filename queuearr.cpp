#include <iostream>
using namespace std;
#define n 20
class queue{
    int front;
    int back;
    int* arr;
    public:
    queue(){
        arr=new int[n];
        front=-1;
        back=-1;
    }
    void push(int x){
        if(back==n-1){
            cout<<"Queue Overflow"<<endl;
        }
        back++;
        arr[back]=x;
        if(front==-1){
            front++;
        }
    }

    void pop(){
        if(front>back || front==-1){
            cout<<"No elements to delete"<<endl;
        }
        front++;
    }

    int peek(){
        if(front>back || front==-1){
            cout<<"No elements to show"<<endl;
        }
        return arr[front];

    }

    bool empty(){
        if(front>back || front==-1){
         return true;
        }

        return false;

    }

};

int main(){
    queue qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    cout<<qu.peek()<<endl;
    qu.pop();
    cout<<qu.peek()<<endl;

    cout<<qu.empty()<<endl;
    qu.pop();
    qu.pop();
    qu.pop();
    cout<<qu.empty()<<endl;
    qu.pop();
    cout<<qu.empty()<<endl;

    
    return 0;
}