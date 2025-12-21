# include <stdio.h>

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Error Please provide a name");
        return 1;
    }

    printf("Hello %s! You are running this programm via command line", argv[1]);
    return 0;
}