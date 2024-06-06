#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

void linklisttraversal(struct node * ptr)
{
    // if(head==NULL)
    //     printf("\n The list is Empty");
    while(ptr!=NULL)
    {
    printf("\n Element:%d",ptr->data);
    ptr=ptr->next;
    }
}

struct node * insertionatbegining(struct node* head, int data)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    head=ptr;
}

struct node * insertionbetween(struct node* head, int data, int index)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
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

struct node * insertionatend(struct node* head, int data)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    ptr->data=data;
    ptr->next=NULL;
    p->next=ptr;
    return head;
}

struct node * insertionafternode(struct node* head, struct node* previous,  int data)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=previous->next;
    previous->next=ptr;
    return head;
}

int main()
{
    struct node * head = (struct node*)malloc(sizeof(struct node));
    struct node * second = (struct node*)malloc(sizeof(struct node));
    struct node * third = (struct node*)malloc(sizeof(struct node));
    struct node * fourth = (struct node*)malloc(sizeof(struct node));
    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=NULL;
    printf("\nElements before Insertion:");
    linklisttraversal(head);
    // head=insertionatbegining(head,69);
    // head=insertionbetween(head,69,2);
    // head=insertionatend(head,50);
    head=insertionafternode(head,second,69);
    printf("\nElements after Insertion:");
    linklisttraversal(head);
    return 0;
}