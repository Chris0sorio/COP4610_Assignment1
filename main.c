#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int factorial(int n){
    int result = 1;
    for (int i = 1; i <= n; i++){
        result *= i;
    }
    return result;
}

int power(int base, int exp) {
    int result = 1;
    
    if (exp > 0) {
        for (int i = 0; i < exp; i++) {
            result *= base; 
        }
    } 
    
    else if (exp == 0) {
        return 1;
    }
    
    else {
        for (int i = 0; i < -exp; i++) {
            result *= base;
        }
        result = 1 / result;  
    }
    
    return result;
}

void find_prime(int n){
    for (int i = 2; i <= n; i++){
        int prime = 1;
        for (int j = 2; j*j <= i; j++){
            if (i % j == 0){
                prime = 0;
                break;
            }
        }
        if (prime) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter the number of child processes to create: ");
    scanf("%d", &n);

    if (n > 4 || n < 1){
        printf("Invalid number selection, please run the program again");
        return 1;
    }
    
    //printf("The number of children entered is: %d", n);
  
    printf("Parent process (PID: %d) is creating %d child processes.\n", getpid(), n);

    for (int i = 0; i < n; i++){
        pid_t pid = fork();

        if (pid < 0){
            printf("Fork failed!");
            return 1;
        }else if (pid == 0) {
            //child process
            //printf("Child %d(PID:%d) started.\n", i+1, getpid());

            if (i == 0){
                printf("Child %d(PID: %d) is computing the factorial of 5.\n", i+1, getpid());
                factorial(5);
                printf("Child %d(PID: %d) completed its task. Result: %d.\n", i+1, getpid(), factorial(5));
            } else if (i == 1){
                printf("Child %d(PID: %d) is find prime numbers up to 20.\n", i+1, getpid());
                printf("Child %d(PID: %d) completed its task. Result: ", i+1, getpid());
                find_prime(20); 
            } else{
                printf("Child %d(PID: %d) is computing 8 to the power of 3.\n", i+1, getpid());
                power(8,3);
                printf("Child %d(PID: %d) completed its task. Result: %d.\n", i+1, getpid(), power(8,3));
            } 
            return 0;
        }
    }

    for (int i = 0; i < n; i++){
        wait(NULL);
    }

    printf("All child processes have completed. Parent (PID: %d) is displaying the final message.\n", getpid());

    return 0;        
}




