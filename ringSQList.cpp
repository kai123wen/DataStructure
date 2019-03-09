#include<iostream>
#include<malloc.h>
typedef int ElementType;
#define MaxSize 10
using namespace std;
typedef struct ringSQStack{
	ElementType data[MaxSize];
	int front;//指向队列头
	int end;//指向队列尾
} Stack;
void initStack(Stack *&stack);
bool Push(Stack *stack,ElementType e);
int main(){
	Stack *stack;
	initStack(stack);
	for(int i=0;i<5;i++){
		Push(stack,i);
	}
}

//初始化环形队列
void initStack(Stack *&stack){
	stack = (Stack*)malloc(sizeof(Stack));
	stack->front = stack->end = -1;
}

//将元素压入队列
bool Push(Stack *stack,ElementType e){
	if((stack->end+1)%MaxSize == stack->front){
		cout<<"队列已满";
		return false;
	}
	stack->end = (stack->end+1)%MaxSize;
	stack->data[stack->end] = e;
	return true;
}
//将元素弹出队列
bool Pop(Stack *&stack,ElementType &e){
	if(stack->front == stack->end){
		cout<<"队列为空";
		return false;
	}
	stack->front = (stack->front+1)%MaxSize;
	e = stack->data[stack->front];
	return false;
}
//销毁队列
bool destroyStack(Stack *&stack){
	free(stack);
}
