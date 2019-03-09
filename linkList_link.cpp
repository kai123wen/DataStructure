#include <iostream>
#include<malloc.h>
typedef int ElementType;
#define MaxCol 10 //set max column
using namespace std;

typedef struct LinkListNode{
	ElementType data[MaxCol];
	struct LinkListNode *next;
} List;
typedef struct HeadNode{
	int row;
	int column;
	struct LinkListNode *next;
} HeadNode;

int main(){
	
	return 0;
}

//interact to creat linklist
void creatLinkList(HeadNode *&head){
	int row,column;
	List *r;//point to tail node
	List *s;//the node to save the data
	head = (HeadNode*)malloc(sizeof(HeadNode));
	head->next = NULL;
	cout<<"please input the row: ";
	cin>>row;
	cout<<"please input the column: ";
	cin>>column;
	head->row = row;
	head->column = column;
	for(int i=0;i<row;i++){
		cout<<"the row is: "<<i<<endl;
		s = (List*)malloc(sizeof(List));
		for(int j=0;j<column;j++){
			cout<<"the column is: ";
			cin>>s->data[j];
		}
		if(head->next == NULL){
			head->next = s;
		}
		else{
			r->next = s;
		}
		r = s;
	}
	r->next = NULL;
}