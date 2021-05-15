import socket #importer socket-modul


def client_program():
    host = socket.gethostname()  # Siden begge koder kjøres på samme pc
    port = 5000  # socket serverens port-nummer

    client_socket = socket.socket()  # instansier
    client_socket.connect((host, port))  # koble til serveren

    message = input(" -> ")  # ta inn input

    while message.lower().strip() != 'bye':
        client_socket.send(message.encode())  # send melding
        data = client_socket.recv(1024).decode()  # motta respons

        print('Received from server: ' + data)  # Vis i terminal
        message = input(" -> ")  # ta inn input igjen

    client_socket.close()  # avslutt tilkoblingen

if __name__ == '__main__':
    client_program()
