#include<iostream>
using namespace std;

//��������
//˼�����������ⲿ�洢����
//ѭ�� ����nλ��
int main01()
{
	int len;
	int* start;
	int* end;

	cout<<"���������������"<<endl;
	cin >> len;

	start = (int*)malloc(len * sizeof(int)); //�����ڴ� 4 * len �Ĵ�С
	end = (int*)malloc(len * sizeof(int));

	cout<<"����������Ԫ�أ��Կո��������";
	for (int i = 0; i < len; i++)
		cin >> start[i];
		//start[i] = cin.get();
		//cin>>start[i];

	for (int current = 0; current < len; current++)
	{
		for (int k = 0; k < len - current; k++)
			end[current + k] = start[k];
		for (int t = len - current, j = 0; t < len; t++, j++)
			end[j] = start[t];
		cout<<"ѭ������%dλ��Ľ����", current;
		for (int m = 0; m < len; m++)
			printf("%d ", end[m]);
		cout << endl;
	}
	system("pause");
	return 0;
}
