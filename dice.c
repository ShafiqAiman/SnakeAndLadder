#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    srand ( time(NULL));
    int a,counter;

    for (counter=0;counter<100;counter++){
        a=rand()%6+1;
        printf("%d\n",a);
    }

    return 0;
}
