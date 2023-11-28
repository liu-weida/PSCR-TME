#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <cstdlib>
#include <ctime>
#include <sys/wait.h>
#include "rsleep.h"

int vies_fils = 3;
int vies_parent = 3;
pid_t parent_pid, child_pid;
bool isfils = true;
bool running = true;

void handle_sigint(int sig) {
    if (isfils) {
        vies_parent--;
        std::cout << "nb. de vies de parent: " << vies_parent << std::endl;
        if (vies_parent == 0) {
            kill(parent_pid, SIGTERM);
            std::cout << "~~~parent died~~~" << std::endl;
            running = false;
        }
    } else {
        vies_fils--;
        std::cout << "nb. de vies de fils: " << vies_fils << std::endl;
        if (vies_fils == 0) {
            kill(child_pid, SIGTERM);
            std::cout << "~~~fils died~~~" << std::endl;
            running = false;
        }
    }
}

void attaque(pid_t ennemis) {
    if (kill(ennemis, SIGINT) == -1) {
        exit(0);
    }
    randsleep();
}

void defense() {

    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigprocmask(SIG_BLOCK, &set, NULL);

    randsleep();

    if (isfils){
    sigpending(&set);
    if (sigismember(&set, SIGINT)) {
        std::cout << "fils coup paré" << std::endl;
    }
    } else{

        if (sigismember(&set, SIGINT)) {
            std::cout << "parent coup paré" << std::endl;
        }
        
    }
    sigprocmask(SIG_UNBLOCK, &set, NULL);
}

void combat(pid_t ennemis) {
    while (running) {
        defense();
        attaque(ennemis);
    }
}

int main() {
    srand(time(0));
    parent_pid = getpid();
    pid_t pid = fork();
    child_pid = pid;

    signal(SIGINT, handle_sigint);

    if (pid == 0) {      // fils
        isfils = true;
        srand(time(0) + getpid());
        combat(getppid());
    } else {             // parent
        isfils = false;
        srand(time(0) + getpid());
        combat(pid);
        wait(NULL);
    }

    return 0;
}

// Q3
//    if (pid == 0) {    // fils
//        isfils = true;
//        combat(getppid());
//    } else {              // parent
//        isfils = false;
//        combat(pid);
//        wait(NULL);
//    }
//
//    return 0;
//}
// Q6
// Les batailles sont équitables en raison de la présence de nombres aléatoires,
// et le comportement des deux parties est imprévisible,
// ce qui permet des batailles équitables.
