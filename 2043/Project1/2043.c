#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>

void compare(int totalcase, int number1, int number2);

int main()
{
	int buffer[10] = { 0 };
	int num1 = 0;
	int num2 = 0;
	int i = 0;
	int count = 1;

	FILE* fp = fopen("input.txt", "rb");
	fscanf(fp, "%d", &num1);
	fscanf(fp, "%d", &num2);
	
	for (i = 0; i < 999; i++)
	{
		if (num1 == num2)
		{
			printf("%d", count);
			break;
		}

		num2 += 1;
		count += 1;
	}
	fclose(fp);
	return 0;

}
