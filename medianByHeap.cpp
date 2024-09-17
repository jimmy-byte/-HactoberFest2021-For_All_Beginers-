 #include "bits/stdc++.h"
 using namespace std;

priority_queue<int,vector<int> > maxh;
priority_queue<int,vector<int>,greater<int> > minh;

void insert(int x){
    if(maxh.size()==minh.size()){
        if(maxh.size()==0){
            maxh.push(x);
            return; 
        }
        if(x<maxh.top()){
            maxh.push(x);
         }
        else{
            minh.push(x);
        }
    }
    else{
        if(maxh.size()>minh.size()){
            if(x>=maxh.top()){
                minh.push(x);
            }
            else{
                int temp=maxh.top();
                maxh.pop();
                minh.push(temp);
                maxh.push(x);
            }
        }
        else if(maxh.size()<minh.size()){
            if(x<=minh.top()){
                maxh.push(x);
            }
            else{
                int temp=minh.top();
                minh.pop();
                maxh.push(temp);
                minh.push(x);
            }
        }
    }
}

void findMedian(){
    if(maxh.size()==minh.size()){
        cout<< (maxh.top()+minh.top())/2.0 <<endl;
    }
    else if(maxh.size()>minh.size()){
        cout<<maxh.top()<<endl;
    }
    else{
        cout<<minh.top()<<endl;
    }
}



int main(){
    insert(10);
    findMedian();
    insert(15);
    findMedian();
    insert(21);
    findMedian();
    insert(30);
    findMedian();
    insert(18);
    findMedian();
    insert(19);
    findMedian();
    return 0;

}


