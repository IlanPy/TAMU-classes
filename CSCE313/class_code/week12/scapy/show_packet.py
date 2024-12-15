# view mycode.py
#!/usr/bin/env python3
from scapy.all import *

pkt = IP()
pkt.dst = "192.168.1.1"
pkt.src = "192.168.8.14"
pkt.ttl = 16
pkt.len = 61

pkt.show()

# Sending the packet:
# Switch to sudo python3 show_packet.py
send(pkt)

'''
specific_packet = Ether(src="00:11:22:33:44:55", dst="ff:ff:ff:ff:ff:ff")/\
                IP(src="192.168.1.1", dst="192.168.1.2")/\
                TCP(sport=1234, dport=80)
                
specific_packet.show()
sendp(specific_packet) # use sendp
# sendp("i am the goat", loop = 1, inter = 0.2)
# inter: delay between two packets
# loop: send the packet multiple times q?
'''