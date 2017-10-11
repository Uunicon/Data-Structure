#include <iostream>
using namespace std;

int n;  //nΪ�̶����Ա�Ԫ�ظ���
struct List
{
	int *Data;
	int last;         
};
List *PtrL;
//�����ձ�
List *MakeEmpty(int n)
{
	PtrL = new List;
	PtrL->Data = new int[n];
	PtrL->last = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> PtrL->Data[i];
		PtrL->last++;
	} 	//�����ǰ���Ա�
	for (int i = 0; i < PtrL->last; i++)
		cout << PtrL->Data[i] <<" ";
	cout<<endl; 
	return PtrL;
}
//����һ����
void Insert(int X, int i, List *p)
{

	int j;
	if (p->last == n - 1)
	{
		cout << "-1" << endl; return;
	}
	if (i<1 || i>p->last + 2)
	{
		cout << "-1" << endl; return;
	}
	for (j = p->last; j >= i - 1; j--) //jΪ�б��� iΪ������������λ��
		p->Data[j + 1] = p->Data[j];   //���ƶ��������ֵ
	p->Data[i - 1] = X;
	p->last++;
	for (int i = 0; i < p->last; i++)
		cout << p->Data[i]<<" ";
	cout << endl;
	return;
}

//ɾ����Ŷ�Ӧ����ֵ
void Delete(int i, List *p)
{
	if (i < 0 || i > p->last)
	{
		cout << "-1" << endl;
		return;
	}
	else
	{
		for (int j = i; j <= p->last; j++)
		{
			p->Data[j - 1] = p->Data[j];
		}
	}
	p->last--;
	for (int t = 0; t < p->last; t++)
		cout << p->Data[t]<<" ";
	cout << endl;
}

//����һ�������ҵ��򷵻ر��i��δ�ҵ��򷵻�-1
int Find(int X, List *p)
{
	int i = 0;
	while (i <= p->last && p->Data[i] != X) //��iС��last��δ�ҵ�X��i++
		i++;
	if (i > p->last)return -1;
	else return i + 1;
}

int main()
{
	List *MakeEmpty(int n);
	cin >> n;                //nΪ�̶����Ա�Ԫ�ظ���
	PtrL = MakeEmpty(n);
	

	//����һ����
	int X,i;     //XΪĿ������iΪ�±�
	cin >> i >> X;
	Insert(X, i, PtrL);
	//ɾ��һ����
	int t2;
	cin >> t2;
	Delete(t2, PtrL);
	//����һ����
	int t1;
	cin >> t1;
	cout<< Find(t1, PtrL);
	return 0;
}
