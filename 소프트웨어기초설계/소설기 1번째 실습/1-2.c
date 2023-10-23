#include<stdio.h>
#include<windows.h>

int main()
{
	COORD p1;

	for (int x = 7; x < 20; x++)
	{
		for (int y = 7; y < 20; y++)
		{
			p1.X = 2 * x;
			p1.Y = y;
			if ((x == 7) || (y == 7) || (y == 19) || (x == 19)) {
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p1);
				printf("бс");
			}
		}
	}
	getchar();
	return 0;
}