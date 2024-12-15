import java.io.*;
import java.net.*;

public class BufferClient {
    public static void main(String argv[]) throws Exception {
        String strFromServer;
        
        // Create client socket with argv[0] as server ip
        // & argv[1] as server port and connect to server
        Socket clientSocket = new Socket(argv[0], Integer.parseInt(argv[1]));
        
        // Create input stream attached to socket
        BufferedReader inFromServer =
            new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

        // Read and print line from server
        strFromServer = inFromServer.readLine();
        System.out.println(strFromServer);

        // Close socket
        clientSocket.close();
    }
}
