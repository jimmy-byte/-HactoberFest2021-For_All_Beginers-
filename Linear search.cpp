#include<iostream>
using namespace std;

void LinearSearch(int arr[], int len, int item)
{

    for(int i=0;i<len;i++)
    {
        if(arr[i] == item)
        {
            cout << item << " Found at index : " << i;
            return;
        }
    }
    cout << "Not found";
    
}

int main() 
{
    int arr[] = {10, 5, 15, 21, -3, 7};
    
    // calculating length of array
    int len = sizeof(arr)/sizeof(arr[0]);
    
    // item to be searched
    int item = 21;
    LinearSearch(arr, len, item);

    return 0;
}