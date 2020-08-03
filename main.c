#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <dos.h>

int get_speed(int v_old){
    int speed = 0; //rychlost cislo

    if(v_old == 0){
        v_old = 350 + rand()%(450 - 350 + 1);
        return v_old;
    }else if(v_old != 0){
        speed = (-5) + rand()%(20 - (-5) + 1);
        //printf("Speed %d\n", speed);
        v_old += speed;
        return v_old;
    }
}

int main() {
    int finish = 40000, n = 0;
    int v_bezec_1 = 0, v_bezec_2 = 0, d_bezec_1 = 0, d_bezec_2 = 0;
    int bezec1 = 0, bezec2 = 0;

    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

    srand(time(NULL)); //printf("%d\n", 80 + rand()%(100 - 80 + 1));
    while((d_bezec_1 <= finish)&&(d_bezec_2 <= finish)){
        n++;
        Sleep(250);
      // printf("Speed old Bezec 1 = %d\n", v_bezec_1);
      // printf("Speed old Bezec 2 = %d\n", v_bezec_2);

        v_bezec_1 = get_speed(v_bezec_1);
        v_bezec_2 = get_speed(v_bezec_2);

       // printf("Speed new Bezec 1 = %d\n", v_bezec_1);
       // printf("Speed new Bezec 2 = %d\n", v_bezec_2);

        d_bezec_1 += v_bezec_1;
        d_bezec_2 += v_bezec_2;

        if(((d_bezec_1/100)%50 == 0)&&((d_bezec_1/100) != 400)){
            v_bezec_1 = 0;
            bezec1++;
        }
        if(((d_bezec_2/100)%50 == 0)&&((d_bezec_2/100) != 400)){
            v_bezec_2 = 0;
            bezec2++;
        }
        SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("\tZa %d sekundu beha.\n", n);
        printf("\t\t1 bezec = %d cm(%d m), rychlost v cm/s = %d (%d m/s)\n", d_bezec_1, d_bezec_1/100, v_bezec_1, v_bezec_1/100);
        printf("\t\t2 bezec = %d cm(%d m), rychlost v cm/s = %d (%d m/s)\n", d_bezec_2, d_bezec_2/100, v_bezec_2, v_bezec_2/100);
    }

    if(d_bezec_1 > d_bezec_2){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN);
        printf("\nBeh sa skoncil na %d sekunde, Vitazom sa stava bezec #1\n", n);
    }else if(d_bezec_2 > d_bezec_1){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN);
        printf("\nBeh sa skoncil na %d sekunde, Vitazom sa stava bezec #2\n", n);}
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_BLUE);
    printf("Bezec #1 narazil sa na prekazky %d krat.\nBezec #2 narazil sa na prekazky %d krat.", bezec1, bezec2);

    getchar();

    return 0;
}