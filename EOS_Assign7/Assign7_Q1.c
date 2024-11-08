#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    int signal_num, pid;

    printf("Enter signal number: ");
    scanf("%d", &signal_num);

    printf("Enter process ID: ");
    scanf("%d", &pid);

    if (signal_num < 1 || signal_num > 31) {
        printf("Invalid signal number.\n");
        return 1;
    }

    if (kill(pid, signal_num) == -1) {
        perror("kill");
        return 1;
    }

    printf("Signal %d sent to process %d.\n", signal_num, pid);

    return 0;
}