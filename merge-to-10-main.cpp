#include<iostream>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include"90-b2.h"
#include"cmd_console_tools.h"
using namespace std;

int main()
{
	int row, col;
	int grid[maxn][maxn] = { 0 };
	int search[maxn][maxn] = { 0 };
	int choose_x, choose_y;
	while (true)
	{
		cct_cls();
		int order = home_menu();
		if (order == 0)
			return 0;
		int goal = 0;//合成目标
		int score = 0;
		int target = 0;//合成的中间变量
		cct_cls();
		srand(unsigned(time(NULL)));

		switch (order)
		{
		case 1:
		{
			size_selection(row, col);
			search_clear(search, row, col);
			search_clear(grid, row, col);
			num_generate(grid, row, col, 3);
			while (getchar() != '\n')
				;//清空缓存区
			output_base(grid, row, col);
			choose_coordinate(grid, choose_x, choose_y, row, col, target);
			search_result(grid, search, row, col, choose_x, choose_y);
			output_search(search, row, col);
			output_highlight(grid, search, row, col);
			cout << endl;
			wait_for_end();
			break;
		}
		case 2:
		{
			size_selection(row, col);
			search_clear(search, row, col);
			search_clear(grid, row, col);
			num_generate(grid, row, col, 3);
			output_base(grid, row, col);
			while (getchar() != '\n')
				;//清空缓存区
			choose_coordinate(grid, choose_x, choose_y, row, col, target);
			search_recursive(grid, search, row, col, choose_x, choose_y, target);
			output_search(search, row, col);
			output_highlight(grid, search, row, col);
			cout << endl;
			wait_for_end();
			break;
		}
		case 3:
		{
			size_selection(row, col);
			search_clear(search, row, col);
			search_clear(grid, row, col);
			num_generate(grid, row, col, 3);
			goal = goal_selection();
			while (getchar() != '\n')
				;//清空缓存区
			output_base(grid, row, col);
			choose_coordinate(grid, choose_x, choose_y, row, col, target);
			search_recursive(grid, search, row, col, choose_x, choose_y, target);
			output_search(search, row, col);
			output_highlight(grid, search, row, col);
			if (merge_confirm(choose_x, choose_y) == merge_yes)
			{
				merged(grid, search, choose_x, choose_y, row, col, score, goal);
				fall_base(grid, search, choose_x, choose_y, row, col);
				fill_base(grid, search, row, col);
			}
			cout << endl;
			wait_for_end();
			break;
		}
		case 4:
		{
			size_selection(row, col);
			search_clear(search, row, col);
			search_clear(grid, row, col);
			num_generate(grid, row, col, 3);
			goal = goal_selection();
			while (getchar() != '\n')
				;//清空缓存区
			while (true)
			{
				bool success = false;
				search_clear(search, row, col);
				output_base(grid, row, col);
				if (!check_game_continue(grid, row, col))
					cout << "无可合并的项，游戏结束！" << endl;
				choose_coordinate(grid, choose_x, choose_y, row, col, target);
				search_recursive(grid, search, row, col, choose_x, choose_y, target);
				output_search(search, row, col);
				output_highlight(grid, search, row, col);
				if (merge_confirm(choose_x, choose_y) == merge_yes)
				{
					merged(grid, search, choose_x, choose_y, row, col, score, goal);
					fall_base(grid, search, choose_x, choose_y, row, col);
					fill_base(grid, search, row, col);
				}
				else if (merge_confirm(choose_x, choose_y) == merge_no)
				{
					search_clear(search, row, col);
					continue;
				}
				else if (merge_confirm(choose_x, choose_y) == merge_quit)
				{
					search_clear(search, row, col);
					break;
				}
				else
					;
				if (!check_goal(grid, row, col, goal, success))
					new_round();
				else
				{
					goal++;
					success = false;
				}
			}
			cout << endl;
			wait_for_end();
			break;
		}
		case 5:
		{
			size_selection(row, col);
			search_clear(search, row, col);
			search_clear(grid, row, col);
			num_generate(grid, row, col, 3);
			cct_cls();
			print_border_non_internal(grid, row, col);
			for (int i = 1; i <= row; i++)
			{
				for (int j = 1; j <= col; j++)
					print_block_non_internal(grid, i, j);
			}
			wait_for_end(row);
			break;
		}
		case 6:
		{
			size_selection(row, col);
			search_clear(search, row, col);
			search_clear(grid, row, col);
			num_generate(grid, row, col, 3);
			cct_cls();
			print_border_internal(grid, row, col);
			for (int i = 1; i <= row; i++)
			{
				for (int j = 1; j <= col; j++)
					print_block_internal(grid, i, j);
			}
			wait_for_end(row);
			break;
		}
		case 7:
		{
			cct_setcursor(CURSOR_INVISIBLE);
			int x = 1, y = 1;
			size_selection(row, col);
			search_clear(search, row, col);
			search_clear(grid, row, col);
			num_generate(grid, row, col, 3);
			cct_cls();
			print_border_internal(grid, row, col);
			print_whole(grid, row, col);
			print_block_chosen(grid, 1, 1);
			cct_gotoxy(0, 4 * row + 2);
			cout << "箭头键移动，回车键选择并结束";
			arrow_whole(grid, search, row, col, x, y);
			wait_for_end(row);
			break;
		}
		case 8:
		{
			cct_setcursor(CURSOR_INVISIBLE);
			int x = 1, y = 1;

			size_selection(row, col);
			search_clear(search, row, col);
			search_clear(grid, row, col);
			num_generate(grid, row, col, 3);
			goal = goal_selection();
			cct_cls();

			print_border_internal(grid, row, col);
			print_whole(grid, row, col);
			print_block_chosen(grid, 1, 1);
			cct_gotoxy(0, 4 * row + 2);
			cout << "箭头键移动，回车键选择                    " << endl;
			int count = 0;
			int temp_score = 0;
			while (true)
			{

				count = 0;
				temp_score = 0;
				arrow_whole(grid, search, row, col, x, y);
				cct_gotoxy(0, 4 * row + 2);
				cout << "箭头键移动并取消当前选择，回车键合成" << endl;
				if (judge(grid, row, col, x, y, grid[x][y]) == false)
				{
					cct_gotoxy(0, 4 * row + 2);
					cout << "周围无相同值，箭头键移动，回车键选择    " << endl;
					continue;
				}
				search_recursive(grid, search, row, col, x, y, grid[x][y]);
				print_block_confirmed(grid, x, y);
				for (int i = 1; i <= row; i++)
				{
					for (int j = 1; j <= col; j++)
					{
						if (search[i][j] && (x != i || y != j))
						{
							count++;
							print_block_chosen(grid, i, j);
						}
					}
				}
				if (choose_confirmed == confirm_choose(grid, search, row, col, x, y))
					break;
			}

			temp_score = (count + 1) * grid[x][y] * 3;
			score += temp_score;
			cct_gotoxy(0, 0);
			cout << "本次得分：" << temp_score << " 总得分：" << score << " 合成目标：" << goal << endl;

			choose_x = x;
			choose_y = y;
			grid[choose_x][choose_y]++;
			for (int i = 1; i <= row; i++)
			{
				for (int j = 1; j <= col; j++)
					if (search[i][j])
						print_block_blank(grid, i, j);
			}
			for (int i = 0; i < 5; i++)
			{
				Sleep(100);
				print_block_chosen(grid, choose_x, choose_y);
				Sleep(100);
				print_block_internal(grid, choose_x, choose_y);
			}
			cct_gotoxy(0, 4 * row + 2);
			cout << "合成完成，回车键下落0                           " << endl;
			wait_for_enter();
			adjust_grid(grid, search, row, col, choose_x, choose_y);
			fall_whole(grid, row, col);
			cct_gotoxy(0, 4 * row + 2);
			cout << "下落0完成，回车键填充新值" << endl;
			wait_for_enter();
			fill_block(grid, row, col);
			for (int i = 1; i <= row; i++)
			{
				for (int j = 1; j <= col; j++)
					print_block_internal(grid, i, j);
			}
			cct_gotoxy(0, 4 * row + 2);
			cout << "本次合成结束，按C继续新一次的合成" << endl;
			while (true)
			{
				if (_getch() == 'c' || _getch() == 'C')
					break;
			}
			wait_for_end(row);
			break;
		}
		case 9:
		{

			cct_setcursor(CURSOR_INVISIBLE);
			int x = 1, y = 1;

			size_selection(row, col);
			search_clear(search, row, col);
			search_clear(grid, row, col);
			num_generate(grid, row, col, 3);
			goal = goal_selection();
			cct_cls();

			print_border_internal(grid, row, col);
			print_whole(grid, row, col);
			while (true)
			{
				print_block_chosen(grid, 1, 1);
				cct_gotoxy(0, 4 * row + 2);
				cout << "箭头键移动，回车键选择                    " << endl;
				int count = 0;
				int temp_score = 0;
				while (true)
				{

					count = 0;
					temp_score = 0;
					arrow_whole(grid, search, row, col, x, y);
					cct_gotoxy(0, 4 * row + 2);
					cout << "箭头键移动并取消当前选择，回车键合成" << endl;
					if (judge(grid, row, col, x, y, grid[x][y]) == false)
					{
						cct_gotoxy(0, 4 * row + 2);
						cout << "周围无相同值，箭头键移动，回车键选择    " << endl;
						continue;
					}
					search_recursive(grid, search, row, col, x, y, grid[x][y]);
					print_block_confirmed(grid, x, y);
					for (int i = 1; i <= row; i++)
					{
						for (int j = 1; j <= col; j++)
						{
							if (search[i][j] && (x != i || y != j))
							{
								count++;
								print_block_chosen(grid, i, j);
							}
						}
					}
					if (choose_confirmed == confirm_choose(grid, search, row, col, x, y))
						break;
				}

				temp_score = (count + 1) * grid[x][y] * 3;
				score += temp_score;
				cct_gotoxy(0, 0);
				cout << "本次得分：" << temp_score << " 总得分：" << score << " 合成目标：" << goal << endl;
				cct_gotoxy(0, 4 * row + 2);
				cout << "                                                        " << endl;
				choose_x = x;
				choose_y = y;
				grid[choose_x][choose_y]++;
				for (int i = 1; i <= row; i++)
				{
					for (int j = 1; j <= col; j++)
						if (search[i][j])
							print_block_blank(grid, i, j);
				}
				for (int i = 0; i < 5; i++)
				{
					Sleep(100);
					print_block_chosen(grid, choose_x, choose_y);
					Sleep(100);
					print_block_internal(grid, choose_x, choose_y);
				}
				adjust_grid(grid, search, row, col, choose_x, choose_y);
				fall_whole(grid, row, col);

				fill_block(grid, row, col);
				print_whole(grid, row, col);
				if (!check_game_continue(grid, row, col))
				{
					cct_gotoxy(0, 4 * row + 3);
					cout << "无可合并的项，游戏结束！按Q退出";
					while (true)
					{
						if (_getch() == 'q' || _getch() == 'Q')
							break;
					}
					wait_for_end(row);
					break;
				}
				if (calculate_max(grid, row, col) == goal)
				{
					cct_gotoxy(0, 4 * row + 2);
					cout << "已合成到" << goal << "，按回车键继续向更高目标进发";
					goal++;
					wait_for_enter();
					cct_gotoxy(0, 0);
					cout << "本次得分：" << temp_score << " 总得分：" << score << " 合成目标：" << goal << endl;
				}
				x = y = 1;
				search_clear(search, row, col);
			}
			break;
		}
		default:
			break;
		}
	}
	return 0;
}