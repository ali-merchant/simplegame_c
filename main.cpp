#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
// up arrow key gives 224/72
// down arrow key gives 224/80
// left arrow key gives 224/75
// right arrow key gives 224/77


void GoToXY(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;

    // Obtain a handle to the console screen buffer.
    // (You're just using the standard console, so you can use STD_OUTPUT_HANDLE
    // in conjunction with the GetStdHandle() to retrieve the handle.)
    // Note that because it is a standard handle, we don't need to close it.
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Finally, call the SetConsoleCursorPosition function.
    SetConsoleCursorPosition(hConsole, coord);


}



int main()
{
    printf("\e[?25l");

    int ci=1,ri=1,c=15,r=28,a=10,b=28,d=1, e = 1,ch,ch2;
    int ballci=1,ballri=1,ballc=1,ballr=1,balla=0,ballb=0,ballai=1,ballbi=1;
    GoToXY(a,b);
    printf("     ");
    GoToXY(c, r);
    printf("*****");


    while(1){
//        a = c -e;
//        b = r - d;


//        c = c + ci;
//        r = r + ri;
        GoToXY(ballc,ballr);
        printf("*");

        GoToXY(balla,ballb);
        printf(" ");

        ballr = ballr + ballri ;
        ballc = ballc + ballci ;
        balla = balla + ballai ;
        ballb = ballb + ballbi ;
        Sleep(100);


        if(ballr>28){system("cls");printf("YOU LOST"); return 0;}

        if(ballr>=28&& ballc >= c && ballc <=c+5){ballri = -ballri;}

        if(ballb>=28&&ballr<=28&& ballc >= c && ballc <=c+5){ballbi = -ballbi;}

        if(ballr<=0){ballri = -ballri;}

        if(ballb<=0){ballbi = -ballbi;}

        if(ballc>=119){ballci=-ballci;}

        if(balla>=119){ballai=-ballai;}

        if(ballc<=0){ballci=-ballci;}

        if(balla<=0){ballai=-ballai;}

        if (_kbhit()){
            ch2 = _getch();
            ch = _getch();

            if(ch == 75){ //left
                a=c+5;
                if(a>0){
                    a-=5;
                }
                if(c > 0){
                    c -= 5;
                }
            GoToXY(a,b);
            printf("     ");
            GoToXY(c, r);
            printf("*****");
            }

            if(ch == 77){ //righ
                a=c-5;
                if(c<=114){
                    c += 5;
                }
                if(a<=114){
                    a += 5;
                }
            GoToXY(a,b);
            printf("     ");
            GoToXY(c, r);
            printf("*****");

           }




        }


    }

    return 0;

}
