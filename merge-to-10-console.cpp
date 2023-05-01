#include<iostream>
#include<conio.h>
#include<iomanip>
#include<time.h>
#include<Windows.h>
#include"cmd_console_tools.h"
#include "90-b2.h"
using namespace std;
void print_border_internal(int grid[][maxn], const int row, const int col)
{
	cct_setconsoleborder(8 * col + 3, 4 * row + 6);//���ô��ڴ�С
	cout << "��ǰ��Ļ����Ϊ��" << 4 * row + 6 << "��" << 8 * col + 3 << "��";
	cout << endl;
	//cout << "  ";
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	cout << "�X";
	for (int i = 1; i < col; i++)
		cout << "�T�T�T�j";
	cout << "�T�T�T�[";
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	cout << endl;
	//cout << "  ";
	for (int j = 1; j <= col; j++)
	{
		cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
		cout << "�U";
		cout << "      ";
	}
	cout << "�U";
	for (int i = 1; i <= row; i++)
	{
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cout << endl;
		for (int j = 1; j <= col; j++)
		{
			cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
			cout << "�U";
			cout << "      ";
		}
		cout << "�U";
		cout << endl;
		for (int j = 1; j <= col; j++)
		{
			cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
			cout << "�U";
			cout << "      ";
		}
		cout << "�U";
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cout << endl;
		cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
		if (i == row)
			cout << "�^";
		else
			cout << "�d";
		for (int j = 1; j < col; j++)
		{
			if (i == row)
				cout << "�T�T�T�m";
			else
				cout << "�T�T�T�p";
		}
		if (i == row)
			cout << "�T�T�T�a";
		else
			cout << "�T�T�T�g";
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cout << endl;// << "  ";
		if (i != row)
		{
			for (int j = 1; j <= col; j++)
			{
				cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
				cout << "�U";
				cout << "      ";
			}

			cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
			cout << "�U";
			cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		}
	}
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}


void print_border_non_internal(int grid[][maxn], const int row, const int col)
{
	cout << endl;
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	cout << "�X";
	for (int i = 1; i <= col; i++)
		cout << "�T�T�T";
	cout << "�[" << endl;

	for (int i = 1; i <= row; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
			cout << "�U";
			for (int j = 1; j <= col; j++)
			{
				cct_setcolor(COLOR_BLACK, COLOR_WHITE);
				cout << "      ";
			}
			cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
			cout << "�U";
			cout << endl;
		}
	}
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	cout << "�^";
	for (int i = 1; i <= col; i++)
		cout << "�T�T�T";
	cout << "�a" << endl;
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);

}

void print_block_non_internal(int grid[][maxn], int i, int j)
{
	cct_gotoxy(6 * j - 4, 3 * i - 1);
	cct_setcolor(grid[i][j] + 6, COLOR_BLACK);
	cout << "�X�T�[";
	cct_gotoxy(6 * j - 4, 3 * i);
	cout << "�U" << static_cast<char>(grid[i][j] % 10 + '0') << " �U";
	cct_gotoxy(6 * j - 4, 3 * i + 1);
	cout << "�^�T�a";
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}

void print_block_internal(int grid[][maxn], int i, int j)
{
	cct_gotoxy(6 * j - 4 + 2 * (j - 1), 3 * i - 1 + (i - 1));
	cct_setcolor(grid[i][j] + 6, COLOR_BLACK);
	cout << "�X�T�[";
	cct_gotoxy(6 * j - 4 + 2 * (j - 1), 3 * i + (i - 1));
	cout << "�U" << static_cast<char>(grid[i][j] % 10 + '0') << " �U";
	cct_gotoxy(6 * j - 4 + 2 * (j - 1), 3 * i + 1 + (i - 1));
	cout << "�^�T�a";
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}

