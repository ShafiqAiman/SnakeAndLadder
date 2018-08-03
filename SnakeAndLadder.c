/*
Name     :1.Muhammad Shafiq Aiman Bin Shahrul Nizam(B04180002)
          2.Thing Wei Jen (B04180042)
          3.Chew Jia Ern (B04180035)
          4.Izzatul Nur Atiqah Binti Rosslan(B04180030)
          5.Aiman Syakirin Basri (B04180049)
Title    :Group Assignment -- Snake And Ladder

Date     :1 August 2018
Lecturer :Sir Mohd Ridzuan Ahmad
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <dos.h>


int music(int pitch, int time)
    {

        Beep( pitch, time);
        return 0;
    }

void colors(int k) //interface text colors
{
    HANDLE hConsole; //acts a handle to an object
    int color;
    hConsole= GetStdHandle(STD_OUTPUT_HANDLE);
    color=k;//
    SetConsoleTextAttribute(hConsole,color); //Sets the foreground (text) and background color attributes of characters written to the console screen buffer.


}
void loader()//loading......
{
    int i,pitch=900;
    system("cls");
    colors(15);
    printf("\n\n\n\t\tPlease wait loading...");
    printf("\n\n\n\t\t");
    for(i=0;i<14;i++)
    {
        music(pitch-=50,100);
        Sleep(100);
        printf("¨");
    }
}

void thanks()//ending interface
{
    loader();
    system("cls");
    colors(14);

    printf("\n\n");
    printf("\n\t*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
    printf("\n\t:                                                         :");
    printf("\n\t:                  Thanks for playing !!                  :");
    printf("\n\t:                                                         :");
    printf("\n\t*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
    printf("\n\n");
    music(2500,400);
    music(2000,300);
    music(1500,200);
}

void quit()//quit option interface
{
    char c;
    do{
    system("cls");
    colors(12);
    printf("\n\n\a");
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
            music(1350,70);
            main();
        }else{
            printf("\n\n\tINVALID CHOICE !!");
            Sleep(500);
             }
    }while(c!='\0');
    return;
}

int firstscr()//starting interface
{
    int acolornum,pitch=0;

    while (acolornum<15){
    music(pitch+=50,150);
    system("cls");
    colors(++acolornum);
    printf("\n\n\n\t============================================================");
    printf("\n                  __                                              ");
    printf("\n                 `--)                                     |__|    ");
    printf("\n                   /                                      |__|    ");
    printf("\n                  /        S N A K E  &  L A D D E R      |__|    ");
    printf("\n              8__/_ _                                     |__|    ");
    printf("\n                ( _ _ )                                   |  |    ");
    printf("\n\n\t============================================================");
    Sleep(150);
    }
    return 0;
}

void displayBoard(char array[21][71])//to display the original board by using 2d array, the board is located at singleplayer, twoplayer and multiplayer function
{

    colors(10); // board color

    int counter,counter1;
    for (counter=0;counter<=20;counter++){//counter is for row
    music(375,175); //audio for board printing
            for (counter1=0;counter1<=70;counter1++){//counter1 is for column

                printf("%c",array[counter][counter1]);

            }
            printf("\n");

        }

}
/*
For all the 3 players movement, same concept is applied into it and separated into 3 different function called PlayerXMovement, PlayerOMovement
and PlayerYMovement. So the explanation is only on function PlayerXMovement.

For each player function, 2 variables are declared, one for assigning the player symbol into next place(x, o and y), and another variable to clear(print space bar)
the previous location of the player symbol (a,b and c).

Some algorithm (manipulating the coordinates of the player symbol and space bar in the 2D array) are applied to create the visual effect of the player movement.
starting from row 2 up to row 5, the player need to move up, so the variable printing the player symbol will stay at same coordinate
while variable printing space bar will be equal to a value that will not affect other spot (in this case such as '2'),
then only the variable will be assigned back to the value it should be when the loop goes again.

Further explanation of player movement is at function PlayerXMovement.
*/
void PlayerXMovement(char array[21][71], int dice,int *x, int *row1,int *pause){//function for the movement of player X
    int counter,counter1,counter2,a;


    for (counter2=dice;counter2>0;counter2--){//counter2 is to know how many time the player will move by 1 step

            printf("\nPlayer X dice  : %d\n",dice);
            colors(10);
            music(1350,50);
            if ((*row1==1)||(*row1==3)||(*row1==5)){//the condition are separated into 2 parts starting from most bottom row of the board as row=1
            a=*x;//variable a is for printing space bar
            *x+=7;//variable x is for printing player symbol
            }else if ((*row1==2)||(*row1==4)||(*row1==6)){//variable x is for printing 'X', variable a is for printing space bar to cover the previous 'X'
            a=*x;                                         //for row=6, its actually designed for the moving backward part when the player go exceeds 50
            *x-=7;
            }

        if (*row1==1){
         for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){
                    if ((counter==19)&&(counter1==a)){
                        array[counter][a]=' ';
                    }
                    if ((counter==19)&&(counter1==*x)){
                        array[counter][*x]='X';
                    }
                printf("%c",array[counter][counter1]);
            }
            printf("\n");

        }
        if (counter2>1){
        Sleep(300);
        system("cls");}

        if (array[19][64]=='X'){//when the player reaches the edge of the board, it will ignore the instruction below and continue the looping for dice
            *row1=2;
            continue;}
        }//row=1

        if (*row1==2){
            for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){
                if (array[19][a]=='X'){//this if statement is for the process when player reaches the edge of the board such as 10,20.
                    array[19][a]=' ';
                    *x=a;
                    a=2;//variable that print space bar need to be assigned to a value that will not affect the board so that it will not overwrite the player symbol
                }else{
                    array[15][a]=' ';
                    }

                if ((counter==15)&&(counter1==(*x))){
                        array[counter][*x]='X';
                    }

               printf("%c",array[counter][counter1]);

            }
             printf("\n");
            }
             if (counter2>1){
        Sleep(300);
        system("cls");}

        if (array[15][1]=='X'){
            *row1=3;
            continue;}
        }//row1=2

        if (*row1==3){
            for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){
                if (array[15][a]=='X'){
                    array[15][a]=' ';
                    *x=a;
                    a=2;
                }else{
                    array[11][a]=' ';
                }

                if ((counter==11)&&(counter1==*x)){
                        array[counter][*x]='X';
                    }
                printf("%c",array[counter][counter1]);
            }
                printf("\n");
            }
            if (counter2>1){
        Sleep(300);
        system("cls");}

        if (array[11][64]=='X'){
            *row1=4;
            continue;}
        }//row1=3

        if (*row1==4){
            for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){
                if (array[11][a]=='X'){
                    array[11][a]=' ';
                    *x=a;
                    a=2;
                }else{
                    array[7][a]=' ';
                    }

                if ((counter==7)&&(counter1==*x)){
                        array[counter][*x]='X';
                    }

               printf("%c",array[counter][counter1]);

            }
             printf("\n");
            }
             if (counter2>1){
        Sleep(300);
        system("cls");}

        if (array[7][1]=='X'){
            *row1=5;
            continue;}
        }//row1=4

        if (*row1==5){
            for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){
                if (array[7][a]=='X'){
                    array[7][a]=' ';
                    *x=a;
                    a=2;
                }else{
                    array[3][a]=' ';
                }

                if ((counter==3)&&(counter1==*x)){
                        array[counter][*x]='X';
                    }
                printf("%c",array[counter][counter1]);
            }
                printf("\n");
            }
            if (counter2>1){
        Sleep(300);
        system("cls");}

        if ((array[3][64]=='X')&&(counter2>1)){
            *row1=6;
            continue;
            }
        }//row1=5

        if (*row1==6){
            for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){
                if ((counter==3)&&(counter1==a)){
                        array[counter][a]=' ';
                    }
                if ((counter==3)&&(counter1==*x)){
                        array[counter][*x]='X';
                    }

                printf("%c",array[counter][counter1]);
            }
            printf("\n");
        }
        if (counter2>1){
        Sleep(300);
        system("cls");}
        if (counter2==1){
            *row1=5;}
        }//row1=6
