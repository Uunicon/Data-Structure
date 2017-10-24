#include<iostream>
using namespace std;
struct LNode {
	int data;
	struct LNode *next;
};
//建立链表，头插法，逆序建立 
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

//链表的逆置
LNode *ReverseList_L(LNode *head)
{
	LNode *H_t, *p, *L, *q;
	H_t = new LNode;
	H_t->next = NULL;
	L = H_t;
	for (q = head->next;q; q=q->next)
	{
		p = new LNode;
		p->data = q->data;
		if (H_t == L)
		{
			L->next = p; p->next = NULL;
			L = p;
		}
		else
		{
			p->next = L;
			H_t->next = p;
			L = p;
		}
	}
	return H_t;
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
	Head = ReverseList_L(Head);
	for (p = Head->next; p; p = p->next)
		if(p->data%3==0)cout << p->data << " ";
	cout << endl;
	return 0;
}