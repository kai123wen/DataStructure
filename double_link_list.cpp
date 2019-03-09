#include <iostream>
#include<malloc.h>
typedef int ElementType;
using namespace std;

typedef struct DoubleLinkList
{
    ElementType data;
    struct DoubleLinkList *prior;
    struct DoubleLinkList *next;
} List;
void creatDoubleListHead(List *&list,ElementType a[],int n);//创建
void creatDoubleListEnd(List *&list,ElementType a[],int n);

int main()
{
    List *list;
    ElementType a[5] = {1,3,2,6,5};
    creatDoubleListEnd(list,a,5);
    cout<<list->next->data;
    return 0;
}

//头插法建立双链表
void creatDoubleListHead(List *&list,ElementType a[],int n){
    List *s;
    list = (List*)malloc(sizeof(List));
    list->next = list->prior = NULL;
    for(int i=0;i<n;i++){
        s = (List*)malloc(sizeof(List));
        s->data = a[i];
        s->next = list->next;
        if(list->next != NULL){
            list->next->prior = s;
        }
        s->prior = list;
        list->next = s;
    }
}
//尾插法建立双链表

void creatDoubleListEnd(List *&list,ElementType a[],int n){
    List *r; //指向尾节点
    List *s;// 存放数据的节点
    list = (List*)malloc(sizeof(List));
    list->next = list->prior = NULL;
    r = list;
    for(int i=0;i<n;i++){
        s = (List*)malloc(sizeof(List));
d        s->next = r->next;
        r->next = s;
        s->prior = r;
        r = s;
    }
    //r->next = NULL;
}
