#include <stdio.h>

/*int main()
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
}*/

/*void find_sleeping_space()
{
	int n;
	scanf("%d", &n);
	int i, j;
	int T_garo_cnt = 0;
	int T_sero_cnt = 0;
	int garo_cnt = 0;
	int sero_cnt = 0;
	char A[101][101];
	getchar();
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%c", &A[i][j]);
		}
		getchar();
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (A[i][j] == '.')
				garo_cnt++;
			else if (A[i][j] = 'X')
			{
				if (garo_cnt >= 2)
					T_garo_cnt++;
				garo_cnt = 0;
			}
			if (A[j][i] == '.')
				sero_cnt++;
			else if (A[j][i] = 'X')
			{
				if (sero_cnt >= 2)
					T_sero_cnt++;
				sero_cnt = 0;
			}
		}
		if (garo_cnt >= 2)
			T_garo_cnt++;
		if (sero_cnt >= 2)
			T_sero_cnt++;
		garo_cnt = sero_cnt = 0;
	}
	printf("%d %d", T_garo_cnt, T_sero_cnt);
}
void main()
{
	find_sleeping_space();
}*/

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
			else if(room[i][j] = 'X')
			{
				if (cnt >= 2)
				{
					garo_cnt++;
				}
				cnt = 0;
			}
			if (room[j][i] == '.')
			{
				cnt++;
			}
			else if(room[j][i] = 'X')
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
			garo_cnt++;
		}
		if (cnt >= 2)
		{
			sero_cnt++;
		}
	}
	printf("%d %d\n", garo_cnt, sero_cnt);

	return 0;
}

