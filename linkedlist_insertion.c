#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)
{
    while (ptr!=NULL)
    {
        printf("Element=%d\n",ptr->data);
        ptr = ptr->next;
    }
}
//case 1
struct Node* insertion_atbegining(struct Node *head, int data)
{
    //insertion at begining
    struct Node *ptr= (struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}

struct Node* insertion_atmiddle(struct Node *head, int data, int index)
{
    //insertion at middle
    struct Node *ptr= (struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

int main() 
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    //    first -> next= NULL;
    head->data=2;
    head->next=second;
    //    second->next=third;
    second->data=12;
    second->next=third;
    //    third->next=fourth;
    third->data=21;
    third->next=fourth;
    //    fourth->next=NULL;
    fourth->data=55;
    fourth->next = NULL;
    printf("Linked list before insertion:\n");
    traversal(head);
    // head=insertion_atbegining(head, 69);
    //traversal(head);
    head=insertion_atmiddle(head, 9, 3);
    printf("Linked list after insertion:\n");
    traversal(head);
    return 0;
}