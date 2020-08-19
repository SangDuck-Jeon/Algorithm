#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{
	int Date = 0;
	int num1 = 0;
	int i = 0;
	int j = 0;
	int cost[1000] = { 0 };
	int buy = 0;
	int sum_cost[1000] = { 0 };
	int final_buy = 0;
	int count = 0;

	FILE* fp = fopen("input.txt", "rb");
	fscanf(fp, "%d", &num1);

	for (i = 0; i < num1; i++)
	{
		fscanf(fp, "%d", &Date);
		printf("Data = %d \n", Date);

		for (j = 0; j < Date; j++)
		{
			fscanf(fp, "%d", &cost[j]);
			printf("cost = %d \n", cost[j]);
		}

			
		for (j = 0; j < Date; j++)
		{
			if (j != Date-1)
			{
				if (cost[j] < cost[j + 1])		// j < j+1			
				{
					buy += cost[j];
					count += 1;
				}
				else if (cost[j] > cost[j + 1])	// j > j+1
				{
					if (count > 0)
					{
						sum_cost[j] = cost[j] * count - buy;
						count = 0;
						buy = 0;
					}
					else
					{
						buy = 0;
						
					}
				}
				else if (cost[j] == cost[j + 1])					// j = j+1
				{
					buy += cost[j];
					count += 1;
				}
			}
			else
			{
				if (cost[j - 1] < cost[j])		// j-1 < j
				{
					sum_cost[j] = cost[j] * count - buy;
					count = 0;
					buy = 0;
				}
				else if (cost[j - 1] > cost[j])	// j-1 > j
				{
					//buy = 0;
				
				}
			}
			printf("buy = %d \n", buy);
			printf("count = %d \n", count);
			printf("sumcost[%d] = %d \n",j, sum_cost[j]);
		}
		for (j = 0; j < Date; j++)
		{
			final_buy += sum_cost[j];
			sum_cost[j] = 0;
		}
		printf("#%d %d \n", i + 1, final_buy);
		final_buy = 0;
		buy = 0;
	}
	fclose(fp);
	return 0;

}

