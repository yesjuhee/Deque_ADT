#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node* next;
	struct _node* prev;
}Node;

typedef struct _dlDeque {
	Node* head;
	Node* tail;
}DLDeque;

typedef DLDeque Deque;

void DequeInit(Deque* pdeq);
int DQIsEmpty(Deque* pdeq);

void DQAddFirst(Deque* pdeq, Data data);	//���� �Ӹ��� ������ �߰�
void DQAddLast(Deque* pdeq, Data data);		//���� ������ ������ �߰�

Data DQRemoveFirst(Deque* pdeq);			//���� �Ӹ����� ������ ����
Data DQRemoveLast(Deque* pdeq);				//���� �������� ������ ����

Data DQGetFirst(Deque* pdeq);				//���� �Ӹ����� ������ ����
Data DQGetLast(Deque* pdeq);				//���� �������� ������ ����

#endif __DEQUE_H__
