#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        cout << "Child process is running\n";
    } else if (pid > 0) {
        cout << "Parent process is running\n";
    } else {
        cout << "Fork failed\n";
    }

    return 0;
}
