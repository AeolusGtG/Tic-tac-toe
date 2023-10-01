#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


const int size = 3;//棋盘尺寸


int Input(int *inp)//自定义函数：用户输入防呆
{
	int inn = 0;
	do
	{
		scanf("%d", &inn);
		*inp = inn;
	} while (*inp < 0 or *inp > 2);
	return 0;
}
//Executable


int Turn(int* type, int turn)//自定义函数：判断回合落子类型
{
	if (turn % 2 != 0)
	{
		*type = 1;
		printf("请玩家1输入落位的横纵轴坐标\n");
	}
	else if (turn % 2 == 0)
	{
		*type = 2;
		printf("请玩家2输入落位的横纵轴坐标\n");
	}
	return 0;
}
//Executable


int Cheakmate(int board[][size], int* result, int* a, int* b, int* qian, int* hou)//自定义函数：判断胜利条件是否达成
{
	for (*a = 0; *a < size; *a = *a + 1)
	{
		int numx = 0, numo = 0;
		for (*b = 0; *b < size; *b = *b + 1)
		{
			if (board[*qian][*hou] == 1) { numx++; }
			else if (board[*qian][*hou] == 2) { numo++; }
		}
		if (numx == size)
		{
			*result = 1;
			printf("--------///玩家1获胜///--------\n");
			goto exit;
		}
		else if (numo == size)
		{
			*result = 2;
			printf("--------///玩家2获胜///--------\n");
			goto exit;
		}
	}
exit:
	return 0;
}
//Executable


int Render(int board[][size])//自定义函数：棋盘渲染
{
	for (int t = 0; t < size; t++)
	{
		for (int s = 0; s < size; s++)
		{
			printf(" (%d,%d)=%d ;", t + 1, s + 1, board[t][s]);
		}
		printf("\n");
	}
	return 0;
}
//Executable



int main()
{
	int mode = 0;//对战模式寄存
	int PVEplayermove = 0;//先后手寄存
	int board[size][size] = { 0 };//初始化空棋盘
	int x = -1, y = -1;//用户落位坐标寄存
	int turn = 1;//回合寄存
	int type;//棋子类型寄存
	int result = -1;//结果判断寄存：-1为初始值继续循环，0为结束程序，1为玩家1获胜，2为玩家2获胜
	int a = 0, b = 0;//行列遍历位置变化寄存


	printf("3X3井字棋：\n输入两个1~3的数据构成坐标,如：2 3\n输入0 0结束程序\n");


	printf("请选择模式：\n1.PVP\n2.PVE\n");//模式选择：PVP&PVE
	Input(&mode);


	if (mode == 2)//PVE玩家选择先后手
	{
		printf("请选择先后手：\n1.先手\n2.后手\n");
		Input(&PVEplayermove);
		if (PVEplayermove == 0)
		{
			goto quick_exit;
		}
	}
	else if (mode == 0)
	{
		goto quick_exit;
	}


	printf("初始化空棋盘\n");
	Render(board);//棋盘渲染


	do
	{
		Turn(&type, turn);//判断回合落子类型


		if (mode == 2 && type != PVEplayermove)//弱智AI回合：随机落子
		{
			srand(time(0));
			x = rand() % 3 + 1;
			y = rand() % 3 + 1;
		}//Executable
		else
		{
			scanf("%d %d", &x, &y);//读取落子坐标
		}


		int x_ = x - 1, y_ = y - 1;//将用户输入值处理为数组专用值


		//分流级联：防呆及中途退出
		if (x == 0 or y == 0)//中途中止程序
		{
			result = 0;
			printf("----------///结束程序///----------\n");
		}//Executable
		else if (x > size or y > size or x < 0 or y < 0)//排除棋盘外落子
		{
			printf("输入坐标超出棋盘范围，请重新输入1~%d区间的坐标\n", size);
			turn--;
		}//Executable
		else if (board[x_][y_] != 0)//排除重复落子
		{
			printf("落位已有棋子,类型为%d\n", board[x_][y_]);
			turn--;
		}//Executable
		else
		{
			board[x_][y_] = type;////棋子落位


			Render(board);//棋盘渲染


			Cheakmate(board, &result, &a, &b, &a, &b);//Executable
			Cheakmate(board, &result, &a, &b, &b, &a);//Executable
			Cheakmate(board, &result, &a, &b, &b, &b);//Executable
			if (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1)
			{
				result = 1;
				printf("\n--------///玩家1获胜///--------\n");
			}
			else if (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2)
			{
				result = 2;
				printf("\n--------///玩家2获胜///--------\n");
			}
		}


		turn++;//回合前进


		if (turn == 9 && result == -1)
		{
			result = 3;
			printf("\n-------///平局///-------\n");
		}
	} while (result == -1);
	quick_exit:
	return 0;
}
