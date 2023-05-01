#define CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<conio.h>
#include<time.h>
#include"cmd_console_tools.h"
#include"90-b2.h"
using namespace std;

void wait_for_enter()
{
	while (true)
	{
		if (_getch() == '\r')
			break;
	}
}

void wait_for_end(const int row)
{
	while (true)
	{
		char buffer[100];
		cct_gotoxy(0, 4 * row + 2);
		cout << "本小题结束，请输入End继续...        \b\b\b\b\b\b\b\b";
		cin >> buffer;
		if (!_strcmpi(buffer, "END"))
			break;
	}
}

void wait_for_end()
{
	while (true)
	{
		char buffer[100];
		cout << "本小题结束，请输入End继续...";
		cin >> buffer;
		if (!_strcmpi(buffer, "END"))
			break;
	}
}

int home_menu()
{

	cct_cls();
	cout << "-------------------------------" << endl;
	cout << "1.命令行找出可合成项并标识（非递归）" << endl;
	cout << "2.命令行找出可合成项并标识（递归）" << endl;
	cout << "3.命令行完成一次合成" << endl;
	cout << "4.命令行完整版（分步骤显示）" << endl;
	cout << "5.伪图形界面显示初始数组（无分隔线）" << endl;
	cout << "6.伪图形界面显示初始数组（有分隔线）" << endl;
	cout << "7.伪图形界面下用箭头键选择当前色块" << endl;
	cout << "8.伪图形界面完成一次合成（分步骤）" << endl;
	cout << "9.伪图形界面完整版" << endl;
	cout << "0.退出游戏" << endl;
	cout << "-------------------------------" << endl;
	cout << "[请选择]：";
	char ch;
	int order;
	while (1)
	{
		ch = _getch();
		order = ch - '0';
		if (order == 1 || order == 2 || order == 3 ||
			order == 4 || order == 5 || order == 6 ||
			order == 7 || order == 8 || order == 9 || order == 0)
			break;//若遇到输入不正确的情况，继续进行循环
	}
	return order;//返回菜单值
}

void size_selection(int &row, int &col)
{
	while (1)
	{
		cout << "请输入行数(5-8)：    \b\b\b\b";
		cin >> row;
		if (row >= 5 && row <= 8)
			break;
		else
		{
			cout << "输入不合法，请重新输入";
			cct_gotoxy(0, 0);
		}
	}
	while (1)
	{
		cout << "请输入列数(5-10)：    \b\b\b\b";
		cin >> col;
		if (col >= 5 && col <= 10)
			break;
		else
		{
			cout << "输入不合法，请重新输入";
			cct_gotoxy(0, 1);
		}
	}
	return;
}

int goal_selection()
{
	int goal;
	while (1)
	{
		cout << "请输入合成目标(5-20)：     \b\b\b\b\b";
		cin >> goal;
		if (goal >= 5 && goal <= 20)
			break;
		else
		{
			cout << "输入不合法，请重新输入";
			cct_gotoxy(0, 2);
		}
	}
	return goal;
}

void num_generate(int grid[][maxn], int row, int col, int max_num)
{
	int generate[20] = { 0 };
	int size = row * col;//总共的格子数
	switch (max_num)
	{
		case 3:
		{
			generate[1] = int(size / 3);
			generate[2] = int(size / 3);
			generate[3] = size - generate[1] - generate[2];
			break;
		}
		case 4:
		{
			for (int i = 1; i <= 3; i++)
				generate[i] = int(size*0.3);
			generate[4] = size-generate[1] * 3;
			break;
		}
		case 5:
		{
			for (int i = 1; i <= 3; i++)
				generate[i] = int(size*0.2);
			generate[4] = int(size*0.15);
			generate[5] = size-generate[4]-generate[1]*3;
			break;
		}
		case 6:
		{
			for (int i = 1; i <= 4; i++)
				generate[i] = int(size*0.2);
			generate[5] = int(size*0.15);
			generate[6] = size - generate[1] * 4 - generate[5];
			break;
		}
		default:
		{
			for (int i = 1; i <= max_num-3; i++)
				generate[i] = int(size*0.8/(max_num-3));
			generate[max_num-2] = int(size*0.1);
			generate[max_num - 1] = int(size*0.05);
			generate[max_num] = size;
			for (int i = 1; i <= max_num - 1; i++)
				generate[max_num] -= generate[i];
			break;
		}
	}

	for (int i = 1; i <= max_num; i++)
	{
		for (int j = 1; j <= generate[i]; j++)
		{
			while (true)
			{
				int x = 0, y = 0;
				x = rand() % row+1;
				y = rand() % col+1;//随机生成坐标
				if(!grid[x][y])
				{
					grid[x][y] = i;
					break;//若原来的坐标上没有赋值，则给当前坐标赋值，否则继续生成新坐标
				}
			}
		}
	}
}

int calculate_max(int grid[][maxn], const int row, const int col)
{
	int max = 0;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (grid[i][j] > max)
				max = grid[i][j];
		}
	}
	return max;
}