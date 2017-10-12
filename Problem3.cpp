#include <iostream>
using namespace std;
#define MAX 20000
int n;  //nΪ�̶����Ա�Ԫ�ظ���
struct List
{
	int *Data;
	int last;
};

//�����ձ� (������ֵ����С����)
bool MakeEmpty(int n,List *p)
{
	p->Data = new int[n];
	p->last = 0;
	int *t = new int[n];  //��ʱ�������
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
		if (t[i] == 0)break; //����0ֹͣ����
		p->last++;
	}
	int i, j, temp;
	for (i = 0; i<p->last - 1; i++) //��ʱ��������
		for (j = 0; j < p->last - 1 - i; j++)
		{
			if (t[j + 1] < t[j])
			{
				temp = t[j + 1]; t[j + 1] = t[j]; t[j] = temp;
			}
		}

	for (int i = 0; i < p->last; i++)//���ź��������������Ա���
	{
		p->Data[i] = t[i];
	}
	return true;
}
//�����ձ� ����������ֵ��
bool Initial(int n, List*p)
{
	p->Data = new int[n];
	p->last = 0;
	return true;
}


//����һ����
void Insert(int X, int i, List *p)
{
	int j;
	for (j = p->last; j >= i - 1; j--) //jΪ�б��� iΪ������������λ��
		p->Data[j + 1] = p->Data[j];   //���ƶ��������ֵ
	p->Data[i - 1] = X;
	p->last++;
}

//����ϲ��������Ա�
void MergeList(List La, List Lb, List Lc)
{
	int *pa = La.Data;
	int *pb = Lb.Data;
	int *pc = Lc.Data;
	int *t=Lc.Data;
	int *pa_last = La.Data + La.last- 1;
	int *pb_last = Lb.Data + Lb.last- 1;
	while (pa <= pa_last&&pb <= pb_last)
	{
		if (*pa <= *pb)*pc++ = *pa++;
		else *pc++ = *pb++;
	}
	while (pa <= pa_last)*pc++ = *pa++;
	while (pb <= pb_last)*pc++ = *pb++;
	for (int i = 0;t<pc; i++,t++)
	{
		cout << Lc.Data[i] << " ";
	}
}

int main()
{
	List La, Lb, Lc;
	MakeEmpty(MAX,&La);
	MakeEmpty(MAX,&Lb);
	Initial(MAX,&Lc);
	MergeList(La, Lb, Lc);
	return 0;
}

