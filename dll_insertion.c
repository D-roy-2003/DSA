#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

void doublyLinkedListTraversal(struct Node *head)
{
    struct Node *current = head;

    while (current != NULL)
    {
        printf("Element: %d\n", current->data);
        current = current->next;
    }
}

// Case 1: Insert at the beginning of the Doubly Linked List
struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;

    // if (head != NULL)
    ptr->next = head;
    head->prev = ptr;
    return ptr; 
}

// Case 2: Insert at a specified index in the Doubly Linked List
struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;

    while (i!=index-1)//&& p != NULL)
    {
        p = p->next;
        i++;
    }

    // if (p == NULL)
    // {
    //     // Index is out of bounds, return the original head
    //     return head;
    // }

    ptr->data = data;
    ptr->prev = p;
    ptr->next = p->next;
    // if (p->next != NULL)
    p->next->prev = ptr;
    p->next = ptr;
    return head;
}

// Case 3: Insert at the end of the Doubly Linked List
struct Node * insertAtEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    // if (head == NULL)
    // {
    //     // If the list is empty, set the new node as the head
    //     ptr->prev = NULL;
    //     return ptr;
    // }

    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = NULL;
    p->next = ptr;
    ptr->prev = p;
    return head;
}

// Case 4: Insert after a specific node in the Doubly Linked List
struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data){
    if (prevNode == NULL)
    {
        // If the provided previous node is NULL, return the original head
        return head;
    }

    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = prevNode;
    ptr->next = prevNode->next;
    prevNode->next->prev = ptr;
    prevNode->next = ptr;
    return head;
}

int main(){
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    struct Node *fourth = NULL;

    // Allocate memory for nodes in the doubly linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link nodes in the doubly linked list
    head->data = 10;
    head->prev = NULL;
    head->next = second;

    second->data = 20;
    second->prev = head;
    second->next = third;

    third->data = 30;
    third->prev = second;
    third->next = fourth;

    fourth->data = 40;
    fourth->prev = third;
    fourth->next = NULL;

    printf("Doubly Linked list before insertion\n");
    doublyLinkedListTraversal(head);

    // Uncomment and test different insertion cases
    // head = insertAtFirst(head, 56);
    head = insertAtIndex(head, 56, 3);
    // head = insertAtEnd(head, 56);
    // head = insertAfterNode(head, third, 69);

    printf("\nDoubly Linked list after insertion\n");
    doublyLinkedListTraversal(head);

    return 0;
}
