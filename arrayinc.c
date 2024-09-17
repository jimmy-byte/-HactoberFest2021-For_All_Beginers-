#include<stdio.h>
#include<math.h>

// Increase each element of array by k 
void increase(int *p,int n, int k ){
    for(int i=0;i<n;i++){
      (*p) = (*p) + k;
      p++;
    }
    return;
}

void display(int *p,int n){
    for(int i=0;i<n;i++){
      printf("%d ", *p);
      p++;
    }
    printf("\n");
    return;
}



int main(){
    
    int a[] = {5,10,15,0,3};
    display(a,5);
    printf(" After Increasing: ");
    increase(a,5,15000);

    display(a,5);


  return 0;
}
