#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void traversal(struct Node* ptr) {
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// Function to delete the first node in the Doubly Linked List
struct Node* deleteAtBegin(struct Node* head) {
    if (head == NULL) {
        printf("\nList is already empty.");
        return NULL;
    }

    struct Node* newHead = head->next;
    if (newHead != NULL) {
        newHead->prev = NULL;
    }

    free(head);
    return newHead;
}

// Function to delete a node at a specific index in the Doubly Linked List
struct Node* deleteAtPosition(struct Node* head, int index) {
    if (head == NULL) {
        printf("\nList is empty.");
        return NULL;
    }

    struct Node* current = head;
    for (int i = 0; i < index && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("\nIndex out of bounds.");
        return head;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        // If the element to be deleted is the head, update the head
        head = current->next;
    }

    free(current);
    return head;
}

// Function to delete the last node in the Doubly Linked List
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("\nList is already empty.");
        return NULL;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev != NULL) {
        current->prev->next = NULL;
    } else {
        // If the list has only one element, set the head to NULL
        head = NULL;
    }

    free(current);
    return head;
}

// Function to delete a node with a specific value in the Doubly Linked List
struct Node* deleteByValue(struct Node* head, int element) {
    if (head == NULL) {
        printf("\nList is empty.");
        return NULL;
    }

    struct Node* current = head;
    while (current != NULL && current->data != element) {
        current = current->next;
    }

    if (current == NULL) {
        printf("\nElement not found in the list.");
        return head;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        // If the element to be deleted is the head, update the head
        head = current->next;
    }

    free(current);
    return head;
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* first = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    head->prev = NULL;
    head->next = first;

    first->data = 20;
    first->prev = head;
    first->next = second;

    second->data = 30;
    second->prev = first;
    second->next = third;

    third->data = 40;
    third->prev = second;
    third->next = fourth;

    fourth->data = 50;
    fourth->prev = third;
    fourth->next = NULL;

    printf("\nGiven doubly linked list before deletion:");
    traversal(head);

    // Uncomment and test different deletion cases
    // head = deleteAtBegin(head);
    // head = deleteAtEnd(head);
    // head = deleteAtPosition(head, 2);
    head = deleteByValue(head, 40);

    printf("\nGiven doubly linked list after deletion:");
    traversal(head);

    return 0;
}
