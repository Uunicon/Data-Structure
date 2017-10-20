#include<iostream>
using namespace std;
struct LNode {
	int data;
	struct LNode *next;
};
//建立链表
LNode *CreateList_L(int n)
{
	LNode *Head, *p, *L;
	Head = new LNode;
	Head->next = NULL;
	L = Head;
	for (int i = 0; i < n; i++)
	{
		p = new LNode;
		cin >> p->data;
		if (Head == L)
		{
			L->next = p; p->next = NULL;
			L = p;
		}
		else
		{
			p->next = L;
			Head->next = p;
			L = p;
		}
	}
	return Head;
}//CreateList

//查找结点
LNode *FindKth(int k, LNode *head)
{
	LNode *p = head;
	int i = 1;
	while (p != NULL&&i < k)
	{
		p = p->next;
		i++;
	}
	if (i == k)return p;
	else return NULL;
}//FindKth

//插入
LNode *Insert(int X, int i, LNode*h)
{
	LNode *p, *s;
	if (i == 1)
	{
		s = new LNode;
		s->data = X;
		s->next = h->next;
		h->next = s;
		for (p = h->next; p; p = p->next)
			cout << p->data << " ";
		return h;
	}
	p = FindKth(i - 1, h->next);
	if (p == NULL)
	{
		cout << "-1";
		return h;
	}
	else
	{
		s = new LNode;
		s->data = X;
		s->next = p->next;
		p->next = s;
		for (p = h->next; p; p = p->next)
			cout << p->data << " ";
		return h;
	}
}//Insert

//删除
LNode *Delete(int i, LNode *head)
{
	LNode *p,*q;
	p = head;
	int j = 0;
	while (p->next&&j<i-1)
	{
		p = p->next; ++j;
	}
	if(!(p->next)||j>i-1)
	{
		cout << "-1" ;
		return head;
	}
	q = p->next; p->next = q->next;
	delete q;
	for (p = head->next; p; p = p->next)
		cout << p->data << " ";
	return head;
}

//按值查找，返回下标
LNode *Find(int X, LNode *head)
{
	LNode *p = head;
	int i = 0;
	while (p->data != X)
	{
		p = p->next;
		i++;
		if (p == NULL)break;
	}
	if (p==NULL)
	{
		cout << "-1" << endl;
		return head;
	}
	else
	{
		cout <<i<< endl;
		return head;
	}
}//Find

//统计元素个数
int Count(LNode *head)
{
	int i = 0;
	LNode *p = head;
	for (; p; p = p->next)
		i++;
	return i-1;
}

int main()
{
	LNode *Head, *p;
	int n;
	cin >> n;
	Head = CreateList_L(n);
	for (p = Head->next; p; p = p->next)
		cout << p->data << " ";
	cout << endl;
	int i, X;
	cin >> i >> X;
	Head = Insert(X, i, Head);
	cout << endl;

	int d;
	cin >> d;
	Head = Delete(d, Head);
	cout << endl;

	int X1;
	cin >> X1;
	Head = Find(X1,Head);

	cout << Count(Head) << endl;
	return 0;
}