void print_block_chosen(int grid[][maxn], int i, int j)
{
	cct_gotoxy(6 * j - 4 + 2 * (j - 1), 3 * i - 1 + (i - 1));
	cct_setcolor(COLOR_HYELLOW, COLOR_BLUE);
	cout << "�X�T�[";
	cct_gotoxy(6 * j - 4 + 2 * (j - 1), 3 * i + (i - 1));
	cout << "�U" << static_cast<char>(grid[i][j] % 10 + '0') << " �U";
	cct_gotoxy(6 * j - 4 + 2 * (j - 1), 3 * i + 1 + (i - 1));
	cout << "�^�T�a";
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}

void print_block_confirmed(int grid[][maxn], int i, int j)
{
	cct_gotoxy(6 * j - 4 + 2 * (j - 1), 3 * i - 1 + (i - 1));
	cct_setcolor(COLOR_HYELLOW, COLOR_RED);
	cout << "�X�T�[";
	cct_gotoxy(6 * j - 4 + 2 * (j - 1), 3 * i + (i - 1));
	cout << "�U" << static_cast<char>(grid[i][j] % 10 + '0') << " �U";
	cct_gotoxy(6 * j - 4 + 2 * (j - 1), 3 * i + 1 + (i - 1));
	cout << "�^�T�a";
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}

void print_block_blank(int grid[][maxn], int i, int j)
{
	cct_gotoxy(6 * j - 4 + 2 * (j - 1), 3 * i - 1 + (i - 1));
	cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
	cout << "�X�T�[";
	cct_gotoxy(6 * j - 4 + 2 * (j - 1), 3 * i + (i - 1));
	cout << "�U" << static_cast<char>(grid[i][j] % 10 + '0') << " �U";
	cct_gotoxy(6 * j - 4 + 2 * (j - 1), 3 * i + 1 + (i - 1));
	cout << "�^�T�a";
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}

void print_block_fall(int grid[][maxn], int i, int j)
{
	for (int cnt = 0; cnt < 4; cnt++)
	{
		Sleep(100);
		cct_gotoxy(6 * j - 4 + 2 * (j - 1), 3 * i - 1 + (i - 1)+cnt);
		
		if(cnt==3)
			cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
		else
		cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
		cout << "�T�T�T";
		cct_gotoxy(6 * j - 4 + 2 * (j - 1), 3 * i + (i - 1) + cnt);
		cct_setcolor(grid[i][j] + 6, COLOR_BLACK);
		cout << "�X�T�[";
		cct_gotoxy(6 * j - 4 + 2 * (j - 1), 3 * i + i + cnt);
		cout << "�U" << static_cast<char>(grid[i][j] % 10 + '0') << " �U";
		cct_gotoxy(6 * j - 4 + 2 * (j - 1), 3 * i + 1 + i + cnt);
		cout << "�^�T�a";
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	}
}



int move_by_arrow(int grid[][maxn], int &x, int &y, const int row, const int col)
{
	int key1, key2;//ʹ���������Ҽ���Ҫ����������λ����һ����λΪ224
	while (1)
	{
		key1 = _getch();
		cct_gotoxy(0, 4 * row + 2);
		cout << "��ͷ���ƶ����س���ѡ��                    " << endl;
		if (key1 == '\r')
			return 0;
		else if (key1 == 224)
		{
			key2 = _getch();
			break;
		}
	}//��ʼ�Ĵ����������������ַ�������ȴ�����
		if (key1 == 224)
		{
			if (key2 == 77)//��
			{
				if (y == col)
				{
					print_block_internal(grid, x, y);
					y = 1;
					//cct_gotoxy(x, y);
					print_block_chosen(grid, x, y);
				}
				else if (y < col)
				{
					//cct_gotoxy(++x, y);
					print_block_internal(grid, x, y);
					print_block_chosen(grid, x, ++y);
				}

			}
			else if (key2 == 80)
			{

				if (x == row)//��
				{
					print_block_internal(grid, x, y);
					x = 1;
					//cct_gotoxy(x, y);
					print_block_chosen(grid, x, y);
				}
				else if (x < row)
				{
					//cct_gotoxy(x, ++y);
					print_block_internal(grid, x, y);
					print_block_chosen(grid, ++x, y);
				}

			}
			else if (key2 == 75)
			{
				if (y == 1)//��
				{
					print_block_internal(grid, x, y);
					y = col;
					//cct_gotoxy(x, y);
					print_block_chosen(grid, x, y);
				}
				else if (y > 1)
				{
					//cct_gotoxy(--x, y);
					print_block_internal(grid, x, y);
					print_block_chosen(grid, x, --y);
				}

			}
			else if (key2 == 72)
			{
				//cct_gotoxy( x, --y);

				if (x == 1)//��
				{
					print_block_internal(grid, x, y);
					x = row;
					//cct_gotoxy(x, y);
					print_block_chosen(grid, x, y);
				}
				else if (x > 1)
				{
					//cct_gotoxy(x, --y);
					print_block_internal(grid, x, y);
					print_block_chosen(grid, --x, y);
				}

			}
		}

	return 1;
}

