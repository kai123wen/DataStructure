//get the path of maze by recursion
#include<iostream>
#include<malloc.h>
#define row 5
#define column 5
#define MaxSize 100
using namespace std;

//box of maze
typedef struct
{
    int i;//x
    int j;//y
} Box;

typedef struct
{
    Box data[MaxSize];
    int length;//
} Path;
void getPath(int inX,int inY,int outX,int outY,Path path);
    //the array is to store the maze,1 : has path 2 :no path
    int maze[row+2][column+2] = {1,1,1,1,1,1,1,
                                 1,0,0,0,1,0,1,
                                 1,0,1,0,0,0,1,
                                 1,1,0,1,0,0,1,
                                 1,0,1,0,1,0,1,
                                 1,0,0,0,0,0,1,
                                 1,1,1,1,1,1,1
                                };
int main()
{
	Path path;
	path.length = 0;
	getPath(1,1,5,5,path);
    return 0;
}
//findPath
void getPath(int inX,int inY,int outX,int outY,Path path){
	int di;//four direction
	int i;// x of current box
	int j;//y of current box
	if (inX == outX && inY == outY){
		path.data[path.length].i = inX;
		path.data[path.length].j = inY;
		path.length++;
	    cout<<"路径:"<<endl;
		for (int k =0;k<path.length;k++){
			cout<<path.data[k].i<<" -> "<<path.data[k].j<<endl;
		}
	}
	else{//inx iny is not exit
		if (maze[inX][inY] == 0){
			di = 0;
			while(di < 4){
				switch(di){
					case 0:
					i = inX+1;j = inY;
					break;
					case 1:
					i = inX;j = inY+1;
					break;
					case 2:
					i = inX -1;j = inY;
					case 3:
					i = inX;j = inY-1;
					break;
				}
					path.data[path.length].i = inX;
					path.data[path.length].j = inY;
					path.length++;
					maze[inX][inY] = -1;
					getPath(i,j,outX,outY,path);
					path.length--;
					maze[inX][inY] = 0;
					di++;
			}
		}
	}
}

