#pragma once
//�궨��
#define maxn 12
#define merge_yes 0
#define merge_no 1
#define merge_quit 2
#define choose_cancelled 0
#define choose_confirmed 1

//���鷽ʽ��αͼ�η�ʽ���ú���
void wait_for_enter();//�ȴ��س�
int home_menu();//��ʼ����Ĳ˵�
void size_selection(int &row, int &col);//�������������������
int goal_selection();//�������������������
void num_generate(int grid[][maxn], int row, int col, int max_num);//��������
int calculate_max(int grid[][maxn], const int row, const int col);//���������ֵ
void wait_for_end(const int row);//�ȴ�����ָ��

//���鷽ʽ���к���
void output_base(int grid[][maxn], int row, int col);//����ڲ�����
void choose_coordinate(int grid[][maxn],int &x, int &y, int row, int col,int& target);//������Ҫչ���������Լ�������Ĵ�����
void search_result(int grid[][maxn],int search[][maxn], int row, int col, int x, int y);//�ǵݹ鷽������������
void search_recursive(int grid[][maxn], int search[][maxn], int row, int col, int x, int y,const int target);//�ݹ鷽������������
bool judge(int grid[][maxn], int row, int col, int x, int y, int target);//�ж���Χ�Ƿ�����ͬ����
void search_clear(int search[][maxn], int row, int col);//��ձ������
void output_highlight(int grid[][maxn], int search[][maxn], int row, int col);//����в�ͬɫ����������
void output_fallen_highlight(int grid[][maxn], int search[][maxn], int row, int col);//����в�ͬɫ����������
void output_search(int search[][maxn], int row, int col);//���ֻ��0��*�ı������
int merge_confirm(int x,int y);//ȷ���Ƿ�ϲ�
void merged(int grid[][maxn], int search[][maxn], const int x, const int y, const int row, const int col, int& score,int goal);
void fall_base(int grid[][maxn], int search[][maxn], const int x, const int y, const int row, const int col);
void fill_base(int grid[][maxn], int search[][maxn],const int row, const int col);
void new_round();
int check_goal(int grid[][maxn], const int row, const int col, int goal,bool& mark);
bool check_game_continue(int grid[][maxn], int row, int col);
void wait_for_end();
//αͼ�ν�����к���
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
