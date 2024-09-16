import java.util.*;

public class Main{

public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);

     // write ur code here
     int n = scn.nextInt();
     int s = n/2+1;
     int t = n/2+1;
     for(int i =1 ; i<=n ;i++){
         for(int j=1 ; j<= n; j++){
             if(i<=n/2 ){
                 if(j==1 || j==n){
                     System.out.print("*\t");
                 }else{
                     System.out.print("\t");
                 }
             }
             else if(i>n/2 ){
                 if(j==1 || j==n || j==t || j==s){
                     System.out.print("*\t");
                 }else{
                     System.out.print("\t");
                 }
             }
         }
         System.out.println();
         if(i>n/2){
             t++;
             s--;
         }
     }

 }
}