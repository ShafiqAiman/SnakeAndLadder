#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
    int dice;

    printf("\nPlease press enter to roll\n\n");
    srand(time(NULL));
    dice = toupper( getche() );
    dice=((rand()%6)+1);
    printf("dice : %d",dice);
    return 0;
}
