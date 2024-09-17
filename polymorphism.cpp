#include <iostream>
using namespace std;

class fnsoverload{
    public:
    void fun(){
        cout<<"This is the function with no args "<<endl;
    }
    void fun(int n){
        cout<<"This is the function with int"<<endl;
    }
    void fun(double b){
        cout<<"This is the function with double args "<<endl;
    }
    

};

class rntmpolyBase {
    public:
   virtual  void fun(){
        cout<<"This is the function with no args of base class"<<endl;
    }
    void fun(int n){
        cout<<"This is the function with int  args of base class"<<endl;
    }
    void fun(double b){
        cout<<"This is the function with double args of base class"<<endl;
    }

};
class rntmpolyDerived: public rntmpolyBase {
    public:
    void fun(){
        cout<<"This is the function with no args of derived class"<<endl;
    }
    void fun(int n){
        cout<<"This is the function with int  args of derived class"<<endl;
    }
    void fun(double b){
        cout<<"This is the function with double args of derived class"<<endl;
    }

};

class Complex{
    private:
    int real,img;
    public:

    Complex(int r=0 , int i=0){
        real=r;
        img=i;

    }
    Complex operator + (Complex const &obj){
    Complex res;
    res.img= img + obj.img;
    res.real = real + obj.real;
    return res;
}
void display(){
    cout<<real<<"+i"<<img<<endl;
}
};
int main(){
    fnsoverload d;
    d.fun();
    d.fun(3);
    d.fun(3.9);
    Complex c1(1,3);
    Complex c2(2,8);
    Complex c3=c1+c2;
    c3.display();


    rntmpolyBase *baseptr;
    rntmpolyDerived x;
    baseptr = &x;
    baseptr -> fun();
    baseptr -> fun(9);
    baseptr -> fun(9.5);


    return 0;
}
