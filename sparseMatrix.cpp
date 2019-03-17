/* 当在一个矩阵中非零元素的个数远小于零元素的个数
 * 采用普通的存储方式就会造成空间的浪费
 * 稀疏矩阵元素的分布无规律
 * 用3元组(1,2,4)存储
 */
#include<iostream>
#include<malloc.h>
typedef int ElementType;
#define MaxSize 100
#define M 3
#define N 3
using namespace std;

typedef struct {

	int i;
	int j;
	ElementType data;
} TupNode;

typedef struct {

	int rows;//矩阵行数
	int cols;//列数
	int nums;//非零元素个数
	TupNode data[MaxSize];
} TupMatrix;//三元组顺序表
 void initTup(TupMatrix *&t);
 void CreatTupMatrix(TupMatrix &t,ElementType a[M][N]);
int main(){


	ElementType a[3][3] = {1,0,0,0,0,2,3,0,4};
	
	TupMatrix *t;
	initTup(t);
	CreatTupMatrix(*t,a);
	cout<<t->data[2].data<<endl;
	return 0;
}
//初始化三元组表
void initTup(TupMatrix *&t){
	t = (TupMatrix*)malloc(sizeof(TupMatrix));
	t->rows = -1;
	t->cols = -1;
	t->nums = 0;
}


//创建三元组表
void CreatTupMatrix(TupMatrix &t,ElementType a[M][N]){
	t.rows = M;
	t.cols = N;
	int k = 0;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if (a[i][j] != 0){
				t.data[k].data = a[i][j];
				t.data[k].i = i;
				t.data[k].j = j;
				k++;
			}
	 	}
	}
}
