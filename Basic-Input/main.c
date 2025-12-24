#include <stdio.h>

int main(){
    char name[50];
    int character;
    
    // char fullName[100];

    printf("Enter your name\n");
    // scanf("%s", name);

    fgets(name, sizeof(name), stdin);

    printf("Nice to meet you %s\n", name);
    fputs("This is me trying the fputs() function", stdout);

    character = getchar();
    printf("The character is: %c", character);



    return 0;
    
}