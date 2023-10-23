#include<stdio.h>
#include<windows.h>

int main()
{
	COORD p1;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;
	HANDLE console;
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	p1.X = 0;
	p1.Y = 0;
	for (int i = 0; i < 7; i++)
	{
		SetConsoleCursorPosition(console, p1);
		GetConsoleScreenBufferInfo(console, &curInfo);
		printf("[%d, %d]\n", curInfo.dwCursorPosition.X, curInfo.dwCursorPosition.Y);
		if (i < 3) p1.X++;
		else p1.X--;
		p1.Y++;
	}
	getchar();
	return 0;
}