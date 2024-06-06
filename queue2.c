#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Initialize queue
void initializeQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Check if queue is full
int isFull(struct Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

// Check if queue is empty
int isEmpty(struct Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Enqueue an element into the queue
void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full, cannot enqueue.\n");
        return ;
    } else {
        queue->rear++;
    }
    queue->items[queue->rear] = value;
}

// Dequeue an element from the queue
int dequeue(struct Queue *queue) {
    int dequeuedItem;
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue.\n");
        return -1;
    } else if (queue->front == queue->rear) {
        dequeuedItem = queue->items[queue->front];
        queue->front = -1;
        queue->rear = -1;
    } else {
        dequeuedItem = queue->items[queue->front];
        queue->front++;
    }
    return dequeuedItem;
}

// Print the queue
void printQueue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);
    int choice, value;

    do {
        printf("\nChoose an option:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                printf("Dequeued element: %d\n", dequeue(&queue));
                break;
            case 3:
                printQueue(&queue);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
