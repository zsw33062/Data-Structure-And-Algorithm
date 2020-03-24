/*******************************************************************
�ö���Ϊ��ʽ���У���������ʱ����ͷ�Ͷ�β��ָ��ͷ��㣬ͷ����в����
���ݣ�ֻ���ָ�룬ͷ������һ���ڵ�ſ�ʼ������ݣ�����������Ŀ����
Ϊ������Ӻͳ���ʱ����Զ��еĲ����������ÿ������������
*******************************************************************/
//Linux �ں�����  �������ֹ��췽ʽ
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct Node
{
	int data;
	struct Node* pNext;
}NODE, * PNODE;

typedef struct Queue
{
	PNODE front;  //��ͷָ��
	PNODE rear;   //��βָ��
}QUEUE, * PQUEUE;
//typedef �ض��� PQUEUE �൱�� QUEUE*
PQUEUE create_queue();
bool is_empty_Queue(PQUEUE);
void en_queue(PQUEUE, int);
bool de_queue(PQUEUE, int*);
void destroy_queue(PQUEUE);
void traverse_queue(PQUEUE);

int main()
{
	int data_de = 0;         //����������ӵ�Ԫ��ֵ

	//�������в�������Ӳ���
	PQUEUE pS = create_queue();
	en_queue(pS, 2);
	en_queue(pS, 4);
	en_queue(pS, 6);
	traverse_queue(pS);

	//���Ӳ���
	if (de_queue(pS, &data_de))
		cout << "delete succeed,the deleted data is: " << data_de << endl;
	else
		cout<<"queue is empty! delete falied!"<<endl;
	traverse_queue(pS);

	//���ٶ��в���
	destroy_queue(pS);
	cout<<"queue destroyed!"<<endl;
	//traverse_queue(pS);

	return 0;
}

/*
����һ���ն��У���ͷָ��Ͷ�βָ�붼ָ��ͷ��㣬
ͷ���pS
�в�������ݣ�ֻ���ָ��
*/
PQUEUE create_queue()
{
	PQUEUE pS = (PQUEUE)malloc(sizeof(Queue));
	//pS ��PQueue���͵�
	if (pS) //�ж�pS�Ƿ�Ϊ�� ����д ������־���
	{
		pS->front = (PNODE)malloc(sizeof(NODE));
	}

	if (!pS || !pS->front)
	{
		cout<<"pS or front malloc failed!!"<<endl;
		exit(-1);
	}
	else
	{
		pS->rear = pS->front;
		pS->front->pNext = NULL;
	}
	return pS;
}

/*
�ж϶����Ƿ�Ϊ��
*/
bool is_empty_Queue(PQUEUE pS)
{
	if (pS->front == pS->rear)
		return true;
	else
		return false;
}

/*
���Ӻ������Ӷ�β���ӣ���ͷָ�뱣�ֲ���
*/
void en_queue(PQUEUE pS, int e)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (!pNew)
	{
		cout<<"pNew malloc failed";
		exit(-1);
	}
	else
	{
		pNew->data = e;
		pNew->pNext = NULL;
		pS->rear->pNext = pNew;
		pS->rear = pNew;
	}
	return;
}

/*
���Ӻ������Ӷ�ͷ���ӣ���βָ�뱣�ֲ��䣬�������һ��Ԫ�س���ʱ��
��Ҫ�Զ�βָ�����¸�ֵ��ʹ��ָ��ͷ���
*/
bool de_queue(PQUEUE pS, int* pData)
{
	if (is_empty_Queue(pS))
		return false;
	else
	{
		PNODE p = pS->front->pNext;
		*pData = p->data;
		pS->front->pNext = p->pNext;

		//�����Ƕ���ͷԪ�س��ӵ����������һ������£�ɾ����ͷԪ��ʱ
		//�����޸�ͷ����е�ָ�룬�������������һ��Ԫ�ر�ɾ��ʱ��
		//����βָ��Ҳ��ʧ�ˣ������Զ�βָ�����¸�ֵ��ָ��ͷ��㣩��
		if (pS->rear == p)
			pS->rear = pS->front;
		free(p);
	}
	return true;
}

/*
�������У��Ӷ�ͷ���β����������е�Ԫ��
*/
void traverse_queue(PQUEUE pS)
{
	if (is_empty_Queue(pS))
		cout<<"there is no data in the queue!"<<endl;
	else
	{
		PNODE pCurrent = pS->front->pNext;
		cout << "Now datas int the queue are:" << endl;
		while (pCurrent)
		{
			cout << pCurrent->data<<" ";
			pCurrent = pCurrent->pNext;
		}
		printf("\n");
	}
	return;
}

/*
���ٶ���,ͷ���Ҳ������,���Ҳ��pS�ڵ����٣�������ָ��Ϊ�գ�����Ұָ��Ĳ���
*/
void destroy_queue(PQUEUE pS)
{
	if (is_empty_Queue(pS))
		return;
	else
	{
		while (pS->front)
		{
			pS->rear = pS->front->pNext;
			free(pS->front);
			pS->front = pS->rear;
		}
	}
	free(pS);
	pS = 0;
	system("pause");
	return;
}
