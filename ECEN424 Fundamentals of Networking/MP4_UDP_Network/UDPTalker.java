import java.io.*;
import java.net.*;

public class UDPTalker {
    /*
     * >./UDPTalker <talker port> <listener port> <msg>
     */
    public static void main(String[] args) throws Exception {
        // Edge Case Handling
        if(args.length != 3 || args[2].length() > 50){
            System.out.println("Command: ./UDPTalker <talker port> <listener port> <msg>");
            System.exit(-1);
        }

        // Ensure 5 messages of 10 characters each
        String msg = args[2];
        msg = msg + "_".repeat(50 - msg.length());
        String[] messages = new String[6];
        messages[0] = "0" + 5;
        for(int i = 0; i < 5; i++) {
            messages[i+1] = (i+1) + msg.substring(i*10, (i+1)*10);
        }

        // Translate IP address using DNS
        int listenerPort = 0, talkerPort = 0;
        try{
            listenerPort = Integer.parseInt(args[1]);
            talkerPort = Integer.parseInt(args[0]);
            // Valid ports between 0 and 65535
            if(talkerPort > 65535 || listenerPort > 65535 || talkerPort < 0 || listenerPort < 0){
                throw new Exception("Invalid port");
            }
        } catch(Exception e){
            System.out.println(e);
            System.out.println("Command: ./UDPTalker <talker port> <listener port> <msg>");
            System.exit(-1);
        }
        
        // Create talker socket
        DatagramSocket talkerSocket = new DatagramSocket(talkerPort);

        byte[] sendData = new byte[1024];
        byte[] receiveData = new byte[1024];

        // Listen for request
        DatagramPacket receivePacket =
            new DatagramPacket(receiveData, receiveData.length);
        while(true){
            talkerSocket.receive(receivePacket);
            String message = new String(receivePacket.getData(), 0, receivePacket.getLength());
            System.out.println("FROM LISTENER: " + message);
            if(message.equals("Requesting connection")){
                break;
            }
        }
        InetAddress listenerIPAddress = receivePacket.getAddress();

        // Send UDP connection request for ACK
        sendData = "ACK connection".getBytes();
        DatagramPacket sendPacket =
            new DatagramPacket(sendData, sendData.length, listenerIPAddress, listenerPort);
        System.out.println("TO LISTENER: " + "ACK connection");
        talkerSocket.send(sendPacket);
        
        // Set timeout for .receive
        talkerSocket.setSoTimeout(2000);

        for(int i = 0; i < 6; i++){
            sendData = new byte[1024];
            receiveData = new byte[1024];
            sendData = messages[i].getBytes();

            // Create datagram with data-to-send, length, IP addr, port
            sendPacket =
                new DatagramPacket(sendData, sendData.length, listenerIPAddress, listenerPort);

            // Send datagram to listener
            System.out.println("TALKER SENDING: " + messages[i]);
            talkerSocket.send(sendPacket);

            receivePacket =
                new DatagramPacket(receiveData, receiveData.length);

            try{
                // Read datagram from listener
                talkerSocket.receive(receivePacket);
            } catch(Exception e){
                --i; // Resend
                continue;
            }

            // Define ack from received packet
            String ack =
                new String(receivePacket.getData());

            System.out.println("FROM LISTENER: ACK#" + ack);
        }
        // Close connection
        talkerSocket.close();
    }
}
