#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"


void DequeInit(Deque* pdeq) 
{
	pdeq->head = NULL; //front
	pdeq->tail = NULL; //rear
}
int DQIsEmpty(Deque* pdeq) //덱이 비었으면 1을 반환
{
	if (pdeq->head == NULL)	return TRUE;
	else                    return FALSE;
}

void DQAddFirst(Deque* pdeq, Data data)				//덱의 머리에 데이터 추가
{			
	Node* newNode = (Node*)malloc(sizeof(Node));	//추가할 노드
	newNode->data = data;
	newNode->next = pdeq->head;						//newNode의 rlink 머리에 연결
	newNode->prev = NULL;							//newNode의 llink는 NULL로 초기화

	if (DQIsEmpty(pdeq))	pdeq->tail = newNode;	    //덱이 비어있다면 tail이 newNode 가리킴
	else					pdeq->head->prev = newNode;	//아니면 첫번째 노드 rlink가 newNode 가리킴

	pdeq->head = newNode;							//덱의 head가 newNode 가리킴
}	
void DQAddLast(Deque* pdeq, Data data) 		//덱의 꼬리에 데이터 추가
{
	Node* newNode = (Node*)malloc(sizeof(Node));	//추가할 노드
	newNode->data = data;
	newNode->prev = pdeq->tail;						//newNode의 llink 꼬리에 연결
	newNode->next = NULL;							//newNode의 rlink NULL로 초기화

	if (DQIsEmpty(pdeq))	pdeq->head = newNode;		//덱이 비어있다면 head가 newNode 가리킴
	else					pdeq->tail->next = newNode; //아니면 마지막 노드에 llink가 newNode 가리킴

	pdeq->tail = newNode;							//덱의 tail이 newNode 가리킴
}

Data DQRemoveFirst(Deque* pdeq)			//덱의 머리에서 데이터 삭제
{
	if (DQIsEmpty(pdeq))				//underflow error message
	{
		printf("Deque Memorry Error!");
		exit(-1);
	};

	Node* rnode = pdeq->head;			//지워질 노드(맨앞)를 가리킬 포인터
	Data rdata;							//데이터 반환을 위한 변수
	
	rdata = pdeq->head->data;

	pdeq->head = pdeq->head->next;		//head 위치를 다음 노드로 변경
	free(rnode);						//메모리 삭제

	if (pdeq->head == NULL) pdeq->tail = NULL;			//덱이 비었다면 tail이 NULL을 가리키도록 조정
	else					pdeq->head->prev = NULL;	//아니라면 삭제된 노드 다음 노드의 llink NULL로 초기화

	return rdata;
}
Data DQRemoveLast(Deque* pdeq)				//덱의 꼬리에서 데이터 삭제
{
	if (DQIsEmpty(pdeq))					//underflow error message
	{
		printf("Deque Memorry Error!");
		exit(-1);
	}; 

	Node* rnode = pdeq->tail;				//지워질 노드(맨뒤)를 가리킬 포인터
	Data rdata;								//데이터 반환을 위한 변수
	
	rdata = pdeq->tail->data;				
	
	pdeq->tail = pdeq->tail->prev;			//tail의 위치를 이전 노드로 변경
	free(rnode);							//메모리 삭제

	if (pdeq->tail == NULL)	pdeq->head = NULL;			//덱이 비었다면 head가 NULL을 가리키도록 조정
	else					pdeq->tail->next = NULL;	//아니라면 삭제된 노드 이전 노드의 rlink를 NULL로 초기화

	return rdata;
}

Data DQGetFirst(Deque* pdeq)				//덱의 머리에서 데이터 참조
{
	if (DQIsEmpty(pdeq))					//underflow error message
	{
		printf("Deque Memorry Error!");
		exit(-1);
	};
	
	return pdeq->head->data;
}
Data DQGetLast(Deque* pdeq)				//덱의 꼬리에서 데이터 참조
{
	if (DQIsEmpty(pdeq))					//underflow error message
	{
		printf("Deque Memorry Error!");
		exit(-1);
	};

	return pdeq->tail->data;
}
