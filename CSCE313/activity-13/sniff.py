from scapy.all import *

'''
Source MAC address: 00:11:22:33:44:55
Destination MAC address: 55:44:33:22:11:00
Destination IP: 192.168.0.2

Sample output:
SNIFFING PACKETS...
Packet captured
Source IP: 192.168.0.1
Destination IP: 192.168.0.2
Protocol: 6
'''

def print_pkt(pkt):
   print("Packet captured")
   print("Source IP:", pkt[IP].src)
   print("Destination IP:", pkt[IP].dst)
   print("Protocol:", pkt[IP].proto)
    
print("SNIFFING PACKETS...")
packet = sniff(filter='ether src 00:11:22:33:44:55 and dst host 192.168.0.2 and ether dst 55:44:33:22:11:00', prn=print_pkt,timeout=10)