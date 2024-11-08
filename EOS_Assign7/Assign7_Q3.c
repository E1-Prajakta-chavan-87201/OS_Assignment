#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3, pid4, pid5, pid6;
    int status;

    // Fork child processes for compilation
    pid1 = fork();
    if (pid1 == 0) {
        execlp("gcc", "gcc", "-c", "circle.c", NULL);
        perror("execlp");
        exit(1);
    }

    pid2 = fork();
    if (pid2 == 0) {
        execlp("gcc", "gcc", "-c", "square.c", NULL);
        perror("execlp");
        exit(1);
    }

    pid3 = fork();
    if (pid3 == 0) {
        execlp("gcc", "gcc", "-c", "rectangle.c", NULL);
        perror("execlp");
        exit(1);
    }

    pid4 = fork();
    if (pid4 == 0) {
        execlp("gcc", "gcc", "-c", "main.c", NULL);
        perror("execlp");
        exit(1);
    }

    // Wait for all compilation processes
    while (wait(&status) > 0);

    // Check if all compilation processes were successful
    if (WEXITSTATUS(status) != 0) {
        printf("Compilation failed.\n");
        exit(1);
    }

    // Fork a child process for linking
    pid5 = fork();
    if (pid5 == 0) {
        execlp("gcc", "gcc", "-o", "program.out", "circle.o", "square.o", "rectangle.o", "main.o", NULL);
        perror("execlp");
        exit(1);
    }

    // Wait for the linking process
    wait(&status);

    // Check if linking was successful
    if (WEXITSTATUS(status) != 0) {
        printf("Linking failed.\n");
        exit(1);
    }

    // Fork a child process for execution
    pid6 = fork();
    if (pid6 == 0) {
        execlp("./program.out", "./program.out", NULL);
        perror("execlp");
        exit(1);
    }

    // Wait for the execution process
    wait(&status);

    // Print the exit status of the execution process
    printf("Program exited with status: %d\n", WEXITSTATUS(status));

    return 0;
}