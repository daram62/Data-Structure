#include <stdio.h>
#include <stdlib.h>

// 노드 정의
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

tyoedef struct Queue
{
    Node *front;
    Node *rear;
    int count; // 큐 안의 노드 개수
}Queue;

//큐 초기화
