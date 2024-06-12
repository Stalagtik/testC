import socket

SERVER_IP = "127.0.0.1"
SERVER_PORT = 8080
BUFFER_SIZE = 1024

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind((SERVER_IP, SERVER_PORT))
server_socket.listen(1)
print("Server listening on {}:{}".format(SERVER_IP, SERVER_PORT))

conn, addr = server_socket.accept()
print("Connection from:", addr)

data = conn.recv(BUFFER_SIZE)
print("Received message:", data.decode())

conn.send(b"Hello from server!")
conn.close()