void print_whole(int grid[][maxn], const int row, const int col)
{
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
			print_block_internal(grid, i, j);
	}
}

void arrow_whole(int grid[][maxn],int search[][maxn], const int row, const int col,int &x,int&y)
{
	while (true)
	{

		if(!move_by_arrow(grid, x, y, row, col))
			break;
		cct_gotoxy(0, 4 * row + 3);
	}
	
}

int confirm_choose(int grid[][maxn],int search[][maxn], const int row, const int col, int &x, int &y)
{
	int key1 = _getch();
	int key2;
	if (key1 == 224)
	{
		key2 = _getch();
		if (key2 == 77)//��
		{
			if (y == col)
			{
				print_block_internal(grid, x, y);
				y = 1;
				//cct_gotoxy(x, y);
				print_block_chosen(grid, x, y);
			}
			else if (y < col)
			{
				//cct_gotoxy(++x, y);
				print_block_internal(grid, x, y);
				print_block_chosen(grid, x, ++y);
			}

		}
		else if (key2 == 80)
		{

			if (x == row)//��
			{
				print_block_internal(grid, x, y);
				x = 1;
				//cct_gotoxy(x, y);
				print_block_chosen(grid, x, y);
			}
			else if (x < row)
			{
				//cct_gotoxy(x, ++y);
				print_block_internal(grid, x, y);
				print_block_chosen(grid, ++x, y);
			}

		}
		else if (key2 == 75)
		{
			if (y == 1)//��
			{
				print_block_internal(grid, x, y);
				y = col;
				//cct_gotoxy(x, y);
				print_block_chosen(grid, x, y);
			}
			else if (y > 1)
			{
				//cct_gotoxy(--x, y);
				print_block_internal(grid, x, y);
				print_block_chosen(grid, x, --y);
			}

		}
		else if (key2 == 72)
		{
			//cct_gotoxy( x, --y);

			if (x == 1)//��
			{
				print_block_internal(grid, x, y);
				x = row;
				//cct_gotoxy(x, y);
				print_block_chosen(grid, x, y);
			}
			else if (x > 1)
			{
				//cct_gotoxy(x, --y);
				print_block_internal(grid, x, y);
				print_block_chosen(grid, --x, y);
			}
		}
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (search[i][j])
				{
					print_block_internal(grid, i, j);
					search[i][j] = 0;
				}
			}
		}
		return choose_cancelled;
	}
	else if (key1 == '\r')
		return choose_confirmed;
	return choose_cancelled;
}

void fall_whole(int grid[][maxn], const int row, const int col)
{
	for (int j =1;j<=col;j++ )
	{
		for (int i = row; i >=1; i--)
		{
			while (grid[i][j]&&grid[i + 1][j] == 0&&(i!=row))
			{
				grid[i + 1][j] = grid[i][j];
				print_block_fall(grid, i, j);
				grid[i][j] = 0;
				i++;
			}
			
		}
	}
}

void adjust_grid(int grid[][maxn], int search[][maxn], const int row, const int col, const int x, const int y)
{
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (search[i][j] && (i != x || j != y))
				grid[i][j] = 0;
		}
	}
}

void fill_block(int grid[][maxn], const int row, const int col)
{
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
	return;
}