/*
The below part is for all the special commands in the snake and ladder game, including go, reverse and pause
*/
         if ((array[19][22]=='X')&&(counter2==1)){//go32
                array[19][22]=' ';
                counter2++;
                *row1=4;
                *x=64;
                 Sleep(300);
                system("cls");
                continue;
            }else if ((array[19][50]=='X')&&(counter2==1)){//p2
                *pause=1;
                continue;
            }else if ((array[15][22]=='X')&&(counter2==1)){//go38
                array[15][22]=' ';
                counter2++;
                *row1=4;
                *x=22;
                Sleep(300);
                system("cls");
                continue;
            }else if ((array[15][57]=='X')&&(counter2==1)){//go28
                array[15][57]=' ';
                counter2++;
                *row1=3;
                *x=43;
                Sleep(300);
                system("cls");
                continue;
            }else if ((array[11][29]=='X')&&(counter2==1)){//re20
                array[11][29]=' ';
                counter2++;
                *row1=1;
                *x=22;
                Sleep(300);
                system("cls");
                continue;
            }else if ((array[7][8]=='X')&&(counter2==1)){//p2
                *pause=2;
                continue;
            }else if ((array[7][36]=='X')&&(counter2==1)){//go49
                array[7][36]=' ';
                counter2++;
                *row1=5;
                *x=50;
                Sleep(300);
                system("cls");
                continue;
            }else if ((array[3][15]=='X')&&(counter2==1)){//re10
                array[3][15]=' ';
                counter2++;
                *row1=4;
                *x=57;
                Sleep(300);
                system("cls");
                continue;
            }else if ((array[3][50]=='X')&&(counter2==1)){//go2
                array[3][50]=' ';
                counter2++;
                *row1=1;
                *x=1;
                Sleep(300);
                system("cls");
                continue;
            }
        }//dice
}

