#include<iostream>
using namespace std;
#define MAX 10000
struct LNode {
	int data;
	struct LNode *next;
};
//建立链表
LNode *CreateList_L(int n)
{
	LNode *Head, *p, *L;
	int m=0;  //输入元素个数
	Head = new LNode;
	Head->next = NULL;
	L = Head;

	int *t = new int[n];  //临时存放数组
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
		if (t[i] == 0)break; //输入0停止输入
		m++;
	}
	int i, j, temp;
	for (i = 0; i<m - 1; i++) //临时数组排序
		for (j = 0; j < m - 1 - i; j++)
		{
			if (t[j + 1] < t[j])  //顺序建立链表，临时数组内数据从小到大 
			{
				temp = t[j + 1]; t[j + 1] = t[j]; t[j] = temp;
			}
		}

	for (int i = 0; i < m; i++)   //顺序插入
	{
		p = new LNode;
		p->data=t[i];
		L->next = p; p->next = NULL;
		L = p;
		
	}
	return Head;
}//CreateList

//建立空链表
LNode *CreateListEmpt_L()
{
	LNode *Head, *L;
	Head = new LNode;
	Head->next = NULL;
	L = Head;
	return Head;
}

//有序合并A、B两个表
LNode *MergeList_L(LNode *ha, LNode *hb, LNode *hc)
{
	LNode *a, *b, *c, *p;
	a = ha; b = hb; c = hc;
	while(a&&b)
	{
		if (a->data > b->data)
		{
			c->next = b; c = b; b = b->next;
		}
		else
		{
			c->next = a; c = a; a = a->next;
		}
	}
	if (b == NULL)
	{
		c->next = a;
	} 
	else 
	{
	    c->next = b;
	}
	return hc; 
}
int main()
{
	LNode *HeadA,*HeadB,*HeadC, *p;
	HeadA = CreateList_L(MAX);
	HeadB = CreateList_L(MAX);
	HeadC = CreateListEmpt_L();
	HeadC = MergeList_L(HeadA->next, HeadB->next, HeadC);
	for (p = HeadC->next; p; p = p->next)
		cout << p->data << " ";
	return 0;
}
