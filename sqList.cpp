#include <iostream>
#include<malloc.h>
typedef int ElementType;
using namespace std;
//����˳���
typedef struct SqList
{
    ElementType *element;
    int length;
} List;
void initList(List *&L);//��ʼ����
void destroyList(List *&L);//���ٱ�
bool isEmpty(List *L);//�п�
void printList(List *L);//��ӡ
bool insertList(List *L,int position, ElementType element); //Ԫ�ز���
bool getElement(List *L,int position, ElementType &element);
bool deleteElements(List *L,ElementType element);
bool cutList(List *L);
void getTheFlag(List *list);
int main()
{
    List *L;
    initList(L);
    insertList(L,1,0);
    insertList(L,2,1);
    insertList(L,3,2);
    insertList(L,4,1);
    insertList(L,5,2);
    insertList(L,6,0);
    insertList(L,7,1);
    getTheFlag(L);
    printList(L);
}

void initList(List *&L)
{
    L = (List*)malloc(sizeof(List));
    L->element = (ElementType*)malloc(sizeof(ElementType));
    L->length = 0;
    cout<<"init success"<<endl;
}
void destroyList(List *&L)
{
    free(L);
}
bool isEmpty(List *L)
{
    return (L->length == 0);
}
void printList(List *L)
{
    if(isEmpty(L))
    {
        return;
    }
    for(int i =0 ; i < L->length; i++)
    {
        cout<<L->element[i]<<endl;
    }
}

//��ĳ��λ�õ�Ԫ��
bool getElement(List *L,int position, ElementType &element)
{
    if(position < 1 || position >L->length)
    {
        return false;
    }
    element = L->element[position-1];
    return true;
}
//Ԫ�ز���
bool insertList(List *L,int position, ElementType element)
{
    if(position<1 || position > L->length+1)
    {
        return false;
    }
    for(int i = L->length-1; i > position-1; i++)
    {
        L->element[i+1] = L->element[i];
    }
    L->element[position-1] = element;
    L->length++;
    return true;
}

bool deleteElements(List *L,ElementType element)
{
    int k = 0;
    if(isEmpty(L))
    {
        return false;
    }
    for(int i = 0; i<L->length-1; i++)
    {
        if(L->element[i] == element)
        {
        }
        else
        {
            L->element[k] = L->element[i];
            k++;
        }
    }
    L->length = k;
    return true;
}

//�Ի�׼�ָ�
bool cutList(List *L)
{
    ElementType element = L->element[0];//��һ��Ԫ��
    int low = 0,high = L->length-1;
    while(low != high)
    {
        while(low != high)
        {
            if(L->element[high] <element)
            {
                L->element[low] = L->element[high];
                break;
            }
            high--;
        }
        while(low != high){
            if(L->element[low] > element){
                L->element[high] = L->element[low];
                break;
            }
            low++;
        }
    }
    L->element[low] = element;
    return true;
}

//�õ���������
void getTheFlag(List *list){
    int i=-1,j=0,k=list->length;
    ElementType temp;
    while(j<k){
        if(list->element[j] == 0){
        i++;
        temp = list->element[j];
        list->element[j] = list->element[i];
        list->element[i] = temp;
        j++;
        }
        else if(list->element[j] == 1){
            j++;
        }
        else {
            k--;
        temp = list->element[j];
        list->element[j] = list->element[k];
        list->element[k] = temp;
        }
    }
}



