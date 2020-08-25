#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>

int main()
{
	int buffer[10] = { 0 };
	int num = 0;
	int num_1 = 0;
	int total_count = 0;
	int num3 = 0;
	int i = 0;
	int j;
	int count = 1;
	int point[1000];

	FILE* fp = fopen("input.txt", "rb");
	fscanf(fp, "%d", &num);

		
	for (i = 1; i <= num; i++)
	{
		fscanf(fp, "%d", &num_1);
		for (j = 0; j < 1000; j++)
		{
			fscanf(fp, "%d", &point[j]);
			count[point[j]] += 1;
			printf("count[%d] = %d \n", point[j], count[point[j]]);
		}


	}

	fclose(fp);
	return 0;

}
#if 0
for (i = 0; i < 10; i++)
{
	if (max <= count[i])
		max = count[i];
	else if (max == count[i])
	{
		if (max < count[i])
			max = count[i];
	}
}
#endif