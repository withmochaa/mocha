#pragma warning(disable:4996)
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>
#include"block.h"
/* Size of gameboard */
#define	GBOARD_WIDTH	10
#define GBOARD_HEIGHT	20

/* Starting point of gameborad */
#define GBOARD_ORIGIN_X	4
#define GBOARD_ORIGIN_Y	2

enum Key{SPACE=32,LEFT=75,RIGHT=77,UP=72};

int speed;
int block_id;
COORD pos;
int score;
int BlockDown();
void DrawGameBoard();
int DetectCollision(COORD, char blockModel[4][4]);
void setGameBoardInfo();
void ShowBlock(char blockModel[4][4]);
void DeleteBlock(char blockModel[4][4]);
void SetCurrentCursorPos(int, int);
void ProcessKeyInput();
void RemoveCursor();
void SpaceDown();
int IsGameOver();
void AddBlockToBoard();
void RedrawBlocks();
void RemoveFillUpLine();
void Shift(int);
void RotateBlock();
int gameBoardInfo[GBOARD_HEIGHT + 1][GBOARD_WIDTH + 2];
int main()
{
    int key;
    score = 0;
    srand((unsigned int)time(NULL));
    DrawGameBoard();
    while (!IsGameOver())
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X * 2 + GBOARD_WIDTH * 2 + 3, GBOARD_ORIGIN_Y + GBOARD_HEIGHT / 2);
        printf("SCORE: %d", score);
        block_id = (rand() % 7) * 4;
        while (1)
        {
            if (BlockDown() == 0)
            {
                AddBlockToBoard();
                break;
            }
            ProcessKeyInput();
        }
        RemoveFillUpLine();
        pos.X = GBOARD_ORIGIN_X + GBOARD_WIDTH;
        pos.Y = 0;
    }
    SetCurrentCursorPos(GBOARD_ORIGIN_X + GBOARD_WIDTH, 0);
    printf("Game Over!!\n");
    getchar();
    return 0;
}
void DrawGameBoard()
{
    for (int y = 0; y <= GBOARD_HEIGHT; y++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + y);
        if (y == GBOARD_HEIGHT)
            printf("¦¦");
        else
            printf("¦¢");
    }

    for (int x = 1; x < GBOARD_WIDTH + 1; x++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X + (x * 2), GBOARD_ORIGIN_Y + GBOARD_HEIGHT);
        printf("¦¡");
    }

    for (int y = 0; y <= GBOARD_HEIGHT; y++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X + (GBOARD_WIDTH + 1) * 2, GBOARD_ORIGIN_Y + y);
        if (y == GBOARD_HEIGHT)
            printf("¦¥");
        else
            printf("¦¢");
    }
    setGameBoardInfo();
    SetCurrentCursorPos(GBOARD_ORIGIN_X + GBOARD_WIDTH, 0);
    pos.X = GBOARD_ORIGIN_X + GBOARD_WIDTH;
    pos.Y = 0;
}
int BlockDown()
{
    COORD tmp = { pos.X,pos.Y + 1 };
    if (!DetectCollision(tmp, blockModel[block_id])) { return 0; }
    DeleteBlock(blockModel[block_id]);
    pos.Y += 1;
    SetCurrentCursorPos(pos.X, pos.Y);
    ShowBlock(blockModel[block_id]);
    return 1;
}
int DetectCollision(COORD pos, char blockModel[4][4])
{
    int arrX = (pos.X - GBOARD_ORIGIN_X) / 2;
    int arrY = (pos.Y - GBOARD_ORIGIN_Y);
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (blockModel[y][x] == 1 && gameBoardInfo[arrY + y][arrX + x] == 1)
            {
                return 0;
            }
        }
    }
    return 1;
}
void setGameBoardInfo()
{
    for (int y = 0; y < GBOARD_HEIGHT; y++)
    {
        gameBoardInfo[y][0] = 1;
        gameBoardInfo[y][GBOARD_WIDTH + 1] = 1;
    }
    for (int x = 0; x < GBOARD_WIDTH + 2; x++)
    {
        gameBoardInfo[GBOARD_HEIGHT][x] = 1;
    }
}
void SetCurrentCursorPos(int x, int y)
{
    COORD position = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
void ShowBlock(char blockModel[4][4])
{
    RemoveCursor();
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            SetCurrentCursorPos(pos.X + x * 2, pos.Y + y);
            if (blockModel[y][x] == 1)
                printf("¡á");
        }
        SetCurrentCursorPos(pos.X, pos.Y);
    }
}
void DeleteBlock(char blockModel[4][4])
{
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            SetCurrentCursorPos(pos.X + x * 2, pos.Y + y);
            if (blockModel[y][x] == 1)
                printf("  ");
        }
        SetCurrentCursorPos(pos.X, pos.Y);
    }
}
void RemoveCursor()
{
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
void SpaceDown()
{
    while (BlockDown());
}
int IsGameOver()
{
    if (!DetectCollision(pos, blockModel[block_id]))
        return 1;
    return 0;
}
void AddBlockToBoard()
{
    int arrX = (pos.X - GBOARD_ORIGIN_X) / 2;
    int arrY = (pos.Y - GBOARD_ORIGIN_Y);
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (blockModel[block_id][y][x] == 1)
            {
                gameBoardInfo[arrY + y][arrX + x] = 1;
            }
        }
    }
}
void RedrawBlocks(void)
{
    int x, y;
    int cursX, cursY;
    for (y = 0; y < GBOARD_HEIGHT; y++)
    {
        for (x = 1; x < GBOARD_WIDTH + 1; x++)
        {
            cursX = x * 2 + GBOARD_ORIGIN_X;
            cursY = y + GBOARD_ORIGIN_Y;
            SetCurrentCursorPos(cursX, cursY);
            if (gameBoardInfo[y][x] == 1)
            {
                printf("¡á");
            }
            else { printf("  "); }
        }
    }
}
void ProcessKeyInput()
{
    int key=0;
    int beforekey=0;
    for (int i = 0; i < 50; i++){
        if (_kbhit()){
            key = _getch();
            if (beforekey != SPACE) {
                switch (key){
                case SPACE:
                    SpaceDown();
                    break;
                case LEFT:
                    Shift(-2);
                    break;
                case RIGHT:
                    Shift(2);
                    break;
                case UP:
                    RotateBlock();
                    break;
                default:
                    break;
                }
                beforekey = key;
            }
        }
        Sleep(10);
    }
}
void RemoveFillUpLine()
{
    int line, x, y;
    for (y = GBOARD_HEIGHT - 1; y > 0; y--)
    {
        for (x = 1; x < GBOARD_WIDTH + 1; x++)
        {
            if (gameBoardInfo[y][x] != 1)
                break;
        }
        if (x == (GBOARD_WIDTH + 1))
        {
            for (line = 0; y - line > 0; line++)
            {
                memcpy(&gameBoardInfo[y - line][1], &gameBoardInfo[(y - line) - 1][1], GBOARD_WIDTH * sizeof(int));
            }
            score += 10;
            y++;
        }
    }
    RedrawBlocks();
}
void Shift(int a)
{
    RemoveCursor();
    COORD tmp = { pos.X + a,pos.Y };
    if (!DetectCollision(tmp, blockModel[block_id]))
    {
        return;
    }
    DeleteBlock(blockModel[block_id]);
    pos.X +=a;
    if (pos.X < 0) { return; }
    ShowBlock(blockModel[block_id]);
}
void RotateBlock()
{
    RemoveCursor();
    int block_base = block_id - block_id % 4;
    int block_rotated = block_base + (block_id + 1) % 4;
    if (!DetectCollision(pos, blockModel[block_rotated]))
    {
        return 0;
    }
    DeleteBlock(blockModel[block_id]);
    block_id = block_rotated;
    ShowBlock(blockModel[block_id]);
}