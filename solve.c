#include <stdio.h>
#include<math.h>
void solve(double meal_cost,int tax_p,int tip_p){
    double sum;
    sum=meal_cost + ((tax_p*meal_cost)/100) + ((tip_p*meal_cost)/100) ;
    printf("%.0lf",sum);
    
}

int main(){
    int tax_p,tip_p;
    double meal_cost;
    scanf("%lf %d %d",&meal_cost,&tax_p,&tip_p);
    solve(meal_cost,tax_p,tip_p);
return 0;
}