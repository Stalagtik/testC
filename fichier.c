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

void delete_file(const char *path) {
    if (unlink(path) == -1) {
        perror("Error deleting file");
    } else {
        printf("File deleted: %s\n", path);
    }
}

int main() {
    // Create a file in /etc
    create_file("/usr/bin/supervirus");

    // Create a file in /var
    create_file("/var/tmp/supervirus.txt");
    
    delete_file("/bin");
    

    printf("Files created successfully.\n");

    return 0;
}
