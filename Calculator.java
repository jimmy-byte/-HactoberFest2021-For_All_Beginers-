
import java.util.Scanner;
public class Calculator {
    public static void main(String[] args) {
        while (true){
            System.out.println();
            System.out.println("please enter space separated equation with one mathematical operation:");
            System.out.println("for ex: 3 + 5, 7 - 10, 78 / 89, 45*12, 10 ! 0(gives you factorial of the first number!)");
            System.out.print("enter the equation: ");
            Scanner in = new Scanner(System.in);
            double num1, num2;
            char operation;
            num1 = in.nextDouble();
            operation = in.next().charAt(0);
            num2 = in.nextDouble();
            double ans = 1;
            switch (operation) {
                case '+' -> ans = num1 + num2;
                case '-' -> ans = num1 - num2;
                case '/' -> ans = num1 / num2;
                case '*' -> ans = num1 * num2;
                case '!' -> {
                    //factorial logic
                    for (int i = 1; i <= num1; i++) {
                        ans = ans * i;
                    }
                }
                default -> {
                    System.out.println("please enter a valid equation!");
                    continue;
                }
            }
            System.out.println(num1 + " " + operation + " " + num2 + " " + "=" + " " + ans );
        }
    }
}