#include<iostream>
using namespace std;
struct LNode {
	int data;
	struct LNode *next;
};
//��������ͷ�巨�������� 
LNode *CreateList_L(int n)
{
	LNode *Head, *p, *L;
	Head = new LNode;
	Head->next = NULL;
	L = Head;
	for (int i = 0; i < n; i++)  //β�巨˳�������� 
	{
		p = new LNode;
		cin >> p->data;
		L->next = p; p->next = NULL;
		L = p;
	}
	return Head;
}//CreateList

 //ɾ������������ָ��Ԫ�� 
LNode *Delete(int X, LNode *head)
{
	LNode *p = head;
	LNode *s;
	int i = 0;
	while (p->next != NULL)   //��һ��Ԫ�طǿ� 
	{
		if (p->next->data != X) p = p->next;  //��һ��Ԫ��ֵ������Ŀ��ֵ 
		else            //p->next->data ==X ��һ��Ԫ��ֵ����Ŀ��ֵ 
		{
			s = p->next;  //���´�ɾ���Ľ�� 
			if(p->next->next!=NULL)
				p->next = p->next->next;
			else p->next = NULL; //���ýڵ�Ϊ���һ���ڵ㣬��next��Ϊ�� 
			delete s;
			i++;  //��¼�ظ�Ԫ�ص����� 
		}
	}
	if (i == 0)  //δ�ҵ����-1 
	{
		cout << "-1" << endl;
		return head;
	}
	else   //�ҵ��������Ԫ�� 
	{
		for (p = head->next; p; p = p->next)
			cout << p->data << " ";
		cout << endl;
		return head;
	}
}//Delete

int main()
{
	LNode *Head, *p;
	int n;
	cin >> n;
	Head = CreateList_L(n);
	int X;
	cin >> X;  //��������ҵ��� 
	Head = Delete(X,Head);
	return 0;
}
