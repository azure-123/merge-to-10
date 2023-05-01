#include<iostream>
#include<conio.h>
#include<iomanip>
#include<time.h>
#include"cmd_console_tools.h"
#include"90-b2.h"
using namespace std;

void search_clear(int search[][maxn], int row, int col)
{
	for (int i = 0; i <= row; i++)
		for (int j = 0; j <= col; j++)
			search[i][j] = 0;
}

void output_base(int grid[][maxn], int row, int col)
{
	int cnt = 0;
	cout << endl << "�ڲ�����:" << endl;
	cout << "  |";
	for (int i = 0; i < col; i++)
	{
		cout << setw(3) << i;//�����һ��	
	}
	cout << endl;
	cout << "--+";
	for (int i = 1; i <= col * 3 + 2; i++)
		cout << '-';//����ڶ���
	cout << endl;
	char ch = 'A';
	for (int i = 1; i <= row; i++)
	{
		cout << ch << " |";
		ch++;
		for (int j = 1; j <= col; j++)
			cout << setw(3) << grid[i][j];
		cout << endl;
	}
	cout << endl;
	//getchar();//����ǰ������ʱ�����Ļس�
}

void choose_coordinate(int grid[][maxn],int &x, int &y, int row, int col,int& target)
{
	while (true)
	{
		char temp_x, temp_y;
		cout << "������ĸ+������ʽ[����c2]����������꣺";
		for (int i = 0; i < 20; i++)
			cout << ' ';
		for (int i = 0; i < 20; i++)
			cout << '\b';//��ֹ������ַ���������Ҫ����

		temp_x = _getche();
		temp_y = _getche();
		
		if (temp_x >= 'a'&&temp_x < 'a' + row)
			temp_x += ('A' - 'a');//������ΪСд��ת���ɴ�д
		x = temp_x - 'A' + 1;
		y = temp_y - '0' + 1;
		while (true)
		{
			if (getchar() == '\n')
				break;
		}
		if ((temp_x >= 'A'&&temp_x < 'A' + row) && (temp_y >= '0'&&temp_y < '0' + col)&&!judge(grid, row, col, x, y, grid[x][y]))
			cout << "����ľ�������λ�ô���������ֵͬ������������" << endl;
		else if ((temp_x >= 'A'&&temp_x < 'A' + row) && (temp_y >= '0'&&temp_y < '0' + col))
		{
			cout << "����Ϊ" << temp_x << "��" << temp_y << "��         " << endl;
			break;
		}
		else if ((temp_x > 'A'||temp_x >= 'A' + row) || (temp_y < '0'&&temp_y >= '0' + col))
		{
			cout << "�����������������";
			int xx, yy;
			cct_getxy(xx, yy);
			cct_gotoxy(0, yy - 1);
		}
	}
	target = grid[x][y];
	return;
}

void output_search(int search[][maxn], int row, int col)
{
	//���
	int cnt = 0;
	cout << endl << "���ҽ������:" << endl;
	cout << "  |";
	for (int i = 0; i < col; i++)
	{
		cout << setw(3) << i;//�����һ��	
	}
	cout << endl;
	cout << "--+";
	for (int i = 1; i <= col * 3 + 2; i++)
		cout << '-';//����ڶ���
	cout << endl;
	char ch = 'A';
	for (int i = 1; i <= row; i++)
	{
		cout << ch << " |";
		ch++;
		for (int j = 1; j <= col; j++)
		{
			if (search[i][j])
				cout << setw(3) << '*';
			else
				cout << setw(3) << '0';
		}
		cout << endl;
	}
	cout << endl;
}

void search_result(int grid[][maxn], int search[][maxn], int row, int col, int x, int y)
{
	search_clear(search, row, col);
	int target = grid[x][y];
	search[x][y] = 1;
	bool flag = 0;
	while (true)
	{
		flag = false;
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (search[i][j] == 1)
				{
					if (grid[i - 1][j] == target && search[i - 1][j] != 1)
					{
						search[i - 1][j] = 1;
						flag = true;
					}
					if (grid[i][j - 1] == target && search[i][j - 1] != 1)
					{
						search[i][j - 1] = 1;
						flag = true;
					}
					if (grid[i][j + 1] == target && search[i][j + 1] != 1)
					{
						search[i][j + 1] = 1;
						flag = true;
					}
					if (grid[i + 1][j] == target && search[i + 1][j] != 1)
					{
						search[i + 1][j] = 1;
						flag = true;
					}
				}
			}
		}
		if (!flag)
			break;
	}
	
}

void search_recursive(int grid[][maxn], int search[][maxn], int row, int col, int x, int y,const int target)
{
	int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
	int ix, iy;
	if (x == 0 || y == 0 || x == row+1 || y == col+1||search[x][y]||grid[x][y]!=target)
		return;
	search[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		ix = x + dir[i][0];
		iy = y + dir[i][1];
		search_recursive(grid, search, row, col, ix, iy,target);
	}
	return;
}

bool judge(int grid[][maxn], int row, int col, int x, int y, int target)
{
	bool res = false;

	if (grid[x - 1][y] == target)
		res = true;
	if (grid[x][y - 1] == target)
		res = true;
	if (grid[x + 1][y] == target)
		res = true;
	if (grid[x][y + 1] == target)
		res = true;

	return res;
}

