#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>

int main()
{
	int buffer[10] = { 0 };
	int num = 0;
	int num_10 = 0;
	int total_count = 0;
	int num3 = 0;
	int i = 0;
	int count = 1;

	FILE* fp = fopen("input.txt", "rb");
	fscanf(fp, "%d", &num);

		
	for (i = 1; i <= num; i++)
	{
		if (i < 10)
		{
			if (((i % 10) == 3) || ((i % 10) == 6) || ((i % 10) == 9))
			{
				total_count = 1;
			}
		}
		else if ((i > 10) && (i < 100))
		{
			if (((i % 10) == 3) || ((i % 10) == 6) || ((i % 10) == 9))
			{
				total_count = 1;
			}

			if (((i / 10) == 3) || ((i / 10) == 6) || ((i / 10) == 9))
			{
				total_count += 1;
			}
		}
		else if (i > 100)
		{
			num_10 = i / 10;
			if (((i % 10) == 3) || ((i % 10) == 6) || ((i % 10) == 9))
			{
				total_count = 1;
			}
			if (((num_10 / 10) == 3) || ((num_10 / 10) == 6) || ((num_10 / 10) == 9))
			{
				total_count += 1;
			}
			if (((i / 100) == 3) || ((i / 100) == 6) || ((i / 100) == 9))
			{
				total_count += 1;
			}

		}

		if (total_count == 1)
		{
			printf("- ");
		}
		else if (total_count == 2)
		{
			printf("-- ");
		}
		else if(total_count == 3)
		{
			printf("--- ");
		}
		else if(total_count == 0)
		{
			printf("%d ", i);
		}
		
		total_count = 0;
	}

	fclose(fp);
	return 0;

}
#if 0
int check_10(int i)
{
	int num_10 = 0;
	int result = 0;

	if (((i / 10) == 3) || ((i / 10) == 6) || ((i / 10) == 9))
	{
		result = 1;
	}
	else
	{
		result = 0;
	}
	if (((num_10 % 10) == 3) || ((num_10 % 10) == 6) || ((num_10 % 10) == 9))
	{
		result += 1;
	}
	else
	{
		result += 0;
	}
	return result;
}

int check_100(int i)
{
	int num_10 = 0;
	int num_1 = 0;
	int result = 0;

	num_10 = i / 10;
	num_1 = num_10 / 10;

	if (((i / 100) == 3) || ((i / 100) == 6) || ((i / 100) == 9))
	{
		result = 1;
	}
	else
	{
		result = 0;
	}

	if (((num_10 % 10) == 3) || ((num_10 % 10) == 6) || ((num_10 % 10) == 9))
	{
		result += 1;
	}
	else
	{
		result += 0;
	}

	if (((num_1 % 10) == 3) || ((num_1 % 10) == 6) || ((num_1 % 10) == 9))
	{
		result += 1;
	}
	else
	{
		result += 0;
	}
	return result;
}
#endif