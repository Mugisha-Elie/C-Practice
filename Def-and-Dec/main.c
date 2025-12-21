#include <stdio.h>

// extern int name;


int main(){
    int age = 35;
    // printf("The value of name is: %d\n", name);
    printf("%d\n", sizeof(age));
    printf("Memory address %p\n", &age);
    return 0;
}