#include <iostream>
#include<vector>
using namespace std;

int main()
{
	int Maxsubseqdum1(int a[],int n);
	int k,sum;
	cin >> k;
	vector<int>a(k);
	for (int i = 0; i < k; i++)
		cin >> a[i];
	sum = Maxsubseqdum1(&a[0], k);
	cout << sum;
	return 0;
}
int Maxsubseqdum1(int a[], int n)
{
	int ThisSum, MaxSum ;
	int i, j, k;
	ThisSum = MaxSum = 0;
	for (i = 0; i < n; i++) {        //i���������λ��
		ThisSum+=a[i];               //�����ۼ�
		if (ThisSum > MaxSum)
			MaxSum = ThisSum;
		else if (ThisSum < 0)        //�����ǰ���к�Ϊ��
			ThisSum = 0;             //��������
	}//iѭ������
	return MaxSum;
}