void output_highlight(int grid[][maxn], int search[][maxn], int row, int col)
{
	//���
	int cnt = 0;
	cout << endl << "��ǰ���飨��ͬɫ��ʶ��:" << endl;
	cout << "  |";
	for (int i = 0; i < col; i++)
	{
		cout << setw(3) << i;//�����һ��	
	}
	cout << endl;
	cout << "--+";
	for (int i = 1; i <= col * 3 + 2; i++)
		cout << '-';//����ڶ���
	cout << endl;
	char ch = 'A';
	for (int i = 1; i <= row; i++)
	{
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cout << ch << " |";
		ch++;
		for (int j = 1; j <= col; j++)
		{
			if (search[i][j])
				cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
			else
				cct_setcolor(COLOR_BLACK, COLOR_WHITE);
			cout << setw(3) << grid[i][j];

		}
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cout << endl;
	}
	cout << endl;
}

int merge_confirm(int x,int y)
{
	char temp_x = x + 'A' - 1;
	char temp_y = y + '0' - 1;
	char choice;
	cout << "��ȷ���Ƿ�����ڵ���ֵͬ�ϲ���" << temp_x << temp_y << "��(Y/N/Q)��";
	while (true)
	{
		choice = _getche();
		if (choice == 'y' || choice == 'n' || choice == 'q')
			choice += 'A' - 'a';
		if (choice == 'Y')
			return merge_yes;
		else if (choice == 'N')
			return merge_no;
		else if (choice == 'Q')
			return merge_quit;
	}
	return -1;
}

void merged(int grid[][maxn],int search[][maxn], const int x, const int y,const int row,const int col, int& score,const int goal)
{
	int temp_score = 0;
	int temp_target = grid[x][y];
	int count = 1;
	grid[x][y]++;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (search[i][j] && (i != x || j != y))
			{
				grid[i][j] = 0;
				count++;
			}
		}
	}
	temp_score = temp_target * count * 3;
	score += temp_score;
	output_highlight(grid, search, row, col);
	cout << "���ε÷֣�" << temp_score << " �ܵ÷֣�" << score << " �ϳ�Ŀ�꣺" << goal << endl;
}

void fall_base(int grid[][maxn], int search[][maxn], const int x, const int y, const int row, const int col)
{
	cout << "���س����������������0����..." << endl;
	wait_for_enter();
	for (int j = 1; j <= col; j++)
	{
		for (int i = row; i >= 1; i--)
		{
			while (grid[i][j] && grid[i + 1][j] == 0 && (i != row))
			{
				grid[i + 1][j] = grid[i][j];
				grid[i][j] = 0;
				i++;
			}
		}
	}
	cout << endl << "��0������飨��ͬɫ��ʶ��:" << endl;
	output_fallen_highlight(grid, search, row, col);
}

void fill_base(int grid[][maxn], int search[][maxn], const int row, const int col)
{
	cout << "���س���������ֵ���...";
	wait_for_enter();
	//search_clear(search, row, col);
	int count = 0;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (!grid[i][j])
			{
			//	search[i][j] = 1;
				count++;//����0�ĸ������ó��������ֵ�ֵ
			}
		}
	}

	int temp_result[maxn][maxn] = { 0 };
	int max_num = calculate_max(grid, row, col);
	num_generate(temp_result, row, col, max_num);
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (!grid[i][j])
			{
				grid[i][j] = temp_result[rand() % row + 1][rand() % col + 1];
			}
		}
	}
	output_highlight(grid, search, row, col);
}

void output_fallen_highlight(int grid[][maxn], int search[][maxn], int row, int col)
{
	//���
	int cnt = 0;	
	cout << "  |";
	for (int i = 0; i < col; i++)
	{
		cout << setw(3) << i;//�����һ��	
	}
	cout << endl;
	cout << "--+";
	for (int i = 1; i <= col * 3 + 2; i++)
		cout << '-';//����ڶ���
	cout << endl;
	char ch = 'A';
	search_clear(search,row,col);
	for (int i = 1; i <= row; i++)
	{
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cout << ch << " |";
		ch++;
		for (int j = 1; j <= col; j++)
		{
			if (!grid[i][j])
			{
				search[i][j] = 1;
				cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
			}
			else
				cct_setcolor(COLOR_BLACK, COLOR_WHITE);
			cout << setw(3) << grid[i][j];

		}
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cout << endl;
	}
	cout << endl;
}

void new_round()
{
	cout << "���κϳɽ��������س���������һ�εĺϳ�..." << endl;
	wait_for_enter();
}

int check_goal(int grid[][maxn], const int row, const int col, int goal,bool& mark)
{
	int temp=0;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (grid[i][j] > temp)
			{
				mark = true;
				temp = grid[i][j];
			}
		}
	}
	if (temp==goal&&mark)
	{
		cout << endl << "�Ѻϳɵ�" << goal << endl;
		cout << "���س������������Ŀ�����..." << endl;
		wait_for_enter();
		return 1;
	}
	return 0;
}

bool check_game_continue(int grid[][maxn], int row, int col)
{
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (judge(grid, row, col, i, j, grid[i][j]) == true)
				return true;
		}
	}
	return false;
}