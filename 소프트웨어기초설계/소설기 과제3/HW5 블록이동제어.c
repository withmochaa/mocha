#pragma warning(disable:4996)
#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#define Q   113
#define W   119
#define E   101
#define A   97
#define S   115
#define D   100
#define Z   122
#define M   120
#define C   99
#define J   106
#define K   107
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
COORD pos = { 4,4 };
int block_id = 0;

void GetRandomBlock() {
    block_id = (rand() % 7) * 4;
}
void ShiftLeft()
{
    pos.X -= 2;
}
void ShiftRight()
{
    pos.X += 2;
}
void BlockDown()
{
    pos.Y += 1;
}
void BlockUp()
{
    pos.Y -= 1;
}

void RotateBlock(int x)
{
    int current_block;
    current_block = block_id - (block_id % 4);
    block_id = current_block + (block_id + x) % 4;
}
void RemoveCursor(void)
{
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
void SetCurrentCursorPos(int x, int y)
{
    COORD position = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
void ShowBlock(char blockInfo[4][4]) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            SetCurrentCursorPos(pos.X + x * 2, pos.Y + y);
            if (blockInfo[y][x] == 1)
                printf("■");
        }
        SetCurrentCursorPos(pos.X, pos.Y);
    }
}
void DeleteBlock(char blockInfo[4][4]) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            SetCurrentCursorPos(pos.X + x * 2, pos.Y + y);
            if (blockInfo[y][x] == 1)
                printf("  ");
        }
        SetCurrentCursorPos(pos.X, pos.Y);
    }
}
void Move(int key)
{
    switch (key){
    case Q:
        ShiftLeft();
        BlockUp();
        break;
    case W:
        BlockUp();
        break;
    case E:
        ShiftRight();
        BlockUp();
        break;
    case A:
        ShiftLeft();
        break;
    case S:
        break;
    case D:
        ShiftRight();
        break;
    case Z:
        ShiftLeft();
        BlockDown();
        break;
    case M:
        BlockDown();
        break;
    case C:
        ShiftRight();
        BlockDown();
        break;
    case J:
        RotateBlock(1);
        break;
    case K:
        RotateBlock(2);
        break;
    default:
        break;
    }
}
int main()
{
    srand((unsigned int)time(NULL));
    RemoveCursor();
    GetRandomBlock();
    ShowBlock(blockModel[block_id]);
    while (1) {
        if (_kbhit()) {
            DeleteBlock(blockModel[block_id]);
            int tmp = _getch();
            if (tmp == 'X')tmp = 'M';
            Move(tmp);
            ShowBlock(blockModel[block_id]);
        }
    }
    return 0;
}