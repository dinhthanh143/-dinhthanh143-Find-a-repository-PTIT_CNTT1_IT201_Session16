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
int isEmpty(Queue *queue) {
    return queue->rear == NULL && queue->front == NULL;
}
void enQueue(Queue *q, int data) {
    Node *newNode = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    }else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
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
int main(){
    Queue *queue = createQueue();
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    printQueue(queue);
    return 0;
}
