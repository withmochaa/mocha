#include<stdio.h>
#include<windows.h>
char blockModel[][4][4] =
{
	{
		{0, 0, 0, 0},
		{1, 0, 0, 0},
		{1, 1, 1, 0},
		{0, 0, 0, 0}	},

	{
		{0, 1, 0, 0},
		{0, 1, 0, 0},
		{1, 1, 0, 0},
		{0, 0, 0, 0}	},

	{
		{1, 1, 1, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}	},

	{
		{1, 1, 0, 0},
		{1, 0, 0, 0},
		{1, 0, 0, 0},
		{0, 0, 0, 0}	},
};
COORD GetCurrentCursorPos(void)
{
	COORD curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curPoint.X = curInfo.dwCursorPosition.X;
	curPoint.Y = curInfo.dwCursorPosition.Y;

	return curPoint;
}
void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Show(char blockInfo[][4])
{
	COORD curPos = GetCurrentCursorPos();

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			gotoxy(curPos.X + (x * 2), curPos.Y + y);
			if (blockInfo[y][x] == 1)
			{
				printf("бс");
			}
		}
	}
	gotoxy(curPos.X, curPos.Y);
}
int SetY(int var) {
	int ret = 0;
	var > 1 ? ret = 1 : ret = 0;
	return ret*10;
}
int main(){
	for (int i = 0; i < 4; i++) {
		gotoxy(((i % 2) * 10), SetY(i));
		Show(blockModel[i]);
	}
	getchar();
	return 0;
}