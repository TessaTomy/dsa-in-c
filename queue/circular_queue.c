#include <stdio.h>

#define MAX 3

int queue[MAX], front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % MAX);
}

int isEmpty() {
    return (front == -1);
}

void enqueue() {
    if (isFull()) {
        printf("Overflow !!\n");
        return;
    }

    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX;
    printf("Enter data: ");
    scanf("%d", &queue[rear]);
    printf("Inserted %d\n", queue[rear]);
}

void dequeue() {
    if (isEmpty()) {
        printf("Underflow !!\n");
        return;
    }
    printf("Deleted %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void traverse() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Circular Queue ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: traverse(); break;
            case 4: return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}
