#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void create_file(const char *path) {
    int fd = open(path, O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        perror("Failed to create file");
        return;
    }
    const char *content = "test fichier\n";
    write(fd, content, strlen(content));
    close(fd);
}

int main() {
    // Create a file in /etc
    create_file("/etc/supervirus");

    // Create a file in /var
    create_file("/var/supervirus.txt");

    printf("Files created successfully.\n");

    return 0;
}
