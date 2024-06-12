#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "192.168.1.41"
#define SERVER_PORT 8080
#define MESSAGE "This is a test message from the potentially malicious C program."

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[1024];

    // Création de la socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    // Conversion de l'adresse IP en format binaire
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        return 1;
    }

    // Connexion au serveur
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return 1;
    }

    // Envoi du message
    send(sock, MESSAGE, strlen(MESSAGE), 0);
    printf("Message sent to server.\n");

    // Lecture de la réponse du serveur
    int valread = read(sock, buffer, 1024);
    printf("Server response: %s\n", buffer);

    // Fermeture de la socket
    close(sock);
    return 0;
}
