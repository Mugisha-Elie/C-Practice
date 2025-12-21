#include <stdio.h>

// #define DEBUG_MSG

int main(){
    printf("Start of the program");

    #ifdef DEBUG_MSG
        printf("Memory allocated to address");
    #endif

    printf("Program ended");

    return 0;
}

