#include<stdio.h>

int main()
{
	int height[51], weight[51], N;
	int i, j, count;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d %d", &weight[i], &height[i]);
	}

	for (i = 0; i < N; i++)
	{
		count = 0;
		for (j = 0; j < N; j++)
		{
			if (weight[j] > weight[i] && height[j] > height[i])
			{
				count++;
			}
		}
		printf("%d ", count + 1);
	}

	return 0;
}
