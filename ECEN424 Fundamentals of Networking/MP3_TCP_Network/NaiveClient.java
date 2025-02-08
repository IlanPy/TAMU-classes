import java.io.*;
import java.net.*;

public class NaiveClient {
    public static void main(String argv[]) throws Exception {
        // Create client socket with argv[0] as server ip
        // & argv[1] as server port and connect to server
        Socket clientSocket = new Socket(argv[0], Integer.parseInt(argv[1]));
        
        // Create input stream attached to socket
        BufferedReader inFromServer =
            new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        
        // Read and print one character at a time from server
        char character;
        while(true){
            character = (char)inFromServer.read();
            System.out.print(character);
            if(character == '\n'){
                break;
            }
        }

        // Close socket
        clientSocket.close();
    }
}
