#include <stdio.h>
#include <stdlib.h>

#define Q_size 5

typedef struct {
    int data[Q_size + 1];
    int head, tail;
} Queue;

void EnQueue(Queue *q, int item);
void printQueue(Queue *q);
int DeQueue(Queue *q);

int main() {
    Queue my_Queue;
    my_Queue.head = 0;
    my_Queue.tail = 0;

    EnQueue(&my_Queue, 10);
    EnQueue(&my_Queue, 20);
    EnQueue(&my_Queue, 30);

    printQueue(&my_Queue);

    int dequeuedItem = DeQueue(&my_Queue);
    if (dequeuedItem != -1) {
        printf("\nDequeued item: %d\n", dequeuedItem);
    }

    printQueue(&my_Queue);

    return 0;
}

void EnQueue(Queue *q, int item) {
    if ((q->tail + 1) % (Q_size + 1) == q->head) {
        printf("Queue is full");
        return;
    }
    q->data[q->tail] = item;
    q->tail = (q->tail + 1) % (Q_size + 1);
}

void printQueue(Queue *q) {
    if (q->head == q->tail) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->head; i != q->tail; i = (i + 1) % (Q_size + 1)) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int DeQueue(Queue *q) {
    int item;
    if (q->head == q->tail) {
        printf("Queue is empty");
        return -1;
    }
    item = q->data[q->head];
    q->head = (q->head + 1) % (Q_size + 1);
    return item;
}
