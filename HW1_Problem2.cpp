#include <iostream>
using namespace std;
#define MAX 10000
int n;  //nΪ�̶����Ա�Ԫ�ظ���
struct List
{
	int *Data;
	int last;
};
List *PtrL;
//�����ձ� (��С����)
List *MakeEmpty(int n)
{
	PtrL = new List;
	PtrL->Data = new int[n];
	PtrL->last = 0;
	int *t = new int[n];  //��ʱ�������
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
		if (t[i] == 0)break; //����0ֹͣ����
		PtrL->last++;
	} 
	int i, j,temp;
	for(i=0;i<PtrL->last-1;i++) //��ʱ��������
		for (j = 0; j < PtrL->last - 1 - i; j++)
		{
			if (t[j + 1] < t[j])
			{
				temp = t[j + 1]; t[j + 1] = t[j]; t[j] = temp;
			}
		}

	for (int i = 0; i < PtrL->last; i++)//���ź��������������Ա���
	{
		PtrL->Data[i] = t[i];
	}
	return PtrL;
}
//����һ����
void OrderInsert(int X,List *p)
{
	int i = 0;
	while (i < p->last&&p->Data[i] < X)i++;
	for (int j = p->last - 1; j >= i; j--)
		p->Data[j + 1] = p->Data[j];
	p->Data[i] = X;
	cout << i+1<<endl; //������������ڵ�λ��
	p->last++;
}

//ɾ����Ŷ�Ӧ����ֵ
void OrderDelete(int X, List *p)
{
	int i = 0;
	while (i < p->last&&p->Data[i] != X)i++;
	if (i > p->last) { cout << "-1" << endl; return; }
	else
	{
		for (int j = i; j <p->last; j++)
			p->Data[j] = p->Data[j+1];
	}
	cout << i + 1 << endl; //���ɾ�������ڵ�λ��
	p->last--;
}


int main()
{
	List *MakeEmpty(int n);              
	PtrL = MakeEmpty(MAX);


	//����һ����
	int X;     //XΪĿ����
	cin >> X;
	OrderInsert(X, PtrL);
	//ɾ��һ����
	int t2;
	cin >> t2;
	OrderDelete(t2, PtrL);
	for (int i = 0; i < PtrL->last; i++)
	{
		cout << PtrL->Data[i] << " ";
	}
	return 0;
}
