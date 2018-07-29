#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
int a,b;

void displayBoard(char array[21][71]);
void PlayerXMovement(char array[21][71], int dice,int *x, int *row1);
void PlayerOMovement(char array[21][71], int dice,int *o, int *Row1);
int main()
{
int dice,game=1,x=1,o=3,row1=1,Row1=1;
char array[21][71]=
     //0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39  40  41  42  43  44  45  46  47  48  49  50  51  52  53  54  55  56  57  58  59  60  61  62  63  64  65  66  67  68  69  70
    {
     {'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},//0
     {'|',' ',' ','4','1',' ',' ','|',' ',' ','4','2',' ',' ','|',' ',' ','4','3',' ',' ','|',' ',' ','4','4',' ',' ','|',' ',' ','4','5',' ',' ','|',' ',' ','4','6',' ',' ','|',' ',' ','4','7',' ',' ','|',' ',' ','4','8',' ',' ','|',' ',' ','4','9',' ',' ','|',' ',' ','5','0',' ',' ','|'},//1
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//2
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//3
     {'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},//4
     {'|',' ',' ','4','0',' ',' ','|',' ',' ','3','9',' ',' ','|',' ',' ','3','8',' ',' ','|',' ',' ','3','7',' ',' ','|',' ',' ','3','6',' ',' ','|',' ',' ','3','5',' ',' ','|',' ',' ','3','4',' ',' ','|',' ',' ','3','3',' ',' ','|',' ',' ','3','2',' ',' ','|',' ',' ','3','1',' ',' ','|'},//5
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//6
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//7
     {'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},//8
     {'|',' ',' ','2','1',' ',' ','|',' ',' ','2','2',' ',' ','|',' ',' ','2','3',' ',' ','|',' ',' ','2','4',' ',' ','|',' ',' ','2','5',' ',' ','|',' ',' ','2','6',' ',' ','|',' ',' ','2','7',' ',' ','|',' ',' ','2','8',' ',' ','|',' ',' ','2','9',' ',' ','|',' ',' ','3','0',' ',' ','|'},//9
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//10
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//11
     {'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},//12
     {'|',' ',' ','2','0',' ',' ','|',' ',' ','1','9',' ',' ','|',' ',' ','1','8',' ',' ','|',' ',' ','1','7',' ',' ','|',' ',' ','1','6',' ',' ','|',' ',' ','1','5',' ',' ','|',' ',' ','1','4',' ',' ','|',' ',' ','1','3',' ',' ','|',' ',' ','1','2',' ',' ','|',' ',' ','1','1',' ',' ','|'},//13
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//14
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//15
     {'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},//16
     {'|',' ',' ',' ','1',' ',' ','|',' ',' ',' ','2',' ',' ','|',' ',' ',' ','3',' ',' ','|',' ',' ',' ','4',' ',' ','|',' ',' ',' ','5',' ',' ','|',' ',' ',' ','6',' ',' ','|',' ',' ',' ','7',' ',' ','|',' ',' ',' ','8',' ',' ','|',' ',' ',' ','9',' ',' ','|',' ',' ','1','0',' ',' ','|'},//17
     {'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//18
     {'|','X',' ','O',' ','Y',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'},//19
     {'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},//20
     };

        displayBoard(array);
        while (game){
        printf("\nPLAYER X :Please press enter to roll\n\n");
        srand(time(NULL));
        dice = toupper( getche() );
        dice=((rand()%6)+1);
        system("cls");
        PlayerXMovement(array, dice, &x, &row1);
        Sleep(800);
        srand(time(NULL));
        dice=((rand()%6)+1);
        system("cls");
        PlayerOMovement(array, dice, &o, &Row1);
        if (array[3][64]=='X'){
            break;

        }
        if (array[3][66]=='O'){
            break;

        }
        }

         return 0;
}

void displayBoard(char array[21][71])
{
    int counter,counter1;
    for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){

                printf("%c",array[counter][counter1]);
            }
            printf("\n");

        }

}

void PlayerXMovement(char array[21][71], int dice,int *x, int *row1){
    int counter,counter1,counter2;

    for (counter2=dice;counter2>0;counter2--){
             printf("\nPlayer X dice  : %d\n",dice);
            if ((*row1==1)||(*row1==3)||(*row1==5)){
            a=*x;
            *x+=7;
            }else if ((*row1==2)||(*row1==4)||(*row1==6)){
            a=*x;
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

        if (array[19][64]=='X'){
            *row1=2;
            continue;}
        }//row=1

        if (*row1==2){
            for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){
                if (array[19][a]=='X'){
                    array[19][a]=' ';
                    *x=a;
                }else{
                    array[15][a]=' ';
                    }

                if ((counter==15)&&(counter1==*x)){
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
            }else if (array[3][64]=='X'){
            printf("Player X win !!");
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
        }//dice
}
void PlayerOMovement(char array[21][71], int dice,int *o, int *Row1){
    int counter,counter1,counter2;

    for (counter2=dice;counter2>0;counter2--){//dice = 5
             printf("\nPlayer O dice  : %d\n",dice);
            if ((*Row1==1)||(*Row1==3)||(*Row1==5)){//if the chess is moving in these rows, they will move to the right
            b=*o;//a=1
            *o+=7;//x=8
            }else if ((*Row1==2)||(*Row1==4)||(*Row1==6)){//if the chess is moving in these rows, they will move to the left.
            b=*o;
            *o-=7;
            }

        if (*Row1==1){
         for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){
                    if ((counter==19)&&(counter1==b)){
                        array[counter][b]=' ';//clear the previous position
                    }
                    if ((counter==19)&&(counter1==*o)){
                        array[counter][*o]='O';//mark the current X
                    }

                printf("%c",array[counter][counter1]);//print back the table since the previous table is deleted.
            }
            printf("\n");

        }
        if (counter2>1){//if the movement of dice finished. The program will ask the user back for dice rolling.
        Sleep(300);
        system("cls");}//the current table will be deleted.

        if (array[19][66]=='O'){//array[19][64] is position of 10. So once the chess is here, the row will be automatically set to row1=2
            *Row1=2;
            continue;}
        }//row=1

        if (*Row1==2){
            for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){
                if (array[19][b]=='O'){
                    array[19][b]=' ';//deleting back X in previous position which is position 10. eg=array[19][64]
                    *o=b;//x=64
                }else{
                    array[15][b]=' ';//eg=until array[15][64],chess x will be deleted.
                    }

                if ((counter==15)&&(counter1==*o)){//eg=at counter ==15 and counter1==64
                        array[counter][*o]='O';//new position of chess X marked.
                    }

               printf("%c",array[counter][counter1]);

            }
             printf("\n");//new line
            }
             if (counter2>1){//if the movement of dice finished. The program will ask the user back for dice rolling.
        Sleep(300);
        system("cls");}//the current table will be deleted.

        if (array[15][3]=='O'){//array[15][1] is position of 10. So once the chess is here, the row will be automatically set to row1=3
            *Row1=3;
            continue;}
        }//row1=2

        if (*Row1==3){
            for (counter=0;counter<=20;counter++){

            for (counter1=0;counter1<=70;counter1++){
                if (array[15][b]=='O'){
                    array[15][b]=' ';
                    *o=b;
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
            }else if (array[3][66]=='O'){
            printf("Player O win !!");
            }
        }//row1=5

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
        }//dice
}








