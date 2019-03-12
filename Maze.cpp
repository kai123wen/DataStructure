//用栈来求解迷宫问题
#include<iostream>
#include<malloc.h>
#define row 5
#define column 5
#define MaxSize 20
using namespace std;

//用于表示每个方格的结构体
typedef struct {
	 int i;//当前方块的行号
	 int j;//当前方块的列号
	 int di;//下一可走相邻方位的方位号
} Box;

// 定义栈
typedef struct{
	Box data[MaxSize];
	int top;//栈顶指针
} Stack;

bool findPath(int inX,int inY,int outX,int outY,int maze[][7]);



int main(){

	//存储迷宫的二维数组,1表示为有障碍不可通过,0表示无障碍可以通过
	int maze[row+2][column+2] = {1,1,1,1,1,1,1,
	                             1,0,0,0,1,0,1,
                				 1,0,1,0,0,0,1,
                 				 1,0,0,1,0,0,1,
                 				 1,0,1,0,1,0,1,
                    			 1,0,0,0,0,0,1,
                				 1,1,1,1,1,1,1};

	findPath(1,1,5,5,maze);
	return 0;
}
//findPath
bool findPath(int inX,int inY,int outX,int outY,int maze[][7]){
	Stack stack;
	int x,y,di;
	int find = 0;//定义找到的变量
	stack.top = -1;
	stack.top++;
	stack.data[stack.top].i = inX;
	stack.data[stack.top].j = inY;
	stack.data[stack.top].di = -1;
	maze[inX][inY] = -1; //避免重复，当一个方块进栈时，将迷宫值改为-1
	while(stack.top > -1){// 栈不为空

	    //取出栈顶元素
		x = stack.data[stack.top].i;
		y = stack.data[stack.top].j;
		di = stack.data[stack.top].di;

		if(x == outX && y == outY){//到了终点
			cout<<"路径为"<<endl;
			while(stack.top != -1){
				cout<<stack.data[stack.top].i<<" "<<stack.data[stack.top].j<<endl;
				stack.top--;
			}
			return true;
		}
		find = 0;
		while(di<4 && find == 0)
            {//继续找下去
			di++;
			switch(di){
            case 0:
				x = stack.data[stack.top].i+1;y = stack.data[stack.top].j;
				break;
            case 1:
                x = stack.data[stack.top].i;y = stack.data[stack.top].j+1;
				break;
            case 2:
				x = stack.data[stack.top].i - 1;y = stack.data[stack.top].j;
				break;
            case 3:
				x=stack.data[stack.top].i;y = stack.data[stack.top].j-1;
				break;
			}
			if(maze[x][y]==0){
				find = 1;//找到下一步方块
			}
		}

		if(find == 1){
			stack.data[stack.top].di = di;
			stack.top++;
			stack.data[stack.top].i = x;
			stack.data[stack.top].j = y;
			cout<<stack.data[stack.top].i<<" "<<stack.data[stack.top].j<<"进栈"<<endl;
			stack.data[stack.top].di = -1;
			maze[x][y] = -1;//避免重复
		}else{//没有路径可走，则退栈
			maze[stack.data[stack.top].i][stack.data[stack.top].j] = 0;
			stack.top--;
		}

	}
	return false;
}

