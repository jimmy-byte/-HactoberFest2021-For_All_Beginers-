#include<iostream>
using namespace std;
void primefactorSieve(int n){
    int spf[n+1]={0};
    for(int i=2;i<=n;i++){
        spf[i]=i;
    }
    for(int i=2;i<n;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=n;j+=i){

                spf[j]=i;
            }
        }
    }

    while(n!=1){
        cout<<spf[n]<<" ";
        n=n/spf[n];
    }
    cout<<endl;

}
void primeSieve(int n){
         int prime[100]={0};
        for(int i=2;i<=n;i++){
        
            if(prime[i]==0){
                for(int j=i*i;j<=n;j=j+i){
                    prime[j]=1;
                }
            }
        } 



    for(int i=2;i<=n;i++){
        if(prime[i]==0)
           { cout<<i<<endl;}
    }   
    
   
}

int main(){
    int n;
    cin>>n;
    //primeSieve(n);
    primefactorSieve(n);
    return 0;




}