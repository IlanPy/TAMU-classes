import java.util.Scanner;

public class Calculator {
    private String name;

    public Float addition(Float A, Float B){
        return A + B;
    }  
    
    public Float subtraction(Float A, Float B){
        return A - B;
    }

    public Float multiplication(Float A, Float B){
        return A * B;
    }

    public void setname(String N){
        name = N;
    }

    public String getname(){
        return name;
    }

    public static void main(String[] args){
        // Instantiate Calculator & Scanner objects
        Calculator mycalc = new Calculator();
        Scanner input = new Scanner(System.in);

        // Set group name
        String name = "Group 13";
        mycalc.setname(name);

        // Welcome message
        String welcome_msg = "Welcome to the Calculator designed by "
                            + mycalc.getname() + ".";
        String options = "Enter A to Add, S to Subtract, M to Multiply, and Q to quit.";

        while(true){
            // Output Welcome message
            System.out.println(welcome_msg);
            System.out.println(options);

            // Read input
            String choice = input.nextLine();
        
            if(choice.equals("Q")){
                // Terminate when Q is entered
                break;
            }
            else if(!choice.equals("A") && !choice.equals("S") && !choice.equals("M")){
                // Return to Welcome message for invalid input
                System.out.println();
                continue;
            }
            
            String arg1, arg2;
            Float arg1_fl, arg2_fl;
            try {
                // Ask for argument 1
                System.out.println("Enter argument 1");
                arg1 = input.nextLine();
                arg1_fl = Float.parseFloat(arg1);

                // Ask for argument 2
                System.out.println("Enter argument 2");
                arg2 = input.nextLine();
                arg2_fl = Float.parseFloat(arg2);
            }
            catch(Exception e) {
                // Return to Welcome message for invalid input
                System.out.println();
                continue;
            }

            Float result;
            String operation;
            switch(choice){
                case "A":
                    result = mycalc.addition(arg1_fl, arg2_fl);
                    operation = "addition";
                    break;
                case "S":
                    result = mycalc.subtraction(arg1_fl, arg2_fl);
                    operation = "subtraction";
                    break;
                case "M":
                    result = mycalc.multiplication(arg1_fl, arg2_fl);
                    operation = "product";
                    break;
                default:
                    continue;
            }
            // Print answer
            String answer = "The " + operation + " of " + arg1 + " and " 
                + arg2 + " is " + result + "\n";
            System.out.println(answer);
        }
        // Close Scanner
        input.close();
    }
}