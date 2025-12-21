#include <stdio.h>

int main(){
    unsigned char level = 12;
    unsigned char score = 5;

    unsigned char packedData = (level << 4) | score;

    unsigned char extractedLevel = packedData >> 4;
    unsigned char extractedScore = packedData & 15;

    printf("%d\n",extractedLevel);
    printf("%d", extractedScore);
}