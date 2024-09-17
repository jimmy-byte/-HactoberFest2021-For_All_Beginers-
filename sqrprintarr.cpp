#include "iostream"

using namespace std;
int main(){
    int row,col;
    cin>>row>>col;
    int arr[row][col];
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        int val;
        cin>>val;
        arr[i][j]=val;


    }
}
int strcnt=0;
int stccnt=0;

 while(strcnt<=row && stccnt<= col){
    int i=strcnt;
    int j=stccnt;
    while(i<=row-1){
        cout<<arr[i][stccnt]<<" ";
        i++;
    }
    while(j<col){
        cout<<arr[row-1][j]<<" ";
        j++;
    }
    while(i>=strcnt){
        cout<<arr[i][col-1]<<" ";
        i++;
    }
    while(j>=stccnt){
        cout<<arr[strcnt][j]<<" ";
        j--;
    }
    col--;
    row--;
    strcnt++;
    stccnt++;
    

}

    return 0;
}