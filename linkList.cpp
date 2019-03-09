#include <iostream>
#include<malloc.h>
typedef int ElementType;
using namespace std;
typedef struct LinkList
{
    ElementType data;
    struct LinkList *next;
} List;
void creatLinkListFoot(List *&list,ElementType a[],int n);
void creatLinkListHead(List *&list,ElementType a[],int n);
void printList(List *list);
void deleteMaxnode(List *list);
void sortTheList(List *list);
void reverseList(List *list);
void reverseListPlus(List *list);
void makeOneToTwo(List *list);
void getTheFlag(List *list);
int main()
{
    List *list;
    int a[7] = {1,0,1,2,0,1,2};
    creatLinkListHead(list,a,7);

    //reverseListPlus(list);
    //printList(list);
    //makeOneToTwo(list);
    //cout<<"a 链表为"<<endl;
    //printList(list);
    getTheFlag(list);
    return 0;
}
//采用尾插法建立单链表,带头节点
void creatLinkListFoot(List *&list,ElementType a[],int n)
{
    List *s,*r;//r指向尾节点
    list = (List*)malloc(sizeof(List));
    r = list;
    for(int i=0; i<n; i++)
    {
        s = (List*)malloc(sizeof(List));
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = NULL;//将尾节点的next设置为null
}
//采用头插法创建单链表，带头节点
void creatLinkListHead(List *&list,ElementType a[],int n)
{
    list = (List*)malloc(sizeof(List));
    list->next = NULL;
    List *s;//存放节点
    for(int i=0; i<n; i++)
    {
        s = (List*)malloc(sizeof(List));
        s->data = a[i];
        s->next = list->next;
        list->next = s;
    }
}

//删除掉链表节点中值最大的节点
void deleteMaxnode(List *list)
{
    List *pre,*p;//pre指向p的前一个节点
    List *MaxPre,*MaxP;//MaxP 指向最大的节点
    pre = list;
    p = list->next;
    MaxP = p;
    MaxPre = pre;
    while(p!= NULL)
    {
        if(p->data>MaxP->data)
        {
            MaxP = p;
            MaxPre = pre;
        }
        pre = p;
        p = p->next;
    }
    MaxPre->next = MaxP->next;
    free(MaxP);
}
//打印全部
void printList(List *list)
{
    List *s = list->next;
    while(s != NULL)
    {
        cout<<s->data<<endl;
        s = s->next;
    }
}
//将单链表节点有序排列
void sortTheList(List *list)
{
    List *pre,*p;
    List *q;//作为p的后继节点
    //下面两步就是将一个链表截取成两段
    p = list->next->next;//让p指向第二个数据节点
    list->next->next = NULL;
    while(p != NULL)
    {
        pre = list;
        q = p->next;
        while(pre->next != NULL&&pre->next->data < p->data)
        {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = q;
    }
}

//将链表逆置
void reverseList(List *list)
{
    List *pre,*p,*q;//q为p的后继节点
    List *preOfq;
    pre = list;
    p = list->next;
    q = p;
    list->next = NULL;
    while(q->next != NULL)
    {
        while(q->next != NULL) //通过循环，使得p指针指向链表的端
        {
            preOfq = q;
            q = q->next;
        }
        pre->next = q;
        pre = pre->next;
        preOfq->next = NULL;
        q = p;
    }
    pre->next = p;
}
//将链表逆置
void reverseListPlus(List *list)
{
    List *p;
    List *temp;
    p = list->next;
    list->next = NULL;
    while(p != NULL)
    {
        temp = (List*)malloc(sizeof(List));
        temp->data = p->data;
        temp->next = list->next;
        list->next = temp;
        p = p->next;
    }
}
//将一个链表拆分成两个链表
//如 a1->b1->a2->b2 => a1->a2 b2->b1
void makeOneToTwo(List *list)
{
    List *listNew;//b的头节点
    listNew = (List*)malloc(sizeof(List));
    listNew->next = NULL;
    //对a采用尾插法
    //对b采用头插法
    List *p;
    List *r;//指向a的尾节点

    List *q;

    List *tempOne;//用于存放a链表的节点
    List *tempTwo;//用于存放b链表的节点

    p = list->next;
    q = p->next;
    list->next = NULL;
    r = list;
    while(p != NULL)
    {
        tempOne = (List*)malloc(sizeof(List));
        tempOne->data = p->data;
        r->next = tempOne;
        r = tempOne;

        tempTwo = (List*)malloc(sizeof(List));
        tempTwo->data = q->data;
        tempTwo->next = listNew->next;
        listNew->next =tempTwo;

        p = q->next;
        if(p == NULL)
        {
            break;
        }
        else
        {
            q = p->next;
        }

    }
    r->next = NULL;
    cout<<"b 链表"<<endl;
    printList(listNew);
}

//有关国旗排列问题
void getTheFlag(List *list)
{
    List *listOne = (List*)malloc(sizeof(List));
    listOne->next = NULL;
    List *listTwo = (List*)malloc(sizeof(List));
    listTwo->next = NULL;
    List *p;
    List *tempOfP;
    p = list->next;
    list->next = NULL;
    while(p != NULL)
    {
        tempOfP = p->next;
        if(p->data == 0)
        {
            p->next = list->next;
            list->next = p;
        }
        else if(p->data == 1)
        {
           p->next = listOne->next;
           listOne->next = p;
        }
        else
        {
          p->next = listTwo->next;
          listTwo->next = p;
        }
        p = tempOfP;
    }
    printList(list);
    printList(listOne);
    printList(listTwo);

}
