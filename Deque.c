#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"


void DequeInit(Deque* pdeq) 
{
	pdeq->head = NULL; //front
	pdeq->tail = NULL; //rear
}
int DQIsEmpty(Deque* pdeq) //���� ������� 1�� ��ȯ
{
	if (pdeq->head == NULL)	return TRUE;
	else                    return FALSE;
}

void DQAddFirst(Deque* pdeq, Data data)				//���� �Ӹ��� ������ �߰�
{			
	Node* newNode = (Node*)malloc(sizeof(Node));	//�߰��� ���
	newNode->data = data;
	newNode->next = pdeq->head;						//newNode�� rlink �Ӹ��� ����
	newNode->prev = NULL;							//newNode�� llink�� NULL�� �ʱ�ȭ

	if (DQIsEmpty(pdeq))	pdeq->tail = newNode;	    //���� ����ִٸ� tail�� newNode ����Ŵ
	else					pdeq->head->prev = newNode;	//�ƴϸ� ù��° ��� rlink�� newNode ����Ŵ

	pdeq->head = newNode;							//���� head�� newNode ����Ŵ
}	
void DQAddLast(Deque* pdeq, Data data) 		//���� ������ ������ �߰�
{
	Node* newNode = (Node*)malloc(sizeof(Node));	//�߰��� ���
	newNode->data = data;
	newNode->prev = pdeq->tail;						//newNode�� llink ������ ����
	newNode->next = NULL;							//newNode�� rlink NULL�� �ʱ�ȭ

	if (DQIsEmpty(pdeq))	pdeq->head = newNode;		//���� ����ִٸ� head�� newNode ����Ŵ
	else					pdeq->tail->next = newNode; //�ƴϸ� ������ ��忡 llink�� newNode ����Ŵ

	pdeq->tail = newNode;							//���� tail�� newNode ����Ŵ
};

Data DQRemoveFirst(Deque* pdeq)			//���� �Ӹ����� ������ ����
{
	if (DQIsEmpty(pdeq))				//underflow error message
	{
		printf("Deque Memorry Error!");
		exit(-1);
	};

	Node* rnode = pdeq->head;			//������ ���(�Ǿ�)�� ����ų ������
	Data rdata;							//������ ��ȯ�� ���� ����
	
	rdata = pdeq->head->data;

	pdeq->head = pdeq->head->next;		//head ��ġ�� ���� ���� ����
	free(rnode);						//�޸� ����

	if (pdeq->head == NULL) pdeq->tail = NULL;			//���� ����ٸ� tail�� NULL�� ����Ű���� ����
	else					pdeq->head->prev = NULL;	//�ƴ϶�� ������ ��� ���� ����� llink NULL�� �ʱ�ȭ

	return rdata;
};
Data DQRemoveLast(Deque* pdeq)				//���� �������� ������ ����
{
	if (DQIsEmpty(pdeq))					//underflow error message
	{
		printf("Deque Memorry Error!");
		exit(-1);
	}; 

	Node* rnode = pdeq->tail;				//������ ���(�ǵ�)�� ����ų ������
	Data rdata;								//������ ��ȯ�� ���� ����
	
	rdata = pdeq->tail->data;				
	
	pdeq->tail = pdeq->tail->prev;			//tail�� ��ġ�� ���� ���� ����
	free(rnode);							//�޸� ����

	if (pdeq->tail == NULL)	pdeq->head = NULL;			//���� ����ٸ� head�� NULL�� ����Ű���� ����
	else					pdeq->tail->next = NULL;	//�ƴ϶�� ������ ��� ���� ����� rlink�� NULL�� �ʱ�ȭ

	return rdata;
};

Data DQGetFirst(Deque* pdeq)				//���� �Ӹ����� ������ ����
{
	if (DQIsEmpty(pdeq))					//underflow error message
	{
		printf("Deque Memorry Error!");
		exit(-1);
	};
	
	return pdeq->head->data;
};
Data DQGetLast(Deque* pdeq)				//���� �������� ������ ����
{
	if (DQIsEmpty(pdeq))					//underflow error message
	{
		printf("Deque Memorry Error!");
		exit(-1);
	};

	return pdeq->tail->data;
}