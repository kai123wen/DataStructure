
/*
	树的基本操作
	查找
	插入/删除
	遍历
*/
#include<iostream>
#define MaxSize 100
#define MaxSon 3;
typedef int ElementType;
using namespace std;

// 树的双亲存储结构
typedef struct {
	ElementType data;
	int parent;
} PTree[MaxSize];

//树的孩子链存储结构
typedef struct node{
	ElementType data;
	struct node * sons[MaxSon];
} STree;
//树的孩子兄弟节点存储结构
typedef struct nodeOne{
	ElementType data;
	struct nodeOne * pBrother;
	struct nodeOne * pSon;
}
int main(){
	
}