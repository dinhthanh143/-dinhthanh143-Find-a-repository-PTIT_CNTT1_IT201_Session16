#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node {
    int data;
    struct Node *next;
}Node;
Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
typedef struct Queue {
    Node *front;
    Node *rear;
}Queue;
Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}
int isEmpty(Queue *q) {
    return q->front ==NULL && q->rear ==NULL;
}
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        return;
    }
    Node *temp = q->front;
    while (temp != NULL) {
        printf("%d \t", temp->data);
        temp = temp->next;
    }
}
int getFront(Queue *q) {
    if (isEmpty(q)) {
        return -1;
    }
    return q->front->data;
}
void enQueue(Queue *q, int data) {
    Node *node = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = node;
    }else {
        q->rear->next = node;
        q->rear = node;
    }
}
int main(){
    Queue *queue = createQueue();
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    printQueue(queue);
    int x = getFront(queue);
    if( x == -1){
     printf("Queue is empty");
    }else{
    printf("%d", x);
    }
    return 0;
}
