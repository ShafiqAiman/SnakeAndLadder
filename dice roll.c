#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
    int r;

    srand(time(NULL));
    r=rand() % 6;
    printf("dice : %d",r+1);
    return 0;
}
