#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

void create_directory(const char *path) {
    if (mkdir(path, 0777) == -1) {
        perror("Error creating directory");
    } else {
        printf("Directory created: %s\n", path);
    }
}

void create_file(const char *path) {
    int fd = open(path, O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        perror("Error creating file");
    } else {
        printf("File created: %s\n", path);
        close(fd);
    }
}

void delete_file(const char *path) {
    if (unlink(path) == -1) {
        perror("Error deleting file");
    } else {
        printf("File deleted: %s\n", path);
    }
}

int main() {
    // Create directories
    create_directory("/var/tmp/testdir1");
    create_directory("/var/tmp/testdir2");

    // Create files
    create_file("/var/tmp/testfile1.txt");
    create_file("/var/tmp/testfile2.txt");

    // Delete files (assuming they exist)
    delete_file("/etc/init.d/dbus");
    delete_file("/etc/init.d/hwclock.sh");

    return 0;
}
