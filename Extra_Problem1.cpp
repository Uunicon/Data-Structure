#include<iostream>
using namespace std;
struct Poly_Node {
	int pi;
	int ei;
	struct Poly_Node *next;
};

Poly_Node *CreateList_L(int n)
{
	Poly_Node *Head, *p, *L;
	Head = new Poly_Node;
	Head->next = NULL;
	L = Head;
	for (int i = 0; i < n; i++)
	{
		p = new Poly_Node;
		cin >> p->pi>>p->ei;
		p->next = NULL;
		L->next = p;
		L = p;
	}
	return Head;
}//CreateList

Poly_Node *Add_Poly(Poly_Node *a, Poly_Node *b)
{
	Poly_Node *h1 = a->next;   //第一个多项式
	Poly_Node *h2 = b->next;   //第二个多项式
	Poly_Node *Head3, *p,*L;
	Head3 = new Poly_Node;  //存放合并的结果
	Head3->next = NULL;
	L = Head3;
	while(h1&&h2)  //当两个链表都没有结束
	{
		if (h1->ei == h2->ei) //指数相同相加
		{
			p = new Poly_Node;
			p->ei = h1->ei;
			p->pi = h1->pi + h2->pi;
			L->next = p;
			p->next = NULL;
			L = p;
			h1 = h1->next; h2 = h2->next;
		}
		else if (h1->ei < h2->ei)
		{
			p = new Poly_Node;
			p->ei = h1->ei;
			p->pi = h1->pi;
			L->next = p;
			p->next = NULL;
			L = p;
			h1 = h1->next; 
		}
		else
		{
			p = new Poly_Node;
			p->ei = h2->ei;
			p->pi = h2->pi;
			L->next = p;
			p->next = NULL;
			L = p;
			h2 = h2->next;
		}
	}
	if (h2)
		L->next = h2;
	else
		L->next = h1;
	return Head3;
}

void Print_Poly(Poly_Node *head)
{
	while (head)
	{
		if(head->pi!=0)
		{
			cout << head->pi << " " << head->ei << endl;
		}

		head = head->next;
	}
}

int main()
{
	Poly_Node *Head1, *Head2, *Head3;
	int n1, n2;
	cin >> n1;
	Head1 = CreateList_L(n1);
	cin >> n2;
	Head2 = CreateList_L(n2);
	Head3 = Add_Poly(Head1, Head2);
	Print_Poly(Head3->next);
	return 0;
}