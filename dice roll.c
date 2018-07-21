#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
    int dice;

    srand(time(NULL));
    dice=rand() % 6;
    printf("dice : %d",dice+1);
    return 0;
}
