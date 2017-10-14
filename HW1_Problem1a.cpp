#include <iostream>
using namespace std;

int n;  //n为固定线性表元素个数
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
//删除所有此数值
void Delete(int t, List *p)
{
	int i = 0,j = 0;
	int *a = new int[p->last];
	for (j = 0; j < p->last; j++)
	{
		if (p->Data[j] != t)
		{
			a[i] = p->Data[j];
			i++;
		}	
	}
	if (i == j)cout << "-1";
	else
	{
		for (j = 0; j < i; j++)cout << a[j] << " ";
	}
	cout << endl;
}


int main()
{
	List *MakeEmpty(int n);
	cin >> n;                //n为固定线性表元素个数
	PtrL = MakeEmpty(n);


	//删除所有t2
	int t2;
	cin >> t2;
	Delete(t2, PtrL);

	return 0;
}
