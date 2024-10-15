# Program to print IP Address and Hostname
import socket

def print_ip_hostname():
    hostname = socket.gethostname()
    ip_address = socket.gethostbyname(hostname)
    print("Hostname:", hostname)
    print("IP Address:", ip_address)

print_ip_hostname()
