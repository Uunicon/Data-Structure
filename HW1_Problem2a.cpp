#include <iostream>
using namespace std;

int n;  //nΪ�̶����Ա�Ԫ�ظ���
struct List
{
	int *Data;
	int last;
};
List *PtrL;

List *MakeEmpty(int n)
{
	PtrL = new List;
	PtrL->Data = new int[n];
	PtrL->last = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> PtrL->Data[i];
		PtrL->last++;
	}
	return PtrL;
}
//ɾ�����д���ֵ
void Delete(List *p)
{
	int k;
	int i=1;
	int *a = new int[p->last]; //a[n]��Ž�� 
	a[0] = p->Data[0];         //����һ��Ԫ�ط���a[0] 
	for (int j = 1; j < p->last; j++) //j=1 �ӵ�2��Ԫ�ؿ�ʼ�Ƚ� 
	{
		for (k = 0; k < i; k++)
		{
			if (p->Data[j] == a[k])break; //���Data[j]����ǰ��Ԫ����ȣ�������Data[j] 
		}
		if (k == i)  //���û���ҵ����Ԫ�� ��Data[j]����a[i]�� 
		{
			a[i] = p->Data[j];
			i++;
		}
	}
	for (int k = 0; k < i; k++)
		cout << a[k] << " ";
	cout << endl;
}


int main()
{
	List *MakeEmpty(int n);
	cin >> n;                //nΪ�̶����Ա�Ԫ�ظ���
	PtrL = MakeEmpty(n);

	//ɾ���ظ�Ԫ��
	Delete(PtrL);

	return 0;
}
