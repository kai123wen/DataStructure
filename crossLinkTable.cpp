/*十字链表存储稀疏矩阵
 */

#include<iostream>
using namespace std;
typedef struct mtxn {
	int row;
	int col;
	struct mtxn *right,*down;//向右向下的指针
	union {//共用体
		int valuel;//数据节点的value
		struct mtxn *link;//头节点value
	}tag;
	
}MatNode;
int main(){

	return 0;
}


