import java.io.*;
import java.net.*;
import java.util.concurrent.atomic.AtomicInteger;

public class TCPServer implements Runnable {
    private static String sentence;
    private static int N;
    private static AtomicInteger count = new AtomicInteger(0);
    private Socket connectionSocket;

    public TCPServer(Socket socket) {
        this.connectionSocket = socket;
    }

    public void run(){
        try{
            // Create output stream attached to socket
            DataOutputStream outToClient =
                new DataOutputStream(connectionSocket.getOutputStream());

            // Send sentence N times to client with 1 second pauses
            for(int i = 0; i < N - 1; i++){
                outToClient.writeBytes(sentence);
                Thread.sleep(1000);
            }
            outToClient.writeBytes(sentence + '\n');

            // Close connection
            connectionSocket.close();
        } catch(Exception e){
            System.out.println(e.getMessage());
        }
        // Decrement client count
        count.decrementAndGet();
    }
    public static void main(String argv[]) throws Exception {
        // Set max_clients as argv[1]
        int max_clients = Integer.parseInt(argv[1]);
        
        // Create input stream attached to system input
        BufferedReader inFromUser =
            new BufferedReader(new InputStreamReader(System.in));

        // Ask user for string and integer
        System.out.print("Enter a string: ");
        sentence = inFromUser.readLine();
        System.out.print("Enter a positive integer: ");
        N = Integer.parseInt(inFromUser.readLine());

        // Create welcoming socket at port argv[0]
        ServerSocket welcomeSocket = new ServerSocket(Integer.parseInt(argv[0]));

        while(true){
            // Only allow connection when available space
            if(count.get() < max_clients){
                // Wait for contact by client
                Socket connectionSocket = welcomeSocket.accept();
                // Count client when connected
                count.incrementAndGet();

                // Instantiate and start thread using TCPServer object
                Thread t = new Thread(new TCPServer(connectionSocket));
                t.start();
            }
        }
    }
}
