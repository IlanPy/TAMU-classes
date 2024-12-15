from scapy.all import *

# Define the Ethernet frame
ether1 = Ether()
ether1.src = "00:11:22:33:44:55"
ether1.dst = "55:44:33:22:11:00"
ether1.type = 0x0800

# Define the IP packet
pkt = IP()
pkt.src = "192.168.0.1"
pkt.dst = "192.168.0.2"

# Define the TCP segment
tcp1 = TCP()
tcp1.sport = 1234
tcp1.dport = 80

# Define the payload
payload = "Packet crafting is neat!"

# Combine everything into a single packet
packet = ether1/pkt/tcp1/payload

# Print the packet summary
print(packet.show())

# Send the packet on the network
send(packet)
