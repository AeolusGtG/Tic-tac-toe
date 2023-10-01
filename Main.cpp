#define#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


extern const int size = 3;//棋盘尺寸


int Input(int *inp)//自定义函数：用户输入防呆
{
	int inn = 0;
	do
	{
		scanf("%d", &inn);
		*inp = inn;
	} while (*inp < 1 or *inp > 2);
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
		对于 (*b = 0; *b < 大小; *b = *b + 1)
		{
			if (board[*qian][*hou] == 1) { numx++; }
			else if (board[*qian][*hou] == 2) { numo++; }
		}
		if (numx == 大小)
		{
			*结果=1；
			printf("--------///玩家1发生///--------\n");
			转到退出；
		}
		else if (numo == size)
		{
			*结果=2；
			printf("--------///玩家2发生///--------\n");
			转到退出；
		}
	}
出口：
	返回0；
}
//可执行文件


int Render(int board[][size])//自定义函数：棋盘渲染
{
	for (int t = 0; t < 大小; t++)
	{
		for (int s = 0; s < 大小; s++)
		{
			printf(" (%d,%d)=%d ;", t + 1, s + 1, board[t][s]);
		}
		printf("\n");
	}
	返回0；
}
//执行文件



int main()
{
	int mode = 0;//对战模式停止
	int Atk_Def = 0;//站立手站立
	int board[size][size] = { 0 };//初始化空棋盘
	int x = -1, y = -1;//用户落位坐标暂停
	intturn = 1;//循环休息
	int type;//棋子类型暂停
	int result = -1;//结果判定停止：-1为初始值继续循环，0为结束程序，1为玩家1事件，2为玩家2事件
	int a = 0, b = 0;//行列遍历位置变化停止


	printf("3X3井字棋：\n输入两个1~3的数据构成坐标,如：2 3\n输入0 0结束程序\n");	
	
	printf("请选择模式：\n1.PVP\n2.PVE\n");//模式选择：PVP&PVE
	做
	{
		输入模式）；
	while (模式 < 1 或模式 > 2);


	if (mode == 2)//PVE玩家选择着陆手
	{
		printf("请选择后手：\n1.先手\n2.后手\n");
		输入（&Atk_Def）；
	}


	printf("初始化空棋盘\n");
	Render(board);//棋盘渲染


	做
	{
		Turn(&type,turn);//填写表格落子类型


		if (mode == 2 && type != Atk_Def)//弱智AI轮询：随机落子
		{
			srand(时间(0));
			x = 兰特() % 3 + 1;
			y = 兰特() % 3 + 1;
		}//执行文件
		另外
		{
			scanf("%d %d", &x, &y);//读取落子坐标
		}


		int x_ = x - 1, y_ = y - 1;//将用户输入值处理为CPU专用值


		//分流级联：防呆及中途退出
		if (x == 0 or y == 0)//中途停止程序
		{
			结果=0；
			printf("----------///结束程序///----------\n");
		}//执行文件
		else if (x > size or y > size or x < 0 or y < 0)//排除棋盘外落子
		{
			printf("输入坐标超出棋盘范围，请重新输入1~%d区间的坐标\n", size);
			转动 - ;
		}//执行文件
		else if (board[x_][y_] != 0)//排除重复落子
		{
			printf("落位已有棋子,类型为%d\n", board[x_][y_]);
			转动 - ;
		}//执行文件
		另外
		{
			board[x_][y_] = type;////棋子落位


			Render(board);//棋盘渲染


			Cheakmate(board, &result, &a, &b, &a, &b);//执行文件
			Cheakmate(board, &result, &a, &b, &b, &a);//执行文件
			Cheakmate(board, &result, &a, &b, &b, &b);//执行文件
			if (板[0][2] == 1 && 板[1][1] == 1 && 板[2][0] == 1)
			{
				结果=1；
				printf("\n--------///玩家1触发///--------\n");
			}
			否则 if ( 板[0][2] == 2 && 板[1][1] == 2 && 板[2][0] == 2)
			{
				结果=2；
				printf("\n--------///玩家2触发///--------\n");
			}
		}


		turn++;//圆形前进


		if  (转 == 9 && 结果 == - 1 )
		{
			结果= 3；
			printf("\n--------///平局///--------\n");
		}
	while (结果==-1);
	返回0；
}
