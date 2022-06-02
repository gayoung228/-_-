#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

int min(int x, int y)
{
	if (x < y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

typedef struct
{
	char color;
	int num;
}card;

int main()
{
	card arr[5];
	char trash[100];
	int col[4]; // �� ������ �� ���� ������ �ִ���
	int number[11]; // �� ���ڵ��� �� ���� ������ �ִ���
	memset(col, 0, sizeof(col));
	memset(number, 0, sizeof(number));
	for (int i = 0; i < 5; i++)
	{
		scanf("%c %d", &arr[i].color, &arr[i].num);
		fgets(trash, 99, stdin); // �̰� �����ָ� �Է��� ����� �ȵ�
		// RBYG
		if (arr[i].color == 'R')
		{
			col[0]++;
		}
		else if (arr[i].color == 'B')
		{
			col[1]++;
		}
		else if (arr[i].color == 'Y')
		{
			col[2]++;
		}
		else
		{
			col[3]++;
		}
		number[arr[i].num]++;
	}
	int ans; 
	// ���� ��ġ�� �� ����� ���س���
	int c_one = 0, c_two = 0, c_three = 0, c_four = 0, c_five = 0;
	for (int i = 0; i < 4; i++)
	{
		if (col[i] == 1)
		{
			c_one++;
		}
		else if (col[i] == 2)
		{
			c_two++;
		}
		else if (col[i] == 3)
		{
			c_three++;
		}
		else if (col[i] == 4)
		{
			c_four++;
		}
		else if (col[i] == 5)
		{
			c_five++;
		}
	}
	// �������� ���� �ִ� �� ���ϱ� 
	int yes = 0, max_num = -1;
	for (int i = 1; i <= 6; i++)
	{
		if (number[i] == 1 && number[i + 1] == 1 && number[i + 2] == 1 && number[i + 3] == 1 && number[i + 4] == 1)
		{
			yes = 1;
		}
	}
	// ���� ���ڵ� �̸� ���ϱ�
	int n_one = 0, n_two = 0, n_three = 0, n_four = 0, n_five = 0, i_four = 0, i_three = 0;
	int i_two[2];
	for (int i = 1; i <= 10; i++)
	{
		if (number[i] > 0)
		{
			max_num = i;
		}
		if (number[i] == 1)
		{
			n_one++;
		}
		else if (number[i] == 2)
		{
			n_two++;
			if (n_two == 1)
			{
				i_two[0] = i;
			}
			else
			{
				i_two[1] = i;
			}
		}
		else if (number[i] == 3)
		{
			n_three++;
			i_three = i;
		}
		else if (number[i] == 4)
		{
			n_four++;
			i_four = i;
		}
		else if (number[i] == 5)
		{
			n_five++;
		}
	}

	// ī�� 5���� ��� �������� ���̸鼭 ���ڰ� �������� �� ������ ���� ���� ���ڿ� 900�� ���Ѵ�. ���� ���, ī�尡 Y4, Y3, Y2, Y5, Y6 �� �� ������ 906(=6+900)���̴�. 
	if (c_five == 1 && yes == 1) ans = max_num + 900;
	//ī�� 5�� �� 4���� ���ڰ� ���� �� ������ ���� ���ڿ� 800�� ���Ѵ�. ���� ���, ī�尡 B3, R3, B7, Y3, G3 �� �� ������ 803(=3+800)���̴�.
	else if (n_four == 1) ans = 800 + i_four;
	//ī�� 5�� �� 3���� ���ڰ� ���� ������ 2�嵵 ���ڰ� ���� �� ������ 3���� ���� ���ڿ� 10�� ���ϰ� 2���� ���� ���ڸ� ���� ���� 700�� ���Ѵ�. ���� ���, ī�尡 R5, Y5, G7, B5, Y7 �� �� ������ 757(=5x10+7+700)���̴�.
	else if (n_three == 1 && n_two == 1)  ans = (i_three * 10) + i_two[0] + 700;
	//5���� ī�� ������ ��� ���� �� ������ ���� ���� ���ڿ� 600�� ���Ѵ�. ���� ���, ī�尡 Y3, Y4, Y8, Y6, Y7 �� �� ������ 608(=8+600)���̴�.
	else if (c_five == 1) ans = max_num + 600;
	//ī�� 5���� ���ڰ� �������� �� ������ ���� ���� ���ڿ� 500�� ���Ѵ�. ���� ��� R7, R8, G9, Y6, B5 �� �� ������ 509(=9+500)���̴�.
	else if (yes == 1) ans = max_num + 500;
	//ī�� 5�� �� 3���� ���ڰ� ���� �� ������ ���� ���ڿ� 400�� ���Ѵ�. ���� ��� R7, Y7, R2, G7, R5 �� �� ������ 407(=7+400)���̴�.
	else if (n_three == 1) ans = i_three + 400;
	//ī�� 5�� �� 2���� ���ڰ� ���� �� �ٸ� 2���� ���ڰ� ���� �� ������ ���� ���� �� ū ���ڿ� 10�� ���ϰ� ���� ���� �� ���� ���ڸ� ���� ���� 300�� ���Ѵ�. ���� ���, R5, Y5, Y4, G9, B4 �� �� ������ 354(=5X10+4+300)���̴�.
	else if (n_two == 2) ans = (max(i_two[0], i_two[1]) * 10) + min(i_two[0], i_two[1]) + 300;
	//ī�� 5�� �� 2���� ���ڰ� ���� �� ������ ���� ���ڿ� 200�� ���Ѵ�. ���� ���, R5, Y2, B5, B3, G4 �� �� ������ 205(=5+200)���̴�.
	else if (n_two == 1) ans = i_two[0] + 200;
	//���� � ��쿡�� �ش����� ���� �� ������ ���� ū ���ڿ� 100�� ���Ѵ�. ���� ���, R1, R2, B4, B8, Y5 �� �� ������ 108(=8+100)���̴�.
	else ans = max_num + 100;

	printf("%d\n", ans);
}