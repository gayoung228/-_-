#include <stdio.h>

int main()
{
	int n;
	int garo_cnt = 0, sero_cnt = 0;
	char room[101][101];
	char c;

	// test
	// test2

	scanf("%d", &n); 
	scanf("%c", &c);
	for (int i = 0; i < n; i++)
	{
		printf("%d", i);
		for (int j = 0; j < n; j++)
		{
			scanf("%c", &room[i][j]);
		}
		scanf("%c", &c);
		
	}
	
	//가로
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (room[i][j] == '.')
			{
				cnt++;
			}
			else
			{
				if (cnt >= 2)
				{
					garo_cnt++;
				}
				cnt = 0;
			}
		}
		if (cnt >= 2)
		{
			garo_cnt++;
		}
	}

	//세로
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (room[j][i] == '.')
			{
				cnt++;
			}
			else
			{
				if (cnt >= 2)
				{
					sero_cnt++;
				}
				cnt = 0;
			}
		}
		if (cnt >= 2)
		{
			sero_cnt++;
		}
	}
	printf("%d %d\n", garo_cnt, sero_cnt);

	return 0;
}