void PlayerOMovement(char array[21][71], int dice,int *o, int *Row1, int *pause){
    int counter,counter1,counter2,b;



   for (counter2=dice;counter2>0;counter2--){
            music(7030,50);
            printf("\nPlayer O dice  : %d\n",dice);
            if ((*Row1==1)||(*Row1==3)||(*Row1==5)){
            b=*o;
            *o+=7;
            }else if ((*Row1==2)||(*Row1==4)||(*Row1==6)){
            b=*o;
            *o-=7;
            }

        if (*Row1==1){
         for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){
                    if ((counter==19)&&(counter1==b)){
                        array[counter][b]=' ';
                    }
                    if ((counter==19)&&(counter1==*o)){
                        array[counter][*o]='O';
                    }

                printf("%c",array[counter][counter1]);
            }
            printf("\n");

        }
        if (counter2>1){
        Sleep(300);
        system("cls");}

        if (array[19][66]=='O'){
            *Row1=2;
            continue;}
        }//row=1

        if (*Row1==2){
            for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){
                if (array[19][b]=='O'){
                    array[19][b]=' ';
                    *o=b;
                    b=2;
                }else{
                    array[15][b]=' ';
                    }

                if ((counter==15)&&(counter1==(*o))){
                        array[counter][*o]='O';
                    }

               printf("%c",array[counter][counter1]);

            }
             printf("\n");
            }
             if (counter2>1){
        Sleep(300);
        system("cls");}

        if (array[15][3]=='O'){
            *Row1=3;
            continue;}
        }//row1=2

        if (*Row1==3){
            for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){
                if (array[15][b]=='O'){
                    array[15][b]=' ';
                    *o=b;
                    b=2;
                }else{
                    array[11][b]=' ';
                }

                if ((counter==11)&&(counter1==*o)){
                        array[counter][*o]='O';
                    }
                printf("%c",array[counter][counter1]);
            }
                printf("\n");
            }
            if (counter2>1){
        Sleep(300);
        system("cls");}

        if (array[11][66]=='O'){
            *Row1=4;
            continue;}
        }//row1=3

        if (*Row1==4){
            for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){
                if (array[11][b]=='O'){
                    array[11][b]=' ';
                    *o=b;
                    b=2;
                }else{
                    array[7][b]=' ';
                    }

                if ((counter==7)&&(counter1==*o)){
                        array[counter][*o]='O';
                    }

               printf("%c",array[counter][counter1]);

            }
             printf("\n");
            }
             if (counter2>1){
        Sleep(300);
        system("cls");}

        if (array[7][3]=='O'){
            *Row1=5;
            continue;}
        }//row1=4

        if (*Row1==5){
            for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){
                if (array[7][b]=='O'){
                    array[7][b]=' ';
                    *o=b;
                    b=2;
                }else{
                    array[3][b]=' ';
                }

                if ((counter==3)&&(counter1==*o)){
                        array[counter][*o]='O';
                    }
                printf("%c",array[counter][counter1]);
            }
                printf("\n");
            }
            if (counter2>1){
        Sleep(300);
        system("cls");}

        if ((array[3][66]=='O')&&(counter2>1)){
            *Row1=6;
            continue;
            }
        }//row=5

        if (*Row1==6){
            for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){
                if ((counter==3)&&(counter1==b)){
                        array[counter][b]=' ';
                    }
                if ((counter==3)&&(counter1==*o)){
                        array[counter][*o]='O';
                    }

                printf("%c",array[counter][counter1]);
            }
            printf("\n");
        }
        if (counter2>1){
        Sleep(300);
        system("cls");}
        if (counter2==1){
            *Row1=5;}
        }//row1=6
        if ((array[19][24]=='O')&&(counter2==1)){//go32
                array[19][24]=' ';
                counter2++;
                *Row1=4;
                *o=66;
                 Sleep(300);
                system("cls");
                continue;
            }else if ((array[19][52]=='O')&&(counter2==1)){//p2
                *pause=1;
                continue;
            }else if ((array[15][24]=='O')&&(counter2==1)){//go38
                array[15][24]=' ';
                counter2++;
                *Row1=4;
                *o=24;
                Sleep(300);
                system("cls");
                continue;
            }else if ((array[15][59]=='O')&&(counter2==1)){//go28
                array[15][59]=' ';
                counter2++;
                *Row1=3;
                *o=45;
                Sleep(300);
                system("cls");
                continue;
            }else if ((array[11][31]=='O')&&(counter2==1)){//re20
                array[11][31]=' ';
                counter2++;
                *Row1=1;
                *o=24;
                Sleep(300);
                system("cls");
                continue;
            }else if ((array[7][38]=='O')&&(counter2==1)){//go49
                array[7][38]=' ';
                counter2++;
                *Row1=5;
                *o=52;
                Sleep(300);
                system("cls");
                continue;
            }else if ((array[7][10]=='O')&&(counter2==1)){//p2
                *pause=2;
                continue;
            }else if ((array[3][17]=='O')&&(counter2==1)){//re10
                array[3][17]=' ';
                counter2++;
                *Row1=4;
                *o=59;
                Sleep(300);
                system("cls");
                continue;
            }else if ((array[3][52]=='O')&&(counter2==1)){//go2
                array[3][52]=' ';
                counter2++;
                *Row1=1;
                *o=3;
                Sleep(300);
                system("cls");
                continue;
            }
        }//dice
}

