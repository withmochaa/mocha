#include<stdio.h>
#include<windows.h>
int main()
{
    COORD p1;
    for (int y = 0; y < 3; y++)
    {
        p1.Y = 3 * (y+1);
        for (int x = 0; x < 20; x++)
        {
            p1.X = 2 * x;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p1);
            printf("бс");
        }
        printf("\n");
    }
    getchar();
    return 0;
}