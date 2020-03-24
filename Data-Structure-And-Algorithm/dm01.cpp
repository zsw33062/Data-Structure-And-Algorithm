#include<iostream>
using namespace std;

//数组右移
//思考：不借助外部存储变量
//循环 右移n位置
int main01()
{
	int len;
	int* start;
	int* end;

	cout<<"请输入数组个数："<<endl;
	cin >> len;

	start = (int*)malloc(len * sizeof(int)); //申请内存 4 * len 的大小
	end = (int*)malloc(len * sizeof(int));

	cout<<"请输入数组元素，以空格键隔开：";
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
		cout<<"循环右移%d位后的结果：", current;
		for (int m = 0; m < len; m++)
			printf("%d ", end[m]);
		cout << endl;
	}
	system("pause");
	return 0;
}
