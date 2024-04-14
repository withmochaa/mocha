#pragma warning(disable:4996)
#include<stdio.h>
#include<Windows.h>
char blockModel[4][4] = {
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0}
};
void SetCurrentCursorPos(int x, int y) {
    COORD position = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
COORD GetCurrentCursorPos(void) {
    COORD curPoint;
    CONSOLE_SCREEN_BUFFER_INFO curInfo;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curPoint.X = curInfo.dwCursorPosition.X;
    curPoint.Y = curInfo.dwCursorPosition.Y;
    return curPoint;
}
void ShowBlock(char block[4][4]) {
    COORD curPos = GetCurrentCursorPos();
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            SetCurrentCursorPos(curPos.X + 2 * x, curPos.Y + y);
            if (block[y][x] == 1)
                printf("бс");
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
int main(){
    COORD curPoint = GetCurrentCursorPos();
    for (int i = 1; i < 6; i++){
        ShowBlock(blockModel);
        Sleep(300);
        DeleteBlock(blockModel);
        SetCurrentCursorPos(curPoint.X + 3*i, curPoint.Y + 3*i);
    }
    return 0;
}