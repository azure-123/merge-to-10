#pragma once
//宏定义
#define maxn 12
#define merge_yes 0
#define merge_no 1
#define merge_quit 2
#define choose_cancelled 0
#define choose_confirmed 1

//数组方式和伪图形方式共用函数
void wait_for_enter();//等待回车
int home_menu();//开始界面的菜单
void size_selection(int &row, int &col);//决定界面的行数和列数
int goal_selection();//决定界面的行数和列数
void num_generate(int grid[][maxn], int row, int col, int max_num);//产生数组
int calculate_max(int grid[][maxn], const int row, const int col);//求出最大的数值
void wait_for_end(const int row);//等待结束指令

//数组方式独有函数
void output_base(int grid[][maxn], int row, int col);//输出内部数组
void choose_coordinate(int grid[][maxn],int &x, int &y, int row, int col,int& target);//输入需要展开的坐标以及其输入的错误处理
void search_result(int grid[][maxn],int search[][maxn], int row, int col, int x, int y);//非递归方法求连续区域
void search_recursive(int grid[][maxn], int search[][maxn], int row, int col, int x, int y,const int target);//递归方法求连续区域
bool judge(int grid[][maxn], int row, int col, int x, int y, int target);//判断周围是否有相同数字
void search_clear(int search[][maxn], int row, int col);//清空标记数组
void output_highlight(int grid[][maxn], int search[][maxn], int row, int col);//输出有不同色高亮的数组
void output_fallen_highlight(int grid[][maxn], int search[][maxn], int row, int col);//输出有不同色高亮的数组
void output_search(int search[][maxn], int row, int col);//输出只有0和*的标记数组
int merge_confirm(int x,int y);//确认是否合并
void merged(int grid[][maxn], int search[][maxn], const int x, const int y, const int row, const int col, int& score,int goal);
void fall_base(int grid[][maxn], int search[][maxn], const int x, const int y, const int row, const int col);
void fill_base(int grid[][maxn], int search[][maxn],const int row, const int col);
void new_round();
int check_goal(int grid[][maxn], const int row, const int col, int goal,bool& mark);
bool check_game_continue(int grid[][maxn], int row, int col);
void wait_for_end();
//伪图形界面独有函数
void print_border_non_internal(int grid[][maxn], const int row, const int col);
void print_border_internal(int grid[][maxn], const int row, const int col);
void print_block_non_internal(int grid[][maxn], int i, int j);
void print_block_internal(int grid[][maxn], int i, int j);
void print_block_chosen(int grid[][maxn], int i, int j);
void print_block_confirmed(int grid[][maxn], int i, int j);
void print_block_blank(int grid[][maxn], int i, int j);
void print_block_fall(int grid[][maxn], int i, int j);
int move_by_arrow(int grid[][maxn], int &x, int &y, const int row, const int col);
void print_whole(int grid[][maxn], const int row, const int col);
void arrow_whole(int grid[][maxn], int search[][maxn], const int row, const int col, int &x, int&y); 
int confirm_choose(int grid[][maxn], int search[][maxn], const int row, const int col, int &x, int &y);
void fall_whole(int grid[][maxn], const int row, const int col);
void adjust_grid(int grid[][maxn], int search[][maxn], const int row, const int col, const int x, const int y);
void fill_block(int grid[][maxn], const int row, const int col);
