#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void main();

void loader()
{
    int i;
    system("cls");
    printf("\n\n\n\t\tPlease wait loading...");
    printf("\n\n\n\t\t");
    for(i=0;i<14;i++)
    {   Sleep(100);
        printf("¨");
    }
}

void thanks()
{
    loader();
    system("cls");
    printf("\n\n");
    printf("\n\t*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
    printf("\n\t:                                                         :");
    printf("\n\t:                  Thanks for playing !!                  :");
    printf("\n\t:                                                         :");
    printf("\n\t*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
    printf("\n\n");
    return ;
}

void quit()
{
    char c;
    do{
    system("cls");
    printf("\n\n");
    printf("\n\t?????????????????????????????????????????????????      ");
    printf("\n\t?                                               ?      ");
    printf("\n\t?    Are You Sure You Want to Quit the Game?    ?      ");
    printf("\n\t?                   (y/n)                       ?      ");
    printf("\n\t?                                               ?      ");
    printf("\n\t?????????????????????????????????????????????????      ");
    printf("\n\n\n\tYour choice : ");
    scanf(" %c",&c);

        if(c=='Y'||c=='y'){
            thanks();
            exit(1);
        }else if(c=='N'||c=='n'){
            loader();
            Sleep(500);
            system("cls");
            printf("\n\n\tWELCOME BACK !!");
            main();
        }else{
            printf("\n\n\tINVALID CHOICE !!");
            Sleep(500);
             }
    }while(c!='\0');
    return;
}

int firstscr()
{
    printf("\n\n\n\t============================================================");
    printf("\n                  __                                              ");
    printf("\n                 `--)                                     |__|    ");
    printf("\n                   /                                      |__|    ");
    printf("\n                  /        S N A K E  &  L A D D E R      |__|    ");
    printf("\n              8__/_ _                                     |__|    ");
    printf("\n                ( _ _ )                                   |  |    ");
    printf("\n\n\t============================================================");
    return 0;
}

void main()
{
    firstscr();
    printf("\n\n\n\n\t\t\t   Press any key to start !!");
    getch();

    int input;
    do{
    system("cls");
    printf("\n\n\n\tGame mode: ");
    printf("\n\n\tPress 1 for Single Mode ");
    printf("\n\tPress 2 for Multi-Player Mode");
    printf("\n\tPress 3 to Exit");
    printf("\n\n\n\tEnter your choice : ");
    scanf("%d",&input);

            switch(input){
            case 1 :/*singleplayer();*/break;
            case 2 :/*function of multiplayer*/;break;
            case 3 :quit();break;
            default:printf("\n\n\tINVALID CHOICE !!");Sleep(500);break;
            }
        }while(input>=0);
}






