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
	cout << endl << "内部数组:" << endl;
	cout << "  |";
	for (int i = 0; i < col; i++)
	{
		cout << setw(3) << i;//输出第一行	
	}
	cout << endl;
	cout << "--+";
	for (int i = 1; i <= col * 3 + 2; i++)
		cout << '-';//输出第二行
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
	//getchar();//接收前面输入时遗留的回车
}

void choose_coordinate(int grid[][maxn],int &x, int &y, int row, int col,int& target)
{
	while (true)
	{
		char temp_x, temp_y;
		cout << "请以字母+数字形式[例：c2]输入矩阵坐标：";
		for (int i = 0; i < 20; i++)
			cout << ' ';
		for (int i = 0; i < 20; i++)
			cout << '\b';//防止输入的字符串过长需要覆盖

		temp_x = _getche();
		temp_y = _getche();
		
		if (temp_x >= 'a'&&temp_x < 'a' + row)
			temp_x += ('A' - 'a');//若输入为小写，转换成大写
		x = temp_x - 'A' + 1;
		y = temp_y - '0' + 1;
		while (true)
		{
			if (getchar() == '\n')
				break;
		}
		if ((temp_x >= 'A'&&temp_x < 'A' + row) && (temp_y >= '0'&&temp_y < '0' + col)&&!judge(grid, row, col, x, y, grid[x][y]))
			cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
		else if ((temp_x >= 'A'&&temp_x < 'A' + row) && (temp_y >= '0'&&temp_y < '0' + col))
		{
			cout << "输入为" << temp_x << "行" << temp_y << "列         " << endl;
			break;
		}
		else if ((temp_x > 'A'||temp_x >= 'A' + row) || (temp_y < '0'&&temp_y >= '0' + col))
		{
			cout << "输入错误，请重新输入";
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
	//输出
	int cnt = 0;
	cout << endl << "查找结果数组:" << endl;
	cout << "  |";
	for (int i = 0; i < col; i++)
	{
		cout << setw(3) << i;//输出第一行	
	}
	cout << endl;
	cout << "--+";
	for (int i = 1; i <= col * 3 + 2; i++)
		cout << '-';//输出第二行
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
	//输出
	int cnt = 0;
	cout << endl << "当前数组（不同色标识）:" << endl;
	cout << "  |";
	for (int i = 0; i < col; i++)
	{
		cout << setw(3) << i;//输出第一行	
	}
	cout << endl;
	cout << "--+";
	for (int i = 1; i <= col * 3 + 2; i++)
		cout << '-';//输出第二行
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
	cout << "请确认是否把相邻的相同值合并到" << temp_x << temp_y << "中(Y/N/Q)：";
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
	cout << "本次得分：" << temp_score << " 总得分：" << score << " 合成目标：" << goal << endl;
}

void fall_base(int grid[][maxn], int search[][maxn], const int x, const int y, const int row, const int col)
{
	cout << "按回车键进行数组下落除0操作..." << endl;
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
	cout << endl << "除0后的数组（不同色标识）:" << endl;
	output_fallen_highlight(grid, search, row, col);
}

void fill_base(int grid[][maxn], int search[][maxn], const int row, const int col)
{
	cout << "按回车键进行新值填充...";
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
				count++;//计算0的个数，得出生成数字的值
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
	//输出
	int cnt = 0;	
	cout << "  |";
	for (int i = 0; i < col; i++)
	{
		cout << setw(3) << i;//输出第一行	
	}
	cout << endl;
	cout << "--+";
	for (int i = 1; i <= col * 3 + 2; i++)
		cout << '-';//输出第二行
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
	cout << "本次合成结束，按回车键继续新一次的合成..." << endl;
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
		cout << endl << "已合成到" << goal << endl;
		cout << "按回车键继续向更高目标进发..." << endl;
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