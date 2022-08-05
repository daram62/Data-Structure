#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// 노드 정의
typedef struct Node
{
    char data;
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
void enqueue(Queue *queue, char data)
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
char dequeue(Queue *queue)
{
    char data;
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

// 전체 큐 프린트하기
int Print(Queue *queue)
{   
    char data;
    int num = 0;
    Node *ptr;
    if (isEmpty(queue))
    {
        printf("Error : Queue is Empty!");
        return 0;
    }
    ptr = queue -> front;
    while(num != queue-> count)
    {
    data = ptr->data;
    printf("%c",data);
    num ++;
    ptr = ptr->next;
    }
    return 0;

}
// 큐의 front 부분 엿보기
void Peek(Queue *queue)
{   
    char data;
    data = queue->front->data;
    printf("%c",data);
}

int main(void){
 
    Queue queue;
    initQueue(&queue);
    
    char cmd[20] = {"\0"}; // 변수 설정 후 초기화
    while(true){
        printf(">>> ");
        fgets(cmd,20,stdin);

        for(int i=0;i<strlen(cmd);i++) // 명령어 길이만큼 한 줄씩 읽는데요 by 상진
        {
            switch(cmd[i]) 
            {
                case '+':
                    enqueue(&queue,cmd[++i]++);
                    break;

                case '-':
                    printf("return %c\n",dequeue(&queue));
                    break;

                case 'L':
                    Print(&queue);
                    printf("\n");
                    break;

                case 'P':
                    Peek(&queue);
                    break;
            } // switch 문입니다
        } // 명령어 해석
    } // 반복문
    return 0;
}