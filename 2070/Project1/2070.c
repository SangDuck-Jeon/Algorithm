#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>

void compare(int totalcase, int number1, int number2);

int main()
{
	int buffer[10] = { 0 };
	int num1 = 0;
	int i = 0;
	int j = 0;

	FILE* fp = fopen("input.txt", "rb");
	fscanf(fp, "%d", &num1);

	for (i = 0; i < num1; i++)
	{
		for (j = 0; j < 2; j++)
		{
			fscanf(fp, "%d", &buffer[j]);
		}

		compare(i, buffer[0], buffer[1]);

	}
	fclose(fp);
	return 0;

}

void compare(int totalcase, int number1, int number2)
{
	int result = 0;

	if (number1 > number2)
	{
		printf("#%d > \n", totalcase + 1);
	}
	else if (number1 < number2)
	{
		printf("#%d < \n", totalcase + 1);
	}
	else
	{
		printf("#%d = \n", totalcase + 1);
	}

	return 0;
}