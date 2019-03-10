//链队
//数据结构包括：数据节点，链队节点（包含指向对头和队尾的指针）
#include<iostream>
#include<malloc.h>
typedef int ElementType;
using namespace std;

//链队节点
typedef struct LinkNode{
	struct DataNode *front;
	struct DataNode *rear;
} HeadNode;

//数据节点
typedef struct DataNode{
	ElementType data;
	struct DataNode *next;
} Node;
bool enterqueue(LinkNode *node,ElementType e);
bool leaveQueue(LinkNode *headNode,ElementType &e);
void initLinkQueue(HeadNode *&headNode);

int main(){

	LinkNode *node;
	initLinkQueue(node);
	for(int i=0;i<5;i++){
		enterqueue(node,i);
	}
	ElementType element;
	leaveQueue(node,element);
	leaveQueue(node,element);
	cout<<element<<"出队";
	return 0;
}
//初始化链队
void initLinkQueue(HeadNode *&headNode){
	headNode = (HeadNode*)malloc(sizeof(HeadNode));
	headNode->front = headNode->rear = NULL;
}

//销毁队列
void destroyLinkQueue(HeadNode *&headNode){
	Node *p = headNode->front;
	Node *r;
	if(p != NULL){//一般的销毁方式，利用两个指针。一个指向将要销毁的，另一个指向他的后面
		r = p->next;
		while(r != NULL){
			free(p);
			p = r;
			r = p->next;
		}
		free(p);
	}
	free(headNode);
}

//判断队空
bool queueIsEmpty(HeadNode *headNode){
	return (headNode->rear == NULL);
}

//出队操作
//这里要考虑 队列为空，队列由一个元素，其他
bool leaveQueue(LinkNode *headNode,ElementType &e){
	DataNode *p;
	if(headNode->rear == NULL){
		cout<<"队列为空"<<endl;
		return false;
	}

	if(headNode->front == headNode->rear != NULL){
		p = headNode->front;
		e = p->data;
		headNode->front = headNode->rear = NULL;
		return true;
	}

	p = headNode->front;
	e = p->data;
	headNode->front = p->next;
	return true;
}

//入队操作
bool enterqueue(LinkNode *node,ElementType e){
	DataNode *s;
	if(node->rear == NULL){//如果队列为空
		s = (DataNode*)malloc(sizeof(DataNode));
		s->data = e;
		node->front = s;
		node->rear = s;
		s->next = NULL;
		return true;
	}
	//如果队列不空
	s = (DataNode*)malloc(sizeof(DataNode));
	s->data = e;
	node->rear->next = s;
	node->rear = s;
	s->next = NULL;
	return true;
}