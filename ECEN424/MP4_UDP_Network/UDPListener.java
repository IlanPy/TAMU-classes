import java.io.*;
import java.net.*;
import java.util.ArrayList;
import java.util.Random;

public class UDPListener {
    /*
     * ./UDPListener <listener port> <talker port> <talker ip>
     */
    public static void main(String[] args) throws Exception {
        // Edge Case Handling
        if(args.length != 3){
            System.out.println("Command: ./UDPListener <listener port> <talker port> <talker ip>");
            System.exit(-1);
        }

        Random random = new Random();

        // Create datagram socket at port 
        int listenerPort = 0, talkerPort = 0;
        InetAddress IPAddress = null;
        try{
            listenerPort = Integer.parseInt(args[0]);
            IPAddress = InetAddress.getByName(args[2]);
            talkerPort = Integer.parseInt(args[1]);
            // Valid ports between 0 and 65535
            if(talkerPort > 65535 || listenerPort > 65535 || talkerPort < 0 || listenerPort < 0){
                throw new Exception("Invalid port");
            }
        } catch(Exception e){
            System.out.println(e);
            System.out.println("Command: ./UDPListener <listener port> <talker port> <talker ip>");
            System.exit(-1);
        }
        DatagramSocket listenerSocket = new DatagramSocket(listenerPort);

        byte[] receiveData = new byte[1024];
        byte[] sendData = new byte[1024];

        // Prepare packets & data
        sendData = "Requesting connection".getBytes();
        DatagramPacket sendPacket =
            new DatagramPacket(sendData, sendData.length, IPAddress, talkerPort);
        DatagramPacket receivePacket = 
            new DatagramPacket(receiveData, receiveData.length);
        listenerSocket.setSoTimeout(2000);

        while(true){
            // Send UDP connection request to talker
            listenerSocket.send(sendPacket);

            // Listen for ACK request from talker
            try{
                listenerSocket.receive(receivePacket);
                String message = new String(receivePacket.getData(), 0, receivePacket.getLength());
                if ("ACK connection".equals(message)){
                    break;
                }
            } catch(Exception e){
                continue;
            }
        }
        // Reset timeout
        listenerSocket.setSoTimeout(0);

        String finalMsg = "";
        int numOfMsgs = 0;
        int i = 0;
        ArrayList<String> messages = new ArrayList<String>();
        
        while(true) {
            receiveData = new byte[1024];
            sendData = new byte[1024];
            // Create space for received datagram
            receivePacket = 
                new DatagramPacket(receiveData, receiveData.length);
            
            // Receive datagram
            listenerSocket.receive(receivePacket);
            String message = new String(receivePacket.getData());

            // Get IP addr, port # of sender
            IPAddress = InetAddress.getByName(args[2]);
            int port = Integer.parseInt(args[1]);
            
            // Define ACK with sequence number of the next message
            String ack = Integer.toString(Integer.parseInt(message.substring(0, 1)) + 1);
            
            // If first message, extract number of messages
            if(i == 0){
                numOfMsgs = Integer.parseInt(message.substring(1).trim());
            }
            
            sendData = ack.getBytes();

            // Do not send ACK with 0.5 probability
            if(random.nextBoolean()){
                continue;
            }
            // Create datagram to send client
            sendPacket =
                new DatagramPacket(sendData, sendData.length, IPAddress, port);
            
            // If not first message, concatenate messages
            if(i != 0 ){
                messages.add(message.substring(1));
            }
            
            // Write out datagram to socket
            listenerSocket.send(sendPacket);

            if(i == numOfMsgs){
                break;
            }
            i++;
        }
        // Close connection, concatenate and display message
        listenerSocket.close();
        for(i = 0; i < numOfMsgs; i++){
            finalMsg += messages.get(i);
        }
        System.out.println(finalMsg);
    }
}
