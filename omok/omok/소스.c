#include <stdio.h>
#include <Windows.h>
#define COL 15
#define ROW 15

int area[ROW+8][COL+8];
int cnt = 0;
int chk = 0;

int create_area();
int print_area();
int input();
int check(int y, int x);
int down_check(int y, int x);
int right_check(int y, int x);
int downRight_check(int y, int x);
int downLeft_check(int y, int x);

int create_area()
{
	for (int i = 0; i < ROW + 8; i++)
	{
		for (int j = 0; j < COL + 8; j++)
		{
			if (i >= 4 && j >= 4 && i <= ROW + 3 && j <= COL + 3)
			{
				area[i][j] = 0;
			}
			else
			{
				area[i][j] = 9;
			}
		}
	}
}
int print_area()
{
	system("cls");
	if (cnt == 0)
	{
		printf("Èæ\n\n\n");
	}
	else
	{
		printf("¹é\n\n\n");
	}
	for (int i = 4; i < ROW+4; i++)
	{
		for (int j = 4; j < COL+4; j++)
		{
			if (area[i][j] == 0)
			{
				printf("¡à");
			}
			else if (area[i][j] == 1)
			{
				printf("¡Û");
			}
			else if (area[i][j] == 2)
			{
				printf("¡Ü");
			}
		}
		printf("\n");
	}
}

int input()
{
	int y, x;
	scanf(" %d%d", &y, &x);
	if (y > 15 || x > 15)
	{
		return input();
	}
	if (area[y+4-1][x+4-1] == 0)
	{
		if (cnt == 0)
		{
			area[y + 4 - 1][x + 4 - 1] = 1;
			cnt = 1;
		}
		else
		{
			area[y + 4 - 1][x + 4 - 1] = 2;
			cnt = 0;
		}
		
	}
	print_area();
	if (!check(y, x))
	{
		return 0;
	}
	return input();
}

int check(int y, int x)
{
	if (down_check(y, x) || right_check(y, x) || downLeft_check(y, x) || downRight_check(y, x))
	{
		if (cnt == 1)
		{
			printf("Èæ ½Â\n");
		}
		else
		{
			printf("¹é ½Â\n");
		}
		return 0;
	}
	return 1;
}

int down_check(int y, int x)
{
	for (int i = 4; i > -5; i--)
	{
		if (cnt == 1)
		{
			if (area[y + 4 - 1 - i][x + 4 - 1] == 1)
			{
				chk++;
			}
			else
			{
				chk=0;
			}
		}
		else
		{
			if (area[y + 4 - 1 - i][x + 4 - 1] == 2)
			{
				chk++;
			}
			else
			{
				chk = 0;
			}
		}

		if (chk >= 5)
		{
			return 1;
		}

	}
	return 0;
}


int right_check(int y, int x)
{
	for (int i = 4; i > -5; i--)
	{
		if (cnt == 1)
		{
			if (area[y + 4 - 1][x + 4 - 1-i] == 1)
			{
				chk++;
			}
			else
			{
				chk = 0;
			}
		}
		else
		{
			if (area[y + 4 - 1][x + 4 - 1-i] == 2)
			{
				chk++;
			}
			else
			{
				chk = 0;
			}
		}

		if (chk >= 5)
		{
			return 1;
		}

	}
	return 0;
}

int downRight_check(int y, int x)
{
	for (int i = 4; i > -5; i--)
	{
		if (cnt == 1)
		{
			if (area[y + 4 - 1 - i][x + 4 - 1-i] == 1)
			{
				chk++;
			}
			else
			{
				chk = 0;
			}
		}
		else
		{
			if (area[y + 4 - 1 - i][x + 4 - 1-i] == 2)
			{
				chk++;
			}
			else
			{
				chk = 0;
			}
		}

		if (chk >= 5)
		{
			return 1;
		}

	}
	return 0;
}

int downLeft_check(int y, int x)
{
	for (int i = 4; i > -5; i--)
	{
		if (cnt == 1)
		{
			if (area[y + 4 - 1 - i][x + 4 - 1+i] == 1)
			{
				chk++;
			}
			else
			{
				chk = 0;
			}
		}
		else
		{
			if (area[y + 4 - 1 - i][x + 4 - 1+i] == 2)
			{
				chk++;
			}
			else
			{
				chk = 0;
			}
		}

		if (chk >= 5)
		{
			return 1;
		}

	}
	return 0;
}


int main()
{
	create_area();
	print_area();
	input();
	return 0;
}