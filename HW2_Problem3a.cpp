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
	for (int i = 0; i < n; i++)
	{
		p = new LNode;
		cin >> p->data;
		L->next = p; p->next = NULL;
		L = p;
	}
	return Head;
}//CreateList

 //ɾ���������ظ�Ԫ��
LNode *Delete(LNode *head)
{
	LNode *p = head;
	LNode *h1 = head;  //���ڱ���Ŀ�������ڵ�����Ԫ��
	LNode *s;        //ָ���ɾ���Ľڵ�
	p = p->next;    //����ͷ��㣬��ָ����ڵ�һ��Ԫ�ش�
	h1 = h1->next;
	int n=1;  //nΪ��ǰ������Ԫ������
	int j;
	while (p->next)
	{
		for (j = 0; j < n; j++) // ����һ��Ԫ���뵱ǰ����������Ԫ�ؽ��бȽ�
		{
			if (h1->data == p->next->data) //�����ɾȥ�ýڵ�
			{
				s = p->next;             //���´�ɾ���Ľ�� 
				if (p->next->next != NULL)
					p->next = p->next->next;
				else p->next = NULL;    //���ýڵ�Ϊ���һ���ڵ㣬��next��Ϊ�� 
				delete s;
				break;
			}
			h1 = h1->next; 
		}
		if (j == n)
		{
			p = p->next;
			n++;
		}
		h1 = head->next;       //ÿ�β��ҽ�����h1�ص���һ��Ԫ�ص�λ��
	}
	for (p = head->next; p; p = p->next)
		cout << p->data << " ";
	cout << endl;
	return head;
	
}//Delete

int main()
{
	LNode *Head, *p;
	int n;
	cin >> n; //��������Ԫ������
	Head = CreateList_L(n);
	Head = Delete(Head);
	return 0;
}