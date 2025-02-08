import java.util.Random;

public class Matrix_Multiplication implements Runnable {
    private int first_matrix[][];
    private int second_matrix[][];
    private int threadID;

    private int result[][];

    public Matrix_Multiplication(int matrix_a[][], int matrix_b[][], int threadID){
        // Class variables points to matrices
        this.first_matrix = matrix_a;
        this.second_matrix = matrix_b;
        this.threadID = threadID;
        this.result = new int[4][20];
    }

    public int[][] getresult(){
        // Return result
        return this.result;
    }

    public void run(){
        // Use threads to calculate 1/5 of product matrix
        for(int i = 4 * threadID; i < 4 * (threadID + 1); i++){
            for(int j = 0; j < 20; j++){
                result[i - (4 * threadID)][j] = 0;
                for(int k = 0; k < 20; k++){
                    result[i - (4 * threadID)][j] += first_matrix[i][k] * second_matrix[k][j];
                }
            }
        }
    }
    public static void main(String[] args) {
        // Instantiate random object
        Random rnd = new Random();

        // Allocate matrix
        int matrix_A[][] = new int[20][20];
        int matrix_B[][] = new int[20][20];

        // Randomize matrix values
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 20; j++){
                matrix_A[i][j] = rnd.nextInt(10); // Random # from 0 to 9
                matrix_B[i][j] = rnd.nextInt(10); // For easy verification 
            }
        }

        // Instantiate threads & matrix objects
        Thread t[] = new Thread[5];
        Matrix_Multiplication m[] = new Matrix_Multiplication[5];
        for(int i = 0; i < 5; i++){
            m[i] = new Matrix_Multiplication(matrix_A, matrix_B, i);
            t[i] = new Thread(m[i]);
            // Start threads
            t[i].start();
        }

        // Join threads
        try{
            for(int i = 0; i < 5; i++){
                t[i].join();
            }
        } catch(Exception e){
            System.exit(-1);
        }

        // Store Result
        int result[][] = new int[20][20];
        int returned[][];
        for(int i = 0; i < 5; i++){
            returned = m[i].getresult();
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 20; k++){
                    result[j + 4 * i][k] = returned[j][k];
                }
            }
        }

        // Print matrices
        int matrices[][][] = {matrix_A, matrix_B, result};
        String msg = "";
        for(int k = 0; k < 3; k++){
            switch(k){
                case 0: msg = "Matrix A:"; break;
                case 1: msg = "\nMatrix B:"; break;
                case 2: msg = "\nResult:"; break;
            }
            System.out.println(msg);
            for(int i = 0; i < 20; i++){
                System.out.print(matrices[k][i][0]);
                for(int j = 1; j < 20; j++){
                    System.out.print(", " + matrices[k][i][j]);
                }
                System.out.println();
            }
        }
        
    }
}
