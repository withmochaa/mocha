#pragma warning(disable:4996)
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>

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

/* Size of gameboard */
#define	GBOARD_WIDTH	10
#define GBOARD_HEIGHT	20

/* Starting point of gameborad */
#define GBOARD_ORIGIN_X	8
#define GBOARD_ORIGIN_Y	4

int speed;
int block_id;
COORD pos = { 0,0 };
int gameBoardInfo[GBOARD_HEIGHT + 1][GBOARD_WIDTH + 2];
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
void DrawGameBoard()
{
    for (int y = 0; y <= GBOARD_HEIGHT; y++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + y);
        if (y == GBOARD_HEIGHT)
            printf("└");
        else
            printf("│");
    }

    for (int x = 1; x < GBOARD_WIDTH + 1; x++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X + (x * 2), GBOARD_ORIGIN_Y + GBOARD_HEIGHT);
        printf("─");
    }

    for (int y = 0; y <= GBOARD_HEIGHT; y++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X + (GBOARD_WIDTH + 1) * 2, GBOARD_ORIGIN_Y + y);
        if (y == GBOARD_HEIGHT)
            printf("┘");
        else
            printf("│");
    }
    setGameBoardInfo();
    SetCurrentCursorPos(GBOARD_ORIGIN_X + GBOARD_WIDTH, 0);
    pos.X = GBOARD_ORIGIN_X + GBOARD_WIDTH;
    pos.Y = 0;
}
void RemoveCursor()
{
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
void ShowBlock(char blockInfo[4][4]) {
    RemoveCursor();
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
int BlockDown()
{
    COORD tmppos = { pos.X,pos.Y + 1 };
    if (Detect(tmppos, blockModel[block_id])) { return 1; }
    DeleteBlock(blockModel[block_id]);
    pos.Y += 1;
    SetCurrentCursorPos(pos.X, pos.Y);
    ShowBlock(blockModel[block_id]);
    return 0;
}
int Detect(COORD pos, char blockModel[4][4])
{
    COORD check;
    check.X = (pos.X - GBOARD_ORIGIN_X) / 2;
    check.Y = (pos.Y - GBOARD_ORIGIN_Y);
    for (int y = 0; y < 4; y++){
        for (int x = 0; x < 4; x++){
            if (blockModel[y][x] == 1 && gameBoardInfo[check.Y + y][check.X + x] == 1){
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    srand((unsigned int)time(NULL));
    block_id = rand() % 7 * 4;
    DrawGameBoard();
    while (1){
        if (BlockDown())
            break;
        Sleep(300);
    }
    getchar();
    return 0;
}