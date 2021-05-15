import socket
import socketserver

def server_program():
    # få hosten's adresse
    host = socket.gethostname()
    port = 5000  # initierer port som ikke er over 1024 bytes

    server_socket = socket.socket()  # få instanse
 
    server_socket.bind(("localhost", port))  # bind hosten's addresse and port sammen

    #Konfigurer hvor mange klienter serveren kan lytte til samtidig
    server_socket.listen(2)
    conn, address = server_socket.accept()  # akksepter ny tilkobling
    print("Connection from: " + str(address))
    while True:
        # motta datastrøm. Data-pakker over 1024 bytes, vil ikke bli akkseptert
        data = conn.recv(1024).decode()
        if not data:
            # break hvis data ikke mottas
            break
        print("from connected user: " + str(data))
        data = input(' -> ')
        conn.send(data.encode())  # send data til klienten

    conn.close()  # avslutt tilkobling
if __name__ == '__main__':
    server_program()


