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
    //cout<<"a ����Ϊ"<<endl;
    //printList(list);
    getTheFlag(list);
    return 0;
}
//����β�巨����������,��ͷ�ڵ�
void creatLinkListFoot(List *&list,ElementType a[],int n)
{
    List *s,*r;//rָ��β�ڵ�
    list = (List*)malloc(sizeof(List));
    r = list;
    for(int i=0; i<n; i++)
    {
        s = (List*)malloc(sizeof(List));
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = NULL;//��β�ڵ��next����Ϊnull
}
//����ͷ�巨������������ͷ�ڵ�
void creatLinkListHead(List *&list,ElementType a[],int n)
{
    list = (List*)malloc(sizeof(List));
    list->next = NULL;
    List *s;//��Žڵ�
    for(int i=0; i<n; i++)
    {
        s = (List*)malloc(sizeof(List));
        s->data = a[i];
        s->next = list->next;
        list->next = s;
    }
}

//ɾ��������ڵ���ֵ���Ľڵ�
void deleteMaxnode(List *list)
{
    List *pre,*p;//preָ��p��ǰһ���ڵ�
    List *MaxPre,*MaxP;//MaxP ָ�����Ľڵ�
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
//��ӡȫ��
void printList(List *list)
{
    List *s = list->next;
    while(s != NULL)
    {
        cout<<s->data<<endl;
        s = s->next;
    }
}
//��������ڵ���������
void sortTheList(List *list)
{
    List *pre,*p;
    List *q;//��Ϊp�ĺ�̽ڵ�
    //�����������ǽ�һ�������ȡ������
    p = list->next->next;//��pָ��ڶ������ݽڵ�
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

//����������
void reverseList(List *list)
{
    List *pre,*p,*q;//qΪp�ĺ�̽ڵ�
    List *preOfq;
    pre = list;
    p = list->next;
    q = p;
    list->next = NULL;
    while(q->next != NULL)
    {
        while(q->next != NULL) //ͨ��ѭ����ʹ��pָ��ָ������Ķ�
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
//����������
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
//��һ�������ֳ���������
//�� a1->b1->a2->b2 => a1->a2 b2->b1
void makeOneToTwo(List *list)
{
    List *listNew;//b��ͷ�ڵ�
    listNew = (List*)malloc(sizeof(List));
    listNew->next = NULL;
    //��a����β�巨
    //��b����ͷ�巨
    List *p;
    List *r;//ָ��a��β�ڵ�

    List *q;

    List *tempOne;//���ڴ��a����Ľڵ�
    List *tempTwo;//���ڴ��b����Ľڵ�

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
    cout<<"b ����"<<endl;
    printList(listNew);
}

//�йع�����������
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
