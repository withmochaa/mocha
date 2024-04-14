#pragma warning(disable:4996)
#include<stdio.h>
#include<Windows.h>
#include<time.h>
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


COORD pos = { 5,4 };
int block_id = 0;


void SetCurrentCursorPos(int x, int y)
{
    COORD position = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
void ShowBlock(char block[4][4]) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            SetCurrentCursorPos(pos.X + 2 * x, pos.Y + y);
            if (block[y][x] == 1)
                printf("■");
        }

        SetCurrentCursorPos(pos.X, pos.Y);
    }
}
void DeleteBlock(char block[4][4]) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            SetCurrentCursorPos(pos.X + 2 * x, pos.Y + y);
            if (block[y][x] == 1)
                printf("  ");
        }
        SetCurrentCursorPos(pos.X, pos.Y);
    }
}
void RemoveCursor(void)
{
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
void GetRandomBlock() {
    block_id = (rand() % 7) * 4;
}

void ShiftLeft()
{
    RemoveCursor();
    DeleteBlock(blockModel[block_id]);
    pos.X -= 2;
    ShowBlock(blockModel[block_id]);
    Sleep(300);
}
void ShiftRight()
{
    RemoveCursor();
    DeleteBlock(blockModel[block_id]);
    pos.X += 2;
    ShowBlock(blockModel[block_id]);
    Sleep(300);
}
void BlockDown()
{
    RemoveCursor();
    DeleteBlock(blockModel[block_id]);
    pos.Y += 1;
    ShowBlock(blockModel[block_id]);
    Sleep(300);
}
void RotateBlock()
{
    RemoveCursor();
    int current_block;
    DeleteBlock(blockModel[block_id]);
    current_block = block_id - (block_id % 4);
    block_id = current_block + (block_id + 1) % 4;
    ShowBlock(blockModel[block_id]);
    Sleep(300);
}
void Repeat(int x, int flag) {
    switch (flag) {
    case 1:
        for (int i = 0; i < x + 2; i++)BlockDown();
        break;
    case 2:
        for (int i = 0; i < x + 2; i++)ShiftRight();
        break;
    case 3:
        for (int i = 0; i < x; i++)RotateBlock();
        break;
    case 4:
        for (int i = 0; i < x + 2; i++)BlockDown();
        break;
    case 5:
        for (int i = 0; i < x + 2; i++)ShiftLeft();
        break;
    case 6:
        for (int i = 0; i < x + 2; i++)BlockDown();
        break;
    default:
        break;
    }
}
int main()
{
    srand((unsigned int)time(NULL));
    GetRandomBlock();
    for (int i = 1; i < 7; i++)Repeat(4, i);
    return 0;
}