void PlayerYMovement(char array[21][71], int dice,int *y, int *row, int *pause){
    int counter,counter1,counter2,c;


    for (counter2=dice;counter2>0;counter2--){
            music(3820,50);
            printf("\nPlayer Y dice  : %d\n",dice);
            if ((*row==1)||(*row==3)||(*row==5)){
            c=*y;
            *y+=7;
            }else if ((*row==2)||(*row==4)||(*row==6)){
            c=*y;
            *y-=7;
            }

        if (*row==1){
         for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){
                    if ((counter==19)&&(counter1==c)){
                        array[counter][c]=' ';
                    }
                    if ((counter==19)&&(counter1==*y)){
                        array[counter][*y]='Y';
                    }

                printf("%c",array[counter][counter1]);
            }
            printf("\n");

        }
        if (counter2>1){
        Sleep(300);
        system("cls");}

        if (array[19][68]=='Y'){
            *row=2;
            continue;}
        }//row=1

        if (*row==2){
            for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){
                if (array[19][c]=='Y'){
                    array[19][c]=' ';
                    *y=c;
                    c=2;
                }else{
                    array[15][c]=' ';
                    }

                if ((counter==15)&&(counter1==*y)){
                        array[counter][*y]='Y';
                    }

               printf("%c",array[counter][counter1]);

            }
             printf("\n");
            }
             if (counter2>1){
        Sleep(300);
        system("cls");}

        if (array[15][5]=='Y'){
            *row=3;
            continue;}
        }//row1=2

        if (*row==3){
            for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){
                if (array[15][c]=='Y'){
                    array[15][c]=' ';
                    *y=c;
                    c=2;
                }else{
                    array[11][c]=' ';
                }

                if ((counter==11)&&(counter1==*y)){
                        array[counter][*y]='Y';
                    }
                printf("%c",array[counter][counter1]);
            }
                printf("\n");
            }
            if (counter2>1){
        Sleep(300);
        system("cls");}

        if (array[11][68]=='Y'){
            *row=4;
            continue;}
        }//row1=3

        if (*row==4){
            for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){
                if (array[11][c]=='Y'){
                    array[11][c]=' ';
                    *y=c;
                    c=2;
                }else{
                    array[7][c]=' ';
                    }

                if ((counter==7)&&(counter1==*y)){
                        array[counter][*y]='Y';
                    }

               printf("%c",array[counter][counter1]);

            }
             printf("\n");
            }
             if (counter2>1){
        Sleep(300);
        system("cls");}

        if (array[7][5]=='Y'){
            *row=5;
            continue;}
        }//row1=4

        if (*row==5){
            for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){
                if (array[7][c]=='Y'){
                    array[7][c]=' ';
                    *y=c;
                    c=2;
                }else{
                    array[3][c]=' ';
                }

                if ((counter==3)&&(counter1==*y)){
                        array[counter][*y]='Y';
                    }
                printf("%c",array[counter][counter1]);
            }
                printf("\n");
            }
            if (counter2>1){
        Sleep(300);
        system("cls");}

        if ((array[3][68]=='Y')&&(counter2>1)){
            *row=6;
            continue;
            }
        }//row=5

        if (*row==6){
            for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){
                if ((counter==3)&&(counter1==c)){
                        array[counter][c]=' ';
                    }
                if ((counter==3)&&(counter1==*y)){
                        array[counter][*y]='Y';
                    }

                printf("%c",array[counter][counter1]);
            }
            printf("\n");
        }
        if (counter2>1){
        Sleep(300);
        system("cls");}
        if (counter2==1){
            *row=5;}
        }//row=6
         if ((array[19][26]=='Y')&&(counter2==1)){//go32
                array[19][26]=' ';
                counter2++;
                *row=4;
                *y=68;
                 Sleep(300);
                system("cls");
                continue;
            }else if ((array[19][54]=='Y')&&(counter2==1)){//p2
                *pause=1;
                continue;
            }else if ((array[15][26]=='Y')&&(counter2==1)){//go38
                array[15][26]=' ';
                counter2++;
                *row=4;
                *y=26;
                Sleep(300);
                system("cls");
                continue;
            }else if ((array[15][61]=='Y')&&(counter2==1)){//go28
                array[15][61]=' ';
                counter2++;
                *row=3;
                *y=47;
                Sleep(300);
                system("cls");
                continue;
            }else if ((array[11][33]=='Y')&&(counter2==1)){//re20
                array[11][33]=' ';
                counter2++;
                *row=1;
                *y=26;
                Sleep(300);
                system("cls");
                continue;
            }else if ((array[7][40]=='Y')&&(counter2==1)){//go49
                array[7][40]=' ';
                counter2++;
                *row=5;
                *y=54;
                Sleep(300);
                system("cls");
                continue;
            }else if ((array[7][12]=='Y')&&(counter2==1)){//p2
                *pause=2;
                continue;
            }else if ((array[3][19]=='Y')&&(counter2==1)){//re10
                array[3][19]=' ';
                counter2++;
                *row=4;
                *y=61;
                Sleep(300);
                system("cls");
                continue;
            }else if ((array[3][54]=='Y')&&(counter2==1)){//go2
                array[3][54]=' ';
                counter2++;
                *row=1;
                *y=5;
                Sleep(300);
                system("cls");
                continue;
            }
        }//dice
}

