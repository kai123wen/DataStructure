//stack
#include<iostream>
#include<malloc.h>
typedef char Elementtype;
#define MaxLength  10
using namespace std;

typedef struct SQlist{
	Elementtype data[MaxLength];
	int top;
} Stack;

bool isSymmetry(Elementtype str[]);//judge the str is symmetry
int main(){
	Elementtype str[7] = {'a','b','c','c','b','a'};
	if(isSymmetry(str)){
		cout<<"is symmetry";
	}else{
		cout<<"is not symmetry";
	}
}
//init stack
void initStack(Stack *&stack){
	stack = (Stack*)malloc(sizeof(Stack));
	stack->top = -1;
}
//destroy stack
void destroy(Stack *&stack){
	free(stack);
}
//judge the stack is empty
bool stackIsEmpty(Stack *stack){
	return (stack->top == -1);
}
//push stack
bool Push(Stack *stack,Elementtype e){
	if(stack->top == MaxLength - 1){
		return false;
	}
	stack->top++;
	stack->data[stack->top] = e;
	return true;
}
//Pop stack
bool Pop(Stack *stack,Elementtype &e){
	if(stack->top == -1){
		return false;
	}
	e = stack->data[stack->top];
	stack->top--;
	return true;
}
//get the top element of the stack
bool getTop(Stack *stack,Elementtype &e){
	if(stack->top == -1){
		return false;
	}
	e = stack->data[stack->top];
	return true;
}
//judge the str is the symmetry str
bool isSymmetry(Elementtype str[]){
	Elementtype e;
	Stack *stack;
	initStack(stack);
	for(int i=0;str[i] !='\0';i++){
		Push(stack,str[i]);
	}
	for(int i=0;str[i] != '\0';i++){
		Pop(stack,e);
		if(str[i] != e){
			destroy(stack);
			return false;
		}
	}
	return true;
}
