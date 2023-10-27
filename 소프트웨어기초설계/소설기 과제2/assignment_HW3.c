#pragma warning(disable:4996)
#include <stdio.h>
#include <windows.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
char blockModel[][4][4] =
{
    /* 첫 번째 블록
         ■
         ■■■     */
    {
        {0, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0} },
    {
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0} },
    {
        {0, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0} },
    {
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0} },

        /* 두 번째 블록
                 ■
             ■■■     */
        {
            {0, 0, 0, 0},
            {0, 0, 1, 0},
            {1, 1, 1, 0},
            {0, 0, 0, 0} },
        {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0} },
        {
            {0, 0, 0, 0},
            {0, 1, 1, 1},
            {0, 1, 0, 0},
            {0, 0, 0, 0} },
        {
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0} },

            /* 세 번째 블록
                    ■
                  ■■■    */
            {
                {0, 0, 0, 0},
                {0, 1, 0, 0},
                {1, 1, 1, 0},
                {0, 0, 0, 0} },
            {
                {0, 0, 0, 0},
                {0, 1, 0, 0},
                {1, 1, 0, 0},
                {0, 1, 0, 0} },
            {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {1, 1, 1, 0},
                {0, 1, 0, 0} },
            {
                {0, 0, 0, 0},
                {0, 1, 0, 0},
                {0, 1, 1, 0},
                {0, 1, 0, 0} },

                /* 네 번째 블록

                      ■■■■   */
                {
                    {0, 1, 0, 0},
                    {0, 1, 0, 0},
                    {0, 1, 0, 0},
                    {0, 1, 0, 0} },
                {
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0} },
                {
                    {0, 1, 0, 0},
                    {0, 1, 0, 0},
                    {0, 1, 0, 0},
                    {0, 1, 0, 0} },
                {
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0} },

                    /* 다섯 번째 블록

                          ■■
                          ■■      */
                    {
                        {1, 1, 0, 0},
                        {1, 1, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0} },
                    {
                        {1, 1, 0, 0},
                        {1, 1, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0} },
                    {
                        {1, 1, 0, 0},
                        {1, 1, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0} },
                    {
                        {1, 1, 0, 0},
                        {1, 1, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0} },


                        /* 여섯 번째 블록
                                ■■
                              ■■      */
                        {
                            {0, 0, 0, 0},
                            {0, 1, 1, 0},
                            {1, 1, 0, 0},
                            {0, 0, 0, 0} },
                        {
                            {0, 1, 0, 0},
                            {0, 1, 1, 0},
                            {0, 0, 1, 0},
                            {0, 0, 0, 0} },
                        {
                            {0, 0, 0, 0},
                            {0, 1, 1, 0},
                            {1, 1, 0, 0},
                            {0, 0, 0, 0} },
                        {
                            {0, 1, 0, 0},
                            {0, 1, 1, 0},
                            {0, 0, 1, 0},
                            {0, 0, 0, 0} },

                            /* 일곱 번째 블록

                                  ■■
                                    ■■    */
                            {
                                {0, 0, 0, 0},
                                {1, 1, 0, 0},
                                {0, 1, 1, 0},
                                {0, 0, 0, 0} },
                            {
                                {0, 1, 0, 0},
                                {1, 1, 0, 0},
                                {1, 0, 0, 0},
                                {0, 0, 0, 0} },
                            {
                                {0, 0, 0, 0},
                                {1, 1, 0, 0},
                                {0, 1, 1, 0},
                                {0, 0, 0, 0} },
                            {
                                {0, 1, 0, 0},
                                {1, 1, 0, 0},
                                {1, 0, 0, 0},
                                {0, 0, 0, 0} },
};
int SizeCheck(COORD curPoint, int w, int h, int* arr) {
    int var = 4;
    if (curPoint.X+arr[0]+ 2*var > w)return 1;
    if (curPoint.Y+arr[1] + var > h)return 1;
    if (curPoint.X + arr[0] < 1)return 1;
    if (curPoint.Y+arr[1] < 1)return 1;
    return 0;
}
int check(int* arr) {
    if (arr[0] ==0&& arr[1] == 0)return 1;
    return 0;
}
void Locate(int *arr) {
    int pass = 1;
    while (pass) {
        arr[0] = (rand() % 3)-1;
        arr[1] = (rand() % 3)-1;
        pass=check(arr);
    }
    arr[0] *= 2;
}
void SetCurrentCursorPos(int x, int y)
{
    COORD position = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
COORD GetCurrentCursorPos(void)
{
    COORD curPoint;
    CONSOLE_SCREEN_BUFFER_INFO curInfo;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curPoint.X = curInfo.dwCursorPosition.X;
    curPoint.Y = curInfo.dwCursorPosition.Y;

    return curPoint;
}
void FullScreen() {
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}
void ShowBlock(char block[4][4]) {
    COORD curPos = GetCurrentCursorPos();
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            SetCurrentCursorPos(curPos.X + 2* x, curPos.Y + y);
            if (block[y][x] == 1)
                printf("■");
        }

        SetCurrentCursorPos(curPos.X, curPos.Y);
    }
}
void DeleteBlock(char block[4][4]) {
    COORD curPos = GetCurrentCursorPos();
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            SetCurrentCursorPos(curPos.X + 2 * x, curPos.Y + y);
            if (block[y][x] == 1)
                printf("  ");
        }
        SetCurrentCursorPos(curPos.X, curPos.Y);
    }
}
int GetRandomBlock() {
    return rand() % 7;
}
COORD RandPos(int w,int h) {
    COORD tmp;
    tmp.X = (rand() % w) +8;
    tmp.Y = (rand() % h) + 8;
    return tmp;
}
int main(){
    //FullScreen();
    COORD curPoint;
    srand((unsigned int)time(NULL));
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);
    width /= 20;
    height /= 20;
    char info[100] = { "" };
    sprintf(info, "mode con cols=%d lines=%d", width, height);
    system(info);
    int flag = 1;
    int num = 0;
    int arr[2] = { 0, };
    int check = 0;
    int time = 0;
    int tmp = 0;
    while (1) {
        if (_kbhit())break;
        curPoint = GetCurrentCursorPos();
        if (check == time)flag = 1;
        if (flag) {
            curPoint = RandPos((width - 16), (height - 16));
            SetCurrentCursorPos(curPoint.X, curPoint.Y);
            time = (rand() % 18) + 2;
            while (1) {
                tmp = 4 * GetRandomBlock();
                if (tmp != num) {
                    num = tmp;
                    break;
                }
            }
            flag = 0;
            check = 0;
        }
        int Size = 1;
        ShowBlock(blockModel[num+check%4]);
        Sleep(400);
        DeleteBlock(blockModel[num+check%4]);
        while (Size) {
            Locate(arr);
            Size = SizeCheck(curPoint, width, height, arr);
        }
        SetCurrentCursorPos(curPoint.X+arr[0], curPoint.Y+arr[1]);
        check++;
    }
    return 0;
}