int singleplayer()//function for single player mode
{
    system("cls");
    int dice,game=1,x=1,o=3,row1=1,Row1=1,pause1=0,pause2=0,choose;
    char array[21][71]=
     //0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39  40  41  42  43  44  45  46  47  48  49  50  51  52  53  54  55  56  57  58  59  60  61  62  63  64  65  66  67  68  69  70
    {
     {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},//0
     {'|',' ',' ','4','1',' ',' ','|',' ',' ','4','2',' ',' ','|',' ',' ','4','3',' ',' ','|',' ',' ','4','4',' ',' ','|',' ',' ','4','5',' ',' ','|',' ',' ','4','6',' ',' ','|',' ',' ','4','7',' ',' ','|',' ',' ','4','8',' ',' ','|',' ',' ','4','9',' ',' ','|',' ',' ','5','0',' ',' ','|'},//1
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','R','E','1','0',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','G','O',' ','2',' ','|',' ',' ',' ',' ',' ',' ','|',' ','W','I','N',' ',' ','|'},//2
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//3
     {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},//4
     {'|',' ',' ','4','0',' ',' ','|',' ',' ','3','9',' ',' ','|',' ',' ','3','8',' ',' ','|',' ',' ','3','7',' ',' ','|',' ',' ','3','6',' ',' ','|',' ',' ','3','5',' ',' ','|',' ',' ','3','4',' ',' ','|',' ',' ','3','3',' ',' ','|',' ',' ','3','2',' ',' ','|',' ',' ','3','1',' ',' ','|'},//5
     {'|',' ',' ',' ',' ',' ',' ','|',' ','P','2','R',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','G','O','4','9',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//6
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//7
     {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},//8
     {'|',' ',' ','2','1',' ',' ','|',' ',' ','2','2',' ',' ','|',' ',' ','2','3',' ',' ','|',' ',' ','2','4',' ',' ','|',' ',' ','2','5',' ',' ','|',' ',' ','2','6',' ',' ','|',' ',' ','2','7',' ',' ','|',' ',' ','2','8',' ',' ','|',' ',' ','2','9',' ',' ','|',' ',' ','3','0',' ',' ','|'},//9
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','R','E','2','0',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//10
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//11
     {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},//12
     {'|',' ',' ','2','0',' ',' ','|',' ',' ','1','9',' ',' ','|',' ',' ','1','8',' ',' ','|',' ',' ','1','7',' ',' ','|',' ',' ','1','6',' ',' ','|',' ',' ','1','5',' ',' ','|',' ',' ','1','4',' ',' ','|',' ',' ','1','3',' ',' ','|',' ',' ','1','2',' ',' ','|',' ',' ','1','1',' ',' ','|'},//13
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','G','O','3','8',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','G','O','2','8',' ','|',' ',' ',' ',' ',' ',' ','|'},//14
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//15
     {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},//16
     {'|',' ',' ',' ','1',' ',' ','|',' ',' ',' ','2',' ',' ','|',' ',' ',' ','3',' ',' ','|',' ',' ',' ','4',' ',' ','|',' ',' ',' ','5',' ',' ','|',' ',' ',' ','6',' ',' ','|',' ',' ',' ','7',' ',' ','|',' ',' ',' ','8',' ',' ','|',' ',' ',' ','9',' ',' ','|',' ',' ','1','0',' ',' ','|'},//17
     {'|','S','T','A','R','T',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','G','O','3','2',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','P','1','R',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//18
     {'|','X',' ','O',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//19
     {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'}//20
     };

        printf("\n\n\n\tPress 1 to let player starts first\n\tPress 2 to let computer starts first\n\n\tEnter Your Choice:");
        scanf(" %d",&choose);
        getchar();
        switch (choose){//to determine who will start the game first
        case 1: loader();
                system("cls");
                printf("Player X VS Computer (Player O)\nPlayer X starts first\n");
                displayBoard(array);
                while (game){//to keep the game looping until someone reached 50
                srand(time(NULL));
                if (pause1<=0){//to perform the pause instruction for player X
                printf("\nPLAYER X :Please press enter to roll\n\n");
                dice = toupper( getche() );
                music(250,100);
                dice=((rand()%6)+1);//dice generator
                system("cls");
                PlayerXMovement(array, dice, &x, &row1,&pause1);//refer to the function
                if (array[3][64]=='X'){
                    printf("\nYou Win!! CONGRATULATION!!\n\nLoading......\nPlease wait......");
                    Sleep(3000);
                    loader();
                    break;//to break out the "while game" loop and go back to main function
                }
                }else{
                    pause1--;
                }
                if (pause2<=0){//to perform the pause instruction for player O
                Sleep(800);
                dice=((rand()%6)+1);
                system("cls");
                PlayerOMovement(array, dice, &o, &Row1,&pause2);
                if (array[3][66]=='O'){
                    printf("\nYou Lose!! Better Luck Next Time!!\n\nLoading......\nPlease wait......");
                    Sleep(3000);
                    loader();
                    break;
                }
                }else{
                    pause2--;
                }
                }
                break;
        case 2: loader();
                system("cls");
                printf("Player X VS Computer (Player O)\nComputer starts first\n");
                displayBoard(array);
                while (game){//to keep the game looping until someone reached 50
                srand(time(NULL));
                if (pause2<=0){//to perform the pause instruction for player O
                Sleep(800);
                dice=((rand()%6)+1);
                system("cls");
                PlayerOMovement(array, dice, &o, &Row1,&pause2);
                if (array[3][66]=='O'){
                    printf("\nYou Lose!! Better Luck Next Time!!\n\nLoading......\nPlease wait......");
                    Sleep(3000);
                    loader();
                    break;
                }
                }else{
                    pause2--;
                }
                if (pause1<=0){//to perform the pause instruction for player X
                printf("\nPLAYER X :Please press enter to roll\n\n");
                dice = toupper( getche() );
                music(250,100);
                dice=((rand()%6)+1);//dice generator
                system("cls");
                PlayerXMovement(array, dice, &x, &row1,&pause1);//refer to the function
                if (array[3][64]=='X'){
                    printf("\nYou Win!! CONGRATULATION!!\n\nLoading......\nPlease wait......");
                    Sleep(3000);
                    loader();
                    break;//to break out the "while game" loop and go back to main function
                }
                }else{
                    pause1--;
                }
                }
                break;
        default:printf("\n\n\tINVALID CHOICE !!");
                Sleep(800);
                loader();
                break;
        }
         return 0;
}

int twoplayer()//2 players mode, the function is similar to single player
{
    loader();
    system("cls");
    int dice,game=1,x=1,o=3,row1=1,Row1=1,pause1=0,pause2=0;
    char array[21][71]=
     //0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39  40  41  42  43  44  45  46  47  48  49  50  51  52  53  54  55  56  57  58  59  60  61  62  63  64  65  66  67  68  69  70
    {
     {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},//0
     {'|',' ',' ','4','1',' ',' ','|',' ',' ','4','2',' ',' ','|',' ',' ','4','3',' ',' ','|',' ',' ','4','4',' ',' ','|',' ',' ','4','5',' ',' ','|',' ',' ','4','6',' ',' ','|',' ',' ','4','7',' ',' ','|',' ',' ','4','8',' ',' ','|',' ',' ','4','9',' ',' ','|',' ',' ','5','0',' ',' ','|'},//1
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','R','E','1','0',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','G','O',' ','2',' ','|',' ',' ',' ',' ',' ',' ','|',' ','W','I','N',' ',' ','|'},//2
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//3
     {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},//4
     {'|',' ',' ','4','0',' ',' ','|',' ',' ','3','9',' ',' ','|',' ',' ','3','8',' ',' ','|',' ',' ','3','7',' ',' ','|',' ',' ','3','6',' ',' ','|',' ',' ','3','5',' ',' ','|',' ',' ','3','4',' ',' ','|',' ',' ','3','3',' ',' ','|',' ',' ','3','2',' ',' ','|',' ',' ','3','1',' ',' ','|'},//5
     {'|',' ',' ',' ',' ',' ',' ','|',' ','P','2','R',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','G','O','4','9',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//6
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//7
     {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},//8
     {'|',' ',' ','2','1',' ',' ','|',' ',' ','2','2',' ',' ','|',' ',' ','2','3',' ',' ','|',' ',' ','2','4',' ',' ','|',' ',' ','2','5',' ',' ','|',' ',' ','2','6',' ',' ','|',' ',' ','2','7',' ',' ','|',' ',' ','2','8',' ',' ','|',' ',' ','2','9',' ',' ','|',' ',' ','3','0',' ',' ','|'},//9
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','R','E','2','0',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//10
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//11
     {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},//12
     {'|',' ',' ','2','0',' ',' ','|',' ',' ','1','9',' ',' ','|',' ',' ','1','8',' ',' ','|',' ',' ','1','7',' ',' ','|',' ',' ','1','6',' ',' ','|',' ',' ','1','5',' ',' ','|',' ',' ','1','4',' ',' ','|',' ',' ','1','3',' ',' ','|',' ',' ','1','2',' ',' ','|',' ',' ','1','1',' ',' ','|'},//13
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','G','O','3','8',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','G','O','2','8',' ','|',' ',' ',' ',' ',' ',' ','|'},//14
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//15
     {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},//16
     {'|',' ',' ',' ','1',' ',' ','|',' ',' ',' ','2',' ',' ','|',' ',' ',' ','3',' ',' ','|',' ',' ',' ','4',' ',' ','|',' ',' ',' ','5',' ',' ','|',' ',' ',' ','6',' ',' ','|',' ',' ',' ','7',' ',' ','|',' ',' ',' ','8',' ',' ','|',' ',' ',' ','9',' ',' ','|',' ',' ','1','0',' ',' ','|'},//17
     {'|','S','T','A','R','T',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','G','O','3','2',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','P','1','R',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//18
     {'|','X',' ','O',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//19
     {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'}//20
     };

        printf("\n2 Players Mode\n");
        displayBoard(array);
        while (game){
        srand(time(NULL));
        if (pause1<=0){
        printf("\nPLAYER X :Please press enter to roll\n\n");
        dice = toupper( getche() );
        music(250,100);
        dice=((rand()%6)+1);
        system("cls");
        PlayerXMovement(array, dice, &x, &row1,&pause1);
        if (array[3][64]=='X'){
            printf("\nPlayer X win !!\n\nLoading......\nPlease wait......");
            Sleep(3000);
            loader();
            break;

        }
        }else{
            pause1--;
        }
        if (pause2<=0){
        printf("\nPLAYER O :Please press enter to roll\n\n");
        dice = toupper( getche() );
        music(250,100);
        dice=((rand()%6)+1);
        system("cls");
        PlayerOMovement(array, dice, &o, &Row1,&pause2);
        if (array[3][66]=='O'){
            printf("\nPlayer O win !!\n\nLoading......\nPlease wait......");
            Sleep(3000);
            loader();
            break;

        }
        }else{
            pause2--;
        }
        }

         return 0;
}

int multiplayer()//3 players mode
{
    loader();
    system("cls");
    int dice,game=1,x=1,row1=1,o=3,Row1=1,y=5,row=1,pause1=0,pause2=0,pause3=0;
    char array[21][71]=
     //0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39  40  41  42  43  44  45  46  47  48  49  50  51  52  53  54  55  56  57  58  59  60  61  62  63  64  65  66  67  68  69  70
    {
     {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},//0
     {'|',' ',' ','4','1',' ',' ','|',' ',' ','4','2',' ',' ','|',' ',' ','4','3',' ',' ','|',' ',' ','4','4',' ',' ','|',' ',' ','4','5',' ',' ','|',' ',' ','4','6',' ',' ','|',' ',' ','4','7',' ',' ','|',' ',' ','4','8',' ',' ','|',' ',' ','4','9',' ',' ','|',' ',' ','5','0',' ',' ','|'},//1
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','R','E','1','0',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','G','O',' ','2',' ','|',' ',' ',' ',' ',' ',' ','|',' ','W','I','N',' ',' ','|'},//2
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//3
     {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},//4
     {'|',' ',' ','4','0',' ',' ','|',' ',' ','3','9',' ',' ','|',' ',' ','3','8',' ',' ','|',' ',' ','3','7',' ',' ','|',' ',' ','3','6',' ',' ','|',' ',' ','3','5',' ',' ','|',' ',' ','3','4',' ',' ','|',' ',' ','3','3',' ',' ','|',' ',' ','3','2',' ',' ','|',' ',' ','3','1',' ',' ','|'},//5
     {'|',' ',' ',' ',' ',' ',' ','|',' ','P','2','R',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','G','O','4','9',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//6
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//7
     {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},//8
     {'|',' ',' ','2','1',' ',' ','|',' ',' ','2','2',' ',' ','|',' ',' ','2','3',' ',' ','|',' ',' ','2','4',' ',' ','|',' ',' ','2','5',' ',' ','|',' ',' ','2','6',' ',' ','|',' ',' ','2','7',' ',' ','|',' ',' ','2','8',' ',' ','|',' ',' ','2','9',' ',' ','|',' ',' ','3','0',' ',' ','|'},//9
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','R','E','2','0',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//10
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//11
     {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},//12
     {'|',' ',' ','2','0',' ',' ','|',' ',' ','1','9',' ',' ','|',' ',' ','1','8',' ',' ','|',' ',' ','1','7',' ',' ','|',' ',' ','1','6',' ',' ','|',' ',' ','1','5',' ',' ','|',' ',' ','1','4',' ',' ','|',' ',' ','1','3',' ',' ','|',' ',' ','1','2',' ',' ','|',' ',' ','1','1',' ',' ','|'},//13
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','G','O','3','8',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','G','O','2','8',' ','|',' ',' ',' ',' ',' ',' ','|'},//14
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//15
     {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},//16
     {'|',' ',' ',' ','1',' ',' ','|',' ',' ',' ','2',' ',' ','|',' ',' ',' ','3',' ',' ','|',' ',' ',' ','4',' ',' ','|',' ',' ',' ','5',' ',' ','|',' ',' ',' ','6',' ',' ','|',' ',' ',' ','7',' ',' ','|',' ',' ',' ','8',' ',' ','|',' ',' ',' ','9',' ',' ','|',' ',' ','1','0',' ',' ','|'},//17
     {'|','S','T','A','R','T',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','G','O','3','2',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','P','1','R',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//18
     {'|','X',' ','O',' ','Y',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//19
     {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'}//20
     };
        printf("\n3 Players Mode\n");
        displayBoard(array);
        while (game){
        srand(time(NULL));
        if (pause1<=0){
        printf("\nPlayer X: Please press enter to roll\n\n");
        dice = toupper( getche() );
        music(250,100);
        dice=((rand()%6)+1);
        system("cls");
        PlayerXMovement(array, dice, &x, &row1,&pause1);
        if (array[3][64]=='X'){
            printf("\nPlayer X win !!\n\nLoading......\nPlease wait......");
            Sleep(3000);
            loader();
            break;
        }
        }else{
            pause1--;
        }
        if (pause2<=0){
        printf("\nPlayer O: Please press enter to roll\n\n");
        dice = toupper( getche() );
        music(250,100);
        dice=((rand()%6)+1);
        system("cls");
        PlayerOMovement(array, dice, &o, &Row1, &pause2);
        if (array[3][66]=='O'){
            printf("\nPlayer O win !!\n\nLoading......\nPlease wait......");
            Sleep(3000);
            loader();
            break;
        }
        }else{
            pause2--;
        }
        if (pause3<=0){
        printf("\nPlayer Y: Please press enter to roll\n\n");
        dice = toupper( getche() );
        music(250,100);
        dice=((rand()%6)+1);
        system("cls");
        PlayerYMovement(array, dice, &y, &row, &pause3);
        if (array[3][68]=='Y'){
            printf("\nPlayer Y win !!\n\nLoading......\nPlease wait......");
            Sleep(3000);
            loader();
            break;
        }
        }else{
            pause3--;
        }
        }

         return 0;
}

int main()//main function
{

    firstscr();//display starting interface
    printf("\n\n\n\n\t\t\t   Press any key to start !!");
    getch();//press any key
    music(250,100);

    int input;

    do{
    system("cls");
    colors(15);
    printf("\n\n\n\tGame mode: ");
    printf("\n\n\tPress 1 for Single-Player VS Computer Mode ");
    printf("\n\tPress 2 for Two-Player Mode");
    printf("\n\tPress 3 for Three-Player Mode");
    printf("\n\tPress 4 to Exit");
    printf("\n\n\n\tEnter your choice : ");
    scanf("%d",&input);
    music(250,100);

            switch(input){
            case 1 :singleplayer();break;
            case 2 :twoplayer();break;
            case 3 :multiplayer();break;
            case 4 :quit();break;
            default:printf("\n\n\tINVALID CHOICE !!");Sleep(500);break;
            }
        }while(input>=0);
        return 0;
}





