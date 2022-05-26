//program to pay workers based on hours worked
import javax.swing.*;
import java.util.*;

class computeSalary{
    public static void main(String[] args) {
     double amount = 0;
        //inputing hours worked from user into the program
        Scanner myScanner = new Scanner(System.in);
        System.out.println("Enter the number of hours(per week) worked"); 
        double hours = myScanner.nextDouble();

          if(hours <= 0)
          {
              System.out.println("Incorrect hours worked!");
          }
          else if(hours <= 30)
          {
              amount = hours * 850;
          }
          else if(hours > 30)
          {
              hours = hours - 30;
              amount = hours * 920;
          }
          else if(hours <= 20) {
               amount = hours * 600;
          }
          amount = amount * 4 * 12;
          System.out.println();
          System.out.println("The Amount before Deductions is\t" +amount);
          //putting into account all govennment taxes
          amount = (amount - 200 - 400 - (amount * 0.04));
         
         //the amount after deductions is below this
         System.out.println("The Final Net Salary you have is\t" +amount);
          
    }
}