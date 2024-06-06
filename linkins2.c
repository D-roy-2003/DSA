#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void linktraversal(struct node* ptr)
{
    while(ptr!=NULL)
    {
        printf("\n Element:%d",ptr->data);
        ptr=ptr->next;
    }
}

struct node* begin(struct node* head , int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}

struct node* between(struct node* head,int index,int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    ptr->data=data;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

struct node* atend(struct node* head,int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    ptr->data=data;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    ptr->next=NULL;
    p->next=ptr;
    return head;
}

struct node* afternode(struct node* head, struct node* previous, int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=previous->next;
    previous->next=ptr;
    return head;
}

int main()
{
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *second = (struct node*)malloc(sizeof(struct node));
    struct node *third = (struct node*)malloc(sizeof(struct node));
    struct node *fourth = (struct node*)malloc(sizeof(struct node));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=NULL;

    printf("\n Element before Traversal:");
    linktraversal(head);
    // head=begin(head,69);
    // head=between(head,3,69);
    // head=atend(head,69);
    head=afternode(head,second,69);
    printf("\n Element before Traversal:");
    linktraversal(head);
    return 0;
}