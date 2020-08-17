#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>

#if 1
int main()
{
	char buffer[10] = { 0 };
	int num1 = 0;
	int i = 0;
	int j = 0;
	int sum = 0;
	float result = 0;
	float round_result = 0;

	FILE* fp = fopen("input.txt", "rb");
	fscanf(fp, "%d", &num1);

	for (i = 0; i < num1; i++)
	{
		for (j = 0; j < 10; j++)
		{
			fscanf(fp, "%d", &buffer[i]);
			printf("%d \n", buffer[i]);
			sum += buffer[i];

		}
		//printf("%f \n", sum);
		result = ((float)sum/10);
		round_result = round(result);
		//printf("#%d %f \n", i + 1, result);
		//printf("#%d %f \n", i + 1, round_result);
		sum = 0;
		result = 0;
	}
	fclose(fp);
	return 0;

}
#else

struct Data {
	char num1;
	char num2;
	char num3;
};

int main()
{
	char buffer[30];
	int num1;
	int i;
	int j;
	struct Data d1;
	int sum = 0;

	FILE* fp = fopen("input.txt", "rb");

	fscanf(fp, "%d",  &num1);
	//printf("%d \n\n", num1);

	for (i = 0; i < num1; i++)
	{
#if 1
		for (j = 0; j < 10; j++)
		{
			fscanf(fp, "%d" , &buffer[i]);
			//printf("%d \n", buffer[i]);
			if ((buffer[i] % 2) == 1)
			{
				sum += buffer[i];
			}
		}
		printf("#%d %d \n", i+1, sum);
		sum = 0;
		
#else
		if (fgets(buffer, sizeof(buffer), fp) == NULL) break;
		num1 = atoi(buffer);
		printf("%d \n", num1);
		//printf("%s \n", buffer[1]);
		//printf("%s \n", buffer[2]);
		//printf("%s \n", buffer[3]);
#endif
	}


	fclose(fp);

	return 0;
}

#endif