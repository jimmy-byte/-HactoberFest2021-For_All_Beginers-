#include<iostream>
#include<string>
#include <cmath>

using namespace std;

int makeBill(int khaneka_kharcha,double cgst, double sgst,double service_tax){
    int ans;
    ans =(int) ( khaneka_kharcha + (cgst+sgst+service_tax)*khaneka_kharcha ) ; 
    
    return ans;
}

int main(){
    int khaneka_kharcha;
    double cgst = 0.05; // 150 * 0.05 
    double sgst=0.03; // 150 * 0.03
    double service_tax=0.10; // 
    
    cout<<"Enter Khane ka Kharcha of customer : ";
    cin>>khaneka_kharcha;
    int bill_amount = makeBill(khaneka_kharcha,cgst,sgst,service_tax);
    cout<<"The total bill of customer is : "<<bill_amount<<endl;

    return 0;
} 
