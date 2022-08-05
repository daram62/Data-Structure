#include <stdio.h>
#include <stdlib.h>

// 노드 정의
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
    int count; // 큐 안의 노드 개수
}Queue;

//큐 초기화

void initQueue(Queue *queue)
{
	queue->front = queue->rear = NULL;
	queue->count = 0; // 큐 안의 노드 개수 0으로 설정
}

// isEmpty 함수
int isEmpty(Queue *queue)
{
	return queue->count == 0;
}

// 큐 데이터 삽입 enqueue 
void enqueue(Queue *queue, int data)
{   
    //newNode 생성
	Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue))
    {
        queue->front = newNode;
    }
    else
    {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    queue->count++;
    
}

// 큐 데이터 반환 dequeue
int dequeue(Queue *queue)
{
    int data;
    Node *ptr;
    if (isEmpty(queue))
    {
        printf("Error : Queue is Empty!");
        return 0;
    }
    ptr = queue->front;
    data = ptr->data;
    queue->front=ptr->next;
    free(ptr);
    queue->count--;

    return data;
}